#ifndef COMPASSSENSOR_H
#define COMPASSSENSOR_H

#include <QObject>
#include <QMagnetometer>
#include <QMagnetometerReading>

class CompassSensor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal azimuth READ azimuth NOTIFY azimuthChanged)
    Q_PROPERTY(QString corrections READ corrections)
    Q_PROPERTY(qreal orig_azimuth READ orig_azimuth NOTIFY orig_azimuthChanged)

    public:
        explicit CompassSensor(QObject *parent = nullptr);
        qreal azimuth() const;
        qreal orig_azimuth() const;
        QString corrections() const;
        bool hasSensorsPermission() const;

    signals:
        void azimuthChanged();
        void orig_azimuthChanged();

    private slots:
        void updateAzimuth();
        //void updateOrig_azimuth();

    private:
        QMagnetometer *m_magnetometer;
        qreal m_azimuth;
        qreal m_orig_azimuth;
        qreal alpha;
        qreal smoothedX = 0;
        qreal smoothedY = 0;
        const qreal m_correctionN = 0.0;
        const qreal m_correctionE = 0.0;
        const qreal m_correctionS = 0.0;
        const qreal m_correctionW = 0.0;

};

#endif // COMPASSSENSOR_H
