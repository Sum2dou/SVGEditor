#include "kcanvas.h"
#include "kshapefactory.h"

KCanvas::KCanvas(QWidget* parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_StyledBackground, true);
	setMouseTracking(true);//�������׷��
	setFocusPolicy(Qt::ClickFocus);//������ȡ����
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
	// ��ԭ����ͼ�����»���
	if (!m_pShapeList->isEmpty())
	{
		for (QList<KShape*>::iterator it = m_pShapeList->begin();
			it != m_pShapeList->end(); ++it)
			(*it)->drawShape(this);
	}

	if (m_pCurrentShape != Q_NULLPTR)
	{
		if (m_isDrawing)
			m_pCurrentShape->drawShape((this));//���Ƶ�ǰͼ��
	}
	// �����ͼ�α�ѡ�У��������Ը�����ʾ
	// ����ѡ��ͼ�εı߿�
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

	//�ж��Ƿ�Ϊ������
	if (event->buttons() == Qt::LeftButton)
	{
		m_isLeftButtonPressed = true;//������µı�־����
		m_pCurrentShape = KShapeFactory::createShape(m_drawFlag);//ʹ��ͼ�ι�������һ��ͼ��
		if (m_pCurrentShape != Q_NULLPTR)
			m_pCurrentShape->setStartPoint(event->pos());//����ͼ�ε���ʼλ��
	}
	update();//������ͼ�¼�,���� paintEvent ������
}

void KCanvas::mouseMoveEvent(QMouseEvent* event)
{
	if (m_drawFlag == KDrawFlag::NoneDrawFlag)
		return;
	//�ж����������£��Ƿ����ڻ�ͼ��־����
	if (m_isLeftButtonPressed && !m_isDrawing)
		m_isDrawing = true;
	if (m_pCurrentShape != Q_NULLPTR)
		m_pCurrentShape->setEndPoint(event->pos()); //��¼�µĽ���λ��

	update();//������ͼ�¼������� paintEvent ������
}

void KCanvas::mouseReleaseEvent(QMouseEvent* event)
{
	if (m_isLeftButtonPressed)
	{
		if (m_drawFlag != KDrawFlag::MouseDrawFlag)// ��ͼ
		{
			if (m_pCurrentShape != Q_NULLPTR)
			{
				if (m_pCurrentShape->isShapeVaild())//�жϻ�ͼ���ο�λ���Ƿ���ȷ
					m_pCurrentShape->setEndPoint(event->pos());//��¼����λ��
				m_pShapeList->prepend(m_pCurrentShape);//��ͼ�ζ��󱣴浽 QList ��
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