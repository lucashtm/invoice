#include <QObject>
#include <cstdint>
#include <QDebug>
#include <iostream>

class InvoiceForm : public QObject {
  Q_OBJECT
  public:
    InvoiceForm();
    uint32_t unitCost = 0;
    uint32_t holidays = 0;
    void load();
  public slots:
    void save();
    void setUnitCost(QString value);
    void setHolidays(QString value);
  private:
    QString filename = "save.json";
};
