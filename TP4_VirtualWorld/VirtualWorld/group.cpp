#include"shape.h"

Group::Group() {
	id = current_id++;
}


QGraphicsItem* Group::getGraphicsItem() const {
	QGraphicsItemGroup* item = new QGraphicsItemGroup();
	item->setData(0, id);
	for (Shape* shape : shapeList) {
		item->addToGroup(shape->getGraphicsItem());
	}
	return item;
}


void Group::getTreeWidgetItem(QTreeWidget* treeview, QTreeWidgetItem* _item) const {
	QTreeWidgetItem* item;
	if (_item == nullptr) {
		item = new QTreeWidgetItem(treeview);
	}
	else {
		item = new QTreeWidgetItem(_item);
	}
	item->setText(0, QString::number(id));
	item->setText(1, type());

	for (Shape* shape : shapeList) {
		shape->getTreeWidgetItem(treeview, item);
	}
}

QString Group::type() const {
	return "Group";
}

void Group::add(Shape* shape) {
	shapeList.append(shape);

}

void Group::move(QPointF _pos) {
	for (Shape* shape : shapeList) {
		shape->move(_pos);
	}
}

QVector<Shape*> Group::getList() {
	return shapeList;
}

QVector<Shape*> Group::getShape() {
	return shapeList;
}