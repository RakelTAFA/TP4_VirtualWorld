#pragma once
#include "shapemanager.h"
#include "shapefactory.h"
#include <QPointF>
#include <QTreeWidget>


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
		void control(const QTreeWidgetItem*);
};

class ControllerGroup
{
	private:
		ShapeManager* shapeManager;

	public:
		ControllerGroup(ShapeManager* sm) : shapeManager(sm) { ; }
		void control(const QVector<QGraphicsItem*>);
};


class ControllerRemoveGroup
{
private:
	ShapeManager* shapeManager;

public:
	ControllerRemoveGroup(ShapeManager* sm) : shapeManager(sm) { ; }
	void control(const QVector<QGraphicsItem*>);
};