#include "controller.h"
#include "shapemanager.h"

#include <cstdlib>
#include <iostream>
#include <ctime>

ControllerAdd::ControllerAdd(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerAdd::control(QString& shapeString)
{
	if (shapeManager == nullptr) return;

	ShapeFactory* factory = new ShapeFactory(shapeManager);
	Shape* shapeCreated = factory->createShape(shapeString);

	// Add Shape

	if (shapeCreated != nullptr) {
		shapeManager->add(shapeCreated);
		//shapeCreated->getGraphicsItem();
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
			shapeManager->moveShape(item->scenePos() + rect.center());
		}
	}

	shapeManager->notifyObserver();
}


void ControllerRemove::control(const QTreeWidgetItem* item)
{
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

