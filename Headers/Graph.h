#pragma once
#include "Edge.h"
#include "Heap.h"
#include "List.h"
#include <vector>
#include "DisjointSets.h"
#include <stdbool.h>
class Graph {
private:
	List* TheGraph;
	int GraphSize = UNINITIALIZED;
	bool* isVisited;
public:
	int getGraphSize() const { return this->GraphSize; }
	void InitilizeGraph(int VerticlesSize, Edge* EdgesArr, int EdgesArrSize);
	List* getTheGraph() const { return this->TheGraph; }
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v) const;
	List  GetAdjList(int u) ;
	void AddEdge(int u, int v, int Weight);
	void RemoveEdge(int u, int v);
	vector<Edge> KruskalAlgorithim(Edge* EdgesArr, int EdgesArrSize, bool isSorted);
	int* PrimAlgorithim(Edge* EdgesArr, int EdgesArrSize);
	void Visit(int u);
	bool isLinked();
	void setIsVisitedToFalse();
	void DeleteGraphLists(List list);
	~Graph();
};

