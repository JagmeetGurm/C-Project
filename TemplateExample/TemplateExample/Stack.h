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

#endif
