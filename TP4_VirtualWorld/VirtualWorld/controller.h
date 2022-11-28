#pragma once
#include "shapemanager.h"
#include "shapefactory.h"
#include <QPointF>


class ControllerAdd {
	private:
		ShapeManager* shapeManager;

	public:
		ControllerAdd(ShapeManager*);
		void control(QString&);
};

class ControllerMoveShape
{
	ShapeManager* shapeManager;
public:
	ControllerMoveShape(ShapeManager* = nullptr);
    void control(const QVector<QGraphicsItem *> &);
};

class ControllerRemove
{
	private:
		ShapeManager* shapeManager;

	public:
		ControllerRemove(ShapeManager* sm) : shapeManager(sm) { ; }
};
