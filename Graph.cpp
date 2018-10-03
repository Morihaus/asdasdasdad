/*
 * Graph.cpp
 *
 *  Created on: 2018. szept. 28.
 *      Author: mori
 */
#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Graph::beolvas(string txt){
	ifstream graphadatok;
	graphadatok.open(txt);
	int meret;
	string sor;
	getline(graphadatok, sor);
	meret=stoi(sor);
	for(int i=0;i<meret;i++)
	{
		getline(graphadatok,sor);


	}


}


