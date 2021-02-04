#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QtQml/qqml.h>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(int shoeSize READ shoeSize WRITE setShoeSize)
    //QML_ELEMENT
public:
    Person(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &);

    int shoeSize() const;
    void setShoeSize(int);
private:
    QString m_name;
    int m_shoeSize;
};

#endif // PERSON_H
