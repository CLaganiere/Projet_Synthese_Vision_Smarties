/****************************************************************************
** Meta object code from reading C++ file 'QIntervalScrollBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QIntervalScrollBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QIntervalScrollBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QIntervalScrollBar_t {
    QByteArrayData data[19];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QIntervalScrollBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QIntervalScrollBar_t qt_meta_stringdata_QIntervalScrollBar = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QIntervalScrollBar"
QT_MOC_LITERAL(1, 19, 12), // "rangeChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "min"
QT_MOC_LITERAL(4, 37, 3), // "max"
QT_MOC_LITERAL(5, 41, 15), // "intervalChanged"
QT_MOC_LITERAL(6, 57, 3), // "low"
QT_MOC_LITERAL(7, 61, 2), // "up"
QT_MOC_LITERAL(8, 64, 10), // "setMinimum"
QT_MOC_LITERAL(9, 75, 10), // "setMaximum"
QT_MOC_LITERAL(10, 86, 8), // "setRange"
QT_MOC_LITERAL(11, 95, 8), // "setLower"
QT_MOC_LITERAL(12, 104, 8), // "setUpper"
QT_MOC_LITERAL(13, 113, 11), // "setInterval"
QT_MOC_LITERAL(14, 125, 18), // "setIntervalToRange"
QT_MOC_LITERAL(15, 144, 24), // "updateFromLowerScrollBar"
QT_MOC_LITERAL(16, 169, 24), // "updateFromUpperScrollBar"
QT_MOC_LITERAL(17, 194, 22), // "updateFromLowerSpinBox"
QT_MOC_LITERAL(18, 217, 22) // "updateFromUpperSpinBox"

    },
    "QIntervalScrollBar\0rangeChanged\0\0min\0"
    "max\0intervalChanged\0low\0up\0setMinimum\0"
    "setMaximum\0setRange\0setLower\0setUpper\0"
    "setInterval\0setIntervalToRange\0"
    "updateFromLowerScrollBar\0"
    "updateFromUpperScrollBar\0"
    "updateFromLowerSpinBox\0updateFromUpperSpinBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QIntervalScrollBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       5,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   89,    2, 0x0a /* Public */,
       9,    1,   92,    2, 0x0a /* Public */,
      10,    2,   95,    2, 0x0a /* Public */,
      11,    1,  100,    2, 0x0a /* Public */,
      12,    1,  103,    2, 0x0a /* Public */,
      13,    2,  106,    2, 0x0a /* Public */,
      14,    0,  111,    2, 0x0a /* Public */,
      15,    1,  112,    2, 0x08 /* Private */,
      16,    1,  115,    2, 0x08 /* Private */,
      17,    1,  118,    2, 0x08 /* Private */,
      18,    1,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void QIntervalScrollBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QIntervalScrollBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->intervalChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setMinimum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setMaximum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setLower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setUpper((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setInterval((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->setIntervalToRange(); break;
        case 9: _t->updateFromLowerScrollBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updateFromUpperScrollBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateFromLowerSpinBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->updateFromUpperSpinBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QIntervalScrollBar::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QIntervalScrollBar::rangeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QIntervalScrollBar::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QIntervalScrollBar::intervalChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QIntervalScrollBar::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QIntervalScrollBar.data,
    qt_meta_data_QIntervalScrollBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QIntervalScrollBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QIntervalScrollBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QIntervalScrollBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QIntervalScrollBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void QIntervalScrollBar::rangeChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QIntervalScrollBar::intervalChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
