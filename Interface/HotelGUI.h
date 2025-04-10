//
// Created by 2005e on 27/08/2024.
//

#ifndef HOTELMANAGEMENT_HOTELGUI_H
#define HOTELMANAGEMENT_HOTELGUI_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSequentialAnimationGroup>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPushButton>
#include <QPropertyAnimation>
#include <vector>
#include "OptionDialog.h"

class Hotel;
class ChooseDialog;

class PixmapItem: public QObject, public QGraphicsPixmapItem, public QPixmap{
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)

public:
    PixmapItem(const QPixmap &pixmap) : QGraphicsPixmapItem(pixmap) {}
};


class HotelGUI: public QMainWindow {
    Q_OBJECT
public:

    explicit HotelGUI(QWidget* parent = 0);

    ~HotelGUI() override;

private:

    std::vector<Hotel*> hotels;

    QPushButton* entry_button;

    QSequentialAnimationGroup* animation_group;

    QList<PixmapItem*> images;

    ChooseDialog * choose_dialog;

public:

    void pauseHomeAnimation();

    void resumeHomeAnimation();

private:

    void startHomeAnimation();

    void createGraphicsView();

    void createEvents() const;

    void initializeChooseDialog();

    void initializeHotels();

signals:
private slots:

    void toChooseDialog();

};

class HotelGUI;

class ChooseDialog: public QMainWindow{
    Q_OBJECT
public:

    ChooseDialog(std::vector<Hotel*> &hotels, HotelGUI *parent = 0);

    ~ChooseDialog() override;

private:

    std::vector<Hotel*> hotels;

    std::vector<QPushButton *> entry_buttons;

    QPushButton * back_button;

    HotelGUI * home_page;

private:

    void createGraphicsView();

    void createEvents() const;

signals:
private slots:

    void backToHome();

    void toOptionWindow() const;


};


#endif //HOTELMANAGEMENT_HOTELGUI_H
