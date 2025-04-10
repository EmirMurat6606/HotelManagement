//
// Created by 2005e on 27/08/2024.
//

#include "../Headers/Room.h"

Room::Room(const std::string &name, const std::string & number) : name(name), number(number) {
    occupied = false;
    visitor = nullptr;
    secret_code = "";
}

Room::~Room() {
    if (visitor != nullptr)
        delete visitor;
}

const std::string &Room::getName() const {
    return name;
}

const std::string& Room::getNumber() const{
    return number;
}

void Room::checkIn(Visitor *visitor) {
    Room::visitor = visitor;
    occupied = true;
}

void Room::checkOut() {
    Visitor *temp = visitor;
    Room::visitor = nullptr;
    delete temp;
    occupied = false;
    secret_code = "";
}

void Room::setSecretCode(const std::string&  secretCode) {
    secret_code = secretCode;
}

bool Room::codeValidation(const std::string&  code) const {
    if (code == secret_code){
        return true;
    }else{
        return false;
    }
}

const bool& Room::isOccupied() const {
    return occupied;
}

void Room::generateSecretCode(std::string& code) {

    if(!code.empty()){
        std::cerr << "Code corruption, please pass an empty string as an argument to Room::generateSecretCode";
        return;
    }

    for(int i = 0; i < 7; i++){
        if(i == 2 || i == 3){
            code += 'a' + rand()%26;
        }else{
            int number = rand() %10 ;
            code += std::to_string(number);
        }
    }
    secret_code = code;
}

Visitor *Room::getVisitor() const {
    return visitor;
}
