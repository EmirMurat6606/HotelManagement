//
// Created by 2005e on 29/08/2024.
//

#include "CheckOutDialog.h"
#include "../Headers/Hotel.h"
#include "../Headers/Room.h"

CheckOutDialog::CheckOutDialog(QWidget *parent)  {
    setMinimumSize(1080, 1080);
    setWindowTitle("Check out");
    hotel = nullptr;
}

CheckOutDialog::~CheckOutDialog() {
    hotel = nullptr;
}

void CheckOutDialog::setHotel(Hotel *hotel) {
    CheckOutDialog::hotel = hotel;
}

void CheckOutDialog::createGraphicsView() {

    this->setStyleSheet("background-color: #FFFFF0;");

    QVBoxLayout * layout = new QVBoxLayout(this);

    for(std::pair<QPushButton*, Room*> pair : buttons){
        layout->addWidget(pair.first);
    }
}

void CheckOutDialog::createEvents() {

    for(Room * room : hotel->getOccupiedRooms()){
        QPushButton * button = new QPushButton(QString::fromStdString(room->getName()) + "-" + QString::fromStdString(room->getNumber()), this);
        button->setStyleSheet("font-weight: bold; color: black;");
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        buttons.emplace_back(button, room);
    }


    for (std::pair<QPushButton*, Room*> pair : buttons) {
        QObject::connect(pair.first, &QPushButton::clicked, this, [this, pair]() {
            this->toValidation(pair.second);  // Roep toValidation aan met de Room*
        });
    }
}

void CheckOutDialog::toValidation(Room* room) {

    QDialog * validation_dialog = new QDialog(this);
    validation_dialog->setWindowTitle("Validation code");

    QVBoxLayout * layout = new QVBoxLayout(validation_dialog);

    QLabel * input_information = new QLabel("Give your validation code to check out:", validation_dialog);

    QLineEdit * input_field = new QLineEdit(validation_dialog);

    layout->addWidget(input_information);
    layout->addWidget(input_field);

    QObject::connect(input_field, &QLineEdit::textChanged, [=](const QString& input_text){
        if(room->codeValidation(input_text.toStdString())){
            validation_dialog->accept();
            room->checkOut();
        }
    });

    validation_dialog->exec();
    this->close();
}
