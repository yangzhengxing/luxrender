/****************************************************************************
** Meta object code from reading C++ file 'colorspacewidget.hxx'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../lux/qtgui/colorspacewidget.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorspacewidget.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ColorSpaceWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   34,   17,   17, 0x08,
      66,   34,   17,   17, 0x08,
      97,   91,   17,   17, 0x08,
     121,   91,   17,   17, 0x08,
     148,   91,   17,   17, 0x08,
     172,   91,   17,   17, 0x08,
     199,   91,   17,   17, 0x08,
     221,   91,   17,   17, 0x08,
     238,   91,   17,   17, 0x08,
     258,   91,   17,   17, 0x08,
     275,   91,   17,   17, 0x08,
     295,   91,   17,   17, 0x08,
     313,   91,   17,   17, 0x08,
     334,   91,   17,   17, 0x08,
     352,   91,   17,   17, 0x08,
     373,   91,   17,   17, 0x08,
     392,   91,   17,   17, 0x08,
     414,   91,   17,   17, 0x08,
     433,   91,   17,   17, 0x08,
     455,   91,   17,   17, 0x08,
     479,   91,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ColorSpaceWidget[] = {
    "ColorSpaceWidget\0\0valuesChanged()\0"
    "choice\0setColorSpacePreset(int)\0"
    "setWhitepointPreset(int)\0value\0"
    "whitePointXChanged(int)\0"
    "whitePointXChanged(double)\0"
    "whitePointYChanged(int)\0"
    "whitePointYChanged(double)\0"
    "precisionChanged(int)\0redXChanged(int)\0"
    "redXChanged(double)\0redYChanged(int)\0"
    "redYChanged(double)\0blueXChanged(int)\0"
    "blueXChanged(double)\0blueYChanged(int)\0"
    "blueYChanged(double)\0greenXChanged(int)\0"
    "greenXChanged(double)\0greenYChanged(int)\0"
    "greenYChanged(double)\0temperatureChanged(int)\0"
    "temperatureChanged(double)\0"
};

void ColorSpaceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ColorSpaceWidget *_t = static_cast<ColorSpaceWidget *>(_o);
        switch (_id) {
        case 0: _t->valuesChanged(); break;
        case 1: _t->setColorSpacePreset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setWhitepointPreset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->whitePointXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->whitePointXChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->whitePointYChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->whitePointYChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->precisionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->redXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->redXChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->redYChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->redYChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->blueXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->blueXChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->blueYChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->blueYChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->greenXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->greenXChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->greenYChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->greenYChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->temperatureChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->temperatureChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ColorSpaceWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ColorSpaceWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ColorSpaceWidget,
      qt_meta_data_ColorSpaceWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ColorSpaceWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ColorSpaceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ColorSpaceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorSpaceWidget))
        return static_cast<void*>(const_cast< ColorSpaceWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ColorSpaceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void ColorSpaceWidget::valuesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
