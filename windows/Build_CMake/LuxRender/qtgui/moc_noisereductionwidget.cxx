/****************************************************************************
** Meta object code from reading C++ file 'noisereductionwidget.hxx'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../lux/qtgui/noisereductionwidget.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'noisereductionwidget.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NoiseReductionWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   38,   21,   21, 0x08,
      78,   38,   21,   21, 0x08,
     115,   38,   21,   21, 0x08,
     139,   38,   21,   21, 0x08,
     172,   38,   21,   21, 0x08,
     195,   38,   21,   21, 0x08,
     221,   38,   21,   21, 0x08,
     243,   38,   21,   21, 0x08,
     268,   38,   21,   21, 0x08,
     290,   38,   21,   21, 0x08,
     315,   38,   21,   21, 0x08,
     333,   38,   21,   21, 0x08,
     354,   38,   21,   21, 0x08,
     372,   38,   21,   21, 0x08,
     393,   38,   21,   21, 0x08,
     415,   38,   21,   21, 0x08,
     440,   38,   21,   21, 0x08,
     458,   38,   21,   21, 0x08,
     479,   38,   21,   21, 0x08,
     499,   38,   21,   21, 0x08,
     522,   38,   21,   21, 0x08,
     542,   38,   21,   21, 0x08,
     565,   38,   21,   21, 0x08,
     586,   38,   21,   21, 0x08,
     609,   38,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NoiseReductionWidget[] = {
    "NoiseReductionWidget\0\0valuesChanged()\0"
    "value\0regularizationEnabledChanged(int)\0"
    "fastApproximationEnabledChanged(int)\0"
    "chiuEnabledChanged(int)\0"
    "includeCenterEnabledChanged(int)\0"
    "iterationsChanged(int)\0iterationsChanged(double)\0"
    "amplitudeChanged(int)\0amplitudeChanged(double)\0"
    "precisionChanged(int)\0precisionChanged(double)\0"
    "alphaChanged(int)\0alphaChanged(double)\0"
    "sigmaChanged(int)\0sigmaChanged(double)\0"
    "sharpnessChanged(int)\0sharpnessChanged(double)\0"
    "anisoChanged(int)\0anisoChanged(double)\0"
    "spatialChanged(int)\0spatialChanged(double)\0"
    "angularChanged(int)\0angularChanged(double)\0"
    "setInterpolType(int)\0chiuRadiusChanged(int)\0"
    "chiuRadiusChanged(double)\0"
};

void NoiseReductionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NoiseReductionWidget *_t = static_cast<NoiseReductionWidget *>(_o);
        switch (_id) {
        case 0: _t->valuesChanged(); break;
        case 1: _t->regularizationEnabledChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->fastApproximationEnabledChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->chiuEnabledChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->includeCenterEnabledChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->iterationsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->iterationsChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->amplitudeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->amplitudeChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->precisionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->precisionChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->alphaChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->alphaChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->sigmaChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->sigmaChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->sharpnessChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->sharpnessChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->anisoChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->anisoChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->spatialChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->spatialChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->angularChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->angularChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->setInterpolType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->chiuRadiusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->chiuRadiusChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NoiseReductionWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NoiseReductionWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NoiseReductionWidget,
      qt_meta_data_NoiseReductionWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NoiseReductionWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NoiseReductionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NoiseReductionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NoiseReductionWidget))
        return static_cast<void*>(const_cast< NoiseReductionWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int NoiseReductionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void NoiseReductionWidget::valuesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
