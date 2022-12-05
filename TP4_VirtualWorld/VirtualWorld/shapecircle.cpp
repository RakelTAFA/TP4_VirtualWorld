#include "shape.h"
#include <QGraphicsEllipseItem>
#include <qpen.h>

int Shape::current_id; // added

Circle::Circle()
{
	id = current_id++;
	pos = QPointF(-1, -1);
	radius = 0.;
}

Circle::Circle(QPointF p, double r, QString& _color) : radius(r)
{
	id = current_id++;
	pos = p;
	QStringList list = _color.split('-');
	color = list[1];
}


QGraphicsItem* Circle::getGraphicsItem() const
{
	QBrush tmpBrush(Qt::SolidPattern);
	if (color == "Red") {
		tmpBrush.setColor(QColor(255, 0, 0));
	}
	else if (color == "Blue") {
		tmpBrush.setColor(QColor(0, 0, 255));
	}
	else {
		tmpBrush.setColor(QColor(255, 255, 255));
	}
	QPen tmpPen;
	tmpPen.setColor(Qt::black);
	tmpPen.setWidth(2);

	QGraphicsEllipseItem* item = new QGraphicsEllipseItem(pos.x() - radius, pos.y() - radius, radius * 2., radius * 2.);
	item->setData(0, id);
	item->setBrush(tmpBrush);
	item->setPen(tmpPen);
	return item;
}

void Circle::getTreeWidgetItem(QTreeWidget* treeview, QTreeWidgetItem* _item) const {
	QTreeWidgetItem* item;
	if (_item == nullptr) {
		item = new QTreeWidgetItem(treeview);
	}
	else {
		item = new QTreeWidgetItem(_item);
	}

	item->setText(0, QString::number(id));
	item->setText(1, type());
}


QString Circle::type() const
{
	return "Circle";
}

void Circle::move(QPointF _pos) {
	pos += _pos;
}

QVector<Shape*> Circle::getShape() {
	QVector<Shape*> s;
	s.append(this);
	return s;
}