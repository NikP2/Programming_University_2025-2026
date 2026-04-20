#pragma once
#include <QString>

struct Date {
    int d;
    int m;
    int y;

    QString toString() const {
        return QString("%1.%2.%3")
        .arg(d, 2, 10, QChar('0'))
            .arg(m, 2, 10, QChar('0'))
            .arg(y);
    }
};