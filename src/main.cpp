#include <QtWidgets>
#include <QDebug>
#include "invoice_form.h"

void buildLayout(QWidget *window, InvoiceForm *form){
  QLabel *unitCostLabel = new QLabel(QApplication::translate("windowlayout", "Unit Cost:"));
  QLineEdit *unitCostLineEdit = new QLineEdit();
  QLabel *workingDaysLabel = new QLabel(QApplication::translate("windowlayout", "Working Days:"));
  QLineEdit *workingDaysLineEdit = new QLineEdit();
  QLabel *holidaysLabel = new QLabel(QApplication::translate("windowlayout", "Holidays:"));
  QLineEdit *holidaysLineEdit = new QLineEdit();
  QPushButton *saveButton = new QPushButton(QApplication::translate("button", "Save"), window);

  QObject::connect(unitCostLineEdit, &QLineEdit::textEdited, [](const QString &text) { qDebug() << text; });
  QObject::connect(unitCostLineEdit, &QLineEdit::textEdited, form, &InvoiceForm::setUnitCost);
  bool result = QObject::connect(saveButton, &QPushButton::clicked, form, &InvoiceForm::save);
  if(!result) {
    qDebug() << "Couldnt connect";
  }
  QFormLayout *layout = new QFormLayout();
  layout->addRow(unitCostLabel, unitCostLineEdit);
  layout->addRow(workingDaysLabel, workingDaysLineEdit);
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
