/****************************************************************************
** Meta object code from reading C++ file 'FileImageGrabber.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../FileImageGrabber.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileImageGrabber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileImageGrabber_t {
    QByteArrayData data[11];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileImageGrabber_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileImageGrabber_t qt_meta_stringdata_FileImageGrabber = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FileImageGrabber"
QT_MOC_LITERAL(1, 17, 11), // "imageLoaded"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "image"
QT_MOC_LITERAL(4, 36, 11), // "colorLoaded"
QT_MOC_LITERAL(5, 48, 18), // "std::vector<Color>"
QT_MOC_LITERAL(6, 67, 9), // "vectColor"
QT_MOC_LITERAL(7, 77, 8), // "setImage"
QT_MOC_LITERAL(8, 86, 9), // "openImage"
QT_MOC_LITERAL(9, 96, 9), // "loadImage"
QT_MOC_LITERAL(10, 106, 14) // "loadColorDebug"

    },
    "FileImageGrabber\0imageLoaded\0\0image\0"
    "colorLoaded\0std::vector<Color>\0vectColor\0"
    "setImage\0openImage\0loadImage\0"
    "loadColorDebug"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileImageGrabber[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   50,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,
       9,    0,   54,    2, 0x0a /* Public */,
      10,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FileImageGrabber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileImageGrabber *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageLoaded((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->colorLoaded((*reinterpret_cast< std::vector<Color>(*)>(_a[1]))); break;
        case 2: _t->setImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 3: _t->openImage(); break;
        case 4: _t->loadImage(); break;
        case 5: _t->loadColorDebug(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileImageGrabber::*)(QImage const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileImageGrabber::imageLoaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileImageGrabber::*)(std::vector<Color> const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileImageGrabber::colorLoaded)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileImageGrabber::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_FileImageGrabber.data,
    qt_meta_data_FileImageGrabber,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileImageGrabber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileImageGrabber::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileImageGrabber.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileImageGrabber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FileImageGrabber::imageLoaded(QImage const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileImageGrabber::colorLoaded(std::vector<Color> const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
