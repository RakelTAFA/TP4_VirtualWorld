#include "shapefactory.h"


ShapeFactory::ShapeFactory(ShapeManager* _shapeManager) : shapeManager(_shapeManager) {

}


void ShapeFactory::createShape(const QString& shapeString) {
	
	if (shapeString == "Circle") {
		ControllerAdd* controllerAdd = new ControllerAdd(shapeManager);
		controllerAdd->control();
		//shapeManager->add(new Circle());
	}
	else if (shapeString == "Rectangle") {

	}
	else if (shapeString == "Square") {

	}

}