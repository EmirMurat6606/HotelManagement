//
// Created by 2005e on 27/08/2024.
//

#ifndef HOTELMANAGEMENT_SUITE_H
#define HOTELMANAGEMENT_SUITE_H

#include "Room.h"

class Suite: public Room {

public:

    /**
     * Constructor of the Suite class
     * @param name : the unique name of the suite
     * @param number : the unique number of the suite
     */
    Suite(const std::string &name, const std::string& number);

    /**
     * Destructor of the Suite class
     */
    ~Suite() override;

    int maxPerson() const;

    std::string getType() const;

};


#endif //HOTELMANAGEMENT_SUITE_H
