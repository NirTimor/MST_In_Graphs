#pragma once
#include "Global.h"
#include "Edge.h"
#include "Element.h"
class Heap {
private:
	Element* theHeap;
	int maxSize = MAXSIZE;
	int heapSize = 0;
	static int Left(int node)  { return (2 * node + 1); }
	static int Right(int node)  { return (2 * node + 2); }
	static int Parent(int node) { return (node - 1) / 2; }
	void fixHeap(int node);
public:
	void BuildHeap(Element* arr, int Size);
	bool IsEmpty() { return heapSize == 1; }
	int  getHeapSize() const { return heapSize; }
	Element Min() const { return theHeap[0]; }
	Element DeleteMin();
	void Insert(Element e);
	void DecreaseKey(int newKey, int Place);
	void SwapElements(Element &a, Element &b);
	~Heap() { delete[] theHeap; }
};

