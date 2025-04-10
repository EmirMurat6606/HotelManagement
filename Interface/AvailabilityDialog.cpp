//
// Created by 2005e on 29/08/2024.
//

#include "AvailabilityDialog.h"
#include "../Headers/Hotel.h"
#include "../Headers/Visitor.h"
#include "../Headers/Room.h"


AvailabilityDialog::AvailabilityDialog(QWidget *parent) {
    setMinimumSize(1080, 1080);
    setWindowTitle("Available Rooms");
    hotel = nullptr;
}

AvailabilityDialog::~AvailabilityDialog() {}

void AvailabilityDialog::createGraphicsView() {

    this->setStyleSheet("background-color: #FFFFF0;");

    QGridLayout *layout = new QGridLayout(this);

    for (Room *room: hotel->getRooms()) {
        QPushButton *button = new QPushButton(QString::fromStdString(room->getName() + "\n" + room->getNumber()));
        if (room->isOccupied()) {
            button->setStyleSheet("border: 5px solid black; color: red;");
        } else {
            button->setStyleSheet("border: 5px solid black; color: green;");
        }
        buttons.emplace_back(std::make_pair(button, room));
    }

    int column_counter = 0;
    int row_counter = 0;

    for (std::pair<QPushButton*, Room*> pair : buttons) {
        if (column_counter == 2) {
            column_counter = 0;
            row_counter++;
        }
        layout->addWidget(pair.first, row_counter, column_counter);
        column_counter++;
    }

}

void AvailabilityDialog::setHotel(Hotel *hotel) {
    AvailabilityDialog::hotel = hotel;
}


void AvailabilityDialog::createEvents() {
    for(std::pair<QPushButton*, Room*> pair: buttons){
        QObject::connect(pair.first, &QPushButton::clicked, this, [this, room=pair.second]() { toRoomInformation(room); });
    }
}

void AvailabilityDialog::toRoomInformation(Room *room) {
    QMessageBox info_box = QMessageBox(this);
    info_box.setFixedSize(100,50);
    info_box.setWindowTitle(QString("Visitor Information"));

    QFont box_font;
    box_font.setFamily(QString("Arial"));
    box_font.setPointSize(18);

    info_box.setFont(box_font);

    if (room->isOccupied()) {
        info_box.setInformativeText(QString::fromStdString(room->getVisitor()->printInfo()));
    } else {
        info_box.setInformativeText(QString("Room is available, no visitor info!"));
    }

    info_box.exec();
}
