#include "amp.h"
#include "cardform.h"

#include <QLabel>

AmP::AmP(QString f, QString s, QString l, Date b)
    : R(l, f, b), secondName(s)
{}

QString AmP::getFullName() const
{
    return firstName + " " + secondName + " " + lastName;
}

void AmP::Craft(CardForm *form)
{
    form->findChild<QLabel*>("nameLabel")->setText(getFullName());
    form->findChild<QLabel*>("dateLabel")->setText(birth.toString());
}
QString AmP::getMiddleName() const {
    return ""; // у американского варианта нет отчества
}