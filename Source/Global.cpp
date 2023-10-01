#include "Global.h"
int partition(Edge arr[], int start, int end) {
    int pivot = arr[start].getEdgeWeight();
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i].getEdgeWeight() <= pivot)
            count++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    SwapEdges(arr[pivotIndex], arr[start]);
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i].getEdgeWeight() <= pivot) {
            i++;
        }

        while (arr[j].getEdgeWeight()> pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            SwapEdges(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(Edge arr[], int start, int end) {
    // base case
    if (start >= end)
        return;
    // partitioning the array
    int p = partition(arr, start, end);
    // Sorting the left part
    quickSort(arr, start, p - 1);
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
void SwapEdges(Edge& a, Edge& b) {
    Edge temp;
    temp.setEdgeU(a.getEdgeU());
    temp.setEdgeV(a.getEdgeV());
    temp.setEdgeWeight(a.getEdgeWeight());
    a.setEdgeU(b.getEdgeU());
    a.setEdgeV(b.getEdgeV());
    a.setEdgeWeight(b.getEdgeWeight());
    b.setEdgeU(temp.getEdgeU());
    b.setEdgeV(temp.getEdgeV());
    b.setEdgeWeight(temp.getEdgeWeight());
}
Edge* getDatafrominputFile(string filename1,string filename2, int& VerticalsSize, int& EdgesSize, Edge &RemovedEdge) {
    string line, temp;
    Edge e;
    int count = 0;
    int cutFrom = 0;
    char c;
    int i, j, lineSize, CountCheck = 0;
    ifstream inputFile;
    inputFile.open(filename1);
    if (!inputFile) {
        cout << "Error! inputFile could not be open." << endl;
        exit(1);
    }
    ofstream outputFile;
    outputFile.open(filename2);
    if (!outputFile) {
        cout << "Error! outputFile could not be open." << endl;
        exit(1);
    }
    getline(inputFile, line);
    VerticalsSize = stoi(line);
    getline(inputFile, line);
    EdgesSize = stoi(line);
    while (getline(inputFile, line)) {
        CountCheck++;
    }
    if ((CountCheck - 1) != EdgesSize) {
        cout << "Invalid Input!" << endl;
        outputFile << "Invalid Input!" << endl;
        exit(1);
    }
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    for (i = 0; i < 2; i++) {
        getline(inputFile, line);
    }
    Edge* EdgesArr = new Edge[EdgesSize];
    for (i = 0; i < EdgesSize; i++) {
        getline(inputFile, line);
        lineSize = line.size();
        c = line[0];
        for (j = 0; j < 3; j++) {
            while ((c != ' ') && (c != '\0')) {
                count++;
                c = line[count];
            }
            temp = line.substr(cutFrom, count);
            cutFrom = count;
            if (j == 0) {
                e.setEdgeU(stoi(temp));
            }
            else if (j == 1) {
                e.setEdgeV(stoi(temp));
            }
            else if (j == 2) {
                e.setEdgeWeight(stoi(temp));
            }
            if (count != lineSize) {
                count++;
            }
            if (count == lineSize && j < 2) {
                cout << "Invalid Input!" << endl;
                outputFile << "Invalid Input!" << endl;
                exit(1);
            }
            c = line[count];
        }
        EdgesArr[i].setEdgeU(e.getEdgeU());
        EdgesArr[i].setEdgeV(e.getEdgeV());
        EdgesArr[i].setEdgeWeight(e.getEdgeWeight());
        count = 0;
        cutFrom = 0;
    }
    getline(inputFile, line);
    lineSize = line.size();
    c = line[0];
    for (j = 0; j < 2; j++) {
        while ((c != ' ') && (c != '\0')) {
            count++;
            c = line[count];
        }
        temp = line.substr(cutFrom, count);
        cutFrom = count;
        if (j == 0) {
            RemovedEdge.setEdgeU(stoi(temp));
        }
        else if (j == 1) {
            RemovedEdge.setEdgeV(stoi(temp));
        }
        if (count != lineSize) {
            count++;
        }
        c = line[count];
    }
        inputFile.close();
        outputFile.close();
        return EdgesArr;
}
void InputCheck(string filename2,Edge* EdgesArr, int NumofEdges, int NumofVerticals, Edge removedEdge) {
    bool flag = false;
    ofstream outputFile;
    outputFile.open(filename2);
    for (int i = 0; i < NumofEdges; i++)  {
        if ((EdgesArr[i].getEdgeU() > NumofVerticals) || (EdgesArr[i].getEdgeU() < 1) || (EdgesArr[i].getEdgeV() > NumofVerticals) || (EdgesArr[i].getEdgeV() < 1))
        {
            cout << "Invalid Input!" << endl;
            outputFile << "Invalid Input!" << endl;
            exit(1);
        }
    }
    for (int i = 0; i < NumofEdges; i++) {
        if ((EdgesArr[i].getEdgeU() == removedEdge.getEdgeU()) && (EdgesArr[i].getEdgeV() == removedEdge.getEdgeV())) {
            flag = true;
        }
    }
    if (!flag) {
        cout << "Invalid Input!" << endl;
        outputFile << "Invalid Input!" << endl;
        exit(1);
    }
    outputFile.close();
    return;
}
int findRemovedEdgePlace(Edge* EdgesArr, int NumofEdges, Edge RemovedEdge) {
    int j = 0;
    for (int i = 0; i < NumofEdges; i++) {
        if ((EdgesArr[i].getEdgeU() == RemovedEdge.getEdgeU()) && (EdgesArr[i].getEdgeV() == RemovedEdge.getEdgeV())) {
            j = i;
                break;
        }
    }
    return j;
}