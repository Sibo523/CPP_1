# Ariel Algorithms Header File

This header file defines the `Algorithms` class within the `ariel` namespace, providing a collection of static methods for graph-related operations. The class is designed to work with the `Graph` class, which should be defined elsewhere in your project. The `Algorithms` class offers functionalities such as checking if a graph is connected, detecting cycles, finding the shortest path between nodes, determining if a graph is bipartite, and identifying negative cycles.

## Public Methods

### `isConnected(Graph g)`

- **Description**: Checks if the given graph `g` is connected.
- **Return Type**: `int`
- **Parameters**: A reference to a `Graph` object `g`.
- **Usage**: To determine if all nodes in the graph are reachable from each other.

### `isContainsCycle(const Graph &g)`

- **Description**: Determines if the graph `g` contains a cycle.
- **Return Type**: `bool`
- **Parameters**: A constant reference to a `Graph` object `g`.
- **Usage**: To check for the presence of a cycle in the graph.

### `shortestPath(Graph g, size_t des, size_t src)`

- **Description**: Finds the shortest path between the source node `src` and the destination node `des` in the graph `g`.
- **Return Type**: `std::string`
- **Parameters**: A `Graph` object `g`, and two `size_t` values representing the source and destination nodes.
- **Usage**: To find the shortest path between two nodes in the graph.

### `isBipartite(Graph g)`

- **Description**: Checks if the graph `g` is bipartite.
- **Return Type**: `std::string`
- **Parameters**: A `Graph` object `g`.
- **Usage**: To determine if the graph can be divided into two disjoint sets where every edge connects a node in one set to a node in the other set.

### `negativeCycle(Graph g)`

- **Description**: Identifies if the graph `g` contains a negative cycle.
- **Return Type**: `bool`
- **Parameters**: A `Graph` object `g`.
- **Usage**: To detect the presence of a negative cycle in the graph.

## Private Methods

### `dfsCycleHelper(const Graph &g, std::vector<bool> &visited, std::vector<int> &recStack, size_t vertex, size_t parent, std::string &result)`

- **Description**: Helper method for depth-first search (DFS) to detect cycles.
- **Return Type**: `bool`
- **Parameters**: A constant reference to a `Graph` object `g`, vectors for visited nodes and recursion stack, a vertex, a parent vertex, and a result string.
- **Usage**: Internally used by `isContainsCycle` to perform DFS and detect cycles.

### `dfs(const Graph &g, std::vector<bool> &visited, size_t vertex)`

- **Description**: Depth-first search traversal of the graph `g`.
- **Return Type**: `void`
- **Parameters**: A constant reference to a `Graph` object `g`, a vector for visited nodes, and a vertex.
- **Usage**: Used internally for various graph traversal needs.

### `makeSymmetric(Graph &g)`

- **Description**: Makes the graph `g` symmetric by adding missing edges.
- **Return Type**: `void`
- **Parameters**: A reference to a `Graph` object `g`.
- **Usage**: Ensures that the graph is fully connected by adding any missing edges.

### `BelmanFord(const Graph &g, size_t srcm, size_t des)`

- **Description**: Implements the Bellman-Ford algorithm to find the shortest path between `srcm` and `des` in the graph `g`.
- **Return Type**: `std::string`
- **Parameters**: A constant reference to a `Graph` object `g`, and two `size_t` values representing the source and destination nodes.
- **Usage**: To find the shortest path between two nodes using the Bellman-Ford algorithm.
