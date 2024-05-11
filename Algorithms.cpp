#include "Algorithms.hpp"
#include <climits>
#include <queue>

namespace ariel
{

    // Function to check if a graph is connected (uses DFS)
    /**
     * need to fix this!!!!!!!!!!!!!!!!!!!!!!!!!!!! might not work
     */
    void Algorithms::dfs(const Graph &g, std::vector<bool> &visited, size_t vertex)
    {
        visited[vertex] = true; // Mark current vertex as visited

        // Recursively visit all unvisited neighbors
        for (size_t neighbor = 0; neighbor < g.getVertices(); ++neighbor)
        {
            if (g.getGraph()[vertex][neighbor] != 0 && !visited[neighbor])
            {
                dfs(g, visited, neighbor);
            }
        }
    }
    void Algorithms::makeSymmetric(Graph &g)
    {
        for (size_t i = 0; i < g.getVertices(); ++i)
        {
            for (size_t j = 0; j < g.getVertices(); ++j)
            {
                if (g.getGraph()[i][j] != g.getGraph()[j][i])
                {
                    g.getGraph()[i][j] = g.getGraph()[j][i] = 1;
                }
            }
        }
    }

    int Algorithms::isConnected(Graph g)
    {
        size_t V = g.getVertices(); // amount of vertirces 
        if (V == 0) {
            return false;
        }
        
        // 1. Create a visited vector to keep track of visited nodes
        std::vector<bool> visited((size_t)g.getVertices(), false);

        // 2. Choose any starting vertex (here we choose the first vertex just because)
        size_t start = 0;

        // 3. Perform DFS traversal starting from the chosen vertex
        // we will see that g is sent by value
        makeSymmetric(g);       // now we have symmetring graph so when we will do dfs if the graph is connected we will get to everyone else not
        dfs(g, visited, start); // we will dfs, if we can reach all the vertices then the graph is connected

        // 4. Check if all vertices are marked visited
        for (size_t i = 0; i < visited.size(); i++)
        {
            if (visited[i] == false) // if one of them is false then the graph is not connected
            {
                std::cout << "false ";
                return 0;
            }
        }

        // 5. If all vertices are visited, the graph is connected
        std::cout << "true ";
        return 1;
    }
    bool Algorithms::dfsCycleHelper(const Graph &g, std::vector<bool> &visited, std::vector<int> &recStack, size_t vertex, size_t parent, std::string &result)
    {
        // std::cout << "Visiting vertex: " << vertex << std::endl;
        visited[vertex] = true;
        recStack[vertex] = true;

        for (size_t neighbor = 0; neighbor < g.getVertices(); neighbor++)
        {
            if (!g.isDirected() && parent == neighbor)
            {
                // std::cout << "Skipping parent in undirected graph: " << neighbor << std::endl;
                continue;
            }

            if (g.getGraph()[vertex][neighbor] != 0 && !visited[neighbor])
            {
                // std::cout << "Recursing to neighbor: " << neighbor << std::endl;
                if (dfsCycleHelper(g, visited, recStack, neighbor, vertex,result))
                {
                    // std::cout<<vertex;
                    result +=  " <- " + std::to_string(vertex) ;
                    return true;
                }
            }
            else if (neighbor != vertex && recStack[neighbor] && g.getGraph()[vertex][neighbor] != 0) // if the neighbor is not the parent and is in the recStack
            {
                if (g.isDirected() || (!g.isDirected() && parent != neighbor)) // can't complete cycle with my parent if I am undirected
                { // if it's directed or if it's undirected and the neighbor is not the parent

                    result += std::to_string(neighbor) + + " <- " +std::to_string(vertex)  ;
                    return true;
                }
            }
        }
        recStack[vertex] = false;
        // std::cout << "Backtracking from vertex: " << vertex << std::endl; // used for debugging
        return false;
    }

    bool Algorithms::isContainsCycle(const Graph &g)
    {
        // 1. Create a visited vector to keep track of visited nodes
        std::vector<bool> visited(g.getVertices(), false);
        std::string result = "";
        // 2. Create a recStack vector to keep track of nodes in the current recursion path

        // 3. Iterate through all vertices
        for (size_t vertex = 0; vertex < g.getVertices(); ++vertex)
        {
            // 4. If the vertex is not visited, call DFS helper function
            if (!visited[vertex])
            {
                std::vector<int> recStack(g.getVertices(), false);
                if (dfsCycleHelper(g, visited, recStack, vertex, (size_t)-1, result))
                {
                    std::cout << result<<"\n"; // print the cycle
                    return true; // Cycle found found a back edge
                }
            }
        }
        // 5. If no cycle found after iterating through all vertices, return false
        // std::cout << "false doesn't contain cycle";
        return false;
    }

