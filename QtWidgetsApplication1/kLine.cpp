#include "kline.h"

KLine::KLine(QObject* parent)
	: KShape(parent)
{
}

KLine::~KLine()
{
}

void KLine::drawShape(QPaintDevice* parent)
{
	QPainter painter(parent);
	painter.drawLine(getStartPoint(), getEndPoint());
}
