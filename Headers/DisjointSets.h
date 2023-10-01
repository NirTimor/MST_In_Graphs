#pragma once
#include "Edge.h"
typedef struct {
	int Parent;
	int Size;
}
VerticalSet;
class DisjointSets {
private:
	VerticalSet* Tree;
	int Size;
public:
	DisjointSets(int n);
	void MakeSet(int x);
	int Find(int x);
	void Union(int x, int y);
	void deleteTree();
};
