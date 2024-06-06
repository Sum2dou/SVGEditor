#include "kcanvas.h"
#include "kshapefactory.h"

KCanvas::KCanvas(QWidget* parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_StyledBackground, true);
	setMouseTracking(true);//设置鼠标追踪
	setFocusPolicy(Qt::ClickFocus);//单击获取焦点
	m_pShapeList = new QList<KShape*>;
}

KCanvas::~KCanvas()
{
	for (auto shape : *m_pShapeList)
		delete shape;
	m_pShapeList->clear();

	delete m_pShapeList;
}

void KCanvas::paintEvent(QPaintEvent* event)
{
	// 将原来的图形重新绘制
	if (!m_pShapeList->isEmpty())
	{
		for (QList<KShape*>::iterator it = m_pShapeList->begin();
			it != m_pShapeList->end(); ++it)
			(*it)->drawShape(this);
	}

	if (m_pCurrentShape != Q_NULLPTR)
	{
		if (m_isDrawing)
			m_pCurrentShape->drawShape((this));//绘制当前图形
	}
	// 如果有图形被选中，绘制它以高亮显示
	// 绘制选中图形的边框
	if (!m_selectedShapes.isEmpty())
	{
		QPainter painter(this);
		painter.setPen(Qt::blue);
		painter.setBrush(Qt::NoBrush);
		for (KShape* shape : m_selectedShapes)
		{
			painter.drawRect(shape->getBoundingRect());
		}
	}
}

void KCanvas::mousePressEvent(QMouseEvent* event)
{
	if (m_drawFlag == KDrawFlag::NoneDrawFlag)
		return;

	//判断是否为鼠标左键
	if (event->buttons() == Qt::LeftButton)
	{
		m_isLeftButtonPressed = true;//左键按下的标志设置
		m_pCurrentShape = KShapeFactory::createShape(m_drawFlag);//使用图形工厂绘制一个图形
		if (m_pCurrentShape != Q_NULLPTR)
			m_pCurrentShape->setStartPoint(event->pos());//设置图形的起始位置
	}
	update();//触发绘图事件,调用 paintEvent 处理函数
}

void KCanvas::mouseMoveEvent(QMouseEvent* event)
{
	if (m_drawFlag == KDrawFlag::NoneDrawFlag)
		return;
	//判断鼠标左键按下，是否正在绘图标志设置
	if (m_isLeftButtonPressed && !m_isDrawing)
		m_isDrawing = true;
	if (m_pCurrentShape != Q_NULLPTR)
		m_pCurrentShape->setEndPoint(event->pos()); //记录新的结束位置

	update();//触发绘图事件，调用 paintEvent 处理函数
}

void KCanvas::mouseReleaseEvent(QMouseEvent* event)
{
	if (m_isLeftButtonPressed)
	{
		if (m_drawFlag != KDrawFlag::MouseDrawFlag)// 绘图
		{
			if (m_pCurrentShape != Q_NULLPTR)
			{
				if (m_pCurrentShape->isShapeVaild())//判断绘图矩形框位置是否正确
					m_pCurrentShape->setEndPoint(event->pos());//记录结束位置
				m_pShapeList->prepend(m_pCurrentShape);//将图形对象保存到 QList 中
				m_pCurrentShape = Q_NULLPTR;
			}
		}
		m_isLeftButtonPressed = false;
		m_isDrawing = false;
	}
	update();
}

void KCanvas::updateCurrentDrawingFlag(KDrawFlag drawFlag)
{
	m_drawFlag = drawFlag;
}

void KCanvas::setSelectionMode(bool enabled)
{
	m_selectionMode = enabled;
	if (!enabled)
	{
		m_selectedShapes.clear();
	}
}