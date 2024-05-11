### Personal Details
- *ID:* 214662439
- *Name:* Roi Sibony
- *Email:* roisi20041@gmail.com
# Algorithms

This header file defines the `Algorithms` class within the `ariel` namespace, providing a collection of static methods for graph-related operations. The class is designed to work with the `Graph` class, which should be defined elsewhere in your project. The `Algorithms` class offers functionalities such as checking if a graph is connected, detecting cycles, finding the shortest path between nodes, determining if a graph is bipartite, and identifying negative cycles.

## Public Methods

### `isConnected(Graph g)`

- **Description**: Checks if the given graph `g` is connected. used dfs and asures that you got to all vertices
- **Return Type**: `int`
- **Parameters**: A reference to a `Graph` object `g`.
- **Usage**: To determine if all nodes in the graph are reachable from each other.

### `isContainsCycle(const Graph &g)`

- **Description**: Determines if the graph `g` contains a cycle. uses dfs helper
- **Return Type**: `bool`
- **Parameters**: A constant reference to a `Graph` object `g`.
- **Usage**: To check for the presence of a cycle in the graph.

### `shortestPath(Graph g, size_t des, size_t src)`

- **Description**: Finds the shortest path between the source node `src` and the destination node `des` in the graph `g`.will always return false if you give it undirected graph with negative weights.
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

# Ariel Graph Header File

This header file defines the `Graph` class within the `ariel` namespace, providing a flexible and efficient way to represent and manipulate graphs. The `Graph` class supports both directed and undirected graphs, allowing for a wide range of graph-based applications.

## Class Overview

The `Graph` class encapsulates the structure and operations of a graph. It includes methods for loading graph data, printing the graph, retrieving the number of vertices and edges, accessing the graph's adjacency matrix, and checking if the graph is directed.

## Class Members

### `Public methods`

- `numOfEdges`: Stores the number of edges in the graph.
- `vec`: A 2D vector representing the adjacency matrix of the graph.
- `numOfVertices`: Stores the number of vertices in the graph.
- `directed`: A boolean flag indicating whether the graph is directed.


### `Public members`

- `Graph()`: Default constructor initializes an empty graph.
- `loadGraph(const std::vector<std::vector<int>> vec1)`: Loads the graph from a 2D vector representation.
- `printGraph() const`: Prints the graph to the console.
- `getVertices() const`: Returns the number of vertices in the graph.
- `getEdges() const`: Returns the number of edges in the graph.
- `getGraph() const`: Returns the graph's adjacency matrix.
- `isDirected() const`: Returns whether the graph is directed.

## Usage

To use the `Graph` class, you need to include the header file in your source code and create instances of the `Graph` class. Here's a simple example demonstrating how to create a graph, add edges, and print it:

// Adding edges to the graph
graph.loadGraph({{0, 1}, {1, 2}, {2, 3}, {3, 0}}); // Creates a directed graph with 4 vertices and 4 edges
// Printing the graph
graph.printGraph();
return 0;



This example demonstrates creating a directed graph with 4 vertices and 4 edges, then printing the graph to the console. The `loadGraph` method is used to populate the graph with edges, and `printGraph` displays the graph's structure.

The `Graph` class provides a solid foundation for graph-based algorithms and data structures, making it easy to implement complex graph operations and algorithms.

### `I used phind in order to create this readme`
 

