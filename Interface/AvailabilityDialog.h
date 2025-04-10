//
// Created by 2005e on 29/08/2024.
//

#ifndef HOTELMANAGEMENT_AVAILABILITYDIALOG_H
#define HOTELMANAGEMENT_AVAILABILITYDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>

class Hotel;
class Room;

class AvailabilityDialog : public QDialog {
Q_OBJECT
public:

    AvailabilityDialog(QWidget *parent = 0);

    ~AvailabilityDialog() override;

    void setHotel(Hotel *hotel);

private:

    Hotel *hotel;

    std::vector<std::pair<QPushButton *, Room*>> buttons;

public:

    void createGraphicsView();

    void createEvents();

signals:
private slots:

    void toRoomInformation(Room *room);

};


#endif //HOTELMANAGEMENT_AVAILABILITYDIALOG_H
