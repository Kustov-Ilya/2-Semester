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
	value_type Ptr[N];
	using iterator = value_type *;


	TArray(){}


	~TArray(){}


	TArray(std::initializer_list<T> data){
		int i = 0;
		for (auto & dat : data) {
			Ptr[i] = dat;
			++i;
		}
	}

	size_type size() const throw(){
		return N;
	}


	size_type max_size() const throw(){
		return N;
	}


	bool empty() const throw(){
		return N == 0;
	}


	reference operator[] (size_type index){
		return Ptr[index];
	}


	const_reference operator[] (size_type index) const{
		return Ptr[index];
	}


	reference at(size_type index){
		if (index <= N && index >= 0) return Ptr[index];
		throw std::out_of_range("Invalide Value\n");
	}


	const_reference at(size_type index) const{
		if (index <= N && index >= 0) return Ptr[index];
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
		
		for (size_type i = 0 ; i < N; ++i)
			Ptr[i] = value;
	}


	void swap(TArray<T, N> & x) throw(){
		std::swap(Ptr, x.Ptr);
	}

};
