#include <iostream>
#include <fstream>
#include <sstream>
#include "CaveSystem.h"

using std::string, std::vector, std::unordered_map, std::pair;

int main(int argc, char** argv) {
    CaveSystem caves;
    std::ifstream inputStream(argv[1]);

    std::string inputString;
    while(getline(inputStream, inputString)) {
        caves.push(inputString);
    }

    Cave* startingVertex = caves.verticies.find("start")->second;
    int numOfPaths = CaveSystem::calculatePaths(startingVertex, {"start"});

    std::cout << numOfPaths << std::endl;

    return 0;
}
