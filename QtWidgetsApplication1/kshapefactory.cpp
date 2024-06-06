#include "kshapefactory.h"

KShapeFactory::KShapeFactory(QObject* parent)
	: QObject(parent)
{
}

KShapeFactory::~KShapeFactory()
{
}

KShape* KShapeFactory::createShape(KCanvas::KDrawFlag drawFlag)
{
	switch (drawFlag)
	{
	case KCanvas::KDrawFlag::RectDrawFlag:
		return new KRect;
	case KCanvas::KDrawFlag::LineDrawFlag:
		return new KLine;
	case KCanvas::KDrawFlag::CircleDrawFlag:
		return new KElli;
	case KCanvas::KDrawFlag::PolyDrawFlag:
		return new KPoly;
	default:
		break;
	}
}
