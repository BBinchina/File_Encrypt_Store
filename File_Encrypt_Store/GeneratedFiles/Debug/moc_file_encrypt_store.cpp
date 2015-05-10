/****************************************************************************
** Meta object code from reading C++ file 'file_encrypt_store.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../file_encrypt_store.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'file_encrypt_store.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_File_Encrypt_Store[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      37,   19,   19,   19, 0x08,
      55,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_File_Encrypt_Store[] = {
    "File_Encrypt_Store\0\0new_filedialog()\0"
    "encrypt_program()\0query_keyname_exist()\0"
};

void File_Encrypt_Store::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        File_Encrypt_Store *_t = static_cast<File_Encrypt_Store *>(_o);
        switch (_id) {
        case 0: _t->new_filedialog(); break;
        case 1: _t->encrypt_program(); break;
        case 2: _t->query_keyname_exist(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData File_Encrypt_Store::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject File_Encrypt_Store::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_File_Encrypt_Store,
      qt_meta_data_File_Encrypt_Store, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &File_Encrypt_Store::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *File_Encrypt_Store::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *File_Encrypt_Store::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_File_Encrypt_Store))
        return static_cast<void*>(const_cast< File_Encrypt_Store*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int File_Encrypt_Store::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
