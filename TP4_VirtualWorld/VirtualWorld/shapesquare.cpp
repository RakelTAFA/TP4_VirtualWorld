#include"shape.h"
#include <qpen.h>

Square::Square() {
	id = current_id++;
	pos = QPointF(-1, -1);
	cote = 0.;
}


Square::Square(QPointF point, double _cote, QString& _color) : cote(_cote) {
	id = current_id++;
	pos = point;
	QStringList list = _color.split('-');
	color = list[1];
}


QGraphicsItem* Square::getGraphicsItem() const {
	
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
	
	QGraphicsRectItem* item = new QGraphicsRectItem(pos.x() - cote / 2, pos.y() - cote / 2, cote, cote);
	item->setData(0, id);
	item->setBrush(tmpBrush);
	item->setPen(tmpPen);
	return item;
}

void Square::getTreeWidgetItem(QTreeWidget* treeview, QTreeWidgetItem* _item) const {
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


QString Square::type() const {
	return "Square";
}

void Square::move(QPointF _pos) {
	pos += _pos;
}

QVector<Shape*> Square::getShape() {
	QVector<Shape*> s;
	s.append(this);
	return s;
}