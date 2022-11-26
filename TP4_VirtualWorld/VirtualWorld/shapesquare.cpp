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
	return nullptr;
}


QString Square::type() const {
	return "Square";
}