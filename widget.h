#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void changeMoney(int n);
    int money{0};
    int money_nmg{0};
    int obaek{0};
    int obaek_nmg{0};
    int baek{0};
    int baek_nmg{0};
    int osip{0};
    int osip_nmg{0};
    int sip{0};



private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb500_clicked();

    void on_pb100_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbGongcha_clicked();

    void on_pbexchange_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
