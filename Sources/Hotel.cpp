//
// Created by 2005e on 27/08/2024.
//

#include "../Headers/Hotel.h"
#include "../Headers/Room.h"

Hotel::Hotel(const std::string &name) : name(name) {}

const std::string &Hotel::getName() const {
    return name;
}

const std::vector<Room *> &Hotel::getRooms() const {
    return rooms;
}

void Hotel::addRoom(Room *room) {
    Hotel::rooms.push_back(room);
}

Hotel::~Hotel() {
    for (Room* room : rooms) {
        delete room;
    }
}

std::vector<Room*> Hotel::getOccupiedRooms() const{
    std::vector<Room*> hotel_rooms;
    for(Room * room : rooms){
        if (room->isOccupied()){
            hotel_rooms.push_back(room);
        }
    }

    return hotel_rooms;
}