    std::string Algorithms::BelmanFord(const Graph &g, size_t src, size_t des)
    {
        size_t V = g.getVertices(); // amount of vertirces 
        if (V == 0) {
            return "Empty graph";
        }
        
        // 1. Create a vector to store the shortest distances from the source vertex
        std::vector<int> dist(g.getVertices(), INT_MAX);
        std::vector<int> parent(g.getVertices(), -1);
        // 2. Set the distance of the source vertex to itself as 0
        dist[src] = 0;

        // 3. Relax edges repeatedly to find the shortest path
        for (size_t i = 0; i < g.getVertices() - 1; ++i)
        {
            // Iterate through all edges and update the distance if a shorter path is found
            for (size_t u = 0; u < g.getVertices(); ++u)
            {
                for (size_t v = 0; v < g.getVertices(); ++v)
                {
                    if (g.getGraph()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getGraph()[u][v] < dist[v])
                    {
                        parent[v] = u;
                        dist[v] = dist[u] + g.getGraph()[u][v];
                    }
                }
            }
        }

        // 4. Check for negative weight cycles
        for (size_t u = 0; u < g.getVertices(); ++u)
        {
            for (size_t v = 0; v < g.getVertices(); ++v)
            {
                if (g.getGraph()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getGraph()[u][v] < dist[v])
                {
                    return "Graph contains negative weight cycle";
                }
            }
        }

        // 5. Return the shortest path from the source vertex to all other vertices
        // std::string result = "Shortest path from vertex " + std::to_string(src) + "to vertex "+std::to_string(des)+std::to_string(dist[des])+"\n";
        std::string result = "";
        if (dist[des] == INT_MAX)
        {
            return "-1";
        }
        while (des != src)
        {
            result += std::to_string(des) + "->";
            des = (size_t)parent[des];
        }

        return result + std::to_string(src);
    }
    // need to fix indents 
    // Function to find the shortest path between two vertices (Dijkstra's algorithm)
    std::string Algorithms::shortestPath(Graph g, size_t des, size_t src)
    {
        return BelmanFord(g, src, des);
    }

    // Function to check if a graph is bipartite (uses BFS)
    std::string Algorithms::isBipartite(Graph g)
    {
        size_t V = g.getVertices(); // amount of vertirces 
        if (V == 0) {
            return "The graph is bipartite: A={}, B={}";
        }
        // Create a color array to store colors assigned to vertices.
        // Initialize all vertices as not colored (-1).
        std::vector<int> colorArr(V, -1);

        // Process all vertices one by one
        for (size_t i = 0; i < V; i++)
        {
            // If vertex is not colored, apply BFS on it.
            if (colorArr[i] == -1)
            {
                std::queue<size_t> q;
                q.push(i);
                colorArr[i] = 1; // Color first vertex as 1.

                // Run while there are vertices in queue
                while (!q.empty())
                {
                    size_t u = q.front(); // sad that I can't pop into u :(
                    q.pop();

                    // Return false if there is a self-loop
                    if (g.getGraph()[u][u] != 0) {
                        return "0";
                    }
                    // Find all non-colored adjacent vertices
                    for (size_t v = 0; v < V; ++v)
                    {
                        // An edge from u to v exists and destination v is not colored
                        if (g.getGraph()[u][v] != 0 && colorArr[v] == -1)
                        {
                            // Assign alternate color to this adjacent v of u
                            colorArr[v] = 1 - colorArr[u];
                            q.push(v);
                        }

                        // An edge from u to v exists and destination v is colored with same color as u
                        else if (g.getGraph()[u][v] !=0 && colorArr[v] == colorArr[u])
                        {
                            return "0";
                        }
                         
                    }
                }
            }
        }
        // this is A
        std::string result= "The graph is bipartite: ";
        result += "A={";
        for (size_t i = 0; i < V; i++)
        {
            if (colorArr[i] == 0)
            {
                result += std::to_string(i) + " ";
            }
        }
        // this is B
        result += "}, B={";
        for (size_t i = 0; i < V; i++)
        {
            if (colorArr[i] == 1)
            {
                result += std::to_string(i) + " ";
            }
        }
        result += "}";
        // If we reach here, then all vertices can be colored with alternate color
        return result;
    }

    // Function to check for a negative cycle in a weighted graph (Bellman-Ford)
    bool Algorithms::negativeCycle(Graph g)
    {

        return BelmanFord(g, 0, 0) == "Graph contains negative weight cycle";
    }

} // namespace ariel
