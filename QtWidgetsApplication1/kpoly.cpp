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
    QPointF startPoint = getStartPoint(); // 获取起点坐标
    QPointF endPoint = getEndPoint(); // 获取终点坐标

    // 计算矩形的左上角和右下角坐标
    qreal left = qMin(startPoint.x(), endPoint.x());
    qreal top = qMin(startPoint.y(), endPoint.y());
    qreal width = qAbs(endPoint.x() - startPoint.x());
    qreal height = qAbs(endPoint.y() - startPoint.y());

    // 获取矩形的中心点
    qreal centerX = left + width / 2;
    qreal centerY = top + height / 2;

    // 计算外部圆的半径
    qreal radius = qMin(width, height) / 2;
    qreal innerRadius = radius * 0.382; // 内部圆的半径

    const qreal pi = 3.1415926; // 定义 pi 值
    qreal angle = pi / 2; // 初始角度
    QPointF points[5]; // 存储五个顶点的坐标

    for (int i = 0; i < 5; ++i) {
        points[i] = QPointF(centerX + radius * qCos(angle), centerY - radius * qSin(angle));
        angle += 2 * pi / 5;
    }

    painter.drawPolygon(points, 5); //绘制五边形
}
