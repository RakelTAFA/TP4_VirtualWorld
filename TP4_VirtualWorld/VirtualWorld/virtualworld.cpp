#include "virtualworld.h"
#include "controller.h"
#include <QDebug>

VirtualWorld::VirtualWorld(QWidget *parent, ShapeManager* sm)
    : QMainWindow(parent), shapeManager(sm)
{
    ui.setupUi(this);

    // Paint View
    paintview = new PaintView(shapeManager);
    shapeManager->addObserver(paintview);
    ui.graphicsView->setScene(paintview);
    paintview->setParent(ui.graphicsView);

    // Tree View
    treeview = new TreeView(shapeManager, ui.treeWidget);
    shapeManager->addObserver(treeview);

    // Connect buttons
    connect(ui.Object_AddButton, &QPushButton::pressed, this, &VirtualWorld::addShape);
}

VirtualWorld::~VirtualWorld()
{}

void VirtualWorld::addShape()
{
    QString selectedRadio = "";

    if (ui.radioButton_Circle->isChecked()) {
        selectedRadio = "Circle";
    }
    else if (ui.radioButton_Rectangle->isChecked()) {
        selectedRadio = "Rectangle";
    }
    else if (ui.radioButton_Square->isChecked()) {
        selectedRadio = "Square";
    }

    ShapeFactory* shapeFactory = new ShapeFactory(shapeManager);
    shapeFactory->createShape(selectedRadio);
    delete shapeFactory;
}
