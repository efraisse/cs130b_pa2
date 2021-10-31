/*
sources cited:

https://www.programiz.com/dsa/kruskal-algorithm
helped me with the general implementation of kruskal's algorithm
*/

#include "graph.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <chrono>
#include <algorithm>
#include <String>
#include <iomanip>

using namespace std;

int main() {
    int numVertices;
    cin >> numVertices;
    map<int, pair<double, double>> verticeIndexToPoint;

    MCST myTree(numVertices);
    for (int i = 0; i < numVertices; i++) {
        pair<double, double> point;
        string stringX = "", stringY = "";
        char test[20];
        cin >> stringX >> stringY;
        double x, y;
        x = stod(stringX);
        y = stod(stringY);
        point.first = x;
        point.second = y;
        //map a point to a specific index to reference it later
        verticeIndexToPoint[i] = point;
    }

    int numEdges;
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        string stringv1, stringv2;
        cin >> stringv1 >> stringv2;
        int x, y;
        x = stoi(stringv1, 0, 10);
        y = stoi(stringv2, 0, 10);
        //calculate the weight value to add it to the edge
        pair<double, double> p1 = verticeIndexToPoint[x];
        pair<double, double> p2 = verticeIndexToPoint[y];
        double dx, dy, weight;
        dx = p2.second - p1.second;
        dy = p2.first - p1.first;
        weight = sqrt(dx*dx + dy*dy);
        myTree.addEdge(weight, x, y);
    }

    if (numEdges == 0) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = i + 1; j < numVertices; j++) {
                pair<double, double> p1 = verticeIndexToPoint[i];
                pair<double, double> p2 = verticeIndexToPoint[j];
                double dx, dy, weight;
                dx = p2.second - p1.second;
                dy = p2.first - p1.first;
                weight = sqrt(dx*dx + dy*dy);
                myTree.addEdge(weight, i, j);
            }
        }
    }

    //now all of the edges and vertices are taken in from the input.txt file
    //run kruskal and output the answer
    myTree.kruskal();
    myTree.printResult();
    return 0;
}