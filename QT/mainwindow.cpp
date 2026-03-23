#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QStandardPaths>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->radio_machine1->setChecked(true);
    ui->lineEdit_marka->setInputMask(">AAAAAAAAAAAAAAAAA"); // > заглавные буквы
    ui->lineEdit_year->setInputMask("0000");
    ui->lineEdit_gos_number->setInputMask(">A000AA000"); // 101 и 111
    ui->lineEdit_marka->setStyleSheet("QLineEdit { border-radius: 3px; background-color: rgba(255, 255, 255, 0.1); border: 0.5px solid #fff};");
    ui->lineEdit_model->setStyleSheet("QLineEdit { border-radius: 3px; background-color: rgba(255, 255, 255, 0.1); border: 0.5px solid #fff};");
    ui->lineEdit_gos_number->setStyleSheet("QLineEdit { border-radius: 3px; background-color: rgba(255, 255, 255, 0.1); border: 0.5px solid #fff};");
    ui->lineEdit_year->setStyleSheet("QLineEdit { border-radius: 3px; background-color: rgba(255, 255, 255, 0.1); border: 0.5px solid #fff};");

    ui->reset->setStyleSheet("QPushButton {"
                             "background-color: red;"
                             "border-radius: 5px"
                             "}"
                             "QPushButton:hover {"
                             "color:black;"
                             "font-weight: 600;"
                             "}");
    ui->sumbit->setStyleSheet("QPushButton {"
                              "background-color: green;"
                              "border-radius: 5px"
                              "}"
                              "QPushButton:hover {"
                              "color:black;"
                              "font-weight: 600;"
                              "}");

}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::on_bt_addiction_clicked()
// {
    // QString qa = ui->arg1->text(); // ui - наш графический интерфейс / arg1 - наш элемент в этом интерфейсе / text() - функция arg1
    // int a = qa.toInt();
    // QString qb = ui->arg1->text();
    // int b = qb.toInt();
    // int c = a + b;
    // QString qc = QString::number(c);
    // ui->result->setText(qc);

// void MainWindow::on_arg1_textChanged(const QString &arg1)
// {
//     qInfo()<< arg1;
// }




void MainWindow::on_reset_clicked()
{
    ui->lineEdit_marka->clear();
    ui->lineEdit_gos_number->clear();
    ui->lineEdit_model->clear();
    ui->lineEdit_year->clear();
    ui->radio_machine1->setChecked(false);
    ui->radio_machine2->setChecked(false);
    ui->checkBox_extra1->setChecked(false);
    ui->checkBox_extra2->setChecked(false);
    ui->checkBox_extra3->setChecked(false);


}


void MainWindow::on_sumbit_clicked()
{
    QString marka = ui->lineEdit_marka->text().trimmed(); //trimmed() - удаляет всю тамбуляцию
    QString model = ui->lineEdit_model->text().trimmed();
    QString year = ui->lineEdit_year->text().trimmed();
    QString gos_number = ui->lineEdit_gos_number->text().trimmed();
    if(marka.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Марка' не заполнено");
        return;
    }
    if(model.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Модель' не заполнено'");
        return;
    }
    if(year.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Год' не заполнено'");
        return;
    }
    if(gos_number.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Гос.Номер' не заполнено'");
        return;
    }
    if(gos_number.length() != 8 && gos_number.length() != 9) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Гос.Номер' должно содержать 8 или 9 символов");
        return;
    }

    QString valid_letters = "АВЕКМНОРСТУХ";
    if(gos_number.length() >= 8) {
        QChar letter1 = gos_number[0];
        QChar letter2 = gos_number[4];
        QChar letter3 = gos_number[5];
        if(!valid_letters.contains(letter1) || !valid_letters.contains(letter2) || !valid_letters.contains(letter3)){
            QMessageBox::warning(this, "Ошибка", "Поле 'Гос.Номер' содержит недопустимые символы");
            return;
        }
        // contains - проверяет наличие элемента
    }

    if(gos_number.length() == 8) {
        QString region = gos_number.mid(6, 2); //mid(6, 2) - 6 (индекс нач элемента), 2 - кол-во элементов после начального (включительно)
        bool fl;
        region.toInt(&fl);
        if(!fl) {
            QMessageBox::warning(this, "Ошибка", "Поле 'Гос.Номер' должен заканчиваться цифрами");
            return;
        }
    }
    else if(gos_number.length() == 9) {
        QString region = gos_number.mid(6, 3);
        if(region != "101" && region != "111") {
            QMessageBox::warning(this, "Ошибка", "Поле 'Гос.Номер' недопустимый регион");
            return;
        }
    }
    if(!ui->radio_machine1->isChecked() && !ui->radio_machine2->isChecked()) {
        QMessageBox::warning(this, "Ошибка", "Выберите тип двигателя");
        return;
    }

    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QFile file(desktopPath + "/result.txt");
    if(file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out (&file);
        out << "Марка: " << marka << "\n";
        out << "Модель: " << model << "\n";
        out << "Год выпуска: " << year << "\n";
        out << "Гос. номер: " << gos_number << "\n";

        if(ui->radio_machine1->isChecked())
            out << "Двигатель: Бензин\n";
        else
            out << "Двигатель: Дизель\n";

        if(ui->checkBox_extra1->isChecked())
            out << "Подогрев сидений\n";
        if(ui->checkBox_extra2->isChecked())
            out << "Парктроники\n";
        if(ui->checkBox_extra3->isChecked())
            out << "Коврики\n";

        file.close();

        QMessageBox::information(this, "Выполнено", "Данные сохранены в файл result.txt");
        on_reset_clicked();
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл :(");
    }
}


