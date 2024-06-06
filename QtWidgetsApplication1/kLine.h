#pragma once


#include <QObject>

#include "kshape.h"

class KLine : public KShape
{
	Q_OBJECT

public:
	KLine(QObject* parent = Q_NULLPTR);
	~KLine();
	virtual void drawShape(QPaintDevice* parent = Q_NULLPTR) override;
};


#pragma once
