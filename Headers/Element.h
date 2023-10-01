#pragma once
//class of Element which has 2 integers to manage the Heap correctly by Min
class Element {
private:
	int Min;
	int Vertical;
public:
	int getMin() const { return this->Min; }
	int getVertical() const { return this->Vertical; }
	void setMin(int x) { this->Min = x; }
	void setVertical(int x) { this->Vertical = x; }
	Element& operator=(const Element& e) {
		if (this != &e) {
			Element res;
			res.Min = e.Min;
			res.Vertical = e.Vertical;
			return res;
		}
		return *this;
	}
};