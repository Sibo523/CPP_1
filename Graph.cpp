#include <iostream>
#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;
    int numVertices;
    int numEdges;

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices), numEdges(0) {
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    // Load graph from a 2D vector
    void loadGraph(const std::vector<std::vector<int>>& vec) {
        if (vec.size() != numVertices || vec[0].size() != numVertices) {
            std::cout << "Error: The input matrix does not match the number of vertices." << std::endl;
            return;
        }
        adjMatrix = vec;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] == 1) {
                    numEdges++;
                }
            }
        }
    }

    // Print the graph
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Get the number of vertices
    int getVertices() {
        return numVertices;
    }

    // Get the number of edges
    int getEdges() {
        return numEdges;
    }

    // Get the graph
    std::vector<std::vector<int>> getGraph() {
        return adjMatrix;
    }
};