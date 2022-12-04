#include "shapefactory.h"
#include<iostream>
using namespace std;


ShapeFactory::ShapeFactory(ShapeManager* _shapeManager) : shapeManager(_shapeManager) {

}


Shape* ShapeFactory::createShape(QString& shapeString) {
	
	if (shapeString == "Circle") {
		return new Circle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100 + 1);
	}
	else if (shapeString == "Rectangle") {
		return new Rectangle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100 + 1, std::rand() % 100 + 1);
	}
	else if (shapeString == "Square") {
		return new Square(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100 + 1);
	}
	else {
		cout << "No shape created" << endl;
	}
	return nullptr;
}


Shape* ShapeFactory::createShape(QVector<Shape*> _shapes)
{
	Group* group = new Group();
	for (Shape* shape : _shapes)
	{
		group->add(shape);
	}
	return group;
}