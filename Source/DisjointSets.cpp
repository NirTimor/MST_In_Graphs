#pragma once
#include "DisjointSets.h"
DisjointSets::DisjointSets(int n) {
	Tree = new VerticalSet[n + 1]; 
	Size = n + 1;
	for (int i = 0; i < n + 1; i++)
	{
		Tree[i].Parent = UNINITIALIZED;
		Tree[i].Size = 0;
	}
}
void DisjointSets::MakeSet(int x) {
	Tree[x].Parent = x;
	Tree[x].Size = 1;
}
int DisjointSets::Find(int x) {
	if (Tree[x].Parent == x)
	{
		return x;
	}
	else
	{
		return (Tree[x].Parent = Find(Tree[x].Parent));
	}
}
void DisjointSets::Union(int x, int y) {
	if (Tree[x].Size > Tree[y].Size)
	{
		Tree[y].Parent = x;
		Tree[x].Size += Tree[y].Size;
	}
	else
	{
		Tree[x].Parent = y;
		Tree[y].Size += Tree[x].Size;
	}
}	
void DisjointSets::deleteTree() {
	//delete[] Tree;
}