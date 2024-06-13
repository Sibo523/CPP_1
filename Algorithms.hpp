/**
 * Roi Sibony
 * roisi20041@gmail.com
*/
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include "Graph.hpp"

namespace ariel {
    class Algorithms {
        public:
            //I assumed connected graph could looks like this:
            // v1->v2;
            // v3->v2;
            static int isConnected(Graph g);

            //dfs to check if there's a cycle
            static bool isContainsCycle(const Graph &g);
            //belman ford, if there's negative cycle in the whole graph will say there's a neg cycle
            //though if I want to still find the shortest path I can run belman 
            //2n times instead of n times and then check if the end point got updated if not
            //just return the shortest path from the end to the start.
            static std::string shortestPath(const Graph &g, size_t des, size_t src);
            
            //just bfs
            static std::string isBipartite(const Graph &g);

            //if I wanted to return the actual cycle I would run a while loop on the parents of the current node 
            //who just got updated and is part of the cycle not needed so I didn't implement it
            static bool negativeCycle(const Graph &g); 
             private:
            //dfs helper is a chuncky boy
            static bool dfsCycleHelper(const Graph &g, std::vector<bool> &visited, std::vector<bool> &recStack, size_t vertex, size_t parent, std::string &result);
            static void dfs(const Graph &g, std::vector<bool> &visited, size_t vertex);
            static void makeSymmetric(Graph &g);
            static bool isSameColor(const Graph &g, std::vector<int> &colorArr, size_t u, size_t v);
            static bool isSelfLoop(const Graph &g, size_t u);
            static bool isNotColored(const Graph &g, std::vector<int> &colorArr, size_t u, size_t v);
            static std::string BelmanFord(const Graph &g, size_t srcm, size_t des);

    };
}

#endif //end of hpp
