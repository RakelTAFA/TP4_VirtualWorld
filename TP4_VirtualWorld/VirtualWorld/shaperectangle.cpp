#include"shape.h"
#include "qpen.h"

Rectangle::Rectangle() {
	id = current_id++;
	pos = QPointF(-1, -1);
	longueur = 0.;
	hauteur = 0.;
}


Rectangle::Rectangle(QPointF point, double _longueur, double _hauteur, QString& _color) : longueur(_longueur), hauteur(_hauteur) {
	id = current_id++;
	pos = point;
	QStringList list = _color.split('-');
	color = list[1];
}


QGraphicsItem* Rectangle::getGraphicsItem() const {

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


	QGraphicsRectItem* item = new QGraphicsRectItem(pos.x() - longueur / 2, pos.y() - hauteur / 2, longueur, hauteur);
	item->setData(0, id);
	item->setBrush(tmpBrush);
	item->setPen(tmpPen);
	return item;
}

void Rectangle::getTreeWidgetItem(QTreeWidget* treeview, QTreeWidgetItem* _item) const {
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

QString Rectangle::type() const {
	return "Rectangle";
}

void Rectangle::move(QPointF _pos) {
	pos += _pos;
}

QVector<Shape*> Rectangle::getShape() {
	QVector<Shape*> s;
	s.append(this);
	return s;
}