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

template<class T>
bool Less(T a, T b) {
	return a > b;
}

template<class T, bool Compare(T a, T b) = Less<T>>
class TMultiset {
public:
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



	};

private:
	Node* Root;
	Node* End;
	size_type Size;

	void InsertBranch(Node *rhs) {
		if (rhs == nullptr) return;
		if (!Root) {
			rhs->Prev = nullptr;
			Root = rhs;
			return;
		}
		Node* tmp = Root;
		while (tmp) {
			if (Compare(rhs->Data, tmp->Data)) {
				if (tmp->Right&&tmp->Right != End) tmp = tmp->Right;
				else {
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


	using iterator = Iterator;
	using const_iterator = const Iterator;

public:

	TMultiset()
		:Root(nullptr), Size(0) {}
	
	TMultiset(const TMultiset& x)
		:Root(nullptr), Size(0) {
		if (x.Root == nullptr)
			throw VoidValue("Myltiset is empty");
		InsertTree(x.Root);
	}

	TMultiset(std::initializer_list<value_type> il)
		:Root(nullptr), Size(0) {
		for (auto &val : il) Insert(val);
	}

	template<class InputIterator>
	TMultiset(InputIterator first, InputIterator last)
		: Root(nullptr), Size(0) {
		for (first; first != last; ++first) Insert(*first);
	}

	~TMultiset() {
		if (Root != nullptr)delete Root;
	}
	
	TMultiset& operator= (const TMultiset& x) {
		if (x.Root == nullptr)
			throw VoidValue("Myltiset is empty");
	        clear();
		TMultiset tmp(x);
		return tmp;
	}

	TMultiset& operator= (std::initializer_list<value_type> il) {
	        clear();
		TMultiset tmp(il);
		return tmp;
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
					if (Compare(val, Fin->Data)) {
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
					if (Compare(val, Fin->Data)) Fin = Fin->Right;
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
	
	void print() {
		if (Root == nullptr)
			throw VoidValue("Myltiset is empty");
		for (Iterator it = begin(); it != end(); ++it) {
			std::cout << *it << " ";
		}
	}
	
	iterator find(const value_type &val) {
		if (Root == nullptr)
			throw VoidValue("Myltiset is empty");
		for (Iterator i = begin(); i != end(); ++i)
			if (*i == val) return i;
		return end();
	}
	
	const_iterator find(const value_type& val) const {
		if (Root == nullptr)
			throw VoidValue("Myltiset is empty");
		for (Iterator i = begin(); i != end(); ++i)
			if (*i == val) return i;
		return end();
	}

	void clear() {
		if (Root == nullptr) return;
		Size = 0;
		delete Root;
		Root = nullptr;
		End = nullptr;
	}

	
	size_type count(const value_type& val) const {
		if (Root == nullptr)
			throw VoidValue("Myltiset is empty");
		Node *tmp = Root;
		while (tmp) {
			if (tmp->Data == val) return tmp->Nom;
			if (Compare(val, tmp->Data)) tmp = tmp->Right;
			else tmp = tmp->Left;
		}
		return 0;
	}

	bool empty() const noexcept {
		return Root == nullptr;
	}

	iterator  erase(const_iterator position) {
		bool FindEl = false;
		Iterator it;
		for (Iterator i = begin(); i != end(); ++i) {
			if (i == position) {
				FindEl = true;
				break;
			}
		}

		if (FindEl == true) {
			it = position;
			++it;
			erase(*position);
		}

		return it;
	}
	
	size_type erase(const value_type& val) {
		if (Root == nullptr) 
			throw VoidValue("Myltiset is empty");
		Node* tmp = Root;
		while (tmp) {
			if (tmp->Data == val) break;
			if (Compare(val, tmp->Data)) tmp = tmp->Right;
			else tmp = tmp->Left;
		}
		if (tmp == nullptr) return 0;
		size_type Num = tmp->Nom;
		Size -= Num;
		DelEnd();
		Node* Nod = nullptr;

		if (tmp == Root) {
			Node* Nod1 = nullptr;
			if (tmp->Right) {
				Nod = tmp->Right;
				tmp->Right = nullptr;
				Nod->Prev = nullptr;
			}
			if (tmp->Left) {
				Nod = tmp->Left;
				tmp->Left = nullptr;
				Nod->Prev = nullptr;
			}
			delete tmp;
			Root = nullptr;
			InsertBranch(Nod);
			InsertBranch(Nod1);
		}
		else
		{
			Node* Elem = tmp->Prev;
			if (Elem->Right == tmp) Elem->Right = nullptr;
			else Elem->Left = nullptr;
			tmp->Prev = nullptr;
			if (tmp->Right) {
				Nod = tmp->Right;
				tmp->Right = nullptr;
				Nod->Prev = nullptr;
				InsertBranch(Nod);
			}

			if (tmp->Left) {
				Nod = tmp->Left;
				tmp->Left = nullptr;
				Nod->Prev = nullptr;
				InsertBranch(Nod);
			}
		}
		if (End == nullptr) SetEnd();
		return Num;

	}

	iterator  erase(const_iterator &first, const_iterator &last) {
		Iterator it = first;
		while (it != last) {
			Iterator delet(it);
			++it;
			erase(delet);
		}
		++it;
		return it;
	}

	void insert(std::initializer_list<value_type> il) {
		for (auto &val : il) {
			insert(val);
		}
	}

	template<class InputIterator>
	void insert(InputIterator first, InputIterator last) {
		Iterator it = first;
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
		if (Compare(val, End->Prev->Data)) return end();
		iterator Iter = this->begin();
		while (Compare(val, *Iter)) ++Iter;
		return Iter;
	}

	iterator upper_bound(const value_type& val)
	{
		if (Compare(val, End->Prev->Data)) return end();
		iterator Iter(*End->Prev);
		while (Compare(*Iter, val))
			--Iter;
		++Iter;
		return Iter;
	}
};
