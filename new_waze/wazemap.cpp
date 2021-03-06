#include "wazemap.h"
#include <QtLocation/QGeoMappingManager>
#include <QtLocation/QGeoServiceProvider>
#include <QGeoCoordinate>
#include "wazemapimageitem.h"

QTM_USE_NAMESPACE

WazeMap::WazeMap() :
    QGraphicsGeoMap((new QGeoServiceProvider("nokia"))->mappingManager())
{
    if (!supportsBearing())
        qDebug("Bearing not supported");

    connect(&_positionSource, SIGNAL(positionUpdated(WazePosition&)), this, SLOT(onPositionChanged()));
    connect(this, SIGNAL(trackPositionChanged()), this, SLOT(onTrackPositionChanged()));
    connect(this, SIGNAL(currentPositionChanged()), this, SIGNAL(speedChanged()));
    connect(this, SIGNAL(currentPositionChanged()), this, SIGNAL(azymuthChanged()));
    connect(this, SIGNAL(currentPositionChanged()), this, SIGNAL(accuracyChanged()));
}


void WazeMap::addMapObject(WazeMapImageItem* imageItem)
{
    QGraphicsGeoMap::addMapObject(imageItem);
}

bool WazeMap::trackPosition()
{
    return _trackPosition;
}

void WazeMap::setTrackPosition(bool trackPosition)
{
    if (_trackPosition == trackPosition) return;

    _trackPosition = trackPosition;

    emit trackPositionChanged();
}

WazePosition& WazeMap::currentPosition()
{
    return _positionSource.position();
}

int WazeMap::speed()
{
    return _positionSource.position().speed();
}

int WazeMap::azymuth()
{
    return _positionSource.position().azymuth();
}

int WazeMap::accuracy()
{
    return _positionSource.position().accuracy();
}

void WazeMap::onPositionChanged()
{
    WazePosition& posSource =  _positionSource.position();
    QGeoCoordinate center = QGraphicsGeoMap::center();
    if (_trackPosition &&
        (center.longitude() != posSource.longitude() ||
         center.latitude() != posSource.latitude()))
    {
        setCenter(posSource.toCoordinate());
        //pan(center.longitude() - posSource.longitude(), center.latitude() - posSource.latitude());
    }

    emit currentPositionChanged();
}

void WazeMap::onTrackPositionChanged()
{
    if (_trackPosition)
    {
        setCenter(_positionSource.position().toCoordinate());
    }
}
