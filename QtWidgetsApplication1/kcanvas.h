#pragma once
#ifndef __K_CANVAS_H_
#define __K_CANVAS_H_

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

#include "kshape.h"

class KCanvas : public QWidget
{
	Q_OBJECT

public:
	enum class KDrawFlag
	{
		NoneDrawFlag = 0,
		MouseDrawFlag,
		PenDrawFlag,
		LineDrawFlag,
		RectDrawFlag,
		CircleDrawFlag,
		SelectFlag,
		TextDrawFlag,
		PolyDrawFlag
	};

	KCanvas(QWidget* parent);
	~KCanvas();

	virtual void paintEvent(QPaintEvent* event) override;
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
	void setSelectionMode(bool enabled);

	void updateCurrentDrawingFlag(KDrawFlag drawFlag);

private:
	KShape* m_pCurrentShape = Q_NULLPTR;
	QList<KShape*>* m_pShapeList = Q_NULLPTR;
	QList<KShape*> m_selectedShapes;
	QPoint m_lastPos;
	bool m_isDrawing = false;
	bool m_selectionMode = false;
	KDrawFlag m_drawFlag = KDrawFlag::NoneDrawFlag;
	bool m_isLeftButtonPressed = false;
};

#endif
