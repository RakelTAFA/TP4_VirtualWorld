#include "virtualworld.h"
#include "controller.h"
#include <QDebug>

VirtualWorld::VirtualWorld(QWidget* parent, ShapeManager* sm)
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
    connect(ui.Object_RemoveButton, &QPushButton::pressed, this, &VirtualWorld::removeShape);
    connect(ui.Object_GroupButton, &QPushButton::pressed, this, &VirtualWorld::addGroup);
    connect(ui.Object_RemoveGroupButton, &QPushButton::pressed, this, &VirtualWorld::removeGroup);
}

VirtualWorld::~VirtualWorld()
{}

void VirtualWorld::addShape()
{
    QString selectedRadio = "";
    QString selectedColor = "";

    if (ui.radioButton_Circle->isChecked()) {
        selectedRadio = "Circle";
    }
    else if (ui.radioButton_Rectangle->isChecked()) {
        selectedRadio = "Rectangle";
    }
    else if (ui.radioButton_Square->isChecked()) {
        selectedRadio = "Square";
    }
    else if (ui.radioCar->isChecked()) {

    }

    if (ui.radioBlue->isChecked()) {
        selectedColor = "Blue";
    }
    else if (ui.radioRed->isChecked()) {
        selectedColor = "Red";
    }

    selectedRadio += "-";
    selectedRadio += selectedColor;

    paintview->saveSelect();
    ControllerAdd* controller = new ControllerAdd(shapeManager);
    controller->control(selectedRadio);
    delete controller;
    paintview->setSelect();
}

void VirtualWorld::removeShape() {
    for (QTreeWidgetItem* index : ui.treeWidget->selectedItems()) {
        paintview->saveSelect();
        ControllerRemove* controller = new ControllerRemove(shapeManager);
        controller->control(index);
        delete controller;
        paintview->setSelect();
    }
}

void VirtualWorld::addGroup() {
    paintview->saveSelect();
    ControllerGroup* controller = new ControllerGroup(shapeManager);
    controller->control(paintview->getSelect());
    delete controller;
    paintview->setSelect();
}

void VirtualWorld::removeGroup() {
    paintview->saveSelect();
    ControllerRemoveGroup* controller = new ControllerRemoveGroup(shapeManager);
    controller->control(paintview->getSelect());
    delete controller;
    paintview->setSelect();
}