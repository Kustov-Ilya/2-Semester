#pragma once
#include<iostream>
#include<initializer_list>
#include<string>
#include<exception>

struct VoidValue
	: public std::exception
{
	VoidValue(char const* const message) throw()
		: std::exception(message){}
};



template<class T, class Compare = std::less<>>
class TMultiset {
public:
	using key_compare = Compare;
	using value_type = T;
	using size_type = size_t;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using reference = value_type&;
	using const_reference = const value_type&;

	struct Node {
		value_type Data;
		size_type Nom;
		Node* Left;
		Node* Right;
		Node* Prev;

	private:
		Node()
			:Left(nullptr), Right(nullptr), Prev(nullptr), Nom(0) {}

		Node(const value_type &val)
			:Data(val), Nom(1), Left(nullptr), Right(nullptr), Prev(nullptr) {}

		~Node()
		{
			if (Left != nullptr)
				delete Left;
			if (Right != nullptr)
				delete Right;
		}

		friend class TMultiset;

	};

	class Iterator
	{
		Node *Ptr;
		size_type n;
	public:
		Iterator()
			:Ptr(nullptr), n(1) {}

		Iterator(Node &rhs)
			:Ptr(&rhs), n(1) {}

		Iterator(const Iterator &rhs)
			:Ptr(rhs.Ptr), n(1) {}

		~Iterator() {
		}

		Iterator& operator++() {
			if (n < this->Ptr->Nom) {
				n++;
				return *this;
			}
			else {
				n = 1;
			}
			Iterator *tmp = this;
			if (tmp->Ptr->Right) {
				tmp->Ptr = tmp->Ptr->Right;
				while (tmp->Ptr->Left)
				{
					tmp->Ptr = tmp->Ptr->Left;
				}
			}
			else {
				Iterator tmpprev(*tmp);
				tmpprev.Ptr = tmpprev.Ptr->Prev;
				while (tmpprev.Ptr->Right == tmp->Ptr) {
					tmpprev.Ptr = tmpprev.Ptr->Prev;
					tmp->Ptr = tmp->Ptr->Prev;
				}
				tmp->Ptr = tmp->Ptr->Prev;
			}
			return *tmp;
		}

		Iterator& operator--() {
			if (n < this->Ptr->Nom) {
				n++;
				return *this;
			}
			else {
				n = 1;
			}
			Iterator *tmp = this;
			if (tmp->Ptr->Left) {
				tmp->Ptr = tmp->Ptr->Left;
				while (tmp->Ptr->Right)
				{
					tmp->Ptr = tmp->Ptr->Right;
				}
			}
			else {
				Iterator tmpprev(*tmp);
				tmpprev.Ptr = tmpprev.Ptr->Prev;
				while (tmpprev.Ptr->Left == tmp->Ptr) {
					tmpprev.Ptr = tmpprev.Ptr->Prev;
					tmp->Ptr = tmp->Ptr->Prev;
				}
				tmp->Ptr = tmp->Ptr->Prev;
			}
			return *tmp;
		}

		const Iterator operator++(int) {
			Iterator it(*this);
			++*this;
			return it;
		}

		const Iterator operator--(int) {
			Iterator it(*this);
			--*this;
			return it;
		}

		Iterator& operator=(const Iterator &rhs) {
			Ptr = rhs.Ptr;
			n = rhs.Ptr->Nom;
			return *this;
		}
		
		reference operator*() {
			if (Ptr == nullptr)
				throw VoidValue("Iterator is empty");
			return (Ptr->Data);
		}
		
		const_reference operator*() const {
			if (Ptr == nullptr)
				throw VoidValue("Iterator is empty");
			return (Ptr->Data);
		}
		
		pointer operator->() {
			if (Ptr == nullptr)
				throw VoidValue("Iterator is empty");
			return &(Ptr->Data);
		}
		
		const_pointer operator->() const {
			if (Ptr == nullptr)
				throw VoidValue("Iterator is empty");
			return &(Ptr->Data);
		}

		const bool operator==(const Iterator &rhs) {
			return (Ptr == rhs.Ptr);
		}

		const bool operator!=(const Iterator &rhs) {
			return (Ptr != rhs.Ptr);
		}

		friend class TMultiset;

	};

private:
	Node* Root;
	Node* End;
	size_type Size;
	key_compare comp;

