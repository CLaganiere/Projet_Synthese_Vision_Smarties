/****************************************************************************
** Meta object code from reading C++ file 'WebCamGrabber.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../WebCamGrabber.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WebCamGrabber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WebCamGrabber_t {
    QByteArrayData data[11];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebCamGrabber_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebCamGrabber_t qt_meta_stringdata_WebCamGrabber = {
    {
QT_MOC_LITERAL(0, 0, 13), // "WebCamGrabber"
QT_MOC_LITERAL(1, 14, 9), // "connected"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "disconnected"
QT_MOC_LITERAL(4, 38, 13), // "imageCaptured"
QT_MOC_LITERAL(5, 52, 5), // "image"
QT_MOC_LITERAL(6, 58, 22), // "readyForCaptureChanged"
QT_MOC_LITERAL(7, 81, 5), // "ready"
QT_MOC_LITERAL(8, 87, 7), // "connect"
QT_MOC_LITERAL(9, 95, 10), // "disconnect"
QT_MOC_LITERAL(10, 106, 7) // "capture"

    },
    "WebCamGrabber\0connected\0\0disconnected\0"
    "imageCaptured\0image\0readyForCaptureChanged\0"
    "ready\0connect\0disconnect\0capture"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebCamGrabber[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WebCamGrabber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WebCamGrabber *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->imageCaptured((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 3: _t->readyForCaptureChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->connect(); break;
        case 5: _t->disconnect(); break;
        case 6: _t->capture(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WebCamGrabber::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebCamGrabber::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WebCamGrabber::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebCamGrabber::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WebCamGrabber::*)(QImage const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebCamGrabber::imageCaptured)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WebCamGrabber::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebCamGrabber::readyForCaptureChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WebCamGrabber::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_WebCamGrabber.data,
    qt_meta_data_WebCamGrabber,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WebCamGrabber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebCamGrabber::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WebCamGrabber.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Camera"))
        return static_cast< Camera*>(this);
    return QObject::qt_metacast(_clname);
}

int WebCamGrabber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void WebCamGrabber::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WebCamGrabber::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WebCamGrabber::imageCaptured(QImage const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WebCamGrabber::readyForCaptureChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
