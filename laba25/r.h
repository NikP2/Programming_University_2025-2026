#pragma once

#include <QString>
#include "date.h"

class CardForm;

class R {
protected:
    QString lastName;
    QString firstName;
    Date birth;

public:
    R(QString l, QString f, Date b)
        : lastName(l), firstName(f), birth(b) {}

    virtual ~R() {}

    QString getLastName() const { return lastName; }
    QString getFirstName() const { return firstName; }
    QString getDate() const { return birth.toString(); }

    virtual QString getFullName() const = 0;
    virtual void Craft(CardForm* form) = 0;
    virtual QString getMiddleName() const = 0;
};