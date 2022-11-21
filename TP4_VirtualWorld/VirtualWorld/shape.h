#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include<QVector>


class Shape {
	public:
		virtual void setColor() = 0;

		QPointF pos;
		int id;
		static int current_id;

		virtual QGraphicsItem* getGraphicsItem() const = 0;
		virtual QString type() const = 0 ;
};


class Group : public Shape {
	private:
		QVector<Shape*> shapeList;

	public:
		Group();

		void setColor() override { return ; }
		QGraphicsItem* getGraphicsItem() const override;
		QString type() const override;
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
};


class Carre : public Shape {
	private:
		double cote;

	public:
		Carre();
		Carre(QPointF, double);

		void setColor() override { return; }
		QGraphicsItem* getGraphicsItem() const override;
		QString type() const override;
};
