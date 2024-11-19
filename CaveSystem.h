//
// Created by Matyáš Cron on 15.11.2024.
//

#ifndef PROJEKT_CAVESYSTEM_H
#define PROJEKT_CAVESYSTEM_H

#include "Cave.h"
#include <unordered_map>
#include <string>
#include <set>

/**
 * @class CaveSystem
 * @brief Represents a system of interconnected caves modeled as a graph.
 */
class CaveSystem {
public:
    /**
     * @brief Map of caves in the system, identified by their unique names.
     */
    std::unordered_map<std::string, Cave*> verticies;

    /**
     * @brief Constructs a new CaveSystem object.
     */
    CaveSystem();

    /**
     * @brief Destroys the CaveSystem object and cleans up allocated resources.
     */
    ~CaveSystem();

    /**
     * @brief Adds a connection (edge) between caves in the system.
     *
     * @param edge A reference to a string representing two connected verticies.
     */
    void push(std::string& edge);

    /**
     * @brief Calculates the number of unique paths through the cave system.
     *
     * @param vert Pointer to the starting cave.
     * @param visitedVerticies A set of visited cave names to prevent revisiting.
     * @return The number of unique paths from the given cave.
     */
    static int calculatePaths(Cave* vert, std::set<std::string> visitedVerticies);
};


#endif // PROJEKT_CAVESYSTEM_H
