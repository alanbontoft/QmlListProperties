#ifndef QVLPARTY_H
#define QVLPARTY_H

#include <QObject>
#include <QVariantList>

#include "person.h"

class QvlParty : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantList guests READ guests)
public:
    explicit QvlParty(QObject *parent = nullptr);

    void addGuest(Person *person) { _guests.append(QVariant::fromValue(person)); }

    QVariantList guests() { return _guests; }

signals:

private:
    QVariantList _guests;

};

#endif // QVLPARTY_H
