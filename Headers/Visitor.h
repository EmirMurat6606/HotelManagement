//
// Created by 2005e on 27/08/2024.
//

#ifndef HOTELMANAGEMENT_VISITOR_H
#define HOTELMANAGEMENT_VISITOR_H

#include <string>

class Visitor {

private:

    /**
     * Firstname of the visitor
     */
    std::string firstname;

    /**
     * Lastname of the visitor
     */
    std::string lastname;

    /**
     * National register number
     */
    std::string register_number;

    /**
     * Contact info (phone number)
     */
     std::string phone_number;

public:

    /**
     * Constructor of the Visitor class
     * @param firstname : firstname of the visitor
     * @param lastname : lastname of the visitor
     * @param registerNumber : national register number
     * @param phoneNumber : contact info (phone number)
     */
    Visitor(const std::string &firstname, const std::string &lastname, const std::string & registerNumber,
            const std::string &phoneNumber);

    /**
     * Destructor of the Visitor class
     */
    virtual ~Visitor();

    /**
     * Getter for the firstname of the visitor
     * @param firstname : firstname of the visitor
     */
    void setFirstname(const std::string &firstname);

    /**
     * Getter for the lastname of the visitor
     * @param lastname : lastname of the visitor
     */
    void setLastname(const std::string &lastname);

    /**
     * Setter for the national register number
     * @param registerNumber : national register number
     */
    void setRegisterNumber(const std::string&  registerNumber);

    /**
     * Setter for the contact info (phone number)
     * @param phoneNumber : contact info (phone number)
     */
    void setPhoneNumber(const std::string &phoneNumber);

    /**
     * Getter for the firstname of the visitor
     * @return firstname of the visitor
     */
    const std::string &getFirstname() const;

    /**
     * Getter for the lastname of the visitor
     * @return lastname of the visitor
     */
    const std::string &getLastname() const;

    /**
     * Getter for the national register number
     * @param registerNumber : national register number
     */
    const std::string& getRegisterNumber() const;

    /**
     * Getter for the contact info (phone number)
     * @return contact info (phone number)
     */
    const std::string &getPhoneNumber() const;

    /**
     * Prints information about the visitor in a structured format
     * @return a string containing information about the visitor
     */
    std::string printInfo() const;


};


#endif //HOTELMANAGEMENT_VISITOR_H
