#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{

    ui->setupUi(this);
    connect(ui->btnGenerar, &QPushButton::clicked, this, &MainWindow::on_btnGenerar_clicked);
    connect(ui->btnCalcular, &QPushButton::clicked, this, &MainWindow::on_btnCalcular_clicked);

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_btnGenerar_clicked()
{
    numVariables = ui->spinVariables->value();
    numRestricciones = ui->spinRestricciones->value();

    coefObjetivo.clear();
    coefRestricciones.clear();
    signoRestricciones.clear();
    ladoDerecho.clear();
    QLayoutItem* item;
    while ((item = ui->layoutObjetivo->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    while ((item = ui->layoutRestricciones->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }


    for (int i = 0; i < numVariables; ++i) {
        QLineEdit* edit = new QLineEdit();
        edit->setFixedWidth(50);
        coefObjetivo.append(edit);

        ui->layoutObjetivo->addWidget(edit, 0, i * 3);

        QLabel* label = new QLabel("x" + QString::number(i + 1));
        ui->layoutObjetivo->addWidget(label, 0, i * 3 + 1);

        if (i < numVariables - 1) {
            QLabel* plus = new QLabel("+");
            ui->layoutObjetivo->addWidget(plus, 0, i * 3 + 2);
        }
    }


    for (int i = 0; i < numRestricciones; ++i) {
        QVector<QLineEdit*> fila;
        for (int j = 0; j < numVariables; ++j) {
            QLineEdit* edit = new QLineEdit();
            edit->setFixedWidth(50);
            fila.append(edit);
            ui->layoutRestricciones->addWidget(edit, i, j * 3);

            QLabel* label = new QLabel("x" + QString::number(j + 1));
            ui->layoutRestricciones->addWidget(label, i, j * 3 + 1);

            if (j < numVariables - 1) {
                QLabel* plus = new QLabel("+");
                ui->layoutRestricciones->addWidget(plus, i, j * 3 + 2);
            }
        }

        coefRestricciones.append(fila);

        QComboBox* signo = new QComboBox();
        signo->addItems({ "<=", "=", ">=" });
        signoRestricciones.append(signo);
        ui->layoutRestricciones->addWidget(signo, i, numVariables * 3);

        QLineEdit* ld = new QLineEdit();
        ld->setFixedWidth(60);
        ladoDerecho.append(ld);
        ui->layoutRestricciones->addWidget(ld, i, numVariables * 3 + 1);
    }

}
void MainWindow::on_btnCalcular_clicked() {
    QVector<double> coeficientesObjetivo;
    QVector<QVector<double>> matrizRestricciones;
    QVector<QString> signos;
    QVector<double> ladosDerechos;

    for (QLineEdit* edit : coefObjetivo) {

        QString texto = edit->text().trimmed();
        if (texto.isEmpty()) {
            QMessageBox::warning(this, "Error", "Por favor llena todos los campos de la función objetivo.");
            return;
        }
        bool ok;
        double valor = texto.toDouble(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Error", "Coeficiente inválido en función objetivo: " + texto);
            return;
        }
        coeficientesObjetivo.append(valor);
    }

    for (int i = 0; i < coefRestricciones.size(); ++i) {
        QVector<double> fila;

        for (QLineEdit* edit : coefRestricciones[i]) {

            QString texto = edit->text().trimmed();
            if (texto.isEmpty()) {
                fila.append(0.0);
            } else {
                bool ok;
                double valor = texto.toDouble(&ok);
                if (!ok) {
                    QMessageBox::warning(this, "Error", "Coeficiente inválido en restricción " + QString::number(i+1) + ": " + texto);
                    return;
                }
                fila.append(valor);
            }
        }
        matrizRestricciones.append(fila);

        QString signo = signoRestricciones[i]->currentText();
        signos.append(signo);

        QString textoDerecho = ladoDerecho[i]->text().trimmed();
        if (textoDerecho.isEmpty()) {
            QMessageBox::warning(this, "Error", "Lado derecho vacío en restricción " + QString::number(i+1));
            return;
        }
        bool ok;
        double valorDerecho = textoDerecho.toDouble(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Error", "Lado derecho inválido en restricción " + QString::number(i+1) + ": " + textoDerecho);
            return;
        }
        ladosDerechos.append(valorDerecho);
    }

    qDebug() << "Función Objetivo:" << coeficientesObjetivo;
    qDebug() << "Restricciones:";
    for (int i = 0; i < matrizRestricciones.size(); ++i) {
        qDebug() << matrizRestricciones[i] << signos[i] << ladosDerechos[i];
    }
    mostrarTablaSimplex(coeficientesObjetivo, matrizRestricciones, signos, ladosDerechos);
}

void MainWindow::mostrarTablaSimplex(
    const QVector<double>& objetivo,
    const QVector<QVector<double>>& restricciones,
    const QVector<QString>& signos,
    const QVector<double>& ladosDerechos)
{
    int numVars = objetivo.size();
    int numRestricciones = restricciones.size();

    int numHolguras = 0;
    for (const QString& signo : signos) {
        if (signo == "<=") numHolguras++;
        else {
            QMessageBox::warning(this, "Advertencia", "Actualmente solo se admite ≤. Las demás serán ignoradas.");
        }
    }

    int totalColumnas = 3 + numVars + numHolguras + 2;
    int totalFilas = numRestricciones + 1;

    ui->tablaSimplex->setRowCount(totalFilas);
    ui->tablaSimplex->setColumnCount(totalColumnas);

    QStringList headers;
    headers << "Ec #" << "VB" << "Z";
    for (int i = 0; i < numVars; ++i)
        headers << "x" + QString::number(i + 1);
    for (int i = 0; i < numHolguras; ++i)
        headers << "s" + QString::number(i + 1);
    headers << "LD";
    headers << "Razón";

    ui->tablaSimplex->setHorizontalHeaderLabels(headers);

    ui->tablaSimplex->setItem(0, 0, new QTableWidgetItem("(0)"));
    ui->tablaSimplex->setItem(0, 1, new QTableWidgetItem("Z"));
    ui->tablaSimplex->setItem(0, 2, new QTableWidgetItem("1"));

    for (int i = 0; i < numVars; ++i) {
        ui->tablaSimplex->setItem(0, 3 + i, new QTableWidgetItem(QString::number(-objetivo[i])));
    }

    for (int i = 0; i < numHolguras; ++i) {
        ui->tablaSimplex->setItem(0, 3 + numVars + i, new QTableWidgetItem("0"));
    }

    ui->tablaSimplex->setItem(0, totalColumnas - 2, new QTableWidgetItem("0"));
    ui->tablaSimplex->setItem(0, totalColumnas - 1, new QTableWidgetItem(""));

    int colPivote = 3;
    double minZ = 0;
    for (int c = 0; c < numVars; ++c) {
        double zCoef = ui->tablaSimplex->item(0, 3 + c)->text().toDouble();
        if (zCoef < minZ) {
            minZ = zCoef;
            colPivote = 3 + c;
        }
    }

    int colHolgura = 0;
    for (int i = 0; i < numRestricciones; ++i) {
        int row = i + 1;

        ui->tablaSimplex->setItem(row, 0, new QTableWidgetItem("(" + QString::number(row) + ")"));
        ui->tablaSimplex->setItem(row, 1, new QTableWidgetItem("s" + QString::number(i + 1)));
        ui->tablaSimplex->setItem(row, 2, new QTableWidgetItem("0")); // Z coef = 0

        for (int j = 0; j < numVars; ++j) {
            ui->tablaSimplex->setItem(row, 3 + j, new QTableWidgetItem(QString::number(restricciones[i][j])));
        }

        for (int j = 0; j < numHolguras; ++j) {
            ui->tablaSimplex->setItem(row, 3 + numVars + j, new QTableWidgetItem("0"));
        }

        if (signos[i] == "<=" && colHolgura < numHolguras) {
            ui->tablaSimplex->setItem(row, 3 + numVars + colHolgura, new QTableWidgetItem("1"));
            colHolgura++;
        }

        double LD = ladosDerechos[i];
        ui->tablaSimplex->setItem(row, totalColumnas - 2, new QTableWidgetItem(QString::number(LD)));

        double valorPivote = ui->tablaSimplex->item(row, colPivote)->text().toDouble();
        if (valorPivote > 0)
            ui->tablaSimplex->setItem(row, totalColumnas - 1,
            new QTableWidgetItem(QString::number(LD / valorPivote, 'f', 2)));
        else
            ui->tablaSimplex->setItem(row, totalColumnas - 1, new QTableWidgetItem("-"));
    }
    imprimirTablaConsola();
}


void MainWindow::imprimirTablaConsola()
{
    int filas = ui->tablaSimplex->rowCount();
    int columnas = ui->tablaSimplex->columnCount();

    QStringList headers;
    for (int j = 0; j < columnas; ++j) {
        headers.append(ui->tablaSimplex->horizontalHeaderItem(j)->text());
    }
    qDebug().noquote() << headers.join("  ");

    for (int i = 0; i < filas; ++i) {
        QStringList filaDatos;
        for (int j = 0; j < columnas; ++j) {
            QTableWidgetItem* item = ui->tablaSimplex->item(i, j);
            filaDatos.append(item ? item->text() : "0");
        }
        qDebug().noquote() << filaDatos.join("  ");
    }
}
