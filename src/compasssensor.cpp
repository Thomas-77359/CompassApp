#include "compasssensor.h"
#include <QtMath>
#include <QDebug>
#include <QSensor>
#include <QThread>  //not orig
#include <QFile>

CompassSensor::CompassSensor(QObject *parent) : QObject(parent), m_azimuth(0)
{
    m_magnetometer = new QMagnetometer(this);

    m_magnetometer->setDataRate(2);
    m_magnetometer->setActive(true);

    m_magnetometer->start();

    connect(m_magnetometer, &QMagnetometer::readingChanged, this, &CompassSensor::updateAzimuth);
}





qreal CompassSensor::azimuth() const
{
    return m_azimuth;
}

qreal CompassSensor::orig_azimuth() const
{
    return m_orig_azimuth;
}

QString CompassSensor::corrections() const
{
    std::string init(std::to_string(qRound(m_correctionN * 100)/100.0) + "," + std::to_string(qRound(m_correctionE * 100)/100.0) + "," + std::to_string(qRound(m_correctionS * 100)/100.0) + "," + std::to_string(qRound(m_correctionW * 100)/100.0));
    QString qstr = QString::fromStdString(init);
    return qstr;
}

void CompassSensor::updateAzimuth()
{
    QMagnetometerReading *reading = m_magnetometer->reading();
    qreal x = reading->x();
    qreal y = reading->y();

    alpha = 0.1;

    smoothedX = alpha * x + (1.0 - alpha) * smoothedX;
    smoothedY = alpha * y + (1.0 - alpha) * smoothedY;


    //qreal azimuth = qAtan2(y,x) * (180 / M_PI);
    qreal azimuth = qAtan2(smoothedY,smoothedX);
    azimuth = qRadiansToDegrees(azimuth);
    m_orig_azimuth = azimuth;

    if(azimuth > 270 || azimuth <= 45){
        azimuth = azimuth + m_correctionN; //manual correction
    }
    else if (azimuth > 45 && azimuth <= 135 ){
        azimuth = azimuth + m_correctionE;
    }
    else if (azimuth > 135 && azimuth <= 225){
        azimuth = azimuth + m_correctionS; //manual correction
    }
    else if (azimuth > 225 && azimuth <= 270){
        azimuth = azimuth + m_correctionW; //manual correction
    }



    if(azimuth <0){
        azimuth += 360;
    }

    if(m_azimuth != azimuth){
        //m_azimuth = azimuth - 15;

        m_azimuth = 360 - azimuth;

        emit azimuthChanged();
        emit orig_azimuthChanged();
    }
}
