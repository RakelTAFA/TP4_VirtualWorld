#include"shape.h"

Square::Square() {
	id = current_id++;
	pos = QPointF(-1, -1);
	cote = 0.;
}


Square::Square(QPointF point, double _cote) : cote(_cote) {
	id = current_id++;
	pos = point;
}


QGraphicsItem* Square::getGraphicsItem() const {
	QGraphicsItem* item = new QGraphicsRectItem(pos.x() - cote / 2, pos.y() - cote / 2, cote, cote);
	item->setData(0, id);
	return item;
}


QString Square::type() const {
	return "Square";
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


void Square::move(QPointF _pos) {
	pos += _pos;
}