#pragma once
#ifndef __K_SHAPE_H_
#define __K_SHAPE_H_

#include <QObject>
#include <QPoint>
#include <QPainter>
#include <QPaintDevice>

enum class KShapeType
{
	None = 0,
	PenShapeType,
	LineShapeType,
	CircleShapeType,
	RectShapeType,
	PentShapeType,
	HexaShapeType,
	TextShapeType,
};

class KShape : public QObject
{
	Q_OBJECT

public:
	KShape(QObject* parent);
	~KShape();

	virtual void drawShape(QPaintDevice* parent = Q_NULLPTR) = 0;
	QPoint getStartPoint() const;
	QPoint getEndPoint() const;
	//添加一个函数来获取形状的边界矩形
	QRect getBoundingRect() const;
	void setStartPoint(const QPoint& point);
	void setEndPoint(const QPoint& point);

	bool isShapeVaild() const;

private:
	QPoint m_startPoint;
	QPoint m_endPoint;
};

#endif
