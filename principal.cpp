#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //Instancia de la imagen
    m_imagen = new QImage(this->size(), QImage::Format_ARGB32_Premultiplied);

    //Rellenar de blanco
    m_imagen->fill(Qt::white);

    //Instanciar el objeto painter
    m_painter = new QPainter(m_imagen);
    m_painter->setRenderHint(QPainter::Antialiasing);
    m_color = Qt::black;
    m_width = DEFAULT_ANCHO;
    m_opcion = 1;
}

Principal::~Principal()
{
    delete ui;
}
/**
 * @brief Principal::paintEvent Se ejecuta cada vez que se redibuja la interfaz
 * @param event
 */
void Principal::paintEvent(QPaintEvent *event)
{
    //Crear otro painter (local)
    QPainter painter(this);

    //Dibujar la imagen
    painter.drawImage(0,0, *m_imagen);

    //Aceptar el evento
    event->accept();
}

void Principal::mousePressEvent(QMouseEvent *event)
{
    m_ptInicial = event->pos();
    /*if(m_opcion == 1){
        m_ptInicial = event->pos();
    }else if (m_opcion == 2){
        if (m_toogle){
            m_ptInicial = event->pos();
        }else {
            m_ptFinal = event->pos();
            QPen pincel;
            pincel.setColor(m_color);
            pincel.setWidth(m_width);
            m_painter->setPen(pincel);
            m_painter->drawLine(m_ptInicial, m_ptFinal);
            //Redibujar la interfaz grafica
            update();
        }
    }else if(m_opcion == 3){
        if (m_toogle){
            m_ptInicial = event->pos();
        }else {
            m_ptFinal = event->pos();
            //Dibujar rectangulo
            int ancho = m_ptFinal.x() - m_ptInicial.y();
            int alto = m_ptFinal.y() - m_ptInicial.y();
            QPen pincel;
            pincel.setColor(m_color);
            pincel.setWidth(m_width);
            m_painter->setPen(pincel);
            m_painter->drawRect(m_ptInicial.x(), m_ptInicial.y(), ancho, alto);
            //Redibujar la interfaz grafica
            update();
        }
    }else if(m_opcion == 4){
        if (m_toogle){
            m_ptInicial = event->pos();
        }else {
            m_ptFinal = event->pos();
            //Dibujar rectangulo
            QPen pincel;
            pincel.setColor(m_color);
            pincel.setWidth(m_width);
            QRectF circulo(m_ptInicial, m_ptFinal);
            m_painter->setPen(pincel);
            m_painter->drawEllipse(circulo);
            //Redibujar la interfaz grafica
            update();
        }
    }
    m_toogle = !m_toogle;*/
}

void Principal::mouseMoveEvent(QMouseEvent *event)
{
    if(m_opcion == 1){
        m_ptFinal = event->pos();
        QPen pincel;
        pincel.setColor(m_color);
        pincel.setWidth(m_width);
        m_painter->setPen(pincel);
        m_painter->drawLine(m_ptInicial, m_ptFinal);
    }
    update();
    m_ptInicial = m_ptFinal;
}

void Principal::on_actionColor_triggered()
{
    m_color = QColorDialog::getColor(m_color,this,"Color del pincel");
}

void Principal::on_actionAncho_triggered()
{
    m_width = QInputDialog::getInt(this, "Ancho del pincel", "Inserte el ancho del pincel",1,1,10);
}

void Principal::on_actionGuardar_triggered()
{
    //Crear un objeto QDir a partir del directorio del usuario
    QDir directorio = QDir::home();

    //Agregar al path absoluto del objeto un nombre por defecto del archivo
    QString pathArchivo = directorio.absolutePath();

    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",pathArchivo,"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (m_imagen->save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_actionLibre_triggered()
{
    m_opcion = 1;
}

void Principal::on_actionL_neas_triggered()
{
    m_opcion = 2;
    m_toogle = true;
}

void Principal::on_actionRect_ngulos_triggered()
{
    m_opcion = 3;
}

void Principal::on_actionCircunferencia_triggered()
{
    m_opcion = 4;
}

void Principal::on_actionNuevo_triggered()
{
    m_imagen->fill(Qt::white);
    m_color = Qt::black;
    m_width = DEFAULT_ANCHO;
    m_opcion = 1;
    update();
}

void Principal::on_actionSalir_triggered()
{
    this->close();
}
