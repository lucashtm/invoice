#include <QtWidgets>
#include <QDebug>
#include "invoice_form.h"

void billedTo(QFormLayout *layout, InvoiceForm *form) {
  int nRows = 10;
  QPlainTextEdit *billedToTextEdit = new QPlainTextEdit();
  QFontMetrics fontMetrics (billedToTextEdit->font());
  int rowHeight = fontMetrics.lineSpacing();
  billedToTextEdit->setFixedHeight  (nRows * rowHeight);
  billedToTextEdit->setReadOnly(!form->billedTo.isEmpty());
  billedToTextEdit->setPlainText(form->billedTo);
  QObject::connect(billedToTextEdit, &QPlainTextEdit::textChanged, form, [billedToTextEdit, form](){ form->setBilledTo(billedToTextEdit->toPlainText()); });
  layout->addRow("&Billed To:", billedToTextEdit);
}

void from(QFormLayout *layout, InvoiceForm *form) {
  int nRows = 10;
  QPlainTextEdit *fromTextEdit = new QPlainTextEdit();
  QFontMetrics fontMetrics (fromTextEdit->font());
  int rowHeight = fontMetrics.lineSpacing();
  fromTextEdit->setFixedHeight  (nRows * rowHeight);
  fromTextEdit->setReadOnly(!form->from.isEmpty());
  fromTextEdit->setPlainText(form->from);
  QObject::connect(fromTextEdit, &QPlainTextEdit::textChanged, form, [fromTextEdit, form](){ form->setFrom(fromTextEdit->toPlainText()); });
  layout->addRow("&From:", fromTextEdit);
}

void buildLayout(QWidget *window, InvoiceForm *form){
  QLineEdit *serviceLineEdit = new QLineEdit();
  serviceLineEdit->setText(form->service);
  QLineEdit *holidaysLineEdit = new QLineEdit();
  holidaysLineEdit->setValidator(new QIntValidator(0, 32));
  holidaysLineEdit->setText(QString::number(form->holidays));
  QLineEdit *unitCostLineEdit = new QLineEdit();
  unitCostLineEdit->setValidator(new QIntValidator(0, 9999));
  unitCostLineEdit->setText(QString::number(form->unitCost));
  QLineEdit *dailyHoursLineEdit = new QLineEdit();
  dailyHoursLineEdit->setValidator(new QDoubleValidator(0, 8, 1));
  dailyHoursLineEdit->setText(QString::number(form->dailyHours));
  QPushButton *saveButton = new QPushButton(QApplication::translate("button", "Save"), window);

  QObject::connect(serviceLineEdit, &QLineEdit::textEdited, form, &InvoiceForm::setService);
  QObject::connect(holidaysLineEdit, &QLineEdit::textEdited, form, &InvoiceForm::setHolidays);
  QObject::connect(unitCostLineEdit, &QLineEdit::textEdited, form, &InvoiceForm::setUnitCost);
  QObject::connect(dailyHoursLineEdit, &QLineEdit::textEdited, form, &InvoiceForm::setDailyHours);
  bool result = QObject::connect(saveButton, &QPushButton::clicked, form, &InvoiceForm::save);
  if(!result) {
    qDebug() << "Couldnt connect";
  }
  QFormLayout *layout = new QFormLayout();
  billedTo(layout, form);
  from(layout, form);
  layout->addRow("&Service:", serviceLineEdit);
  layout->addRow("&Holidays:", holidaysLineEdit);
  layout->addRow("&Unit Cost:", unitCostLineEdit);
  layout->addRow("&Daily Hours:", dailyHoursLineEdit);
  layout->addWidget(saveButton);
  window->setLayout(layout);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    InvoiceForm *form = new InvoiceForm();
    buildLayout(&window, form);
    window.show();
    window.setWindowTitle(QApplication::translate("window", "Invoice"));

    return app.exec();
}
