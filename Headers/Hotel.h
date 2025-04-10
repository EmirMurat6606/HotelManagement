//
// Created by 2005e on 27/08/2024.
//

#ifndef HOTELMANAGEMENT_HOTEL_H
#define HOTELMANAGEMENT_HOTEL_H

#include <string>
#include <vector>


class Room;

class Hotel {
private:

    /**
     * The name of the hotel
     */
    std::string name;

    /**
     * Rooms of the hotel
     */
    std::vector<Room*> rooms;

public:

    /**
     * Constructor of the Hotel class
     * @param name : name of the hotel
     */
    explicit Hotel(const std::string &name);

    /**
     * Destructor of the hotel class
     */
    virtual ~Hotel();

    /**
     * Getter for the hotel name
     * @return name of the hotel
     */
    const std::string &getName() const;

    /**
     * Getter for the rooms of the hotel
     * @return vector with rooms
     */
    const std::vector<Room *> &getRooms() const;

    /**
     * Adds a room to the hotel
     * @param room : a Room object
     */
    void addRoom(Room* room);

    /**
     * Returns the names of the free hotel rooms
     */
    std::vector<Room*> getOccupiedRooms() const;


};


#endif //HOTELMANAGEMENT_HOTEL_H
