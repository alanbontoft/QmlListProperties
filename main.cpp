#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>

#include <QQmlComponent>
#include <QDebug>

#include "birthdayparty.h"
#include "person.h"
#include "qvlparty.h"

int main(int argc, char ** argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // hide cursor for touch app
    // QGuiApplication::setOverrideCursor(QCursor(Qt::BlankCursor));

    qmlRegisterUncreatableType<BirthdayParty>("Party", 1, 0, "BirthdayParty", "DataModel is uncreatable type");
    qmlRegisterUncreatableType<Person>("Person", 1, 0, "DataList", "DataList is uncreatable type");

    // declare data model objects
    BirthdayParty party;
    Person *person;
    QvlParty qparty;


    person = new Person();
    person->setName("Bob");
    person->setShoeSize(9);
    party.appendGuest(person);
    qparty.addGuest(person);

    person = new Person();
    person->setName("Paul");
    person->setShoeSize(11);
    party.appendGuest(person);
    qparty.addGuest(person);

    person = new Person();
    person->setName("Derek");
    person->setShoeSize(8);
    party.appendGuest(person);
    qparty.addGuest(person);

    person = new Person();
    person->setName("Jonny");
    person->setShoeSize(10);
    party.appendGuest(person);
    qparty.addGuest(person);

    QQmlApplicationEngine engine;

    // make data models visible to QML
    // engine.rootContext()->setContextProperty("TheParty", &party);
    engine.rootContext()->setContextProperty("TheParty", &qparty);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