	void InsertBranch(Node *rhs) {
		if (rhs == nullptr) return;
			if (!Root) {
			rhs->Prev = nullptr;
			Root = rhs;
			return;
		}
		if (rhs->Nom == 0) {
			Node *tmp = Root;
			while (tmp->Right) tmp = tmp->Right;
			tmp->Right = rhs;
			rhs->Prev = tmp;
			return;
			}
		Node* tmp = Root;
		while (tmp) {
			if (comp(tmp->Data, rhs->Data)) {
				if (tmp->Right&&tmp->Right != End) tmp = tmp->Right;
				else {
					DelEnd();
					rhs->Prev = tmp;
					tmp->Right = rhs;
					SetEnd();
					return;
				}
			}
			else {
				if (tmp->Left) tmp = tmp->Left;
				else {
					rhs->Prev = tmp;
					tmp->Left = rhs;
					return;
				}
			}
		}
	}

	void InsertTree(Node *root) {
		for (size_type i = 0; i < root->Nom; i++) insert(root->Data);
		if (root->Right&&root->Nom != 0) InsertTree(root->Right);
		if (root->Left) InsertTree(root->Left);
	}

	void SetEnd() {
		if (End) DelEnd();
		End = new Node;
		Node *tmp = Root;
		if (tmp->Right) {
			while (tmp->Right != nullptr) tmp = tmp->Right;
			tmp->Right = End;
			End->Prev = tmp;
		}
		else {
			Root->Right = End;
			End->Prev = tmp;
		}
	}

	void DelEnd() {
		if (End == nullptr) return;
		Node *tmp = End;
		tmp = tmp->Prev;
		tmp->Right = nullptr;
		delete End;
		End = nullptr;
	}

	Node * FindNode(const value_type& val) const{
		if (Root == nullptr)
			throw VoidValue("Myltiset is empty");
		Node *tmp = Root;
		while (tmp&&tmp->Nom!=0) {
			if (!comp(val, tmp->Data) &&!comp(tmp->Data, val)) {
				return tmp;
			}
			if (comp(tmp->Data, val)) tmp = tmp->Right;
			else tmp = tmp->Left;
		}
		return nullptr;
	}

	using iterator = Iterator;
	using const_iterator = const Iterator;

public:

	explicit TMultiset(const key_compare& compare = key_compare())
		:Root(nullptr), Size(0) {
		comp = compare;
	}
	
	TMultiset(const TMultiset& x, const key_compare& compare = key_compare())
		:TMultiset() {
		if (x.Root == nullptr)
			throw VoidValue("Myltiset is empty");
		InsertTree(x.Root);
	}

	TMultiset(std::initializer_list<value_type> il, const key_compare& compare = key_compare())
		:TMultiset() {
		insert(il.begin(), il.end());
	}

	template<class InputIterator>
	TMultiset(InputIterator first, InputIterator last, const key_compare& compare = key_compare())
		:TMultiset() {
		for (first; first != last; ++first) Insert(*first);
	}

	~TMultiset() {
		if (Root != nullptr)delete Root;
	}
	
	TMultiset& operator= (const TMultiset& x) {
		if (x.Root == nullptr)
			throw VoidValue("Myltiset is empty");

		if (Root == x.Root) return *this;
		clear();
		for (Iterator it = x.begin(); it != x.end(); ++it)
			insert(*it);
		return *this;
	}

	TMultiset& operator= (std::initializer_list<value_type> il) {
		if (Root) clear();
		for (Iterator it = il.begin(); it != il.end(); ++it)
			insert(*it);
		return *this;
	}

	void insert(const value_type &val) {
		Size++;
		if (Root == nullptr) {
			Root = new Node(val);
			SetEnd();
		}
		else {
			Node* Fin = Root;
			if (count(val) == 0) {
				Node *tmp = new Node(val);
				while (tmp) {
					if (comp(Fin->Data,val)) {
						if (Fin->Right&&Fin->Right != End) Fin = Fin->Right;
						else {
							DelEnd();
							Fin->Right = tmp;
							tmp->Prev = Fin;
							SetEnd();
							return;
						}
					}
					else {
						if (Fin->Left) Fin = Fin->Left;
						else {
							Fin->Left = tmp;
							tmp->Prev = Fin;
							return;
						}
					}
				}
			}
			else {
				while (Fin) {
					if (Fin->Data == val) {
						Fin->Nom++;
						return;
					}
					if (comp(Fin->Data, val)) Fin = Fin->Right;
					else Fin = Fin->Left;
				}
			}
		}
	}

