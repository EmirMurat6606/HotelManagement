//
// Created by 2005e on 27/08/2024.
//

#include "../Headers/Comfort.h"

int Comfort::maxPerson() const {
    return 3;
}

std::string Comfort::getType() const {
    return "Comfort";
}

Comfort::Comfort(const std::string &name, const std::string &number) : Room(name, number) {}

Comfort::~Comfort() {}
