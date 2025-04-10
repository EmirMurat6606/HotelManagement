//
// Created by 2005e on 27/08/2024.
//

#include "../Headers/Visitor.h"

Visitor::Visitor(const std::string &firstname, const std::string &lastname, const std::string &registerNumber,
                 const std::string &phoneNumber) : firstname(firstname), lastname(lastname),
                                                   register_number(registerNumber), phone_number(phoneNumber) {}

void Visitor::setFirstname(const std::string &firstname) {
    Visitor::firstname = firstname;
}

void Visitor::setLastname(const std::string &lastname) {
    Visitor::lastname = lastname;
}

void Visitor::setRegisterNumber(const std::string &registerNumber) {
    register_number = registerNumber;
}

void Visitor::setPhoneNumber(const std::string &phoneNumber) {
    phone_number = phoneNumber;
}

const std::string &Visitor::getFirstname() const {
    return firstname;
}

const std::string &Visitor::getLastname() const {
    return lastname;
}

const std::string &Visitor::getRegisterNumber() const {
    return register_number;
}

const std::string &Visitor::getPhoneNumber() const {
    return phone_number;
}

Visitor::~Visitor() {}

std::string Visitor::printInfo() const {
    return "Firstname: " + firstname + "\nLastname: " + lastname + "\nPhone Number: " + phone_number +
           "\nRegister Number: " + register_number;
}
