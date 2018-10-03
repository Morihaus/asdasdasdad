/*
 * Graph.hpp
 *
 *  Created on: 2018. szept. 28.
 *      Author: mori
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <vector>
#include <string>

class Graph{
private:
	class Node{
	public:
		int id;
		Node* pCsucs,pSuly;
		std::vector<Node*> szomszedok;
	};
public:
	void beolvas(std::string txt);
	Graph();
	~Graph();
};



#endif /* GRAPH_HPP_ */
