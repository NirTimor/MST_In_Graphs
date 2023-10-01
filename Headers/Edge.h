#pragma once
#include <stdlib.h>
#include <iostream>
#define MAXSIZE 100
#define UNINITIALIZED -1
using namespace std;
class Edge {
private:
	int u = UNINITIALIZED;
	int v = UNINITIALIZED;
	int Weight = INT32_MAX;
public:
	int  getEdgeU() const { return this->u; }
	int  getEdgeV() const { return this->v; }
	int  getEdgeWeight() const { return this->Weight; }
	void setEdgeU(int newU) { this->u = newU; }
	void setEdgeV(int newV) { this->v = newV; }
	void setEdgeWeight(int newWeight) { this->Weight = newWeight; }
	bool operator==(const Edge& e) {
		if (this->getEdgeU() == e.u && this->getEdgeV() == e.v && this->getEdgeWeight() == e.Weight) {
			return true;
		}
		return false;
	}
	Edge& operator=(const Edge& e) {
		if (this != &e) {
			Edge res;
			res.setEdgeU(e.getEdgeU());
			res.setEdgeV(e.getEdgeV());
			res.setEdgeWeight(e.getEdgeWeight());
			return res;
		}
		return *this;
	}
};