	iterator end()noexcept {
		Iterator End1(*End);
		return End1;
	}

	const_iterator end() const noexcept {
		Iterator End1(*End);
		return End1;
	}

	iterator begin() noexcept {
		Node *tmp = Root;
		if (tmp->Left) {
			while (tmp->Left != nullptr) tmp = tmp->Left;
			Iterator tm(*tmp);
			return tm;
		}
		else {
			Iterator tm(*Root);
			return tm;
		}
	}

	const_iterator begin() const noexcept {
		Node *tmp = Root;
		if (tmp->Left) {
			while (tmp->Left != nullptr) tmp = tmp->Left;
			Iterator tm(*tmp);
			return tm;
		}
		else {
			Iterator tm(*Root);
			return tm;
		}
	}
	
	iterator find(const value_type &val) {
		Node * tmp = FindNode(val);
		if(tmp==nullptr) return end();
		Iterator it(*tmp);
		return it;
	}
	
	const_iterator find(const value_type& val) const {
		Node * tmp = FindNode(val);
		if (tmp == nullptr) return end();
		Iterator it(*tmp);
		return it;
	}

	void clear() {
		if (Root == nullptr) return;
		Size = 0;
		delete Root;
		Root = nullptr;
		End = nullptr;
	}

	
	size_type count(const value_type& val) const{
		Node * tmp = FindNode(val);
		if (tmp == nullptr) return 0;
		return tmp->Nom;
	}

	bool empty() const noexcept {
		return Root == nullptr;
	}

	iterator  erase(const_iterator position) {
		if (position.Ptr == nullptr) throw VoidValue("Iterator does not exist");
		Iterator it = position;
		Size--;
		if (it == end()) return end();
		++it;
		if (position.Ptr->Nom > 1) {
			position.Ptr->Nom--;
			return it;
		}
		Node *tmpL = nullptr;
		Node *tmpR = nullptr;
		if (position.Ptr->Right) {
			tmpR = position.Ptr->Right;
			position.Ptr->Right = nullptr;
		}
		if (position.Ptr->Left) {
			tmpL = position.Ptr->Left;
			position.Ptr->Left = nullptr;
		}
		if (position.Ptr == Root) {
			delete Root;
			Root = nullptr;
		}
		else {
			if (comp(position.Ptr->Prev->Data, *position))
				position.Ptr->Prev->Right = nullptr;
			else position.Ptr->Prev->Left = nullptr;
			position.Ptr->Prev = nullptr;
			delete position.Ptr;
		}
		InsertBranch(tmpL);
		InsertBranch(tmpR);
		if (End == nullptr) SetEnd();
		return it;
	}
	
	size_type erase(const value_type& val) {
		Iterator it = find(val);
		if (it == end()) return 0;
		size_type Num = it.Ptr->Nom;
		for (size_type i = Num; 0 < i; --i) {
			Iterator delet = it;
			++it;
			erase(delet);
		} 
			return Num;
	}

	iterator  erase(const_iterator &first, const_iterator &last) {
		Iterator delet;
		if (begin() == first  && end() == last) {
			clear();
			return delet;
		} 
		Iterator it = first;
		if (end() != last)
		{
			while (it != last) {
				delet = it;
				it = erase(delet);
			}
		}
		else
		{
			while (it!=end())
			{
				delet = it;
				it = erase(delet);
			}
			if (Root->Nom == 0) {
				delete End;
				Root = nullptr;
				End = nullptr;
			}
		}
		return it;
	}

	void insert(std::initializer_list<value_type> il) {
		for (auto &val : il) {
			insert(val);
		}
	}

	template<class InputIterator>
	void insert(InputIterator first, InputIterator last) {
		InputIterator it = first;
		for (it; it != last; ++it)
			insert(*it);
	}

	size_type size() const noexcept {
		return Size;
	}

	void swap(TMultiset& x) {
		std::swap(Size, x.Size);
		std::swap(End, x.End);
		std::swap(Root, x.Root);
	}

	iterator lower_bound(const value_type& val)
	{
		if (comp(End->Prev->Data, val)) return end();
		Iterator Iter = this->begin();
		while (comp(*Iter, val)) ++Iter;
		return Iter;
	}

	iterator upper_bound(const value_type& val)
	{
		if (comp(End->Prev->Data, val)) return end();
		Iterator Iter(*End->Prev);
		while (comp(val, *Iter))
			--Iter;
		++Iter;
		return Iter;
	}
};