#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "rup.h"
#include "amp.h"
#include "cardform.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    for (auto p : people)
        delete p;
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл");

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    // очищаем старые данные
    for (auto p : people) delete p;
    people.clear();

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        if (line.isEmpty())
            continue;

        QStringList parts = line.split(",");

        if (parts.size() < 7)
            continue;

        int code = parts[0].toInt();

        if (code == 1) {
            // 1,Фамилия,Имя,Отчество,д,м,г
            QString l = parts[1];
            QString f = parts[2];
            QString m = parts[3];

            int d  = parts[4].toInt();
            int mo = parts[5].toInt();
            int y  = parts[6].toInt();

            people.push_back(new RuP(l, f, m, {d, mo, y}));
        }
        else if (code == 2) {
            // 2,Имя,Имя2,Фамилия,м,д,г
            QString f = parts[1];
            QString s = parts[2];
            QString l = parts[3];

            int mo = parts[4].toInt();
            int d  = parts[5].toInt();
            int y  = parts[6].toInt();

            people.push_back(new AmP(f, s, l, {d, mo, y}));
        }
    }

    updateTable();
}

void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(static_cast<int>(people.size()));

    for (int i = 0; i < (int)people.size(); i++) {

        ui->tableWidget->setItem(i, 0,
                                 new QTableWidgetItem(people[i]->getLastName()));

        ui->tableWidget->setItem(i, 1,
                                 new QTableWidgetItem(people[i]->getFirstName()));

        QString middle = people[i]->getMiddleName();
        if (middle.isEmpty())
            middle = "-";

        ui->tableWidget->setItem(i, 2,
                                 new QTableWidgetItem(middle));

        ui->tableWidget->setItem(i, 3,
                                 new QTableWidgetItem(people[i]->getDate()));
    }
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int)
{
    if (row < 0 || row >= (int)people.size())
        return;

    CardForm *form = new CardForm();

    connect(form, &CardForm::removePerson,
            this, &MainWindow::removePerson);

    form->setPerson(people[row]);
    form->show();
}

void MainWindow::removePerson(R *p)
{
    auto it = std::find(people.begin(), people.end(), p);

    if (it != people.end()) {
        delete *it;
        people.erase(it);
    }

    updateTable();
}