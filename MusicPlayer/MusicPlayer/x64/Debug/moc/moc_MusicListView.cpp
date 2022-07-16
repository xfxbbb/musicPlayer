/****************************************************************************
** Meta object code from reading C++ file 'MusicListView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MusicListView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MusicListView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMusicListView_t {
    QByteArrayData data[8];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMusicListView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMusicListView_t qt_meta_stringdata_CMusicListView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CMusicListView"
QT_MOC_LITERAL(1, 15, 16), // "signal_dropEvent"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "pos"
QT_MOC_LITERAL(4, 37, 20), // "signal_openMusicInfo"
QT_MOC_LITERAL(5, 58, 17), // "signal_musicPlayl"
QT_MOC_LITERAL(6, 76, 3), // "row"
QT_MOC_LITERAL(7, 80, 23) // "signal_musicLeftRelease"

    },
    "CMusicListView\0signal_dropEvent\0\0pos\0"
    "signal_openMusicInfo\0signal_musicPlayl\0"
    "row\0signal_musicLeftRelease"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMusicListView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,
       7,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void CMusicListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CMusicListView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_dropEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->signal_openMusicInfo((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->signal_musicPlayl((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signal_musicLeftRelease(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CMusicListView::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMusicListView::signal_dropEvent)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CMusicListView::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMusicListView::signal_openMusicInfo)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CMusicListView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMusicListView::signal_musicPlayl)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CMusicListView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMusicListView::signal_musicLeftRelease)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CMusicListView::staticMetaObject = { {
    QMetaObject::SuperData::link<QListView::staticMetaObject>(),
    qt_meta_stringdata_CMusicListView.data,
    qt_meta_data_CMusicListView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CMusicListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMusicListView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMusicListView.stringdata0))
        return static_cast<void*>(this);
    return QListView::qt_metacast(_clname);
}

int CMusicListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CMusicListView::signal_dropEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CMusicListView::signal_openMusicInfo(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CMusicListView::signal_musicPlayl(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CMusicListView::signal_musicLeftRelease()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
