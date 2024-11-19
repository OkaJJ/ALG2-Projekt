//
// Created by Matyáš Cron on 15.11.2024.
//

#include "CaveSystem.h"
#include "Cave.h"
#include <sstream>

CaveSystem::CaveSystem() {
    verticies = {};
}

CaveSystem::~CaveSystem() {
    for (auto& pair : verticies) {
        delete pair.second;
    }
}

void CaveSystem::push(std::string& edge) {
    if (!edge.empty() && edge.back() == '\r') {
        edge.pop_back();
    }

    std::stringstream ss(edge);
    std::string vertexA, vertexB;

    std::getline(ss, vertexA, '-');
    std::getline(ss, vertexB, '-');

    if (verticies.find(vertexA) == verticies.end()) {
        verticies[vertexA] = new Cave(vertexA);
    }
    if (verticies.find(vertexB) == verticies.end()) {
        verticies[vertexB] = new Cave(vertexB);
    }

    Cave* vA = verticies[vertexA];
    Cave* vB = verticies[vertexB];

    vA->addNeighbor(vB);
    vB->addNeighbor(vA);
}

int CaveSystem::calculatePaths(Cave* vert, std::set<std::string> visitedVerticies = {}) {
    if(vert->id == "end") return 1;
    int count = 0;
    if(!(vert->isBig)) {
        visitedVerticies.insert(vert->id);
    }
    for (auto& vertex : vert->neighbors) {
        if(visitedVerticies.find(vertex->id) == visitedVerticies.end()) {
            count += calculatePaths(vertex, visitedVerticies);
        }
    }
    return count;
}