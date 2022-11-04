#include <QtWidgets>
#include <QDebug>

void buildLayout(QWidget *window){
  QLabel *unitCostLabel = new QLabel(QApplication::translate("windowlayout", "Unit Cost:"));
  QLineEdit *unitCostLineEdit = new QLineEdit();
  QLabel *workingDaysLabel = new QLabel(QApplication::translate("windowlayout", "Working Days:"));
  QLineEdit *workingDaysLineEdit = new QLineEdit();
  QLabel *holidaysLabel = new QLabel(QApplication::translate("windowlayout", "Holidays:"));
  QLineEdit *holidaysLineEdit = new QLineEdit();
  QPushButton *saveButton = new QPushButton(QApplication::translate("button", "Save"), window);

  QObject::connect(unitCostLineEdit, &QLineEdit::textEdited, [](const QString &text) { qDebug() << text; });
  QObject::connect(saveButton, &QPushButton::clicked, [unitCostLineEdit](bool checked) {
      QJsonObject save {};
      save["unitCost"] = unitCostLineEdit->text();
      QFile saveFile(QStringLiteral("save.json"));
      if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
      }
      saveFile.write(QJsonDocument(save).toJson());
  });
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
    buildLayout(&window);
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(QApplication::translate("toplevel", "Top-level widget"));
    return app.exec();
}
