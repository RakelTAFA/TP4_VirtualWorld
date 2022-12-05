#include "view.h"

TreeView::TreeView(ShapeManager* sm, QTreeWidget* tw) : Observer(), shapeManager(sm), treeview(tw)
{}

void TreeView::updateModel()
{
	// Clear Treeview
	treeview->clear();

	// Generate Data
	QStringList labels;
	labels << "id" << "type";
	treeview->setHeaderLabels(labels);

	QVector<Shape*> shapes = shapeManager->getShapes();
	for (Shape* shape : shapes)
	{
		shape->getTreeWidgetItem(treeview);
	}
}
