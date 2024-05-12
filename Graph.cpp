/**
 * Roi Sibony
 * roisi20041@gmail.com
*/
#include "Graph.hpp" // Include the header file
// bro says that if we can give refrence to something is optimize cause than we don't need to copy it 

namespace ariel {

// Constructor
Graph::Graph() : numOfEdges(0), numOfVertices(0), directed(false) {
    // Initialize vec with an empty vector
    vec = std::vector<std::vector<int>>();
}

// Load graph from a 2D vector
void Graph::loadGraph(const std::vector<std::vector<int>> &vec1) {
    //might won't work  cause we never intilized numOfVertices
    if (!vec1.empty() &&  vec1.size() != vec1[0].size()) { // means that this is not a square matrix
        
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix." );

        return;
    }
    vec = vec1;
    numOfVertices = vec1.size();
    numOfEdges = 0; // Reset numOfEdges before counting
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            if (vec[i][j] != 0) {
                numOfEdges++;
            }
        }
    }
    // check if it's exactly semtric if so then it's undirected
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            if (vec[i][j] != vec[j][i]) {
                directed = true;
                return;
            }
        }
    }
    numOfEdges /= 2; // Divide by 2 because the graph is undirected
}

// Print the graph
void Graph::printGraph() const{
    for (size_t i = 0; i < numOfVertices; ++i) {
        for (size_t j = 0; j < numOfVertices; ++j) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout<<"Graph with "<<numOfVertices<<" vertices and "<<numOfEdges<<" edges.\n";
}

// Get the number of vertices
size_t Graph::getVertices() const{
    return (size_t)numOfVertices;
}

// Get the number of edges
size_t Graph::getEdges()const {
    return (size_t)numOfEdges;
}

// Get the graph
std::vector<std::vector<int>> Graph::getGraph() const {
    return vec;
}
bool Graph::isDirected()const{
    return directed;
}
} // namespace ariel
