#pragma once
#include "Graph.h"
void Graph::MakeEmptyGraph(int n) {
	TheGraph = new List[n + 1];
	GraphSize = n + 1;
	isVisited = new bool[GraphSize];
}
void Graph::InitilizeGraph(int VerticlesSize, Edge* EdgesArr, int EdgesArrSize) {
	for (int i = 0; i < (EdgesArrSize); i++) {
		TheGraph[EdgesArr[i].getEdgeU()].AddNodeToEnd(EdgesArr[i]);
		Edge reverseE;
		reverseE.setEdgeU(EdgesArr[i].getEdgeV());
		reverseE.setEdgeV(EdgesArr[i].getEdgeU());
		reverseE.setEdgeWeight(EdgesArr[i].getEdgeWeight());
		TheGraph[EdgesArr[i].getEdgeV()].AddNodeToEnd(reverseE);
	}
}
bool Graph::IsAdjacent(int u, int v) const {
	if (u > (GraphSize + 1) || u < 1) {
		cout << " Invalid Input!" << endl;
		exit(1);
	}
		return TheGraph[u].isOnTheList(v);
}
List Graph::GetAdjList(int u) {
	return TheGraph[u];
}
void Graph::AddEdge(int u, int v, int Weight) {
	Edge newEdge, reverseNewEdge;
	newEdge.setEdgeU(u);
	newEdge.setEdgeV(v);
	newEdge.setEdgeWeight(Weight);
	reverseNewEdge.setEdgeU(v);
	reverseNewEdge.setEdgeV(u);
	reverseNewEdge.setEdgeWeight(Weight);
	TheGraph[u].AddNodeToEnd(newEdge);
	TheGraph[v].AddNodeToEnd(reverseNewEdge);
}
void Graph::RemoveEdge(int u, int v) {
	TheGraph[u].deleteNode(v);
	TheGraph[v].deleteNode(u);
}
vector<Edge> Graph::KruskalAlgorithim(Edge* EdgesArr, int EdgesArrSize, bool isSorted) {
	vector<Edge> Res;
	int i, x, y;
	DisjointSets Sets(GraphSize);
	for (i = 0; i < GraphSize; i++) {
		Sets.MakeSet(i);
	}
	if (isSorted == false) {
		quickSort(EdgesArr, 0, EdgesArrSize - 1);
	}
	for (i = 0; i < EdgesArrSize; i++) {
		x = Sets.Find(EdgesArr[i].getEdgeU());
		y = Sets.Find(EdgesArr[i].getEdgeV());
		if (x != y) {
			Res.push_back(EdgesArr[i]);
			Sets.Union(x, y);
		}
	}
	Sets.deleteTree();
	return Res;
}
int* Graph::PrimAlgorithim(Edge* EdgesArr, int EdgesArrSize) {
	Heap Q; // Priority Queue to retreive the edge with minimum value to add to the tree
	int i, u;
	bool* InTree = new bool[GraphSize]; // boolean array to know if vertical x is in the tree
	int* parentsArr = new int[GraphSize]; // an array that tells for each vertical its parent 
	int* min = new int[GraphSize]; // an array that tells for each vertical the value of adding it to the Tree
	Element* elementArr = new Element[GraphSize]; 
	Node* temp;
	for (i = 0; i < GraphSize; i++) {
		elementArr[i].setMin(INT32_MAX);
		elementArr[i].setVertical(i);
		parentsArr[i] = UNINITIALIZED;
		min[i] = INT32_MAX;
		InTree[i] = false;
	}
	elementArr[1].setMin(0);
	Q.BuildHeap(elementArr, GraphSize - 1);
	while (!(Q.IsEmpty())) {
		u = Q.DeleteMin().getVertical();
		InTree[u] = true;
		temp = TheGraph[u].getHead();
		while (temp != nullptr) {
			if ((InTree[temp->getData().getEdgeV()] == false) && (temp->getData().getEdgeWeight()) < (min[temp->getData().getEdgeV()]))
			{
				min[temp->getData().getEdgeV()] = temp->getData().getEdgeWeight();
				parentsArr[temp->getData().getEdgeV()] = u;
				Q.DecreaseKey(min[temp->getData().getEdgeV()], temp->getData().getEdgeV());
			}
			temp = temp->getNext();
		}
	}
	return parentsArr;
}
void Graph::Visit(int u) {
	isVisited[u] = true;
	Node* temp;
	temp = TheGraph[u].getHead();
	while (temp != nullptr) {
		if (isVisited[temp->getData().getEdgeV()] == false)
		{
			Visit(temp->getData().getEdgeV());
		}
		temp = temp->getNext();
	}
}
void Graph::setIsVisitedToFalse()
{
	for (int i = 0; i < GraphSize; i++)	{
		isVisited[i] = false;
	}
}
bool Graph::isLinked() {
	Visit(1);
	for (int i = 1; i < GraphSize ; i++) {
		if (isVisited[i] == false)
		{
			return false;
		}
	}
	return true;
}
void Graph::DeleteGraphLists(List list) {
	Node* currentNode = list.getHead();
	while(currentNode != nullptr) {
		Node* nextNode = currentNode->getNext();
		delete currentNode;
		currentNode = nextNode;
	}
}
Graph::~Graph() {
	for (int i = 0; i < GraphSize; i++) {
		DeleteGraphLists(TheGraph[i]);
	}
	delete[] TheGraph;
	delete[] isVisited;
};


