#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include "Graph.hpp"

namespace ariel {
    class Algorithms {
        public:
            static int isConnected(Graph g);
            static bool isContainsCycle(const Graph &g);
            static std::string shortestPath(Graph g, size_t des, size_t src);
            static std::string isBipartite(Graph g);
            static bool negativeCycle(Graph g); 
        private:
            //dfs helper is a chuncky boy
            static bool dfsCycleHelper(const Graph &g, std::vector<bool> &visited, std::vector<int> &recStack, size_t vertex, size_t parent, std::string &result);
            static void dfs(const Graph &g, std::vector<bool> &visited, size_t vertex);
            static void makeSymmetric(Graph &g);
            static std::string BelmanFord(const Graph &g, size_t srcm, size_t des);

    };
}

#endif //end of hpp
