//
// Created by 2005e on 29/08/2024.
//

#include "OptionDialog.h"
#include "HotelGUI.h"
#include "../Headers/Hotel.h"



OptionDialog::OptionDialog(QWidget *parent)   {
    setMinimumSize(600, 300);
    hotel = nullptr;
    createGraphicsView();
    createEvents();
}


void OptionDialog::createGraphicsView() {

    QPushButton * check_in = new QPushButton(QString("Check in"), this);

    QPushButton * check_out = new QPushButton(QString("Check out"), this);

    QPushButton * availability = new QPushButton(QString("Availability"), this);

    QVBoxLayout *layout = new QVBoxLayout(this);

    check_in->setStyleSheet("QPushButton { font-weight: bold; color: blue; }");
    check_out->setStyleSheet("QPushButton { font-weight: bold; color: blue; }");
    availability->setStyleSheet("QPushButton { font-weight: bold; color: blue; }");

    layout->addWidget(check_in);
    layout->addWidget(check_out);
    layout->addWidget(availability);

    check_in->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    check_out->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    availability->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    option_buttons.push_back(check_in);
    option_buttons.push_back(check_out);
    option_buttons.push_back(availability);

}

void OptionDialog::createEvents() const {

    for(QPushButton * option_button : option_buttons){
        if(option_button->text() == QString("Check in")){
            QObject::connect(option_button, SIGNAL(clicked()), this, SLOT(toCheckIn()));
        }else if (option_button->text() == QString("Check out")){
            QObject::connect(option_button, SIGNAL(clicked()), this, SLOT(toCheckOut()));
        }else if (option_button->text() == "Availability"){
            QObject::connect(option_button, SIGNAL(clicked()), this, SLOT(toAvailability()));
        }
    }
}

void OptionDialog::setHotel(Hotel *hotel) {
    OptionDialog::hotel = hotel;
}

void OptionDialog::setOptionButtons(const std::vector<QPushButton *> &optionButtons) {
    option_buttons = optionButtons;
}

const QMetaObject &OptionDialog::getStaticMetaObject() {
    return staticMetaObject;
}

Hotel *OptionDialog::getHotel() const {
    return hotel;
}

const std::vector<QPushButton *> &OptionDialog::getOptionButtons() const {
    return option_buttons;
}

void OptionDialog::toCheckIn() {
    CheckInDialog * check_in = new CheckInDialog(this);
    check_in->setHotel(hotel);
    check_in->createGraphicsView();
    check_in->createEvents();
    this->close();
    check_in->exec();
}

void OptionDialog::toCheckOut() {
    CheckOutDialog * check_out = new CheckOutDialog(this);
    check_out->setHotel(hotel);
    check_out->createEvents();
    check_out->createGraphicsView();
    this->close();
    check_out->exec();
}

void OptionDialog::toAvailability() {
    AvailabilityDialog * availability = new AvailabilityDialog(this);
    availability->setHotel(hotel);
    availability->createGraphicsView();
    availability->createEvents();
    this->close();
    availability->exec();
}

OptionDialog::~OptionDialog() {
    hotel = nullptr;
}

