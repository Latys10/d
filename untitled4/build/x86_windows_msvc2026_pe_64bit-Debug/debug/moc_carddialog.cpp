/****************************************************************************
** Meta object code from reading C++ file 'carddialog.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../carddialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'carddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10CardDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto CardDialog::qt_create_metaobjectdata<qt_meta_tag_ZN10CardDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "CardDialog",
        "0$h5YY8mX0t1c++1L74Sq9vyBR6RY",
        "printRequested",
        "",
        "cancelRequested",
        "onPrintButtonClicked",
        "onCancelButtonClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'printRequested'
        QtMocHelpers::SignalData<void()>(2, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'cancelRequested'
        QtMocHelpers::SignalData<void()>(4, 3, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onPrintButtonClicked'
        QtMocHelpers::SlotData<void()>(5, 3, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onCancelButtonClicked'
        QtMocHelpers::SlotData<void()>(6, 3, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    uint qt_metaObjectHashIndex = 1;
    return QtMocHelpers::metaObjectData<CardDialog, qt_meta_tag_ZN10CardDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_metaObjectHashIndex);
}
Q_CONSTINIT const QMetaObject CardDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10CardDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10CardDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10CardDialogE_t>.metaTypes,
    nullptr
} };

void CardDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<CardDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->printRequested(); break;
        case 1: _t->cancelRequested(); break;
        case 2: _t->onPrintButtonClicked(); break;
        case 3: _t->onCancelButtonClicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (CardDialog::*)()>(_a, &CardDialog::printRequested, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (CardDialog::*)()>(_a, &CardDialog::cancelRequested, 1))
            return;
    }
}

const QMetaObject *CardDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CardDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10CardDialogE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CardDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CardDialog::printRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CardDialog::cancelRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
