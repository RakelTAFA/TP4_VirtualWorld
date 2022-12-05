#include "controller.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

ControllerAdd::ControllerAdd(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerAdd::control(QString& shapeString)
{
	if (shapeManager == nullptr) return;

	ShapeFactory* factory = new ShapeFactory();
	Shape* shapeCreated = factory->createShape(shapeString);

	// Add Shape

	if (shapeCreated != nullptr) {
		shapeManager->add(shapeCreated);
	}
	delete factory;
}

ControllerMoveShape::ControllerMoveShape(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerMoveShape::control(const QVector<QGraphicsItem*>& items)
{
	if (shapeManager == nullptr) return;

	// Move Shape
	for (QGraphicsItem* item : items)
	{
		QVariant variant = item->data(0);
		int id = variant.toInt();

		bool selected = shapeManager->selectShape(id);
		if (selected)
		{
			QRectF rect = item->boundingRect();
			shapeManager->moveShape(item->scenePos());
		}
	}

	shapeManager->notifyObserver();
}

void ControllerRemove::control(const QTreeWidgetItem* item) {
	if (shapeManager == nullptr) return;

	QVariant variant = item->text(0);
	int id = variant.toInt();

	for (Shape* shape : shapeManager->getShapes())
	{
		if (shape->id == id)
		{
			shapeManager->remove(shape);
		}
	}

	shapeManager->notifyObserver();
}

void ControllerGroup::control(QVector<QGraphicsItem*> items) {
	if (shapeManager == nullptr) return;
	QVector<Shape*> _shapes;

	for (QGraphicsItem* item : items) {
		for (Shape* shape : shapeManager->getShapes())
		{
			if (shape->id == item->data(0))
			{
				_shapes.append(shape);
			}
		}
	}

	ShapeFactory* factory = new ShapeFactory();
	Shape* shapeCreated = factory->createShape(_shapes);

	// Add Shape

	if (shapeCreated != nullptr) {
		shapeManager->add(shapeCreated);
		for (Shape* shape : _shapes) {
			shapeManager->remove(shape);
		}
	}
	delete factory;
}

void ControllerRemoveGroup::control(QVector<QGraphicsItem*> items) {
	if (shapeManager == nullptr) return;
	QVector<Shape*> _shapes;

	for (QGraphicsItem* item : items) {
		for (Shape* shape : shapeManager->getShapes())
		{
			if (shape->id == item->data(0))
			{
				shapeManager->removeGroup(shape);
				break;
			}
		}
	}

	shapeManager->notifyObserver();
}