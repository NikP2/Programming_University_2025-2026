#pragma once
#include "r.h"

class AmP : public R {
    QString secondName;

public:
    AmP(QString f, QString s, QString l, Date b);
    QString getMiddleName() const override;
    QString getFullName() const override;
    void Craft(CardForm* form) override;
};