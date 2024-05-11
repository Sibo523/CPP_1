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
        void loadGraph(const std::vector<std::vector<int>> vec1);
        void printGraph() const;
        size_t getVertices() const;
        size_t getEdges() const;
        std::vector<std::vector<int>> getGraph() const;
        bool isDirected() const;
};
}
#endif //GRAPH_H
