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
	QGraphicsItem* item = new QGraphicsRectItem(pos.x() - cote, pos.y() - cote, cote, cote);
	item->setData(0, id);
	return item;
}


QString Square::type() const {
	return "Square";
}