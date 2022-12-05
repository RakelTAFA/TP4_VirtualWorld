#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include <qtreewidget.h>
#include<QVector>


class Shape {
public:

	QPointF pos;
	int id;
	static int current_id;

	virtual void setColor() = 0;
	virtual QGraphicsItem* getGraphicsItem() const = 0;
	virtual void getTreeWidgetItem(QTreeWidget*, QTreeWidgetItem* = nullptr) const = 0;
	virtual QString type() const = 0;
	virtual QVector<Shape*> getShape() = 0;
	virtual void move(QPointF) = 0;
};


class Group : public Shape {
protected:
	QVector<Shape*> shapeList;

public:
	Group();

	QVector<Shape*> getList();
	void add(Shape*);
	void setColor() override { return; }
	QGraphicsItem* getGraphicsItem() const override;
	void getTreeWidgetItem(QTreeWidget*, QTreeWidgetItem* = nullptr) const override;
	QString type() const override;
	QVector<Shape*> getShape() override;
	void move(QPointF) override;
};


class Circle : public Shape
{
private:
	double radius;
	QString color;

public:
	// added

	Circle();
	Circle(QPointF, double, QString&);

	void setColor() override { return; }
	QGraphicsItem* getGraphicsItem() const override;
	void getTreeWidgetItem(QTreeWidget*, QTreeWidgetItem* = nullptr) const override;
	QString type() const override;
	QVector<Shape*> getShape() override;
	void move(QPointF) override;
};


class Rectangle : public Shape {
private:
	double longueur;
	double hauteur;
	QString color;

public:
	Rectangle();
	Rectangle(QPointF, double, double, QString&);

	void setColor() override { return; }
	QGraphicsItem* getGraphicsItem() const override;
	void getTreeWidgetItem(QTreeWidget*, QTreeWidgetItem* = nullptr) const override;
	QString type() const override;
	QVector<Shape*> getShape() override;
	void move(QPointF) override;
};


class Square : public Shape {
private:
	double cote;
	QString color;


public:
	Square();
	Square(QPointF, double, QString&);

	void setColor() override { return; }
	QGraphicsItem* getGraphicsItem() const override;
	void getTreeWidgetItem(QTreeWidget*, QTreeWidgetItem* = nullptr) const override;
	QString type() const override;
	QVector<Shape*> getShape() override;
	void move(QPointF) override;
};


class Voiture : public Group
{
	public:
		Voiture(QPointF, double, double);
};