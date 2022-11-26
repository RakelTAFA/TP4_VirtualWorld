#include "shapefactory.h"
#include<iostream>
using namespace std;


ShapeFactory::ShapeFactory(ShapeManager* _shapeManager) : shapeManager(_shapeManager) {

}


void ShapeFactory::createShape(QString& shapeString) {
	
	if (shapeString == "Circle") {
		ControllerAdd* controllerAdd = new ControllerAddCircle(shapeManager);
		controllerAdd->control();
		delete controllerAdd;
	}
	else if (shapeString == "Rectangle") {
		ControllerAdd* controllerAdd = new ControllerAddRectangle(shapeManager);
		controllerAdd->control();
		delete controllerAdd;
	}
	else if (shapeString == "Square") {
		ControllerAdd* controllerAdd = new ControllerAddSquare(shapeManager);
		controllerAdd->control();
		delete controllerAdd;
	}
	else {
		cout << "No shape created" << endl;
		return;
	}
}