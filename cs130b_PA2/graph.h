#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class MCST {
    public:
        MCST(int v);
        void addEdge(double weight, int v1Label, int v2Label);
        void kruskal();
        void printResult();

    private:
        vector<pair<double, pair<int, int>>> graph;
        vector<pair<double, pair<int, int>>> mst;
        vector<int> connected;
};

#endif