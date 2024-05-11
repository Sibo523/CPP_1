#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test empty graph") {
    ariel::Graph g;
    // No need to load any graph here, it's empty by default
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "Empty graph");  // Empty graph has no path
    CHECK(ariel::Algorithms::isConnected(g) == false);  // Empty graph is not connected
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);  // Empty graph has no cycles
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={}, B={}");  // Empty graph is bipartite
}
TEST_CASE("Test disconnected graph with more nodes") {
  ariel::Graph g;
  vector<vector<int>> graph = {
      {0, 0, 0, 0},
      {0, 0, 1, 1},
      {0, 1, 0, 0},
      {0, 1, 0, 0}};
  g.loadGraph(graph);
  CHECK(ariel::Algorithms::isConnected(g) == false);
}
TEST_CASE("Test shortestPath for longer path") {
  ariel::Graph g;
  vector<vector<int>> graph = {
      {0, 1, 0, 0, 0},
      {1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0},
      {0, 1, 1, 0, 1},
      {0, 0, 0, 1, 0}};
  g.loadGraph(graph);
  CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->1->3->4");
}
TEST_CASE("Test isContainsCycle for different cycle structure") {
  ariel::Graph g;
  vector<vector<int>> graph = {
      {0, 1, 0, 0},
      {1, 0, 1, 0},
      {0, 1, 0, 1},
      {0, 0, 1, 0}};
  g.loadGraph(graph);
  CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}
TEST_CASE("Test isBipartite for multiple valid partitions") {
  ariel::Graph g;
  vector<vector<int>> graph = {
      {0, 1, 0, 0},
      {1, 0, 1, 1},
      {0, 1, 0, 0},
      {0, 1, 0, 0}};
  g.loadGraph(graph);
  // Both {1, 3} and {0, 2} are valid bipartitions for this graph
  CHECK(ariel::Algorithms::isBipartite(g).find("The graph is bipartite") != string::npos); 
  //npos is the largest possible value of size_t (means that it's not found)
}

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={1 }, B={0 2 }");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 0, 0, 0},
        {2, 0, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={1 2 4 }, B={0 3 }");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test Graph constructor") {
  ariel::Graph g;
  CHECK(g.getVertices() == 0);  // Empty graph should have 0 vertices
  CHECK(g.getEdges() == 0);      // Empty graph should have 0 edges
}

TEST_CASE("Test loadGraph") {
  ariel::Graph g;
  vector<vector<int>> graph = {
    {0, 1, 0},
   {1, 0, 1},
    {0, 1, 0}};
  g.loadGraph(graph);
  CHECK(g.getVertices() == 3);  // Graph should have 3 vertices
  CHECK(g.getEdges() == 2);      // Graph should have 2 edges 
}

TEST_CASE("Test getGraph") {
  ariel::Graph g;
  vector<vector<int>> graph = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
  g.loadGraph(graph);
  vector<vector<int>> returnedGraph = g.getGraph();
  CHECK(returnedGraph == graph);  // Check if returned graph matches loaded graph
}

TEST_CASE("Test isDirected for undirected graph") {
  ariel::Graph g;
  vector<vector<int>> graph = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
  g.loadGraph(graph);
  CHECK(g.isDirected() == false);  // By default, graph should be undirected
}

