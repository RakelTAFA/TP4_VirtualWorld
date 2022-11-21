#include"shape.h"

Group::Group() {
	id = current_id++;
}


QGraphicsItem* Group::getGraphicsItem() const {
	return nullptr;
}


QString Group::type() const {
	return "Group";
}