#pragma once
#include"shapemanager.h"
#include"controller.h"


class ShapeFactory
{
	private:
		ShapeManager* shapeManager;

	public:
		ShapeFactory(ShapeManager*);

		void createShape(QString&);
};

