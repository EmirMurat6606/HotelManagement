//
// Created by 2005e on 27/08/2024.
//

#include "../Headers/BigSuite.h"

BigSuite::BigSuite(const std::string &name, const std::string &number) : Room(name, number) {}

BigSuite::~BigSuite() {}

int BigSuite::maxPerson() const {
    return 6;
}

std::string BigSuite::getType() const {
    return "BigSuite";
}
