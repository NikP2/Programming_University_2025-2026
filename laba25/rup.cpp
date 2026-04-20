#include "rup.h"
#include "cardform.h"

#include <QLabel>

RuP::RuP(QString l, QString f, QString m, Date b)
    : R(l, f, b), middleName(m)
{}

QString RuP::getFullName() const
{
    return lastName + " " + firstName + " " + middleName;
}

void RuP::Craft(CardForm *form)
{
    form->findChild<QLabel*>("nameLabel")->setText(getFullName());
    form->findChild<QLabel*>("dateLabel")->setText(birth.toString());
}

QString RuP::getMiddleName() const {
    return middleName;
}