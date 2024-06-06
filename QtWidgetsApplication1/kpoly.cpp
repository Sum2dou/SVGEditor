#include "kpoly.h"

KPoly::KPoly(QObject* parent)
	: KShape(parent)
{
}

KPoly::~KPoly()
{
}

void KPoly::drawShape(QPaintDevice* parent)
{
	QPainter painter(parent);
    QPointF startPoint = getStartPoint(); // ��ȡ�������
    QPointF endPoint = getEndPoint(); // ��ȡ�յ�����

    // ������ε����ϽǺ����½�����
    qreal left = qMin(startPoint.x(), endPoint.x());
    qreal top = qMin(startPoint.y(), endPoint.y());
    qreal width = qAbs(endPoint.x() - startPoint.x());
    qreal height = qAbs(endPoint.y() - startPoint.y());

    // ��ȡ���ε����ĵ�
    qreal centerX = left + width / 2;
    qreal centerY = top + height / 2;

    // �����ⲿԲ�İ뾶
    qreal radius = qMin(width, height) / 2;
    qreal innerRadius = radius * 0.382; // �ڲ�Բ�İ뾶

    const qreal pi = 3.1415926; // ���� pi ֵ
    qreal angle = pi / 2; // ��ʼ�Ƕ�
    QPointF points[5]; // �洢������������

    for (int i = 0; i < 5; ++i) {
        points[i] = QPointF(centerX + radius * qCos(angle), centerY - radius * qSin(angle));
        angle += 2 * pi / 5;
    }

    painter.drawPolygon(points, 5); //���������
}
