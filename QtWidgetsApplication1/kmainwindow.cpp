#include "kmainwindow.h"

KMainWindow::KMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    (void)connect(ui.m_pBtnRect, &QPushButton::clicked, this, &KMainWindow::onDrawRectBtnClicked);
    (void)connect(ui.m_pBtnLine, &QPushButton::clicked, this, &KMainWindow::onDrawLineBtnClicked);
    (void)connect(ui.m_pBtnEllipse, &QPushButton::clicked, this, &KMainWindow::onDrawEllipseBtnClicked);
    (void)connect(ui.m_pBtnPoly, &QPushButton::clicked, this, &KMainWindow::onDrawPolyBtnClicked);
    (void)connect(this, &KMainWindow::onDrawingFlagChanged, ui.m_pCanvas, &KCanvas::updateCurrentDrawingFlag);
    connect(ui.m_pBtnSelect, &QPushButton::clicked, this, &KMainWindow::onSelectButtonClicked);

}

void KMainWindow::onDrawRectBtnClicked()
{
    emit onDrawingFlagChanged(KCanvas::KDrawFlag::RectDrawFlag);
}

void KMainWindow::onDrawLineBtnClicked()
{
    emit onDrawingFlagChanged(KCanvas::KDrawFlag::LineDrawFlag);
}

void KMainWindow::onDrawEllipseBtnClicked()
{
    emit onDrawingFlagChanged(KCanvas::KDrawFlag::CircleDrawFlag);
}

void KMainWindow::onDrawPolyBtnClicked()
{
    emit onDrawingFlagChanged(KCanvas::KDrawFlag::PolyDrawFlag);
}
void KMainWindow::onSelectButtonClicked()
{
    ui.m_pCanvas->setSelectionMode(true);
    emit onDrawingFlagChanged(KCanvas::KDrawFlag::SelectFlag);
}
