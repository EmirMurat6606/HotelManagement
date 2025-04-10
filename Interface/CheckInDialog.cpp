//
// Created by 2005e on 29/08/2024.
//

#include "CheckInDialog.h"
#include "../Headers/Hotel.h"
#include "QMessageBox"
#include "../Headers/Room.h"
#include "../Headers/Visitor.h"


CheckInDialog::CheckInDialog(QWidget *parent) {
    setMinimumSize(1080, 1080);
    setWindowTitle("Check In");
}

CheckInDialog::~CheckInDialog() {
    hotel = nullptr;
}

void CheckInDialog::closeEvent(QCloseEvent *event) {
    // Toon een bericht of doe iets anders
    QMessageBox::information(this, "Info", "Gebruik de 'Cancel' knop om dit venster te sluiten.");
    event->ignore(); // Annuleer het sluitverzoek
}

void CheckInDialog::setHotel(Hotel *hotel) {
    CheckInDialog::hotel = hotel;
}

void CheckInDialog::createGraphicsView() {
    this->setStyleSheet("background-color: #FFFFF0;");

    QGridLayout *layout = new QGridLayout(this);

    QLabel *first_name_grid = new QLabel("First name: ", this);
    first_name = new QLineEdit(this);
    first_name->setStyleSheet("border: 2px solid black;");

    QLabel *last_name_grid = new QLabel("Last name: ", this);
    last_name = new QLineEdit(this);
    last_name->setStyleSheet("border: 2px solid black;");

    QLabel *phone_number_grid = new QLabel("Phone number: ", this);
    phone_number = new QLineEdit(this);
    phone_number->setStyleSheet("border: 2px solid black;");

    QLabel *register_number_grid = new QLabel("National Register Number", this);
    register_number = new QLineEdit(this);
    register_number->setStyleSheet("border: 2px solid black;");

    QLabel *hotel_room_grid = new QLabel("Available rooms", this);
    createHotelSelectionbar();

    apply_button = new QPushButton("Apply", this);
    apply_button->setStyleSheet("background-color: blue; color: white; font-weight: bold; ");

    cancel_button = new QPushButton("Cancel", this);
    cancel_button->setStyleSheet("background-color: red; color: white; font-weight: bold;");

    layout->addWidget(first_name_grid, 0, 0);
    layout->addWidget(first_name, 0, 1);
    layout->addWidget(last_name_grid, 1, 0);
    layout->addWidget(last_name, 1, 1);
    layout->addWidget(phone_number_grid, 2, 0);
    layout->addWidget(phone_number, 2, 1);
    layout->addWidget(register_number_grid, 3, 0);
    layout->addWidget(register_number, 3, 1);
    layout->addWidget(hotel_room_grid, 4, 0);
    layout->addWidget(selected_room, 4, 1);
    layout->addWidget(apply_button, 6, 0);
    layout->addWidget(cancel_button, 6, 3);

}

void CheckInDialog::createEvents() const {

    QObject::connect(apply_button, SIGNAL(clicked(bool)), this, SLOT(saveRegistration()));

    QObject::connect(cancel_button,  SIGNAL(clicked(bool)), this, SLOT(cancelRegistration()));
}

void CheckInDialog::saveRegistration() {
    QStringList selected_hotelroom = splitUpRoomInfo();
    if(selected_hotelroom[0] == QString("empty")){
        this->reject(); // No rooms available
    }

    Visitor *new_visitor = new Visitor(first_name->text().toStdString(),last_name->text().toStdString(), register_number->text().toStdString(),phone_number->text().toStdString());

    std::string code;
    for(Room * room : hotel->getRooms()){
        if(room->getName() == selected_hotelroom[1].toStdString()){
            room->checkIn(new_visitor);
            room->generateSecretCode(code);
            break;
        }
    }
    QMessageBox::information(this, "Secret Code", QString::fromStdString(code));
    this->accept();
}

void CheckInDialog::cancelRegistration() {
    this->reject();
}

void CheckInDialog::createHotelSelectionbar() {
    selected_room = new QComboBox(this);
    QStringList hotel_rooms;
    for (Room *room: hotel->getRooms()) {
        if (!room->isOccupied()) {
            std::string room_info;
            room_info +=
                    room->getType() + " - " + room->getName() + " - " + room->getNumber() + " - " + "max persons:" +
                    std::to_string(room->maxPerson());
            hotel_rooms.push_back(QString::fromStdString(room_info));
        }
    }
    selected_room->addItems(hotel_rooms);
}

QStringList CheckInDialog::splitUpRoomInfo() const {
    QStringList room_information;
    if(selected_room->currentText() == ""){
        room_information.push_back(QString("empty"));
    }else{
        room_information = selected_room->currentText().split(QString(" - "));
    }
    return room_information;
}
