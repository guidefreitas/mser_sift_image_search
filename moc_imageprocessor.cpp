/****************************************************************************
** Meta object code from reading C++ file 'imageprocessor.h'
**
** Created: Wed May 15 12:51:53 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imageprocessor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageProcessor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      45,   15,   15,   15, 0x05,
      66,   15,   15,   15, 0x05,
      86,   15,   15,   15, 0x05,
     103,   15,   15,   15, 0x05,
     120,   15,   15,   15, 0x05,
     134,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     151,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageProcessor[] = {
    "ImageProcessor\0\0captureOriginalFrame(QImage)\0"
    "captureFrame(QImage)\0trainningComplete()\0"
    "trainningStart()\0trainningClear()\0"
    "searchStart()\0searchComplete()\0DoWork()\0"
};

void ImageProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageProcessor *_t = static_cast<ImageProcessor *>(_o);
        switch (_id) {
        case 0: _t->captureOriginalFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->captureFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->trainningComplete(); break;
        case 3: _t->trainningStart(); break;
        case 4: _t->trainningClear(); break;
        case 5: _t->searchStart(); break;
        case 6: _t->searchComplete(); break;
        case 7: _t->DoWork(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageProcessor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageProcessor,
      qt_meta_data_ImageProcessor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageProcessor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcessor))
        return static_cast<void*>(const_cast< ImageProcessor*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ImageProcessor::captureOriginalFrame(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageProcessor::captureFrame(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImageProcessor::trainningComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ImageProcessor::trainningStart()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ImageProcessor::trainningClear()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void ImageProcessor::searchStart()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void ImageProcessor::searchComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
