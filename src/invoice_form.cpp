#include "invoice_form.h"
#include <QtWidgets>

InvoiceForm::InvoiceForm() {
  this->load();
}

void InvoiceForm::save() {
  QJsonObject save {};
  save["billedTo"] = this->billedTo;
  save["from"] = this->from;
  save["service"] = this->service;
  save["unitCost"] = static_cast<qint64>(this->unitCost);
  save["holidays"] = static_cast<qint64>(this->holidays);
  save["dailyHours"] = static_cast<double>(this->dailyHours);
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
  QFile saveFile(this->filename);
  if (!saveFile.open(QIODevice::ReadOnly)) {
    qWarning("Couldn't open save file.");
    return;
  }
  QByteArray data = saveFile.readAll();
  save = QJsonDocument::fromJson(data).object();
  this->billedTo = save["billedTo"].toString();
  this->from = save["from"].toString();
  this->service = save["service"].toString();
  this->unitCost = save["unitCost"].toInt();
  this->holidays = save["holidays"].toInt();
  this->dailyHours = save["dailyHours"].toDouble();
  qDebug() << "Loaded";
}

void InvoiceForm::setBilledTo(QString value) {
  this->billedTo = value;
}

void InvoiceForm::setFrom(QString value) {
  this->from = value;
}

void InvoiceForm::setService(QString value) {
  this->service = value;
}

void InvoiceForm::setUnitCost(QString value) {
  this->unitCost = value.toInt();
}

void InvoiceForm::setHolidays(QString value) {
  this->holidays = value.toInt();
}

void InvoiceForm::setDailyHours(QString value) {
  this->dailyHours = value.toDouble();
}
