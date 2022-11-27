#include "controller.h"
#include "shapemanager.h"

#include <cstdlib>
#include <iostream>
#include <ctime>

ControllerAddCircle::ControllerAddCircle(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerAddCircle::control()
{
	if (shapeManager == nullptr) return;

	// Add Shape
	shapeManager->add(new Circle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100));
	//shapeManager->add(new Circle(QPointF(0., 0.), 100.));
}

ControllerAddRectangle::ControllerAddRectangle(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerAddRectangle::control()
{
	if (shapeManager == nullptr) return;

	// Add Shape
	shapeManager->add(new Rectangle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100, std::rand() % 100));
	//shapeManager->add(new Circle(QPointF(0., 0.), 100.));
}

ControllerAddSquare::ControllerAddSquare(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerAddSquare::control()
{
	if (shapeManager == nullptr) return;

	// Add Shape
	shapeManager->add(new Square(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100));
	//shapeManager->add(new Circle(QPointF(0., 0.), 100.));
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
