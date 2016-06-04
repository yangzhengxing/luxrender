/****************************************************************************
** Meta object code from reading C++ file 'lightgroupwidget.hxx'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../lux/qtgui/lightgroupwidget.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lightgroupwidget.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LightGroupWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   17,   17,   17, 0x08,
      57,   17,   17,   17, 0x08,
      85,   79,   17,   17, 0x08,
     102,   79,   17,   17, 0x08,
     122,   79,   17,   17, 0x08,
     144,   79,   17,   17, 0x08,
     169,   17,   17,   17, 0x08,
     189,  183,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LightGroupWidget[] = {
    "LightGroupWidget\0\0valuesChanged()\0"
    "rgbEnabledChanged(int)\0bbEnabledChanged(int)\0"
    "value\0gainChanged(int)\0gainChanged(double)\0"
    "colortempChanged(int)\0colortempChanged(double)\0"
    "colorPicker()\0color\0colorSelected(QColor)\0"
};

void LightGroupWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LightGroupWidget *_t = static_cast<LightGroupWidget *>(_o);
        switch (_id) {
        case 0: _t->valuesChanged(); break;
        case 1: _t->rgbEnabledChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->bbEnabledChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->gainChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->gainChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->colortempChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->colortempChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->colorPicker(); break;
        case 8: _t->colorSelected((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LightGroupWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LightGroupWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LightGroupWidget,
      qt_meta_data_LightGroupWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LightGroupWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LightGroupWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LightGroupWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LightGroupWidget))
        return static_cast<void*>(const_cast< LightGroupWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LightGroupWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void LightGroupWidget::valuesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
