#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Graph.h"
using namespace std;
int main(int argc, char* argv[]) {
	string fileName1(argv[1]);
	string fileName2(argv[2]);
	Graph G;
	int NumofVerticals, NumofEdges, i, FirstKruskalCount = 0, PrimCount = 0, SecondKruskalCount = 0, removedEdgePlace = 0;
	Edge RemovedEdge;
	Edge* EdgesArr;
	bool isLinkedAfterRemove;
	Node* temp;
	ofstream outputFile;
	vector<Edge> FirstKruskalVec;
	vector<Edge> SecondKruskalVec;
	outputFile.open(fileName2);
	if (!outputFile) {
		cout << "Error! output file could not be opened." << endl;
		exit(1);
	}
	EdgesArr = getDatafrominputFile(fileName1, fileName2, NumofVerticals, NumofEdges, RemovedEdge);
	int* pArr = new int[NumofVerticals + 1];
	InputCheck(fileName2,EdgesArr, NumofEdges, NumofVerticals, RemovedEdge);
	G.MakeEmptyGraph(NumofVerticals);
	G.InitilizeGraph(NumofVerticals, EdgesArr, NumofEdges);
	if (G.isLinked() == false) {
		cout << "No MST ! " << endl;
		outputFile << "No MST ! " << endl;
		exit(1);
	}
	G.setIsVisitedToFalse();
	FirstKruskalVec = G.KruskalAlgorithim(EdgesArr, NumofEdges, false);
	for (auto& l : FirstKruskalVec) {
		FirstKruskalCount += l.getEdgeWeight();
	}
	pArr = G.PrimAlgorithim(EdgesArr, NumofEdges);
	for (i = 1; i < G.getGraphSize(); i++) {
		temp = (G.getTheGraph())[i].getHead();
		while (temp != nullptr) {
			if (temp->getData().getEdgeV() == pArr[i]) {
				PrimCount += temp->getData().getEdgeWeight();
			}
			temp = temp->getNext();
		}
	}
	G.RemoveEdge(RemovedEdge.getEdgeU(), RemovedEdge.getEdgeV());
	if (G.isLinked() == false) {
		isLinkedAfterRemove = false;
	}
	else {
		isLinkedAfterRemove = true;
		removedEdgePlace = findRemovedEdgePlace(EdgesArr, NumofEdges, RemovedEdge);
		for (int j = removedEdgePlace; j < NumofEdges; j++) {
			SwapEdges(EdgesArr[j], EdgesArr[j + 1]);
		 }
		SecondKruskalVec = G.KruskalAlgorithim(EdgesArr, NumofEdges - 1, true);
		for (auto& k : SecondKruskalVec) {
			SecondKruskalCount += k.getEdgeWeight();
			}
		}
	cout << "Kruskal " << FirstKruskalCount << endl;
	cout << "Prim " << PrimCount << endl;
	outputFile << "Kruskal " << FirstKruskalCount << endl;
	outputFile << "Prim " << PrimCount << endl;
	if (isLinkedAfterRemove == true) {
	cout << "Kruskal2 " << SecondKruskalCount << endl;
	outputFile << "Kruskal2 " << SecondKruskalCount << endl;

	}
	else {
	cout << "Kruskal2 No MST" << endl;
	outputFile << "Kruskal2 No MST" << endl;
	}
	outputFile.close();
	delete[] pArr;
	return 0;
}
