#pragma once


#include <QObject>
#include <qmath.h>
#include "kshape.h"

class KPoly : public KShape
{
	Q_OBJECT

public:
	KPoly(QObject* parent = Q_NULLPTR);
	~KPoly();
	virtual void drawShape(QPaintDevice* parent = Q_NULLPTR) override;
};


#pragma once
#pragma once
#pragma once
