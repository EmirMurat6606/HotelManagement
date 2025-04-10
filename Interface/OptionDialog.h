//
// Created by 2005e on 29/08/2024.
//

#ifndef HOTELMANAGEMENT_OPTIONDIALOG_H
#define HOTELMANAGEMENT_OPTIONDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <vector>
#include <QVBoxLayout>
#include <QSize>
#include "CheckInDialog.h"
#include "CheckOutDialog.h"
#include "AvailabilityDialog.h"

class Hotel;

class OptionDialog: public QDialog{
    Q_OBJECT
public:

    OptionDialog(QWidget *parent = 0);

    ~OptionDialog() override;

    void setHotel(Hotel *hotel);

    void setOptionButtons(const std::vector<QPushButton *> &optionButtons);

    static const QMetaObject &getStaticMetaObject();

    Hotel *getHotel() const;

    const std::vector<QPushButton *> &getOptionButtons() const;

private:

    Hotel *hotel;

    std::vector<QPushButton *> option_buttons;

private:

    void createGraphicsView();

    void createEvents() const;


    signals:
private slots:

    void toCheckIn();

    void toCheckOut();

    void toAvailability();


};


#endif //HOTELMANAGEMENT_OPTIONDIALOG_H
