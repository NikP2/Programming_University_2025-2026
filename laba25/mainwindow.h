#pragma once

#include <QWidget>
#include <vector>
#include "r.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadButton_clicked();
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void removePerson(R* p);

private:
    Ui::MainWindow *ui;
    std::vector<R*> people;

    void updateTable();
};