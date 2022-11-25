#ifndef GRAPHALGORITHMS_GRAPH_H
#define GRAPHALGORITHMS_GRAPH_H
#include <vector>
#include <unordered_map>
#include "GraphNode.h"
#include "GraphEdge.h"
using namespace std;
//Un-implemented yet AdjacencyList Representation. Need to build conversion to the underlying Edge representation.
typedef unordered_map<GraphNode* ,vector<GraphEdge*>> AdjacencyList;
//Implemented Conversion from AdjacencyMatrix required representation to the underlying Edge Representation.
typedef vector<vector<int>> AdjacencyMatrix;
typedef std::vector < std::vector<int> > tAdjacencyMatrix;
class Graph {
    AdjacencyMatrix adjacencyMatrix;
    tAdjacencyMatrix adj;
    int numberOfVertices;
    
    vector<GraphEdge*> edges;
    vector<GraphNode*> vertices;
public:

    virtual ~Graph();
    Graph(int numberOfVertices);
    vector<string> splitString(const string &s, char delimiter);
    bool read_file();
    void addEdge(int i, int j, int value);
    bool isEdge(int i, int j);
    string toString() const;
    
private:
    void printParents(int index,int sourceIndex,int *parentVertices);
    // To compare two edges
    class myComparator
    {
    public:
        int operator() (GraphEdge& edge1, GraphEdge& edge2);

    };
};
#endif //GRAPHALGORITHMS_GRAPH_H
