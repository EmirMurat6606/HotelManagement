//
// Created by 2005e on 27/08/2024.
//

#ifndef HOTELMANAGEMENT_COMFORT_H
#define HOTELMANAGEMENT_COMFORT_H

#include "Room.h"

class Comfort: public Room {
public:

    /**
     * Constructor of the Comfort class
     * @param name : the unique name of the room
     * @param number : the unique number of the room
     */
    Comfort(const std::string &name, const std::string &number);

    /**
     * Destructor of the Comfort class
     */
    ~Comfort() override;

    int maxPerson() const;

    std::string getType() const;

};


#endif //HOTELMANAGEMENT_COMFORT_H
