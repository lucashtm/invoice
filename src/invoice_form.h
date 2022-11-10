#include <QObject>
#include <cstdint>
#include <QDebug>
#include <iostream>

class InvoiceForm : public QObject {
  Q_OBJECT
  public:
    InvoiceForm();
    QString billedTo;
    QString from;
    QString service;
    uint32_t unitCost = 0;
    uint32_t holidays = 0;
    double dailyHours = 0;
    void load();
  public slots:
    void save();
    void setBilledTo(QString value);
    void setFrom(QString value);
    void setService(QString value);
    void setUnitCost(QString value);
    void setHolidays(QString value);
    void setDailyHours(QString value);
  private:
    QString filename = "save.json";
};
