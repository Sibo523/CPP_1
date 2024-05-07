#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
namespace ariel{
class Graph{
    private:
        int numOfEdges;
        std::vector<std::vector<int>> vec;
        int numOfVertices;
        bool directed;
    public:
        Graph();
        void loadGraph(std::vector<std::vector<int>> vec1);
        void printGraph();
        size_t getVertices();
        size_t getEdges();
        std::vector<std::vector<int>> getGraph();
        bool isDirected();
};
}
#endif //GRAPH_H
