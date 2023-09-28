#include "graph-bfs.h"
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

  // pre: none
  // post: an empty undirected Graph has been created
  Graph::Graph() {
    // default constructor for vector called, nothing to do.
  }

  // pre: none
  // post: returns the number of vertices in this Graph
  std::size_t Graph::n() const {
    return adjList_.size();
  }

  // pre: none
  // post: returns the number of edges in this Graph
  std::size_t Graph::m() const {
    std::size_t count = 0;
    for(auto list : adjList_) {
        count += list.size();
    }
    /*
     * alternatively
     * for (int i = 0; i < adjList_.size(); i ++) {
     *   count += adjList_[i].size();
     * }
     * return count / 2;
     */
    return count / 2;
  }

  // pre: none
  // post: a new vertex with label n() has been added to this Graph
  void Graph::addVertex() {
    // add empty vector to adjList_
    adjList_.push_back(std::vector<std::size_t>());
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} has been added to this Graph
  //       if it is not an edge already
  //       If edge {i, j} is already added, do nothing
  void Graph::addEdge(std::size_t i, std::size_t j) {
    assert(i<n()&&j<n());
    for (auto v : adjList_[i]) {
      if (v == j) {
        // edge is already added, do nothing
        return;
      }
    }

    adjList_[i].push_back(j);
    adjList_[j].push_back(i);
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} is not in this Graph
  void Graph::deleteEdge(std::size_t i, std::size_t j) {
    // https://cplusplus.com/reference/vector/vector/erase/
    assert(i<n()&&j<n());

    // remove vertex j from adjacency list of i
    for (int k = 0; k < adjList_[i].size(); k ++) {
      if (adjList_[i][k] == j) {
        adjList_[i].erase(adjList_[i].begin() + k);
        break;
      }
    }

    // remove vertex i from adjacency list of j
    for (int k = 0; k < adjList_[i].size(); k ++) {
      if (adjList_[i][k] == j) {
        adjList_[i].erase(adjList_[i].begin() + k);
        break;
      }
    }
  }


  // pre: i < n()
  // post: returns the adjacency list of i in this Graph
  std::vector<std::size_t> Graph::adj(std::size_t i) const {
    return adjList_[i];
  }


  // pre: source < n()
  // post: returns list of vertices connected to source
  std::vector<std::size_t> Graph::connectedList(std::size_t source) {
    std::vector<std::size_t> output;
    std::queue<std::size_t> q; // First in, first out
    std::vector<bool> visited(n(), 0); // vector of n zeros

    q.push(source); // Add Shweta to queue

    while (q.size() > 0) {
      // Visit the next user
      std::size_t currentId = q.front();
      q.pop();

      if (visited[currentId]) { continue; }
      std::cout << "Visiting vertex " << currentId << std::endl;
      visited[currentId] = true;

      // Add current user to output
      output.push_back(currentId);

      // Add their friends to queue
      for (int i = 0; i < adjList_[currentId].size(); i ++) {
       q.push(adjList_[currentId][i]);
      }
    }

    return output;
  }


  // pre: from < n(), to < n()
  // post: returns a vector listing the ids of the vertices along the shortest path between vertex 'from' and vertex 'to'
  std::vector<std::size_t> Graph::shortestPath(std::size_t from, std::size_t to) 
  {
    std::vector<std::size_t> output;
    std::queue<std::size_t> q; // First in, first out
    std::vector<bool> visited(n(), 0); // vector of n zeros
    std::vector<std::size_t> prev(n(), 0); // vector of n zeros

    // implement a BFS that returns the list of vertices along the shortest path
    // from vertex 'from' to vertex 'to'

    q.push(from); // Add Shweta to queue

    while (q.size() > 0) {
      // Visit the next user
      std::size_t currentId = q.front();
      q.pop();

      if (visited[currentId]) { continue; }
      std::cout << "Visiting vertex " << currentId << std::endl;
      visited[currentId] = true;

      // Add current user to output
      output.push_back(currentId);

      // Add their friends to queue
      for (int i = 0; i < adjList_[currentId].size(); i ++) {
       q.push(adjList_[currentId][i]);
      }
    }
    return output;
  }


