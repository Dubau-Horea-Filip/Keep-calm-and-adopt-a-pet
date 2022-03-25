#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_A89.h"

class A89 : public QMainWindow
{
    Q_OBJECT

public:
    A89(QWidget *parent = Q_NULLPTR);

private:
    Ui::A89Class ui;
};
