#include "cardform.h"
#include "ui_cardform.h"

#include <QPixmap>
#include <QLabel>
#include <cstdlib>

CardForm::CardForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CardForm)
    , person(nullptr)
{
    ui->setupUi(this);
}

CardForm::~CardForm()
{
    delete ui;
}

void CardForm::setPerson(R *p)
{
    person = p;

    // заполнение через полиморфизм
    p->Craft(this);

    // рандомная картинка
    int r = rand() % 3 + 1;

    QLabel* img = findChild<QLabel*>("imageLabel");
    if (img) {
        img->setPixmap(QPixmap(QString("img_res/%1.png").arg(r)));
        img->setScaledContents(true);
    }
}

void CardForm::on_cancelButton_clicked()
{
    close();
}

void CardForm::on_printButton_clicked()
{
    emit removePerson(person);
    close();
}