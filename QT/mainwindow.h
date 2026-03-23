#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_reset_clicked();

    void on_sumbit_clicked();

    // void on_bt_addiction_clicked();

    // void on_arr_1_textChanged(const QString &arg1);

    // void on_arg1_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    // size_t counter_ = 0;
};
#endif // MAINWINDOW_H
