#include "kshape.h"

KShape::KShape(QObject* parent)
	: QObject(parent)
{
}

KShape::~KShape()
{
}

QPoint KShape::getStartPoint() const
{
	return m_startPoint;
}

QPoint KShape::getEndPoint() const
{
	return m_endPoint;
}

void KShape::setStartPoint(const QPoint& point)
{
	m_startPoint = point;
}

void KShape::setEndPoint(const QPoint& point)
{
	m_endPoint = point;
}

bool KShape::isShapeVaild() const
{
	return (m_startPoint.x() != m_endPoint.x() || m_startPoint.y() != m_endPoint.y());
}

// getBoundingRect 函数
QRect KShape::getBoundingRect() const
{
	// 返回矩形的边界矩形
	return QRect(getStartPoint(), getEndPoint());
}
