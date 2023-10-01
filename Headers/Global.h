// this Global.h includes all the functions that arent belongs to any class of the project 
#pragma once
#include "Edge.h"
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;
int partition(Edge arr[], int start, int end);
void quickSort(Edge arr[], int start, int end);
void SwapEdges(Edge& a, Edge& b); // swap two edges 
Edge* getDatafrominputFile(string filename1, string filename2, int& VerticalsSize, int& EdgesSize, Edge& RemovedEdge); // gets all the data from the input file 
void InputCheck(string filename2,Edge* EdgesArr, int NumofEdges, int NumofVerticals, Edge removedEdge); // some checks to see if the input is legal
int findRemovedEdgePlace(Edge* EdgesArr, int NumofEdges, Edge RemovedEdge); // returns the index of the removededge in the edges arr

