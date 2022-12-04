#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include <QTreeWidget>
#include<QVector>


class Shape {
	public:

		QPointF pos;
		int id;
		static int current_id;

		virtual void setColor() = 0;
		virtual QGraphicsItem* getGraphicsItem() const = 0;
		virtual QString type() const = 0;
		virtual void move(QPointF) = 0;
		virtual void getTreeWidgetItem(QTreeWidget*, QTreeWidgetItem* = nullptr) const = 0;
};


class Group : public Shape {
	private:
		QVector<Shape*> shapeList;

	public:
		Group();

		void setColor() override { return ; }
		QGraphicsItem* getGraphicsItem() const override;
		QString type() const override;
		void add(Shape*);
		void move(QPointF) override;
		void getTreeWidgetItem(QTreeWidget*, QTreeWidgetItem* = nullptr) const override;

};


class Circle : public Shape
{
private:
	double radius;

public: 
	// added

	Circle();
	Circle(QPointF, double);

	void setColor() override { return; }
	QGraphicsItem* getGraphicsItem() const override;
	QString type() const override;
	void getTreeWidgetItem(QTreeWidget*, QTreeWidgetItem* = nullptr) const override;
	void move(QPointF) override;
};


class Rectangle : public Shape {
	private:
		double longueur;
		double hauteur;

	public:
		Rectangle();
		Rectangle(QPointF, double, double);

		void setColor() override { return; }
		QGraphicsItem* getGraphicsItem() const override;
		QString type() const override;
		void move(QPointF) override;
		void getTreeWidgetItem(QTreeWidget*, QTreeWidgetItem* = nullptr) const override;
};


class Square : public Shape {
	private:
		double cote;

	public:
		Square();
		Square(QPointF, double);

		void setColor() override { return; }
		QGraphicsItem* getGraphicsItem() const override;
		QString type() const override;
		void move(QPointF) override;
		void getTreeWidgetItem(QTreeWidget*, QTreeWidgetItem* = nullptr) const override;
};
