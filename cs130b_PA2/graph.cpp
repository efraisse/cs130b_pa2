#include "graph.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

MCST::MCST(int v) {
    connected = vector<int>(v);
    for (int i = 0; i < connected.size(); i++) connected[i] = i;
}

void MCST::addEdge(double weight, int v1Label, int v2Label) {
    pair<int, int> edge = make_pair(v1Label, v2Label);
    pair<double, pair<int, int>> graphElement = make_pair(weight, edge);
    graph.push_back(graphElement);
}

bool sortGraph(pair<double, pair<int, int>> el1, pair<double, pair<int, int>> el2) {
    return el1.first < el2.first;
}

void MCST::kruskal() {
    sort(graph.begin(), graph.end(), sortGraph); //increasing weight;

    for (auto el: graph) {
        int set1 = el.second.first, set2 = el.second.second;
        while (set1 != connected[set1]) {
            set1 = connected[set1];
        }
        while (set2 != connected[set2]) {
            set2 = connected[set2];
        }
        if (set1 != set2) {
            connected[set1] = connected[set2];
            mst.push_back(el);
        }
    }
}

bool sortVectors(pair<int, int>& v1, pair<int, int> &v2) {
    if (v1.first != v2.first) return (v1.first < v2.first);
    else return (v1.second < v2.second);
}

void MCST::printResult() {
    vector<pair<int, int>> answer;
    for (int i = 0; i < mst.size(); i++) {
        answer.push_back(mst[i].second);
    }
    sort(answer.begin(), answer.end(), sortVectors);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i].first << " " << answer[i].second << endl;
    }
}