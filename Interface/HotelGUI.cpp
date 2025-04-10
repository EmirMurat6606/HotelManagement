//
// Created by 2005e on 27/08/2024.
//

#include "HotelGUI.h"
#include "../Headers/Hotel.h"
#include "../Headers/BigSuite.h"
#include "../Headers/Comfort.h"
#include "../Headers/Suite.h"
#include <QPropertyAnimation>

HotelGUI::HotelGUI(QWidget *parent) {

    setFixedSize(1920, 1080);
    setWindowTitle(QString("HotelManagement"));
    createGraphicsView();
    createEvents();
    startHomeAnimation();
    initializeHotels();
    initializeChooseDialog();
}

HotelGUI::~HotelGUI() noexcept {
    for (Hotel * hotel : hotels){
        delete hotel;
    }
}

void HotelGUI::createEvents() const {

    QObject::connect(animation_group, SIGNAL(finished()), animation_group, SLOT(start()));

    QObject::connect(entry_button, SIGNAL(clicked()), this, SLOT(toChooseDialog()));
}

void HotelGUI::createGraphicsView() {

    animation_group = new QSequentialAnimationGroup(this);

    QGraphicsView* graphics_view = new QGraphicsView(this);
    graphics_view->setGeometry(0, 0, 1920, 1080);
    graphics_view->setStyleSheet("background-color: #F5F5DC;");
    graphics_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphics_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsScene * graphics_scene = new QGraphicsScene(this);
    graphics_view->setScene(graphics_scene);

    PixmapItem * image1 = new PixmapItem(QPixmap("../Images/HomepageFirst.png"));
    PixmapItem * image2 = new PixmapItem(QPixmap("../Images/HomepageSecond.png"));
    PixmapItem * image3 = new PixmapItem(QPixmap("../Images/HomepageThird.png"));

    images.append(image1);
    images.append(image2);
    images.append(image3);

    for(PixmapItem * image: images){
        graphics_scene->addItem(image);
        image->setOpacity(0);
    }

    for(int i = 0; i < images.size(); ++i) {
        QPropertyAnimation *fadeIn = new QPropertyAnimation(images[i], "opacity");
        fadeIn->setDuration(1000);
        fadeIn->setStartValue(0);
        fadeIn->setEndValue(1);

        QPropertyAnimation *fadeOut = new QPropertyAnimation(images[i], "opacity");
        fadeOut->setDuration(1000);
        fadeOut->setStartValue(1);
        fadeOut->setEndValue(0);

        animation_group->addAnimation(fadeIn);
        animation_group->addPause(4000);
        animation_group->addAnimation(fadeOut);
    }

    QFont button_font("Italic", 10);

    entry_button = new QPushButton("Home", graphics_view);
    entry_button->setGeometry(872, 485, 225, 110);
    entry_button->setStyleSheet("background-color: #FFF5EE;");
    entry_button->setToolTip("Click to check in/out");
    entry_button->setFont(button_font);
}

void HotelGUI::pauseHomeAnimation() {
    animation_group->pause();
}

void HotelGUI::startHomeAnimation() {
    animation_group->start();
}

void HotelGUI::toChooseDialog() {
    pauseHomeAnimation();
    choose_dialog->show();
    this->close();
}

void HotelGUI::initializeChooseDialog() {
    choose_dialog = new ChooseDialog(hotels, this);
}

void HotelGUI::resumeHomeAnimation() {
    animation_group->resume();
}

void HotelGUI::initializeHotels() {

    // Initialization of the PlazaHotel object
    Hotel * PlazaHotel = new Hotel("PlazaHotel");

    Comfort* PL_room_001 = new Comfort("Urban Oasis", "001");
    Comfort * PL_room_002 = new Comfort("Horizon Haven", "002");
    Suite * PL_room_003 = new Suite("Skyline Suite", "003");
    Comfort * PL_room_104 = new Comfort("Serenity Cove", "104");
    Comfort * PL_room_105 = new Comfort("Tranquil Retreat", "105");
    Suite * PL_room_106 = new Suite("Elegance Suite", "106");
    BigSuite * PL_room_207 = new BigSuite("Grand Plaza Suite", "207");

    PlazaHotel->addRoom(PL_room_001);
    PlazaHotel->addRoom(PL_room_002);
    PlazaHotel->addRoom(PL_room_003);
    PlazaHotel->addRoom(PL_room_104);
    PlazaHotel->addRoom(PL_room_105);
    PlazaHotel->addRoom(PL_room_106);
    PlazaHotel->addRoom(PL_room_207);

    // Initialization of the PalmVillage object

    Hotel * PalmVillage = new Hotel("PalmVillage");

    Comfort * PA_room_001 = new Comfort("Coconut Cove", "001");
    Suite * PA_room_002 = new Suite("Sunset Suite", "002");
    Comfort * PA_room_103 = new Comfort("Tropical Breeze", "103");
    Suite * PA_room_104 = new Suite("Palm Grove Suite", "104");
    BigSuite * PA_room_205 = new BigSuite("Paradise Retreet", "205");

    PalmVillage->addRoom(PA_room_001);
    PalmVillage->addRoom(PA_room_002);
    PalmVillage->addRoom(PA_room_103);
    PalmVillage->addRoom(PA_room_104);
    PalmVillage->addRoom(PA_room_205);

    // Add the hotels to the the vector hotels
    hotels.push_back(PlazaHotel);
    hotels.push_back(PalmVillage);
}

