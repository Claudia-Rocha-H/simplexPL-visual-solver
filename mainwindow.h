#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QVector>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnGenerar_clicked();
    void on_btnCalcular_clicked();
    void imprimirTablaConsola();
    void mostrarTablaSimplex(const QVector<double>& objetivo,
                             const QVector<QVector<double>>& restricciones,
                             const QVector<QString>& signos,
                             const QVector<double>& ladosDerechos);

private:
    Ui::MainWindow *ui;
    int numVariables;
    int numRestricciones;
    QVector<QLineEdit*> coefObjetivo;
    QVector<QVector<QLineEdit*>> coefRestricciones;
    QVector<QComboBox*> signoRestricciones;
    QVector<QLineEdit*> ladoDerecho;
};
#endif // MAINWINDOW_H
