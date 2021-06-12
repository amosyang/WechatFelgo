#include <QApplication>
#include <FelgoApplication>

#include "controllers/chatscontroller.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>

// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
//#include <FelgoLiveClient>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FelgoApplication felgo;

    // Use platform-specific fonts instead of Felgo's default font
    felgo.setPreservePlatformFonts(true);

    QQmlApplicationEngine engine;
    felgo.initialize(&engine);

    ChatsController chatsController;
    chatsController.prepend(new ChatItem("../../../assets/logo-showcase.png",
                                         "Group1",
                                         "Message1",
                                         2021,
                                         false,
                                         0));
    chatsController.prepend(new ChatItem("../../../assets/logo-showcase.png",
                                         "Group2",
                                         "Message2",
                                         2021,
                                         false,
                                         0));
    chatsController.prepend(new ChatItem("../../../assets/logo-showcase.png",
                                         "Group3",
                                         "Message3",
                                         2021,
                                         false,
                                         0));
    chatsController.prepend(new ChatItem("../../../assets/logo-showcase.png",
                                         "Group4",
                                         "Message4",
                                         2021,
                                         false,
                                         0));
    chatsController.prepend(new ChatItem("../../../assets/logo-showcase.png",
                                         "Group5",
                                         "Message5",
                                         2021,
                                         false,
                                         0));
    chatsController.prepend(new ChatItem("../../../assets/logo-showcase.png",
                                         "Group6",
                                         "Message6",
                                         2021,
                                         false,
                                         2));
    engine.rootContext()->setContextProperty("chatsController",
                                             &chatsController);

    // Set an optional license key from project file
    // This does not work if using Felgo Live, only for Felgo Cloud Builds and
    // local builds
    felgo.setLicenseKey(PRODUCT_LICENSE_KEY);

    // use this during development
    // for PUBLISHING, use the entry point below
    //  felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

    // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
    // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
    // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
    // also see the .pro file for more details
    felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

    engine.load(QUrl(felgo.mainQmlFileName()));

    // to start your project as Live Client, comment (remove) the lines "felgo.setMainQmlFileName ..." & "engine.load ...",
    // and uncomment the line below
    //FelgoLiveClient client (&engine);

    return app.exec();
}
