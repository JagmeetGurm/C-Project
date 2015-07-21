#ifndef STACK_H
#define STACK_H

using namespace std;


	template <class T>
	class Stack {
	private:
		vector<T> ints;     // elements 

	public:
		void push(T const&);  // push element 
		void pop();               // pop element 
		T top() ;            // return top element 
		bool empty() {       // return true if empty.
			return ints.empty();
		}
	};

	template <class T>
	void Stack<T>::push(T const& elem)
	{
		// append copy of passed element 
		ints.push_back(elem);
	}

	template <class T>
	void Stack<T>::pop()
	{
		if (ints.empty()) {
			throw out_of_range("Stack<>::pop(): empty stack");
		}
		// remove last element 
		ints.pop_back();
	}

	T Stack<T>::top(){
		if (ints.empty()){
			throw out_of_range("stack<T>::top():empty stack");

		}
		return ints.back();

	}
#endif
