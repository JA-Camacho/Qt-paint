#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QColorDialog>
#include <QInputDialog>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#define DEFAULT_ANCHO 2;

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void on_actionColor_triggered();

    void on_actionAncho_triggered();

    void on_actionGuardar_triggered();

    void on_actionLibre_triggered();

    void on_actionL_neas_triggered();

    void on_actionRect_ngulos_triggered();

    void on_actionCircunferencia_triggered();

    void on_actionNuevo_triggered();

    void on_actionSalir_triggered();

private:
    Ui::Principal *ui;
    QPen pincel;
    QColor m_color; //Color de la linea
    int m_width; //Ancho de la linea
    int m_opcion; //Opcion de dibujo
    QImage *m_imagen; //Imagen sobre la cual se va a dibujar
    QPainter *m_painter; //El objeto painter
    QPoint m_ptInicial; //Punto inicial para dibujar
    QPoint m_ptFinal;   //Punto final para dibujar
    bool m_toogle = true;
};
#endif // PRINCIPAL_H
