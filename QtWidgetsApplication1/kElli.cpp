#include "kelli.h"

KElli::KElli(QObject* parent)
	: KShape(parent)
{
}

KElli::~KElli()
{
}

void KElli::drawShape(QPaintDevice* parent)
{
	QPainter painter(parent);
	painter.drawEllipse(QRect(getStartPoint(), getEndPoint()));
}
