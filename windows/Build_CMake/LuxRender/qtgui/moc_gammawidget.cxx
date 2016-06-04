/****************************************************************************
** Meta object code from reading C++ file 'gammawidget.hxx'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../lux/qtgui/gammawidget.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gammawidget.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GammaWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   29,   12,   12, 0x08,
      53,   29,   12,   12, 0x08,
      74,   29,   12,   12, 0x08,
      98,   90,   12,   12, 0x08,
     120,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GammaWidget[] = {
    "GammaWidget\0\0valuesChanged()\0value\0"
    "gammaChanged(int)\0gammaChanged(double)\0"
    "CRFChanged(int)\0sOption\0SetCRFPreset(QString)\0"
    "loadCRF()\0"
};

void GammaWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GammaWidget *_t = static_cast<GammaWidget *>(_o);
        switch (_id) {
        case 0: _t->valuesChanged(); break;
        case 1: _t->gammaChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->gammaChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->CRFChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SetCRFPreset((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->loadCRF(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GammaWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GammaWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GammaWidget,
      qt_meta_data_GammaWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GammaWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GammaWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GammaWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GammaWidget))
        return static_cast<void*>(const_cast< GammaWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GammaWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GammaWidget::valuesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
