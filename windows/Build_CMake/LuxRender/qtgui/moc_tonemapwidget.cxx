/****************************************************************************
** Meta object code from reading C++ file 'tonemapwidget.hxx'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../lux/qtgui/tonemapwidget.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tonemapwidget.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ToneMapWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      31,   14,   14,   14, 0x05,
      47,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   61,   14,   14, 0x08,
      90,   61,   14,   14, 0x08,
     110,   61,   14,   14, 0x08,
     136,   61,   14,   14, 0x08,
     159,   61,   14,   14, 0x08,
     185,  179,   14,   14, 0x08,
     206,  179,   14,   14, 0x08,
     230,  179,   14,   14, 0x08,
     252,  179,   14,   14, 0x08,
     277,  179,   14,   14, 0x08,
     294,  179,   14,   14, 0x08,
     314,  179,   14,   14, 0x08,
     338,  179,   14,   14, 0x08,
     365,  179,   14,   14, 0x08,
     386,  179,   14,   14, 0x08,
     410,  179,   14,   14, 0x08,
     428,  179,   14,   14, 0x08,
     449,  179,   14,   14, 0x08,
     473,  179,   14,   14, 0x08,
     500,   14,   14,   14, 0x08,
     517,  179,   14,   14, 0x08,
     533,  179,   14,   14, 0x08,
     552,  179,   14,   14, 0x08,
     576,  179,   14,   14, 0x08,
     600,   14,   14,   14, 0x08,
     621,  179,   14,   14, 0x08,
     648,   14,   14,   14, 0x08,
     669,  179,   14,   14, 0x08,
     696,   61,   14,   14, 0x08,
     716,   61,   14,   14, 0x08,
     740,   14,   14,   14, 0x08,
     757,   14,   14,   14, 0x08,
     774,  179,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ToneMapWidget[] = {
    "ToneMapWidget\0\0valuesChanged()\0"
    "returnPressed()\0textChanged()\0choice\0"
    "setTonemapKernel(int)\0setClampMethod(int)\0"
    "setSensitivityPreset(int)\0"
    "setExposurePreset(int)\0setFStopPreset(int)\0"
    "value\0prescaleChanged(int)\0"
    "prescaleChanged(double)\0postscaleChanged(int)\0"
    "postscaleChanged(double)\0burnChanged(int)\0"
    "burnChanged(double)\0sensitivityChanged(int)\0"
    "sensitivityChanged(double)\0"
    "exposureChanged(int)\0exposureChanged(double)\0"
    "fstopChanged(int)\0fstopChanged(double)\0"
    "gammaLinearChanged(int)\0"
    "gammaLinearChanged(double)\0estimateLinear()\0"
    "ywaChanged(int)\0ywaChanged(double)\0"
    "falsemaxChanged(double)\0falseminChanged(double)\0"
    "falsemaxSatChanged()\0falsemaxSatChanged(double)\0"
    "falseminSatChanged()\0falseminSatChanged(double)\0"
    "setFalseMethod(int)\0setFalseColorScale(int)\0"
    "initFalseColor()\0legendeChanged()\0"
    "legendeChanged(int)\0"
};

void ToneMapWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ToneMapWidget *_t = static_cast<ToneMapWidget *>(_o);
        switch (_id) {
        case 0: _t->valuesChanged(); break;
        case 1: _t->returnPressed(); break;
        case 2: _t->textChanged(); break;
        case 3: _t->setTonemapKernel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setClampMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setSensitivityPreset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setExposurePreset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setFStopPreset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->prescaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->prescaleChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->postscaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->postscaleChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->burnChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->burnChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->sensitivityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->sensitivityChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->exposureChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->exposureChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->fstopChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->fstopChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->gammaLinearChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->gammaLinearChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: _t->estimateLinear(); break;
        case 23: _t->ywaChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->ywaChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->falsemaxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->falseminChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->falsemaxSatChanged(); break;
        case 28: _t->falsemaxSatChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->falseminSatChanged(); break;
        case 30: _t->falseminSatChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->setFalseMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->setFalseColorScale((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->initFalseColor(); break;
        case 34: _t->legendeChanged(); break;
        case 35: _t->legendeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ToneMapWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ToneMapWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ToneMapWidget,
      qt_meta_data_ToneMapWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ToneMapWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ToneMapWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ToneMapWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ToneMapWidget))
        return static_cast<void*>(const_cast< ToneMapWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ToneMapWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void ToneMapWidget::valuesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ToneMapWidget::returnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ToneMapWidget::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
