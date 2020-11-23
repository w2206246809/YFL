#ifndef PSTSTRING_H
#include "pstString.h"
#endif // !PSTSTRING_H

#ifndef STDIO_H
#include <stdio.h>
#endif // !STDIO_H

#ifndef VECTOR
#include <vector>
#endif // !VECTOR

#pragma once

class Edge;
class Graph;

class Node {
private:
	friend Edge;
	friend Graph;
	Str _name;
	int _id;
	Node *_next; // next node in Graph() linked list
	std::vector<Edge*> _edges; // Edge()s which is link to this Node()
	int _nextEdgeP;
	void addEdge(Edge *edge);
public:
	Node(int nodeId, const char nodeName[]) {
		_id = nodeId;
		_name = nodeName;
		_next = NULL;
		_edges = std::vector<Edge*>();
		_nextEdgeP = 0;
	}
	Node(int nodeId, const Str nodeName = "") {
		_id = nodeId;
		_name = nodeName;
		_next = NULL;
		_edges = std::vector<Edge*>();
	}
	void resetNextNode();
	Node* nextNode();
};

class Edge {
private:
	friend Node;
	friend Graph;
	int _id;
	Node *_node1, *_node2;
	bool _directed;
	Edge *_next; // next node in Graph() linked list
	Node* anotherNode(Node* node) {
		return (node == _node1) ? _node2 : _node1;
	}
public:
	Edge(Node* node1, Node* node2, bool directed = false) {
		static int edgeId = 1;
		_id = edgeId++;
		_node1 = node1;
		_node2 = node2;
		_directed = directed;
		_next = NULL;
		node1->addEdge(this);
		node2->addEdge(this);
	}
};

void Node::addEdge(Edge *edge) {
	_edges.push_back(edge);
}
void Node::resetNextNode() {
	_nextEdgeP = 0;
}
Node* Node::nextNode() {
	if (_nextEdgeP >= _edges.size()) {
		_nextEdgeP = 0;
		return NULL;
	}
	return _edges[_nextEdgeP++]->anotherNode(this);
}

class Graph {
private:
	Str _name;
	bool _directed;
	Node *_nodes;
	Edge *_edges;
public:
	Graph(const Str name = "", bool directed = false) {
		_name = name;
		_directed = directed;
		_nodes = NULL;
		_edges = NULL;
	}
	Graph(const char name[], bool directed = false) {
		_name = name;
		_directed = directed;
		_nodes = NULL;
		_edges = NULL;
	}
	Node* addNode(int nodeId, const Str nodeName = "") {
		Node *newNode = new Node(nodeId, nodeName);
		newNode->_next = _nodes;
		_nodes = newNode;
		return _nodes;
	}
	Node* addNode(int nodeId, const char nodeName[]) {
		Node *newNode = new Node(nodeId, nodeName);
		newNode->_next = _nodes;
		_nodes = newNode;
		return _nodes;
	}
	void addEdge(Node* node1, Node* node2, bool directed = false) {
		if (node1 == NULL || node2 == NULL) {
			return;
		}
		Edge *newEdge = new Edge(node1, node2, directed | _directed);
		newEdge->_next = _edges;
		_edges = newEdge;
	}
	void addEdge(int nodeId1, int nodeId2, bool directed = false) {
		addEdge(findNodeById(nodeId1), findNodeById(nodeId2), directed);
	}
	Node* findNodeById(int nodeId) {
		Node* currentNode = _nodes;
		while (currentNode) {
			if (currentNode->_id == nodeId) {
				return currentNode;
			}
			currentNode = currentNode->_next;
		}
		return NULL;
	}
	void print() { // for test
		Edge *e = _edges;
		while (e) {
			printf("%d: node%d <--> node%d\n", e->_id, e->_node1->_id, e->_node2->_id);
			e = e->_next;
		}
		Node *n = _nodes;
		while (n) {
			n->resetNextNode();
			printf("node%d:\n", n->_id);
			while (Node *currentNode = n->nextNode()) {
				printf("	-> node%d\n", currentNode->_id);
			}
			n = n->_next;
		}
	}
};