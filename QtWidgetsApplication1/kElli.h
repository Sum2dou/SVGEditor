#pragma once


#include <QObject>

#include "kshape.h"

class KElli : public KShape
{
	Q_OBJECT

public:
	KElli(QObject* parent = Q_NULLPTR);
	~KElli();
	virtual void drawShape(QPaintDevice* parent = Q_NULLPTR) override;
};


#pragma once
#pragma once