ChooseDialog::ChooseDialog(std::vector<Hotel*>& hotels, HotelGUI *parent) : hotels(hotels) {
    this->setFixedSize(1920, 1080);
    this->setWindowTitle("HotelManagement");
    home_page = parent;
    createGraphicsView();
    createEvents();
}

ChooseDialog::~ChooseDialog() {}

void ChooseDialog::createGraphicsView() {

    QGraphicsView * background_view = new QGraphicsView(this);
    background_view->setGeometry(0, 0, 1920, 1080);
    background_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    background_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    background_view->setStyleSheet(QString("background-color: #F5F5DC;"));

    QPixmap plaza_pixmap = QPixmap("../Images/HomepageThird.png");
    QPixmap palm_pixmap = QPixmap("../Images/HomepageFirst.png");

    plaza_pixmap = plaza_pixmap.scaled(QSize(960, 1080), Qt::KeepAspectRatio);
    palm_pixmap = palm_pixmap.scaled(QSize(960, 1080), Qt::KeepAspectRatio);

    PixmapItem * plaza_image = new PixmapItem(plaza_pixmap);
    PixmapItem * palm_image = new PixmapItem(palm_pixmap);

    palm_image->setPos(plaza_pixmap.width(), 0);

    QGraphicsScene *  background_scene = new QGraphicsScene(background_view);
    background_scene->addItem(plaza_image);
    background_scene->addItem(palm_image);

    background_view->setScene(background_scene);

    background_scene->setSceneRect(0, 0, plaza_image->width() + palm_image->width(), qMax(plaza_image->height(), palm_image->height()));

    // Stel de grootte van de view in
    background_view->setSceneRect(background_scene->sceneRect());
    resize(plaza_image->width() + palm_image->width(), qMax(plaza_image->height(), palm_image->height()));

    QFont button_font("Italic", 10);

    QPushButton * plaza_hotel_button = new QPushButton("PlazaHotel", background_view);
    plaza_hotel_button->setGeometry(405,515,150,50);
    plaza_hotel_button->setObjectName("PlazaHotelButton");

    QPushButton * palm_village_button = new QPushButton("Palm Village", background_view);
    palm_village_button->setGeometry(1365, 515, 150, 50);
    palm_village_button->setObjectName("PalmVillageButton");

    plaza_hotel_button->setFont(button_font);
    palm_village_button->setFont(button_font);

    entry_buttons.push_back(plaza_hotel_button);
    entry_buttons.push_back(palm_village_button);

    back_button = new QPushButton(background_view);
    QIcon back_arrow = QIcon("../Images/BackArrow.png");
    back_button->setIcon(back_arrow);
    back_button->setIconSize(QSize(50,50));
    back_button->setFlat(true);

}

void ChooseDialog::createEvents() const {
    QObject::connect(back_button, SIGNAL(clicked()), this, SLOT(backToHome()));

    for (QPushButton * button : entry_buttons){
        QObject::connect(button, SIGNAL(clicked()), this, SLOT(toOptionWindow()));
    }
}

void ChooseDialog::backToHome() {
    this->close();
    home_page->show();
    home_page->resumeHomeAnimation();
}

void ChooseDialog::toOptionWindow() const{

    QPushButton * pressed_button = qobject_cast<QPushButton*>(sender());
    OptionDialog * option_dialog = new OptionDialog();

    if(pressed_button->objectName() == "PlazaHotelButton") {
        for(Hotel * hotel: hotels){
            if (hotel->getName() == "PlazaHotel"){
                option_dialog->setHotel(hotel);
                option_dialog->setWindowTitle("PlazaHotel");
            }
        }
    }else if (pressed_button->objectName() == "PalmVillageButton"){
        for(Hotel * hotel: hotels){
            if (hotel->getName() == "PalmVillage"){
                option_dialog->setHotel(hotel);
                option_dialog->setWindowTitle("PalmVillage");
            }
        }
    }
    option_dialog->exec();
}


