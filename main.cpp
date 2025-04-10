#include <QApplication>
#include "Interface/HotelGUI.h"


// Press the green arrow to run the application
// Do not change code in this file

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    HotelGUI hotel_application;
    hotel_application.show();
    return app.exec();
}
