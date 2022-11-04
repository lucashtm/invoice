#include "invoice_form.h"
#include <QtWidgets>

void InvoiceForm::save() {
  qDebug() << "Saved";
  QJsonObject save {};
  save["unitCost"] = static_cast<qint64>(this->unitCost);
  QFile saveFile(QStringLiteral("save.json"));
  if (!saveFile.open(QIODevice::WriteOnly)) {
    qWarning("Couldn't open save file.");
    return;
  }
  saveFile.write(QJsonDocument(save).toJson());
}

void InvoiceForm::setUnitCost(QString value) {
  qDebug() << value;
  this->unitCost = value.toInt();
}
