#pragma once
#include "shapemanager.h"
#include <QPointF>


class ControllerAdd {
	public:
		virtual void control() = 0;
};

class ControllerAddCircle : public ControllerAdd
{
	ShapeManager* shapeManager;
public:
	ControllerAddCircle(ShapeManager* = nullptr);
	void control() override;
};

class ControllerAddRectangle : public ControllerAdd
{
	ShapeManager* shapeManager;
public:
	ControllerAddRectangle(ShapeManager* = nullptr);
	void control() override;
};

class ControllerAddSquare : public ControllerAdd
{
	ShapeManager* shapeManager;
public:
	ControllerAddSquare(ShapeManager* = nullptr);
	void control() override;
};

class ControllerMoveShape
{
	ShapeManager* shapeManager;
public:
	ControllerMoveShape(ShapeManager* = nullptr);
    void control(const QVector<QGraphicsItem *> &);
};
