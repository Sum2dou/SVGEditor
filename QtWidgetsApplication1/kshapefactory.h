#pragma once
#ifndef __K_SHAPE_FACTORY_H_
#define __K_SHAPE_FACTORY_H_

#include <QObject>
#include "krect.h"
#include "kcanvas.h"

#include "kline.h"

#include "kelli.h"
#include "kpoly.h"

class KShapeFactory : public QObject
{
	Q_OBJECT

public:
	KShapeFactory(QObject* parent);
	~KShapeFactory();
	static KShape* createShape(KCanvas::KDrawFlag drawFlag);
};

#endif