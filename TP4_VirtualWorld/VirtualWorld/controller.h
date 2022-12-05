#pragma once
#include "shapemanager.h"
#include "shapefactory.h"
#include <QPointF>
#include <qtreewidget.h>


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
	void control(const QVector<QGraphicsItem*>&);
};

class ControllerRemove
{
private:
	ShapeManager* shapeManager;

public:
	ControllerRemove(ShapeManager* sm) : shapeManager(sm) { ; }
	void control(const QTreeWidgetItem* item);
};

class ControllerGroup {
	ShapeManager* shapeManager;

public:
	ControllerGroup(ShapeManager* sm) : shapeManager(sm) { ; }
	void control(const QVector<QGraphicsItem*>);
};

class ControllerRemoveGroup {
	ShapeManager* shapeManager;

public:
	ControllerRemoveGroup(ShapeManager* sm) : shapeManager(sm) { ; }
	void control(const QVector<QGraphicsItem*>);
};
