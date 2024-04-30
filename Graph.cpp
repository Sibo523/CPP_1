#include "Graph.hpp" // Include the header file

namespace ariel {

// Constructor
Graph::Graph() : numOfEdges(0), numOfVertices(0) {
    // Initialize vec with an empty vector
    vec = std::vector<std::vector<int>>();
}

// Load graph from a 2D vector
void Graph::loadGraph(std::vector<std::vector<int>> vec1) {
    //might won't work  cause we never intilized numOfVertices
    if (!vec1.empty() &&  vec1.size() != vec1[0].size()) { // means that this is not a square matrix
        std::cout << "Invalid graph: The graph is not a square matrix." << std::endl;
        return;
    }
    vec = vec1;
    numOfVertices = vec1.size();
    numOfEdges = 0; // Reset numOfEdges before counting
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            if (vec[i][j] == 1) {
                numOfEdges++;
            }
        }
    }
}

// Print the graph
void Graph::printGraph() {
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Get the number of vertices
size_t Graph::getVertices() {
    return (size_t)numOfVertices;
}

// Get the number of edges
size_t Graph::getEdges() {
    return (size_t)numOfEdges;
}

// Get the graph
std::vector<std::vector<int>> Graph::getGraph() {
    return vec;
}

} // namespace ariel
