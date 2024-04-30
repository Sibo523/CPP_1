#include "Algorithms.hpp"

namespace ariel
{

    // Function to check if a graph is connected (uses DFS)
    /**
     * need to fix this!!!!!!!!!!!!!!!!!!!!!!!!!!!! might not work
     */
    void Algorithms::dfs(Graph g, std::vector<bool> &visited, size_t vertex)
    {
        visited[vertex] = true; // Mark current vertex as visited

        // Recursively visit all unvisited neighbors
        for (size_t neighbor = 0; neighbor < g.getVertices(); ++neighbor)
        {
            if (g.getGraph()[vertex][neighbor] == 1 && !visited[neighbor])
            {
                dfs(g, visited, neighbor);
            }
        }
    }

    int Algorithms::isConnected(Graph g)
    {
        // 1. Create a visited vector to keep track of visited nodes
        std::vector<bool> visited((size_t)g.getVertices(), false);

        // 2. Choose any starting vertex (here we choose the first vertex)
        size_t start = 0;

        // 3. Perform DFS traversal starting from the chosen vertex
        dfs(g, visited, start);

        // 4. Check if all vertices are marked visited
        for (bool isVisited : visited)
        {
            if (!isVisited)
            {
                return 0; // Not connected if some vertex is false
            }
        }

        // 5. If all vertices are visited, the graph is connected
        std::cout<<"true"<<std::endl;
        return 1;
    }
    // Function to check if a graph contains a cycle (uses DFS)
    // bool Algorithms::isContainsCycle(Graph g)
    // {
    //     // Implement Depth-First Search (DFS) with cycle detection
    //     // Check if a back edge is encountered during traversal
    //     // Return true if a cycle exists, false otherwise
    //     // (Implementation details omitted for brevity)
    // }

    bool Algorithms::isContainsCycle(Graph g)
    {
        // 1. Create a visited vector to keep track of visited nodes
        std::vector<bool> visited(g.getVertices(), false);
        // 2. Create a recStack vector to keep track of nodes in the current recursion path
        std::vector<bool> recStack(g.getVertices(), false);

        // 3. Iterate through all vertices
        for (size_t vertex = 0; vertex < g.getVertices(); ++vertex)
        {
            // 4. If the vertex is not visited, call DFS helper function
            if (!visited[vertex])
            {
                if (dfsCycleHelper(g, visited, recStack, vertex))
                {
                    return true; // Cycle found found a back edge
                }
            }
        }
        // 5. If no cycle found after iterating through all vertices, return false
        return false;
    }

    // Helper function for cycle detection in DFS traversal
    bool Algorithms::dfsCycleHelper(Graph g, std::vector<bool> &visited, std::vector<bool> &recStack, size_t vertex)
    {
        // Mark current vertex as visited and in recursion stack
        visited[vertex] = true;
        recStack[vertex] = true;

        // Iterate through all neighbors of the current vertex
        for (size_t neighbor = 0; neighbor < g.getVertices(); ++neighbor)
        {
            // If there's an edge to an unvisited neighbor, go to it 
            if (g.getGraph()[vertex][neighbor] == 1 && !visited[neighbor])
            {
                if (dfsCycleHelper(g, visited, recStack, neighbor))
                {
                    return true; // Cycle found in recursive exploration
                }
            }
            else if (recStack[neighbor])
            { // Back edge detected (cycle)
                return true;
            }
        }

        // Unset recursion stack flag for the current vertex (backtracking)
        recStack[vertex] = false;

        // No cycle found in this branch of DFS, return false
        return false;
    }
    // Function to find the shortest path between two vertices (Dijkstra's algorithm)
    std::string Algorithms::shortestPath(Graph g, int des, int src)
    {

        return " ";
    }

    // Function to check if a graph is bipartite (uses BFS)
    std::string Algorithms::isBipartite(Graph g)
    {
        // Implement Breadth-First Search (BFS) with bipartite coloring
        // Check if any adjacent nodes have the same color
        // Return "Yes" if bipartite, "No" otherwise (or an error message)
        // (Implementation details omitted for brevity)
        return " ";
    }

    // Function to check for a negative cycle in a weighted graph (Bellman-Ford)
    bool Algorithms::negativeCycle(Graph g)
    {
        // Implement Bellman-Ford algorithm to detect negative weight cycles
        // Return true if a negative cycle exists, false otherwise
        // (Implementation details omitted for brevity)
        return true;
    }

    // Helper function for isPath (recursive DFS)
    bool Algorithms::isPathHelp(std::vector<std::vector<int>> edges, unsigned long src, int des, std::vector<bool> visited)
    {
        // Mark current node as visited
        visited[src] = true;

        // Check if current node is the destination
        if (src == des)
        {
            return true;
        }

        // // Recur for all neighbors if not visited
        // for (unsigned long neighbor : edges[src])
        // {
        //     if (!visited[neighbor])
        //     {
        //         if (isPathHelp(edges, neighbor, des, visited))
        //         {
        //             return true;
        //         }
        //     }
        // }

        // Return false if no path is found from current vertex
        return false;
    }

    // Function to check if a path exists between two vertices in a graph
    bool Algorithms::isPath(std::vector<std::vector<int>> edges, unsigned long src, int des)
    {
        // Create a visited vector to keep track of visited nodes
        std::vector<bool> visited(edges.size(), false);

        // Call the helper function to perform DFS traversal
        return isPathHelp(edges, src, des, visited);
    }

} // namespace ariel
