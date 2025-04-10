//
// Created by 2005e on 28/08/2024.
//

#ifndef HOTELMANAGEMENT_LOGGER_H
#define HOTELMANAGEMENT_LOGGER_H

#include <fstream>
#include "Hotel.h"

class Logger {
private:

    std::ofstream * save_file;

public:

    explicit Logger(std::ofstream &saveFile);

    virtual ~Logger();

    void saveData(const Hotel* hotel) const;


};


#endif //HOTELMANAGEMENT_LOGGER_H
