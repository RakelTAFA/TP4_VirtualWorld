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
	QGraphicsItem* item = new QGraphicsRectItem(pos.x() - longueur / 2, pos.y() - hauteur / 2, longueur, hauteur);
	item->setData(0, id);
	return item;
}


QString Rectangle::type() const {
	return "Rectangle";
}