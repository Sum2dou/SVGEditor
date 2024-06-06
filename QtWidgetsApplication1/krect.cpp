#include "krect.h"

KRect::KRect(QObject* parent)
	: KShape(parent)
{
}

KRect::~KRect()
{
}

void KRect::drawShape(QPaintDevice* parent)
{
	QPainter painter(parent);
	painter.drawRect(QRect(getStartPoint(), getEndPoint()));
}
