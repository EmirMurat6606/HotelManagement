//
// Created by 2005e on 27/08/2024.
//

#ifndef HOTELMANAGEMENT_ROOM_H
#define HOTELMANAGEMENT_ROOM_H

#include <string>
#include <random>
#include <iostream>

class Visitor;

class Room {

protected:
    /**
     * Unique name of the room
     */
    std::string name;

    /**
     * Unique room number
     */
    std::string number;

    /**
     * The current visitor of the room
     */
    Visitor* visitor;

    /**
     * The occupancy status of the room
     */
    bool occupied;

    /**
     * The secret access code of the room
     * Code structure: exaple: "12ab345"
     */
    std::string secret_code;

public:

    /**
     * Constructor of the Room class
     * @param name : the unique name of the room
     * @param number : the unique number of the room
     */
    Room(const std::string &name, const std::string & number);

    /**
     * Destructor of the Room class
     */
    virtual ~Room();

    /**
     * Getter for the name of a room
     * @return room name
     */
    const std::string &getName() const;

    /**
     * Getter for the room number
     * @return room number
     */
    const std::string & getNumber() const;

    /**
     * Checks if the room is occupied or not
     * @return true if the room is occupied, else false
     */
    const bool& isOccupied() const;

    /**
     * Checks in a visitor
     * @param visitor : the visitor that is checked in
     */
    void checkIn(Visitor* visitor);

    /**
     * Setter for the secret code
     * @param secretCode : the code
     */
    void setSecretCode(const std::string &secretCode);

    /**
     * Checks if the given code is equal to the secret code
     * @param code : the given code
     * @return true is the code is valid, else false
     */
     bool codeValidation(const std::string& code) const;

    /**
     * Checks out a visitor
     */
     void checkOut();

    /**
     * Maximum number of people that can stay in a room
     * @return max occupancy
     */
    virtual int maxPerson() const = 0;

    /**
     * Gets type of the room
     * @return type of the room
     */
     virtual std::string getType() const = 0;

     /**
      * Generates a secret code for the room
      * Takes an empty string and stores the code in it
      */
     void generateSecretCode(std::string& code);

     /**
      * Getter for the visitor of the room
      * @return a pointer to the visitor
      */
     Visitor* getVisitor() const;


};


#endif //HOTELMANAGEMENT_ROOM_H
