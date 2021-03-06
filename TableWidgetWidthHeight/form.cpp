#include <QtGui>

#include "form.h"

#include <QTableWidgetItem>

Form::Form(QWidget *parent)
    : QWidget(parent)
{
  setupUi(this);
  
  this->tableWidget->setColumnCount(1);
  this->tableWidget->setRowCount(2);
  
  //QTableWidgetItem* item=new QTableWidgetItem("A");
  // The above is the same as:
  
  QTableWidgetItem* textItem = new QTableWidgetItem;
  textItem->setText("A");
  
  this->tableWidget->setItem(0,0, textItem);
  
  // Add an image to the table
  QColor black(0,0,0);
  unsigned int imageSize = 100;
  QPixmap pixmap(imageSize,imageSize);
  pixmap.fill(black);
  
  // This works:
  QLabel* imageLabel = new QLabel();
  imageLabel->setPixmap(pixmap);

  this->tableWidget->setCellWidget(1,0,imageLabel);
  
  this->tableWidget->setRowHeight(1,1000);

  
}
