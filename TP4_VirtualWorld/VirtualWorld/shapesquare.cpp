#include"shape.h"

Carre::Carre() {
	id = current_id++;
	pos = QPointF(-1, -1);
	cote = 0.;
}


Carre::Carre(QPointF point, double _cote) : cote(_cote) {
	id = current_id++;
	pos = point;
}


QGraphicsItem* Carre::getGraphicsItem() const {
	return nullptr;
}


QString Carre::type() const {
	return "Square";
}