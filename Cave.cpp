//
// Created by Matyáš Cron on 15.11.2024.
//

#include "Cave.h"
#include <string>

Cave::Cave(const std::string& id) : id(id) {
    if(id[0] >= 'A' && id[0] <= 'Z') isBig = true;
    else isBig = false;
}

void Cave::addNeighbor(Cave* neighbor) {
    for (auto& n : neighbors) {
        if (n->id == neighbor->id) {
            return;
        }
    }
    neighbors.push_back(neighbor);
}
