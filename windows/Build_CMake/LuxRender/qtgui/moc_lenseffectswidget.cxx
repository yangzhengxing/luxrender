/****************************************************************************
** Meta object code from reading C++ file 'lenseffectswidget.hxx'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../lux/qtgui/lenseffectswidget.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lenseffectswidget.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LensEffectsWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      35,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   49,   18,   18, 0x08,
      82,   49,   18,   18, 0x08,
     112,   49,   18,   18, 0x08,
     139,   49,   18,   18, 0x08,
     169,   18,   18,   18, 0x08,
     189,   18,   18,   18, 0x08,
     208,   49,   18,   18, 0x08,
     237,   49,   18,   18, 0x08,
     269,   49,   18,   18, 0x08,
     299,   49,   18,   18, 0x08,
     320,   49,   18,   18, 0x08,
     344,   49,   18,   18, 0x08,
     366,   49,   18,   18, 0x08,
     390,   49,   18,   18, 0x08,
     417,   49,   18,   18, 0x08,
     441,   49,   18,   18, 0x08,
     468,   49,   18,   18, 0x08,
     492,   49,   18,   18, 0x08,
     525,   49,   18,   18, 0x08,
     562,   18,   18,   18, 0x08,
     583,   18,   18,   18, 0x08,
     605,   18,   18,   18, 0x08,
     628,   18,   18,   18, 0x08,
     648,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LensEffectsWidget[] = {
    "LensEffectsWidget\0\0valuesChanged()\0"
    "forceUpdate()\0value\0gaussianAmountChanged(int)\0"
    "gaussianAmountChanged(double)\0"
    "gaussianRadiusChanged(int)\0"
    "gaussianRadiusChanged(double)\0"
    "computeBloomLayer()\0deleteBloomLayer()\0"
    "vignettingAmountChanged(int)\0"
    "vignettingAmountChanged(double)\0"
    "vignettingEnabledChanged(int)\0"
    "caAmountChanged(int)\0caAmountChanged(double)\0"
    "caEnabledChanged(int)\0glareAmountChanged(int)\0"
    "glareAmountChanged(double)\0"
    "glareRadiusChanged(int)\0"
    "glareRadiusChanged(double)\0"
    "glareBladesChanged(int)\0"
    "glareThresholdSliderChanged(int)\0"
    "glareThresholdSpinBoxChanged(double)\0"
    "glareMapChanged(int)\0glareBrowsePupilMap()\0"
    "glareBrowseLashesMap()\0computeGlareLayer()\0"
    "deleteGlareLayer()\0"
};

void LensEffectsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LensEffectsWidget *_t = static_cast<LensEffectsWidget *>(_o);
        switch (_id) {
        case 0: _t->valuesChanged(); break;
        case 1: _t->forceUpdate(); break;
        case 2: _t->gaussianAmountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->gaussianAmountChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->gaussianRadiusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->gaussianRadiusChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->computeBloomLayer(); break;
        case 7: _t->deleteBloomLayer(); break;
        case 8: _t->vignettingAmountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->vignettingAmountChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->vignettingEnabledChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->caAmountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->caAmountChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->caEnabledChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->glareAmountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->glareAmountChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->glareRadiusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->glareRadiusChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->glareBladesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->glareThresholdSliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->glareThresholdSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->glareMapChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->glareBrowsePupilMap(); break;
        case 23: _t->glareBrowseLashesMap(); break;
        case 24: _t->computeGlareLayer(); break;
        case 25: _t->deleteGlareLayer(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LensEffectsWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LensEffectsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LensEffectsWidget,
      qt_meta_data_LensEffectsWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LensEffectsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LensEffectsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LensEffectsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LensEffectsWidget))
        return static_cast<void*>(const_cast< LensEffectsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LensEffectsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void LensEffectsWidget::valuesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void LensEffectsWidget::forceUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
