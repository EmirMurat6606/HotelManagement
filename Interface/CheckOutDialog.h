//
// Created by 2005e on 29/08/2024.
//

#ifndef HOTELMANAGEMENT_CHECKOUTDIALOG_H
#define HOTELMANAGEMENT_CHECKOUTDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWindow>
#include <QLineEdit>
#include <QLabel>
#include <vector>

class Hotel;
class Room;

class CheckOutDialog : public QDialog {
    Q_OBJECT
public:

    CheckOutDialog(QWidget *parent = 0);

    ~CheckOutDialog() override;

    void setHotel(Hotel *hotel);

    void createGraphicsView();

    void createEvents();

private:

    Hotel * hotel;

    std::vector<std::pair<QPushButton*, Room*>> buttons;


signals:
private slots:

    void toValidation(Room * room);

};


#endif //HOTELMANAGEMENT_CHECKOUTDIALOG_H
