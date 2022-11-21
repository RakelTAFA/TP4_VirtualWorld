#include"shape.h"

Rectangle::Rectangle() {
	id = current_id++;
	pos = QPointF(-1, -1);
	longueur = 0.;
	hauteur = 0.;
}


Rectangle::Rectangle(QPointF point, double _longueur, double _hauteur) : longueur(_longueur), hauteur(_hauteur) {
	id = current_id++;
	pos = point;
}


QGraphicsItem* Rectangle::getGraphicsItem() const {
	return nullptr;
}


QString Rectangle::type() const {
	return "Rectangle";
}