#include <queue>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Graph.h"
#define randomVertix 0
using namespace std;

int numberOfVertices = 6;
vector<vector<int>> matrix2((unsigned long) numberOfVertices);
vector<vector<int>> headermatrix((unsigned long) numberOfVertices);


bool read_file(string filename, bool adj){
    ifstream ip(filename);
    if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';
    char linec[10000];
    string line;
    size_t len = 1000;
    int A,B,C,D,E,F;
    int v = 0;
    char roomname[100];
    while (ip.good()){
        getline(ip, line);
        strcpy(linec, line.c_str());
        cout<<line<<endl;
        sscanf(linec, "%[^,],%d,%d ,%d ,%d ,%d ,%d", roomname,
           &A, &B, &C, &D, &E, &F);
        cout <<roomname<<endl;
        if (adj){
        matrix2.at((unsigned long) v).push_back(A);
        matrix2.at((unsigned long) v).push_back(B);
        matrix2.at((unsigned long) v).push_back(C);
        matrix2.at((unsigned long) v).push_back(D);
        matrix2.at((unsigned long) v).push_back(E);
        matrix2.at((unsigned long) v).push_back(F);
        }
        
        v++;
    }
    cout << "parsed matrix: \n";
    for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = 0; j < numberOfVertices; ++j) {
            cout << matrix2[i][j]<<" ";
        }
        cout <<endl;
    }
    
}



int main() {
    unsigned long src;
    read_file("graphcopy.csv", true);
    //read_file("headings.csv", false);
    int sum=0;
    int x; 
    cout<<"------------------------Dijkstra Algorithm Test--------------------"<<endl;
    Graph graph2(numberOfVertices,matrix2);
    cout<<"Enter the source vertex's index"<<endl;
    cin>>src;
    cout<<"------------------------Dijkstra Algorithm Results--------------------"<<endl;
    graph2.dijkstraAlgorithm(graph2.getVertices().at(src));
    return 0;
}