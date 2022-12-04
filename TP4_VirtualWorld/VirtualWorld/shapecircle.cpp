#include "shape.h"
#include <QGraphicsEllipseItem>

int Shape::current_id; // added

Circle::Circle()
{
	id = current_id++;
	pos = QPointF(-1, -1);
	radius = 0.;
}

Circle::Circle(QPointF p, double r) : radius(r)
{
	id = current_id++;
	pos = p;
}


QGraphicsItem* Circle::getGraphicsItem() const
{
	QGraphicsItem* item = new QGraphicsEllipseItem(pos.x()-radius, pos.y()-radius, radius*2., radius*2.);
	item->setData(0,id);
	return item;
}


QString Circle::type() const
{
	return "Circle";
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


void Circle::move(QPointF _pos) {
	pos += _pos;
}