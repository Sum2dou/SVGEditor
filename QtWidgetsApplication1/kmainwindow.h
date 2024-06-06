#pragma once

#include <QtWidgets/QMainWindow>
#ifndef __K_MAINWINDOW_H_
#define __K_MAINWINDOW_H_

#include <QtWidgets/QMainWindow>
#include "ui_kmainwindow.h"
#include "kcanvas.h"

class KMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    KMainWindow(QWidget* parent = Q_NULLPTR);

    void onDrawRectBtnClicked();
    void onDrawLineBtnClicked();
    void onDrawEllipseBtnClicked();
    void onDrawPolyBtnClicked();
    void onSelectButtonClicked();

signals:
    void onDrawingFlagChanged(KCanvas::KDrawFlag drawFlag);
private:
    Ui::KMainWindowClass ui;
};

#endif
