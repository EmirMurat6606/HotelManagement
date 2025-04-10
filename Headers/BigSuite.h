//
// Created by 2005e on 27/08/2024.
//

#ifndef HOTELMANAGEMENT_BIGSUITE_H
#define HOTELMANAGEMENT_BIGSUITE_H

#include "Room.h"

class BigSuite: public Room {
public:

    /**
     * Constructor of the BigSuite class
     * @param name : the unique name of the BigSuite
     * @param number : the unique number of the BigSuite
     */
    BigSuite(const std::string &name, const std::string &number);

    /**
     * Destructor of the BigSuite class
     */
    ~BigSuite() override;

    int maxPerson() const;

    std::string getType() const;

};


#endif //HOTELMANAGEMENT_BIGSUITE_H
