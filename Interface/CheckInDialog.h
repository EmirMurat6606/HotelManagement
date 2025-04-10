//
// Created by 2005e on 29/08/2024.
//

#ifndef HOTELMANAGEMENT_CHECKINDIALOG_H
#define HOTELMANAGEMENT_CHECKINDIALOG_H

#include "QDialog"
#include "QCloseEvent"
#include "QLabel"
#include "QLineEdit"
#include "QGridLayout"
#include "QPushButton"
#include "QComboBox"

class Hotel;

class CheckInDialog : public QDialog {
Q_OBJECT
public:

    CheckInDialog(QWidget *parent = 0);

    ~CheckInDialog() override;

    void setHotel(Hotel *hotel);

    void createGraphicsView();

    void createEvents() const;

private:

    Hotel *hotel;

    QLineEdit *first_name;

    QLineEdit *last_name;

    QLineEdit *phone_number;

    QLineEdit *register_number;

    QPushButton *apply_button;

    QPushButton *cancel_button;

    QComboBox *selected_room;

private:

    void closeEvent(QCloseEvent *event) override;

    void createHotelSelectionbar();

    QStringList splitUpRoomInfo() const;


signals:
private slots:

    void cancelRegistration();

    void saveRegistration();

};


#endif //HOTELMANAGEMENT_CHECKINDIALOG_H
