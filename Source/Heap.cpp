#include "Heap.h"
#include "iostream"
void Heap::Insert(Element e) {
	if (heapSize == MAXSIZE) {
		cout << "Invalid Input! Heap is FULL";
		exit(1);
	}
	else {
		int i = heapSize;
		heapSize++;
		while ((i > 0) && ((theHeap[Parent(i)]).getMin() > (e.getMin()))) // checks if my parent is smaller than item to insert.
		{
			theHeap[i].setMin(theHeap[Parent(i)].getMin());
			theHeap[i].setVertical(theHeap[Parent(i)].getVertical());
			i = Parent(i);
		}
		theHeap[i].setMin(e.getMin());
		theHeap[i].setVertical(e.getVertical());
	}
}
void Heap::SwapElements(Element& a, Element& b) { //Swap Elements
	Element newE;
	newE.setMin(a.getMin());
	newE.setVertical(a.getVertical());
	a.setMin(b.getMin());
	a.setVertical(b.getVertical());
	b.setMin(newE.getMin());
	b.setVertical(newE.getVertical());
}
void Heap::fixHeap(int node) {
	int min;
	int left = Left(node);
	int right = Right(node);
	if ((left < heapSize) && (theHeap[left].getMin()) < (theHeap[node].getMin()))
	{
		min = left;
	}
	else
	{
		min = node;
	}
	if ((right < heapSize) && (theHeap[right].getMin()) < (theHeap[min].getMin()))
	{
		min = right;
	}
	if (min != node)
	{
		SwapElements(theHeap[node], theHeap[min]);
		fixHeap(min);
	}
}
Element Heap::DeleteMin() {
	if (heapSize < 1) {
		cout << "Invalid Input! Heap is Empty.";
		exit(1);
	}
	else {
		Element min;
		min.setMin(theHeap[0].getMin());
		min.setVertical(theHeap[0].getVertical());
		heapSize--;
		theHeap[0].setMin(theHeap[heapSize].getMin());
		theHeap[0].setVertical(theHeap[heapSize].getVertical());
		fixHeap(0);
		return min;
		}
}
void Heap::BuildHeap(Element* arr, int Size) {
	theHeap = new Element[Size];
	int i;
	for (i = 0; i < Size; i++) {
		theHeap[i].setMin(arr[i+1].getMin());
		theHeap[i].setVertical(arr[i + 1].getVertical());
	}
	heapSize = Size;
}
void Heap::DecreaseKey(int newKey, int Place) {
	int i;
	for (i = 0; i < heapSize; i++) {
		if (theHeap[i].getVertical() == Place) 	{
			theHeap[i].setMin(newKey);
			while (i != 0 && theHeap[Parent(i)].getMin() > theHeap[i].getMin())
			{
				SwapElements(theHeap[i], theHeap[Parent(i)]);
				i = Parent(i);
			}
			return;
		}
	}
	cout << " Invalid Input! The key is not on the Heap .";
	exit(1);
}
