#include <QtWidgets>
#include <QDebug>
#include <qvalidator.h>
#include "invoice_form.h"

void buildLayout(QWidget *window, InvoiceForm *form){
  QLabel *unitCostLabel = new QLabel(QApplication::translate("windowlayout", "Unit Cost:"));
  QLineEdit *unitCostLineEdit = new QLineEdit();
  unitCostLineEdit->setValidator(new QIntValidator(0, 9999));
  unitCostLineEdit->setText(QString::number(form->unitCost));
  QLabel *holidaysLabel = new QLabel(QApplication::translate("windowlayout", "Holidays:"));
  QLineEdit *holidaysLineEdit = new QLineEdit();
  holidaysLineEdit->setValidator(new QIntValidator(0, 32));
  holidaysLineEdit->setText(QString::number(form->holidays));
  QPushButton *saveButton = new QPushButton(QApplication::translate("button", "Save"), window);

  QObject::connect(unitCostLineEdit, &QLineEdit::textEdited, form, &InvoiceForm::setUnitCost);
  QObject::connect(holidaysLineEdit, &QLineEdit::textEdited, form, &InvoiceForm::setHolidays);
  bool result = QObject::connect(saveButton, &QPushButton::clicked, form, &InvoiceForm::save);
  if(!result) {
    qDebug() << "Couldnt connect";
  }
  QFormLayout *layout = new QFormLayout();
  layout->addRow(unitCostLabel, unitCostLineEdit);
  layout->addRow(holidaysLabel, holidaysLineEdit);
  layout->addWidget(saveButton);
  window->setLayout(layout);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    InvoiceForm *form = new InvoiceForm();
    buildLayout(&window, form);
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(QApplication::translate("window", "Invoice"));

    return app.exec();
}
