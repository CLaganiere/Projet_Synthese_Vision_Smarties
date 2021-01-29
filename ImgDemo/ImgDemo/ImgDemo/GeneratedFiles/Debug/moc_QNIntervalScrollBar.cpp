/****************************************************************************
** Meta object code from reading C++ file 'QNIntervalScrollBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QNIntervalScrollBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QNIntervalScrollBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QNIntervalScrollBar_t {
    QByteArrayData data[15];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QNIntervalScrollBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QNIntervalScrollBar_t qt_meta_stringdata_QNIntervalScrollBar = {
    {
QT_MOC_LITERAL(0, 0, 19), // "QNIntervalScrollBar"
QT_MOC_LITERAL(1, 20, 12), // "rangeChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "intervalChanged"
QT_MOC_LITERAL(4, 50, 10), // "setMinimum"
QT_MOC_LITERAL(5, 61, 3), // "min"
QT_MOC_LITERAL(6, 65, 10), // "setMaximum"
QT_MOC_LITERAL(7, 76, 3), // "max"
QT_MOC_LITERAL(8, 80, 8), // "setRange"
QT_MOC_LITERAL(9, 89, 8), // "setLower"
QT_MOC_LITERAL(10, 98, 3), // "low"
QT_MOC_LITERAL(11, 102, 8), // "setUpper"
QT_MOC_LITERAL(12, 111, 2), // "up"
QT_MOC_LITERAL(13, 114, 11), // "setInterval"
QT_MOC_LITERAL(14, 126, 18) // "setIntervalToRange"

    },
    "QNIntervalScrollBar\0rangeChanged\0\0"
    "intervalChanged\0setMinimum\0min\0"
    "setMaximum\0max\0setRange\0setLower\0low\0"
    "setUpper\0up\0setInterval\0setIntervalToRange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QNIntervalScrollBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   61,    2, 0x0a /* Public */,
       6,    1,   64,    2, 0x0a /* Public */,
       8,    2,   67,    2, 0x0a /* Public */,
       9,    1,   72,    2, 0x0a /* Public */,
      11,    1,   75,    2, 0x0a /* Public */,
      13,    2,   78,    2, 0x0a /* Public */,
      14,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    7,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   12,
    QMetaType::Void,

       0        // eod
};

void QNIntervalScrollBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QNIntervalScrollBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rangeChanged(); break;
        case 1: _t->intervalChanged(); break;
        case 2: _t->setMinimum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setMaximum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setLower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setUpper((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setInterval((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->setIntervalToRange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QNIntervalScrollBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNIntervalScrollBar::rangeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QNIntervalScrollBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNIntervalScrollBar::intervalChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QNIntervalScrollBar::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QNIntervalScrollBar.data,
    qt_meta_data_QNIntervalScrollBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QNIntervalScrollBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNIntervalScrollBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QNIntervalScrollBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QNIntervalScrollBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QNIntervalScrollBar::rangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QNIntervalScrollBar::intervalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
