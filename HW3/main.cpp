#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <cstring>

// compile: g++ homework3.cpp
// pass arguments: ./a.out graph.txt dist.txt

class Graph {
    private:
        int numVertices; // total number of vertices in graph
        bool * visited;
        std::vector< std::pair<int, int> > * adjacencyList;
    public:
        Graph(int numVertices);
        ~Graph();
        void addPath(int origin, int destination, int weight);
        void shortestPath();
        int * distance; // v.d in the book
};

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    adjacencyList = new std::vector< std::pair<int, int> >[numVertices];
    distance = new int[numVertices];
    distance[0] = 0; // always starting at vertex 0 so the distance from vertex 0 will always be 0
    visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++) { visited[i] = false; }
}

Graph::~Graph() {
    delete[] adjacencyList;
    delete[] distance;
    delete[] visited;
}

void Graph::addPath(int origin, int destination, int weight) {
    adjacencyList[origin].push_back(std::make_pair(destination, weight));
}

void removeCharsFromString( std::string &str, char* charsToRemove ) {
   for ( unsigned int i = 0; i < std::strlen(charsToRemove); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
   }
}

void parseLinesToPath(std::string line, Graph * graph) {
    std::vector<int> vect;
    int origin, destination, weight, temp;
    char chars[] = "()";

    removeCharsFromString(line, chars);

    for(size_t i = 0; i < line.size(); i++) {
        if(line[i] == ' ') {
            line[i] = ',';
        }
    }

    std::stringstream stream(line);

    while(stream >> temp) {
        vect.push_back(temp);

        if(stream.peek() == ' ' || stream.peek() == ',') { stream.ignore(); }
    }

    origin = vect[0];
    for(size_t i = 1; i < vect.size(); i = i + 2) {
        destination = vect[i];
        weight = vect[i + 1];
        graph->addPath(origin, destination, weight);
    }
}

void Graph::shortestPath() {
    for(int i = 1; i < numVertices; i++) { distance[i] = INT_MAX; } // INT_MAX used as infinity
    int currentVertex, currentWeight, adjacentVertex, pathWeight;
    // implementing priority queue with min-heap by passing std::greater... to the last parameter
    std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > pQueue;
    pQueue.push(std::make_pair(0, 0)); // source and distance from source (both of which are 0)
    while(!pQueue.empty()) {
        currentVertex = pQueue.top().first;
        currentWeight = pQueue.top().second;
        pQueue.pop();

        if(!visited[currentVertex]) {
            visited[currentVertex] = true;
            for(unsigned int i = 0; i < adjacencyList[currentVertex].size(); i++) {
                adjacentVertex = adjacencyList[currentVertex][i].first;
                pathWeight = adjacencyList[currentVertex][i].second + currentWeight;
                if(!visited[adjacentVertex] && pathWeight < distance[adjacentVertex]) {
                    distance[adjacentVertex] = pathWeight;
                    pQueue.push(std::make_pair(adjacentVertex, distance[adjacentVertex]));
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {

    std::string line, inputFilename = "graph.txt", outputFilename = "dist.txt";
    if(argc == 2) { inputFilename = argv[1]; }
    else if (argc == 3) { inputFilename = argv[1]; outputFilename = argv[2]; }

    std::ifstream inputFile(inputFilename.c_str(), std::ios::in);
    std::vector<std::string> lines;
    if(inputFile.is_open()) {
        while(getline(inputFile, line)) {
            lines.push_back(line);
        }
        inputFile.close();
    }

    Graph graph(lines.size());

    for(size_t i = 0; i < lines.size(); i++) {
        parseLinesToPath(lines[i], &graph);
    }

    graph.shortestPath();

    std::ofstream outputFile(outputFilename.c_str() , std::ios::out);

    if(outputFile.is_open()) {
        for(unsigned int i = 0; i < lines.size(); i++) { outputFile << i << '\t'; }
        outputFile << std::endl;
        for(unsigned int i = 0; i < lines.size(); i++) { outputFile << graph.distance[i] << '\t'; }
        outputFile.close();
    }

    std::cout << "Your array of shortest path weights have been written to \"" << outputFilename << ".\"" << std::endl;

    return 0;
}
