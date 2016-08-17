#include "stdafx.h"
#include "heap.h"
#include <iostream>
using namespace std;






template <typename E, typename Comp>

heap<E,Comp>::heap(E* h, int num, int max) // Constructor
{
	Heap = h; n = num; maxsize = max; buildHeap();
}

template <typename E, typename Comp>

int heap<E,Comp>:: size()  // Return current heap size
{
	return n;
}

template <typename E, typename Comp>

void heap<E,Comp>::print()
{
	for (int i = 0; i < n; i++)
	{
		cout << Heap[i] << endl;
	}
}
template <typename E, typename Comp>
void heap<E,Comp>:: swap(E* h, int a, int b)
{
	E temp = h[a];
	h[a] = h[b];
	h[b] = temp;
}

template <typename E,typename Comp>

bool heap<E,Comp>:: isLeaf(int pos)  // True if pos is a leaf
{
	heapread++;
	return (pos >= n / 2) && (pos < n);
}

template <typename E, typename Comp>

int heap<E,Comp>:: leftchild(int pos) 
{
	heapread++;
	return 2 * pos + 1;
} // Return leftchild position

template <typename E, typename Comp>

int heap<E,Comp>:: rightchild(int pos) 
{
	heapread++;
	return 2 * pos + 2;
} // Return rightchild position
template <typename E, typename Comp>

int heap<E,Comp>::parent(int pos)  // Return parent position
{
	heapread++;
	return (pos - 1) / 2;
}

template <typename E, typename Comp>

void heap<E,Comp>:: buildHeap() // Heapify contents of Heap
{
	for (int i = n / 2 - 1; i >= 0; i--) heapread++; siftdown(i);
}


// Insert "it" into the heap
template <typename E, typename Comp>

void heap<E,Comp>::insert(const E& it) {
//	Assert(n < maxsize, "Heap is full");
	int curr = n++;
	Heap[curr] = it; // Start at end of heap
	// Now sift up until curr’s parent > curr
	while ((curr != 0) &&
		(Comp::prior(Heap[curr], Heap[parent(curr)]))) {
		swap(Heap, curr, parent(curr));
		curr = parent(curr);
	}
	heapwrite++;
}

template <typename E, typename Comp>
E heap<E, Comp>::removefirst() {
	//Assert(n > 0, "Heap is empty");
	swap(Heap, 0, --n); // Swap first with last value
	if (n != 0) siftdown(0); // Siftdown new root val
	return Heap[n]; // Return deleted value
}
// Remove and return element at specified position

template <typename E, typename Comp>
E heap<E,Comp>::remove(int pos) {
	//Assert((pos >= 0) && (pos < n), "Bad position");
	if (pos == (n - 1)) n--; // Last element, no work to do
	else
	{
		swap(Heap, pos, --n); // Swap with last value
		while ((pos != 0) &&
			(Comp::prior(Heap[pos], Heap[parent(pos)]))) {
			swap(Heap, pos, parent(pos)); // Push up large key
			pos = parent(pos);
		}
		if (n != 0) siftdown(pos); // Push down small key
	}
	heapwrite++;
	return Heap[n];
}

template <typename E, typename Comp>

int heap<E,Comp>:: getheapwrite()
{
	return heapwrite;
}

template <typename E, typename Comp>

int heap<E,Comp>::getheapread()
{
	return heapread;
}

/*template <typename E, typename Comp>

	bool Comp<E,Comp>::prior(int a, int b)
	{
		return (a > b);
	}
	*/