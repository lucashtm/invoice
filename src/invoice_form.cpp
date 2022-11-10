#include "invoice_form.h"
#include <QtWidgets>

InvoiceForm::InvoiceForm() {
  this->load();
}

void InvoiceForm::save() {
  QJsonObject save {};
  save["unitCost"] = static_cast<qint64>(this->unitCost);
  save["holidays"] = static_cast<qint64>(this->holidays);
  QFile saveFile(this->filename);
  if (!saveFile.open(QIODevice::WriteOnly)) {
    qWarning("Couldn't open save file.");
    return;
  }
  saveFile.write(QJsonDocument(save).toJson());
  qDebug() << "Saved";
}

void InvoiceForm::load() {
  QJsonObject save {};
  save["unitCost"] = static_cast<qint64>(this->unitCost);
  save["holidays"] = static_cast<qint64>(this->holidays);
  QFile saveFile(this->filename);
  if (!saveFile.open(QIODevice::ReadOnly)) {
    qWarning("Couldn't open save file.");
    return;
  }
  QByteArray data = saveFile.readAll();
  save = QJsonDocument::fromJson(data).object();
  this->unitCost = save["unitCost"].toInt();
  this->holidays = save["holidays"].toInt();
  qDebug() << "Loaded";
}

void InvoiceForm::setUnitCost(QString value) {
  this->unitCost = value.toInt();
}

void InvoiceForm::setHolidays(QString value) {
  this->holidays = value.toInt();
}
