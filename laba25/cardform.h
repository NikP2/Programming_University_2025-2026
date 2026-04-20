#pragma once

#include <QWidget>
#include "r.h"

namespace Ui {
class CardForm;
}

class CardForm : public QWidget {
    Q_OBJECT

public:
    explicit CardForm(QWidget *parent = nullptr);
    ~CardForm();

    void setPerson(R* p);

signals:
    void removePerson(R* p);

private slots:
    void on_printButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CardForm *ui;
    R* person;
};