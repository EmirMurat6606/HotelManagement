//
// Created by 2005e on 27/08/2024.
//

#include "../Headers/Suite.h"

Suite::Suite(const std::string &name, const std::string & number) : Room(name, number) {}

Suite::~Suite() {}

int Suite::maxPerson() const {
    return 4;
}

std::string Suite::getType() const {
    return "Suite";
}
