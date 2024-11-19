//
// Created by Matyáš Cron on 15.11.2024.
//

#ifndef PROJEKT_CAVE_H
#define PROJEKT_CAVE_H

#include <string>
#include <vector>

/**
 * @class Cave
 * @brief Represents a single cave.
 */
class Cave {
public:
    /**
     * @brief Unique identifier for the cave. If the ID is uppercase, then it's a big cave, otherwise it's a small cave.
     */
    std::string id;

    /**
     * @brief List of neighboring caves directly connected to this cave.
     */
    std::vector<Cave*> neighbors;

    /**
     * @brief Flag indicating if the cave is considered "big."
     *
     * @details Big caves can be revisited multiple times during
     * a traversal, small caves can be visited only once. This is just
     * a helper variable, the real way of identifying a big cave is if
     * its ID is in uppercase.
     */
    bool isBig;

    /**
     * @brief Constructs a new Cave with the given ID.
     *
     * @param id A unique identifier for the cave. If the ID is uppercase, then it's a big cave, otherwise it's a small cave.
     */
    Cave(const std::string& id);

    /**
     * @brief Adds a neighboring cave to this cave.
     *
     * @param neighbor A pointer to the cave to be added as a neighbor.
     */
    void addNeighbor(Cave* neighbor);
};



#endif //PROJEKT_CAVE_H
