#ifndef STACK_H
#define STACK_H
#include <vector>
#include <iostream>
using namespace std;


	template <class T>
	class Stack {
	private:
		vector<T> elements;     // elements 

	public:
		void push(T const&);  // push element 
		void pop();               // pop element 
		T top() ;            // return top element 
		bool empty();
		
	};

	template <class T>
	void Stack<T>::push(T const& elem)
	{
		// append copy of passed element 
		elements.push_back(elem);
	}

	template <class T>
	void Stack<T>::pop()
	{
		if (elements.empty()) {
			throw out_of_range("Stack<>::pop(): empty stack");
		}
		// remove last element 
		elements.pop_back();
	}
	template<class T>
	T Stack<T>::top(){
		if (elements.empty()){
			throw out_of_range("stack<T>::top():empty stack");

		}
		return elements.back();

	}

	template<class T>
	bool Stack<T>::empty(){
		return(elements.empty());
	}
#endif
