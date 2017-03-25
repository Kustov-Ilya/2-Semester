#pragma once
#include <iostream>
#include <exception>
#include<stdexcept>

template <class T, std::size_t N> struct TArray {
	using value_type = T;
	using size_type = size_t;
	using reference = value_type&;
	using const_reference = const value_type&;
	using const_pointer = const T*;
	size_type Num = 0;
	value_type * Ptr;
	using iterator = value_type *;


	TArray(){
		Ptr = new value_type[N];
	}


	~TArray(){
		delete[] Ptr;
	}


	TArray(std::initializer_list<T> init){
		Ptr = new value_type[N];
		memcpy(begin(), init.begin(), sizeof(init));
		Num = init.size();
	}


	TArray& operator= (std::initializer_list<T> init){
		if (Ptr) delete[] Ptr;
		Ptr = new value_type[N];
		memcpy(begin(), init.begin(), sizeof(init));
		Num = init.size();
		return *this;
	}


	size_type size() const throw(){
		return Num;
	}


	size_type max_size() const throw(){
		return N;
	}


	bool empty() const throw(){
		return Num == 0;
	}


	reference operator[] (size_type index){
		return Ptr[index];
	}


	const_reference operator[] (size_type index) const{
		return Ptr[index];
	}


	reference at(size_type index){
		if (index <= Num && index >= 0) return Ptr[index];
		throw std::out_of_range("Invalide Value\n");
	}


	const_reference at(size_type index) const{
		if (index <= Num && index >= 0) return Ptr[index];
		throw std::out_of_range("Invalide Value\n");
	}


	iterator begin() throw(){
		return Ptr;
	}


	iterator end() throw(){
		return Ptr + N;
	}


	reference front(){
		return Ptr[0];
	}


	const_reference front() const{
		return Ptr[0];
	}


	reference back(){
		return Ptr[N - 1];
	}


	const_reference back() const{
		return Ptr[N - 1];
	}


	iterator data() throw(){
		return Ptr;
	}
	

	const iterator data() const throw(){
		return Ptr;
	}


	void fill(const_reference value){
		
		for (size_type i = 0 ; i < N; i++)
			Ptr[i] = value;
		Num = N;
	}


	void swap(TArray<T, N> & x) throw(){
		std::swap(Ptr, x.Ptr);
		std::swap(Num, x.Num);
	}

};
