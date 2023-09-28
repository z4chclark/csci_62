#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>

// assumption: vertices are numbered 0, 1, ..., n-1

class Graph {
public:
  // pre: none
  // post: an empty Graph has been created
  Graph();

  // pre: none
  // post: returns the number of vertices in this Graph
  std::size_t n() const;

  // pre: none
  // post: returns the number of edges in this Graph
  std::size_t m() const;

  // pre: none
  // post: a new vertex with label n() has been added to this Graph
  void addVertex();

  // pre: i < n() && j < n()
  // post: edge {i, j} has been added to this Graph
  //       if it is not an edge already
  void addEdge(std::size_t i, std::size_t j);

  // pre: i < n() && j < n()
  // post: edge {i, j} is not in this Graph
  void deleteEdge(std::size_t i, std::size_t j);

  // pre: i < n()
  // post: returns the adjacency list of i in this Graph
  std::vector<std::size_t> adj(std::size_t i) const;

  // pre: source < n()
  // post: returns list of vertices connected to source
  std::vector<std::size_t> connectedList(std::size_t source);

  // pre: from < n(), to < n()
  // post: returns a vector listing the ids of the vertices along the shortest path between vertex 'from' and vertex 'to'
  std::vector<std::size_t> shortestPath(std::size_t from, std::size_t to);

 private:
  std::vector<std::vector<std::size_t> > adjList_;

};



#endif // GRAPH_H
