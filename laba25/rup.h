#pragma once
#include "r.h"

class RuP : public R {
    QString middleName;

public:
    RuP(QString l, QString f, QString m, Date b);

    QString getFullName() const override;
    void Craft(CardForm* form) override;
    QString getMiddleName() const override;
};