/***********************************************************************
*
* Copyright (c) 2012-2024 Barbara Geller
* Copyright (c) 2012-2024 Ansel Sermersheim
*
* Copyright (c) 2015 The Qt Company Ltd.
* Copyright (c) 2012-2016 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
*
* This file is part of CopperSpice.
*
* CopperSpice is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://www.gnu.org/licenses/
*
***********************************************************************/

#ifndef LSCSOBJECT_MACRO_H
#define LSCSOBJECT_MACRO_H

#include <lscs_signal.h>
#include <lscs_slot.h>
#include <qglobal.h>

#include <optional>

class QMetaObject;

#define qPrintable(string)          QString(string).constData()
#define lscsPrintable(string)         (string).constData()

#define Q_EMIT
#define Q_ARG(type, data)           LSCSArgument<type>{data, #type}
#define Q_RETURN_ARG(type, data)    LSCSReturnArgument<type>(data)

#define LSCS_TOKENPASTE1(x,y)         x ## y
#define LSCS_TOKENPASTE2(x,y)         LSCS_TOKENPASTE1(x,y)

#define LSCS_PLUGIN_IID(data)                                                         \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =          \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                           \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>       \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);           \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>) \
   {  \
      QMetaObject_T<lscs_class> &meta = const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()); \
      meta.register_classInfo("plugin_iid", data);                                  \
      meta.register_classInfo("plugin_version", QString::number(LSCS_VERSION));       \
      \
      constexpr int cntValue = LSCS_TOKENPASTE2(lscs_counter_value, __LINE__);          \
      \
      QString cname = QString::fromUtf8(lscs_className());                            \
      meta.register_method<QObject * (*)()>(                                        \
            cname, &lscs_class::LSCS_TOKENPASTE2(lscs_fauxConstructor, __LINE__),         \
            QMetaMethod::Constructor, cname + " " + cname + "()", QMetaMethod::Public);  \
      \
      lscs_regTrigger(lscs_number<cntValue + 1>{});                                     \
   }                                                                                \
   static QObject * LSCS_TOKENPASTE2(lscs_fauxConstructor, __LINE__)()                  \
   {                                                                                \
      return new lscs_class;                                                          \
   }

#define LSCS_PLUGIN_KEY(y)  LSCS_CLASSINFO("plugin_key", y)

#define LSCS_PLUGIN_REGISTER(classname)                                                \
   extern "C" Q_DECL_EXPORT QMetaObject *lscs_internal_plugin_metaobject() {           \
      return const_cast<QMetaObject_T<classname> *>(&classname::staticMetaObject()); \
   }

#if ! defined (LSCS_DOXYPRESS)

template<int N>
class lscs_number : public lscs_number<N - 1>
{
public:
    static constexpr int value = N;
};

template<>
class lscs_number<0>
{
public:
    static constexpr int value = 0;
};

#endif // doxypress

# define LSCS_TR_FUNCTIONS \
   static inline QString tr(const char *text, const char *comment = nullptr, std::optional<int> numArg = std::optional<int>()) \
   { return staticMetaObject().tr(text, comment, numArg); }

// ** lscs_object
#define LSCS_OBJECT(classNameX)      \
 public:                           \
   using lscs_parent = lscs_class;     \
   using lscs_class  = classNameX;   \
   LSCS_OBJECT_INTERNAL(classNameX)  \
 private:

#define LSCS_OBJECT_MULTIPLE(classNameX,parentX) \
 public:                           \
   using lscs_parent = parentX;      \
   using lscs_class  = classNameX;   \
   LSCS_OBJECT_INTERNAL(classNameX)  \
 private:

#define LSCS_OBJECT_OUTSIDE(classNameX)     \
 public:                                  \
   using lscs_parent = lscs_class;            \
   using lscs_class  = classNameX;          \
   LSCS_OBJECT_INTERNAL_OUTSIDE(classNameX) \
 private:

#define LSCS_OBJECT_MULTIPLE_OUTSIDE(classNameX,parentX) \
 public:                                  \
   using lscs_parent = parentX;             \
   using lscs_class  = classNameX;          \
   LSCS_OBJECT_INTERNAL_OUTSIDE(classNameX) \
 private:

#define LSCS_OVERRIDE override

#define LSCS_OBJECT_INTERNAL(classNameX)  \
 public:                                \
   static const char *lscs_className()    \
   { \
      static const char *retval(#classNameX); \
      return retval;                          \
   } \
   template<int N>                            \
   static void lscs_regTrigger(lscs_number<N>)    \
   { \
   } \
   static constexpr lscs_number<0> lscs_counter(lscs_number<0>) \
   { \
      return lscs_number<0>{};                  \
   } \
   friend QMetaObject_T<classNameX>;          \
   [[gnu::used]] Q_EXPORT_MAYBE static const QMetaObject_T<classNameX> &staticMetaObject()  \
   { \
      static std::atomic<bool> isCreated(false);                            \
      static std::atomic<QMetaObject_T<classNameX> *> createdObj(nullptr);  \
      if (isCreated) {                                                      \
         return *createdObj;                                                \
      } \
      std::lock_guard<std::recursive_mutex> lock(m_metaObjectMutex());      \
      if (createdObj != nullptr) {                                          \
         return *createdObj;                                                \
      } \
      QMap<std::type_index, QMetaObject *> &temp = m_metaObjectsAll();      \
      auto index = temp.find(typeid(lscs_class));    \
      QMetaObject_T<classNameX> *newMeta;          \
      if (index == temp.end()) {                   \
         newMeta = new QMetaObject_T<classNameX>;  \
         temp.insert(typeid(lscs_class), newMeta);   \
         createdObj.store(newMeta);                \
         newMeta->postConstruct();                 \
         isCreated = true;                         \
         return *newMeta;                          \
      } else {  \
         newMeta = dynamic_cast<QMetaObject_T<classNameX> *> (index.value()); \
         createdObj.store(newMeta);  \
         isCreated = true;           \
         return *newMeta;            \
      } \
   } \
   virtual Q_EXPORT_MAYBE const QMetaObject *metaObject() const LSCS_OVERRIDE \
   { \
      return &staticMetaObject(); \
   } \
   LSCS_TR_FUNCTIONS \
 private:

#define LSCS_OBJECT_INTERNAL_OUTSIDE(classNameX) \
 public:                                       \
   static const char *lscs_className()           \
   { \
      static const char * retval(#classNameX); \
      return retval;                           \
   } \
   static const QMetaObject_T<classNameX> & staticMetaObject(); \
   virtual const QMetaObject *metaObject() const LSCS_OVERRIDE;   \
   LSCS_TR_FUNCTIONS \
 private:

// ** lscs_gadget
#define LSCS_GADGET(classNameX)                \
 public:                                     \
   using lscs_parent = LSCSGadget_Fake_Parent;   \
   using lscs_class  = classNameX;             \
   LSCS_GADGET_INTERNAL(classNameX)            \
 private:

#define LSCS_GADGET_OUTSIDE(classNameX)        \
 public:                                     \
   using lscs_parent = LSCSGadget_Fake_Parent;   \
   using lscs_class  = classNameX;             \
   LSCS_GADGET_INTERNAL_OUTSIDE(classNameX)    \
 private:

#define LSCS_GADGET_INTERNAL(classNameX) \
 public:                               \
   static const char *lscs_className()   \
   { \
      static const char *retval(#classNameX); \
      return retval;                          \
   } \
   template<int N>                            \
   static void lscs_regTrigger(lscs_number<N>)    \
   { \
   } \
   static constexpr lscs_number<0> lscs_counter(lscs_number<0>)   \
   { \
      return lscs_number<0>{};                  \
   } \
   friend QMetaObject_T<classNameX>;          \
   [[gnu::used]] Q_EXPORT_MAYBE static const QMetaObject_T<classNameX> &staticMetaObject() \
   { \
      static std::atomic<bool> isCreated(false);                             \
      static std::atomic<QMetaObject_T<classNameX> *> createdObj(nullptr);   \
      if (isCreated) {               \
         return *createdObj;         \
      } \
      std::lock_guard<std::recursive_mutex> lock(QObject::m_metaObjectMutex()); \
      if (createdObj != nullptr) {   \
         return *createdObj;         \
      } \
      QMap<std::type_index, QMetaObject *> &temp = QObject::m_metaObjectsAll(); \
      auto index = temp.find(typeid(lscs_class));       \
      QMetaObject_T<classNameX> *newMeta;             \
      if (index == temp.end()) {                      \
         newMeta = new QMetaObject_T<classNameX>;     \
         temp.insert(typeid(lscs_class), newMeta);      \
         newMeta->postConstruct();                    \
         return *newMeta;                             \
      } else {                                        \
         newMeta = dynamic_cast<QMetaObject_T<classNameX> *> (index.value()); \
         createdObj.store(newMeta);  \
         isCreated = true;           \
         return *newMeta;            \
      } \
   } \
   LSCS_TR_FUNCTIONS                   \
 private:

#define LSCS_GADGET_INTERNAL_OUTSIDE(classNameX) \
 public:                                       \
   static const char *lscs_className()           \
   { \
      static const char *retval(#classNameX);  \
      return retval;                           \
   } \
   static const QMetaObject_T<classNameX> &staticMetaObject(); \
   LSCS_TR_FUNCTIONS                             \
 private:

// ** interface
#define LSCS_DECLARE_INTERFACE(IFace, IId)       \
   template<>                                  \
   inline const QString &qobject_interface_iid<IFace *>() \
   {  \
      static QString retval(IId);              \
      return retval;                           \
   }

#define LSCS_INTERFACES(...)                     \
 public: \
   bool lscs_interface_query(const QString &interfaceData) const override \
   {  \
      if (lscs_factory_interface_query<__VA_ARGS__>(interfaceData)) { \
         return true;                          \
      }  \
      return false;                            \
   }  \
 private:

// ** classInfo
#define LSCS_CLASSINFO(name, data) \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =           \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                            \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>        \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);            \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)  \
   {  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_classInfo(name, data); \
      \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{} );   \
   }

// ** enum
#define LSCS_ENUM(name) \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =           \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                            \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>        \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);            \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)  \
   {  \
      lscs_namespace_register_enum<lscs_class>(#name, typeid(name), lscs_className());     \
      \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{} );   \
   }

#define LSCS_REGISTER_ENUM(...) \
   __VA_ARGS__ \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =           \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                            \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>        \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);            \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)  \
   {  \
      lscs_namespace_register_enum_data<lscs_class>(#__VA_ARGS__);                       \
      \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{} );   \
   }

// ** flag
#define LSCS_FLAG(enumName, flagName) \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =           \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                            \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>        \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);            \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)  \
   {  \
      lscs_namespace_register_flag<lscs_class>(#enumName, lscs_className(),                \
            #flagName, typeid(flagName));                                            \
      \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{} );   \
   }

// ** invoke constructor
#define LSCS_INVOKABLE_CONSTRUCTOR_1(access, ...) \
   __VA_ARGS__; \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =          \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                           \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>       \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);           \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>) \
   {  \
      QString va_args = #__VA_ARGS__;                                               \
      QMetaMethod::Access accessType = QMetaMethod::access;                         \
      constexpr int cntValue = LSCS_TOKENPASTE2(lscs_counter_value, __LINE__);
// do not remove the ";", this is required for part two of the macro

#define LSCS_INVOKABLE_CONSTRUCTOR_2(className, ...)                                  \
   const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method       \
   <QObject * (*)(__VA_ARGS__)>(                                                            \
         #className, &lscs_class::LSCS_TOKENPASTE2(lscs_fauxConstructor, __LINE__)<__VA_ARGS__>,  \
         QMetaMethod::Constructor, QString(#className) + " " + va_args, accessType);        \
   lscs_regTrigger(lscs_number<cntValue + 1>{} );                                               \
   } \
   template <class... Ts>                                                 \
   static QObject * LSCS_TOKENPASTE2(lscs_fauxConstructor, __LINE__)(Ts...Vs) \
   { \
      return new className{Vs...};                                        \
   }

// ** invoke
#define LSCS_INVOKABLE_METHOD_1(access, ...) \
   __VA_ARGS__; \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =          \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                           \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>       \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);           \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>) \
   {  \
      const auto &va_args = #__VA_ARGS__;                   \
      QMetaMethod::Access accessType = QMetaMethod::access; \
      constexpr int cntValue = LSCS_TOKENPASTE2(lscs_counter_value, __LINE__);
// do not remove the ";", this is required for part two of the macro

#define LSCS_INVOKABLE_METHOD_2(methodName)                   \
   const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method(  \
         #methodName, &lscs_class::methodName, QMetaMethod::Method, va_args, accessType); \
   lscs_regTrigger(lscs_number<cntValue + 1>{});                \
   }

#define LSCS_INVOKABLE_OVERLOAD(methodName, argTypes, ...)                                \
   const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method(  \
         #methodName, static_cast<void (lscs_class::*)argTypes>(&lscs_class::methodName),   \
         QMetaMethod::Method, va_args, accessType);         \
   lscs_regTrigger(lscs_number<cntValue + 1>{});                \
   }

// ** revision
#define LSCS_REVISION(methodName,revision) \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =           \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                            \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>        \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);            \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)  \
   {  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method_rev( \
            &lscs_class::methodName, revision);                                        \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{} );   \
   }

#define LSCS_REVISION_OVERLOAD(methodName, revision, argTypes)                         \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =           \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                            \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>        \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);            \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)  \
   {  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method_rev( \
            static_cast<void (lscs_class::*)argTypes>(&lscs_class::methodName), revision);        \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});    \
   }

// ** slots
#define LSCS_SLOT_1(access, ...)                                                      \
   __VA_ARGS__;                                                                     \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =          \
         decltype(lscs_counter(lscs_number<255>{}))::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>       \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);           \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>) \
   {  \
      const auto &va_args = #__VA_ARGS__;                                           \
      QMetaMethod::Access accessType = QMetaMethod::access;                         \
      constexpr int cntValue = LSCS_TOKENPASTE2(lscs_counter_value, __LINE__);
// do not remove the ";", this is required for part two of the macro

#define LSCS_SLOT_2(slotName) \
   const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method(  \
         #slotName, &lscs_class::slotName, QMetaMethod::Slot, va_args, accessType);       \
   lscs_regTrigger(lscs_number<cntValue + 1>{} );                                           \
   }

// ** signals
#define LSCS_SIGNAL_1(access, ...)                                                    \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =          \
         decltype(lscs_counter(lscs_number<255>{}))::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>       \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);           \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>) \
   {  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method_s1(  \
            #__VA_ARGS__, QMetaMethod::access, QMetaMethod::Signal);                \
      \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{} );  \
   }  \
   Q_EXPORT_MAYBE  __VA_ARGS__ {      \
      if (this->signalsBlocked()) {   \
         return;                      \
      }
// do not remove the "{", this is required for part two of the macro

#define LSCS_SIGNAL_2(signalName, ...) \
   LsCsSignal::activate(*this, &lscs_class::signalName, ##__VA_ARGS__);                 \
   }  \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =          \
         decltype(lscs_counter(lscs_number<255>{}))::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>       \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);           \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>) \
   {  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method_s2(  \
            #signalName, &lscs_class::signalName, QMetaMethod::Signal);               \
      \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{} );  \
   }  \

#define LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...) \
   LsCsSignal::activate(*this, static_cast<void (lscs_class::*)argTypes>(&lscs_class::signalName), ##__VA_ARGS__); \
   }  \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =          \
         decltype(lscs_counter(lscs_number<255>{}))::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>       \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);           \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>) \
   {  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method_s2(  \
            #signalName #argTypes, static_cast<void (lscs_class::*)argTypes>(&lscs_class::signalName), QMetaMethod::Signal);  \
      \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{} );  \
   }  \

#define LSCS_SLOT_OVERLOAD(slotName, argTypes)                                                 \
   const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method(       \
         #slotName #argTypes, static_cast<void (lscs_class::*)argTypes>(&lscs_class::slotName),  \
         QMetaMethod::Slot, va_args, accessType);                                            \
   lscs_regTrigger(lscs_number<cntValue + 1>{} );                                                \
   }

#define LSCS_SLOT_OVERLOAD_BOOL(slotName, argTypes)                                            \
   const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_method(       \
         #slotName #argTypes, static_cast<bool (lscs_class::*)argTypes>(&lscs_class::slotName),  \
         QMetaMethod::Slot, va_args, accessType);                                            \
   lscs_regTrigger(lscs_number<cntValue + 1>{} );                                                \
   }

#if defined(LSCS_SHOW_DEBUG_CORE)

#define LSCS_NUMBER_TO_STRING_INTERNAL(number)       #number
#define LSCS_NUMBER_TO_STRING(number)                LSCS_NUMBER_TO_STRING_INTERNAL(number)

// SIGNAL
#define SIGNAL(...) \
   #__VA_ARGS__ , __FILE__ ":" LSCS_NUMBER_TO_STRING(__LINE__)

// SLOT
#define SLOT(...) \
   #__VA_ARGS__

#else

// SIGNAL
#define SIGNAL(...) \
   #__VA_ARGS__

// SLOT
#define SLOT(...) \
   #__VA_ARGS__

#endif

// ** metaMethod tag
#define LSCS_TAG(name, data) \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =           \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                            \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>        \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);            \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)  \
   {                                                                                 \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_tag(#name, #data); \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});    \
   }

// ** properties
#define LSCS_PROPERTY_READ(name, method) \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =           \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                            \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>        \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);            \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)  \
   {                                                                                 \
      using T = decltype(&lscs_class::method);                                         \
      using R = lscs_returnType<T>::type;                                              \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())             \
            .register_property_read(#name, typeid(R),                                \
            [] () { return lscs_typeToName<R>(); },                                    \
            new SpiceJarRead<lscs_class, R>(&lscs_class::method));                       \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});    \
   }

#define LSCS_PROPERTY_WRITE(name, method) \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      using T = decltype(&lscs_class::method);                                          \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_write(#name,                                           \
            new SpiceJarWrite<lscs_class, lscs_argType<T>::type>(&lscs_class::method),      \
            #method);                                                                 \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

#define LSCS_PROPERTY_NOTIFY(name, method) \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_notify(#name, &lscs_class::method);                      \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

#define LSCS_PROPERTY_RESET(name, method) \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_reset(#name, &lscs_class::method);                       \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

#define LSCS_PROPERTY_REVISION(name, data) \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_int(#name, data, QMetaProperty::REVISION);             \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

#define LSCS_PROPERTY_DESIGNABLE(name, data)                 \
   static bool LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)()   \
   {                                                    \
      return data;                                      \
   }                                                    \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_bool(#name, new SpiceJarRead<lscs_class, bool>           \
            (&lscs_class::LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)), QMetaProperty::DESIGNABLE); \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

#define LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)       \
   bool LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)() const    \
   {                                                       \
      return data;                                         \
   }                                                       \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_bool(#name, new SpiceJarRead<lscs_class, bool>           \
            (&lscs_class::LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)), QMetaProperty::DESIGNABLE); \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

#define LSCS_PROPERTY_SCRIPTABLE(name, data)                 \
   static bool LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)()   \
   {                                                       \
      return data;                                         \
   }                                                       \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =             \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                              \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>          \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);              \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)    \
   {                                                                                   \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())               \
            .register_property_bool(#name, new SpiceJarRead<lscs_class, bool>            \
            (&lscs_class::LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)), QMetaProperty::SCRIPTABLE); \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});      \
   }

#define LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)       \
   bool LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)() const    \
   {                                                       \
      return data;                                         \
   }                                                       \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_bool(#name, new SpiceJarRead<lscs_class, bool>           \
            (&lscs_class::LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)), QMetaProperty::SCRIPTABLE); \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

#define LSCS_PROPERTY_STORED(name, data)                     \
   static bool LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)()   \
   {                                                       \
      return data;                                         \
   }                                                       \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =             \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                              \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>          \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);              \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)    \
   {                                                                                   \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())               \
            .register_property_bool(#name, new SpiceJarRead<lscs_class, bool>            \
            (&lscs_class::LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)), QMetaProperty::STORED); \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});      \
   }

#define LSCS_PROPERTY_STORED_NONSTATIC(name, data)           \
   bool LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)() const    \
   {                                                       \
      return data;                                         \
   }                                                       \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_bool(#name, new SpiceJarRead<lscs_class, bool>           \
            (&lscs_class::LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)), QMetaProperty::STORED); \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

#define LSCS_PROPERTY_USER(name, data)                       \
   static bool LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)()   \
   {                                                       \
      return data;                                         \
   }                                                       \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_bool(#name, new SpiceJarRead<lscs_class, bool>           \
            (&lscs_class::LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)), QMetaProperty::USER); \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

#define LSCS_PROPERTY_USER_NONSTATIC(name, data)             \
   bool LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)()  const   \
   {                                                       \
      return data;                                         \
   }                                                       \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_bool(#name, new SpiceJarRead<lscs_class, bool>             \
            (&lscs_class::LSCS_TOKENPASTE2(lscs_fauxMethod, __LINE__)), QMetaProperty::USER); \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});      \
   }

#define LSCS_PROPERTY_CONSTANT(name)                                                    \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject())              \
            .register_property_int(#name, 1, QMetaProperty::CONSTANT);                \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

#define LSCS_PROPERTY_FINAL(name)                                                       \
   static constexpr const int LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) =            \
         decltype( lscs_counter(lscs_number<255>{}) )::value;                             \
   static constexpr lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>         \
   lscs_counter(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>);             \
   static void lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__)>)   \
   {                                                                                  \
      const_cast<QMetaObject_T<lscs_class>&>(lscs_class::staticMetaObject()).register_property_int(  \
            #name, 1, QMetaProperty::FINAL);                                          \
      lscs_regTrigger(lscs_number<LSCS_TOKENPASTE2(lscs_counter_value, __LINE__) + 1>{});     \
   }

// ** macros used when compiling

// ** 1
#if defined(QT_BUILD_CORE_LIB) || defined(Q_OS_DARWIN)

#define CORE_LSCS_OBJECT(className)                              LSCS_OBJECT(className)
#define CORE_LSCS_OBJECT_MULTIPLE(className, parentX)            LSCS_OBJECT_MULTIPLE(className, parentX)
#define CORE_LSCS_OBJECT_INTERNAL(className)                     LSCS_OBJECT_INTERNAL(className)
#define CORE_LSCS_GADGET(className)                              LSCS_GADGET(className)

#define CORE_LSCS_SLOT_1(access, ...)                            LSCS_SLOT_1(access, __VA_ARGS__)
#define CORE_LSCS_SLOT_2(slotName)                               LSCS_SLOT_2(slotName)
#define CORE_LSCS_SLOT_OVERLOAD(slotName, argTypes)              LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define CORE_LSCS_SIGNAL_1(access, ...)                          LSCS_SIGNAL_1(access, __VA_ARGS__)
#define CORE_LSCS_SIGNAL_2(signalName, ...)                      LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define CORE_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)     LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#define CORE_LSCS_INVOKABLE_CONSTRUCTOR_1(access, ...)           LSCS_INVOKABLE_CONSTRUCTOR_1(access, __VA_ARGS__)
#define CORE_LSCS_INVOKABLE_CONSTRUCTOR_2(className, ...)        LSCS_INVOKABLE_CONSTRUCTOR_2(className, __VA_ARGS__)

#define CORE_LSCS_ENUM(name)                                     LSCS_ENUM(name)
#define CORE_LSCS_REGISTER_ENUM(...)                             LSCS_REGISTER_ENUM(__VA_ARGS__)
#define CORE_LSCS_FLAG(enumName, flagName)                       LSCS_FLAG(enumName, flagName)

#define CORE_LSCS_PROPERTY_READ(name, method)                    LSCS_PROPERTY_READ(name, method)
#define CORE_LSCS_PROPERTY_WRITE(name, method)                   LSCS_PROPERTY_WRITE(name, method)
#define CORE_LSCS_PROPERTY_NOTIFY(name, method)                  LSCS_PROPERTY_NOTIFY(name, method)
#define CORE_LSCS_PROPERTY_RESET(name, method)                   LSCS_PROPERTY_RESET(name, method)
#define CORE_LSCS_PROPERTY_REVISION(name, data)                  LSCS_PROPERTY_REVISION(name, data)
#define CORE_LSCS_PROPERTY_DESIGNABLE(name, data)                LSCS_PROPERTY_DESIGNABLE(name, data)
#define CORE_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)      LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define CORE_LSCS_PROPERTY_SCRIPTABLE(name, data)                LSCS_PROPERTY_SCRIPTABLE(name, data)
#define CORE_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)      LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define CORE_LSCS_PROPERTY_STORED(name, data)                    LSCS_PROPERTY_STORED(name, data)
#define CORE_LSCS_PROPERTY_STORED_NONSTATIC(name, data)          LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define CORE_LSCS_PROPERTY_USER(name, data)                      LSCS_PROPERTY_USER(name, data)
#define CORE_LSCS_PROPERTY_USER_NONSTATIC(name, data)            LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define CORE_LSCS_PROPERTY_CONSTANT(name)                        LSCS_PROPERTY_CONSTANT(name)
#define CORE_LSCS_PROPERTY_FINAL(name)                           LSCS_PROPERTY_FINAL(name)

#else

#define CORE_LSCS_OBJECT(className)                              LSCS_OBJECT_OUTSIDE(className)
#define CORE_LSCS_OBJECT_MULTIPLE(className, parentX)            LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define CORE_LSCS_OBJECT_INTERNAL(className)                     LSCS_OBJECT_INTERNAL_OUTSIDE(className)
#define CORE_LSCS_GADGET(className)                              LSCS_GADGET_OUTSIDE(className)

#define CORE_LSCS_SLOT_1(access, ...)                            __VA_ARGS__;
#define CORE_LSCS_SLOT_2(slotName)
#define CORE_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define CORE_LSCS_SIGNAL_1(access, ...)                          __VA_ARGS__;
#define CORE_LSCS_SIGNAL_2(signalName, ...)
#define CORE_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#define CORE_LSCS_INVOKABLE_CONSTRUCTOR_1(access, ...)           __VA_ARGS__;
#define CORE_LSCS_INVOKABLE_CONSTRUCTOR_2(className, ...)

#define CORE_LSCS_ENUM(name)
#define CORE_LSCS_REGISTER_ENUM(...)                             __VA_ARGS__           // do not add ;
#define CORE_LSCS_FLAG(enumName, flagName)

#define CORE_LSCS_PROPERTY_READ(name, method)
#define CORE_LSCS_PROPERTY_WRITE(name, method)
#define CORE_LSCS_PROPERTY_NOTIFY(name, method)
#define CORE_LSCS_PROPERTY_RESET(name, method)
#define CORE_LSCS_PROPERTY_REVISION(name, data)
#define CORE_LSCS_PROPERTY_DESIGNABLE(name, data)
#define CORE_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define CORE_LSCS_PROPERTY_SCRIPTABLE(name, data)
#define CORE_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define CORE_LSCS_PROPERTY_STORED(name, data)
#define CORE_LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define CORE_LSCS_PROPERTY_USER(name, data)
#define CORE_LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define CORE_LSCS_PROPERTY_CONSTANT(name)
#define CORE_LSCS_PROPERTY_FINAL(name)

#endif

// ** 2
#if defined(QT_BUILD_GUI_LIB) || defined(Q_OS_DARWIN)

#define GUI_LSCS_OBJECT(className)                                  LSCS_OBJECT(className)
#define GUI_LSCS_OBJECT_MULTIPLE(className, parentX)                LSCS_OBJECT_MULTIPLE(className, parentX)
#define GUI_LSCS_GADGET(className)                                  LSCS_GADGET(className)

#define GUI_LSCS_CLASSINFO(name, data)                              LSCS_CLASSINFO(name, data)

#define GUI_LSCS_SLOT_1(access, ...)                                LSCS_SLOT_1(access, __VA_ARGS__)
#define GUI_LSCS_SLOT_2(slotName)                                   LSCS_SLOT_2(slotName)
#define GUI_LSCS_SLOT_OVERLOAD(slotName, argTypes)                  LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define GUI_LSCS_SIGNAL_1(access, ...)                              LSCS_SIGNAL_1(access, __VA_ARGS__)
#define GUI_LSCS_SIGNAL_2(signalName, ...)                          LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define GUI_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)         LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#define GUI_LSCS_ENUM(name)                                         LSCS_ENUM(name)
#define GUI_LSCS_REGISTER_ENUM(...)                                 LSCS_REGISTER_ENUM(__VA_ARGS__)
#define GUI_LSCS_FLAG(enumName, flagName)                           LSCS_FLAG(enumName, flagName)

#define GUI_LSCS_PROPERTY_READ(name, method)                        LSCS_PROPERTY_READ(name, method)
#define GUI_LSCS_PROPERTY_WRITE(name, method)                       LSCS_PROPERTY_WRITE(name, method)
#define GUI_LSCS_PROPERTY_NOTIFY(name, method)                      LSCS_PROPERTY_NOTIFY(name, method)
#define GUI_LSCS_PROPERTY_RESET(name, method)                       LSCS_PROPERTY_RESET(name, method)
#define GUI_LSCS_PROPERTY_REVISION(name, data)                      LSCS_PROPERTY_REVISION(name, data)
#define GUI_LSCS_PROPERTY_DESIGNABLE(name, data)                    LSCS_PROPERTY_DESIGNABLE(name, data)
#define GUI_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)          LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define GUI_LSCS_PROPERTY_SCRIPTABLE(name, data)                    LSCS_PROPERTY_SCRIPTABLE(name, data)
#define GUI_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)          LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define GUI_LSCS_PROPERTY_STORED(name, data)                        LSCS_PROPERTY_STORED(name, data)
#define GUI_LSCS_PROPERTY_STORED_NONSTATIC(name, data)              LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define GUI_LSCS_PROPERTY_USER(name, data)                          LSCS_PROPERTY_USER(name, data)
#define GUI_LSCS_PROPERTY_USER_NONSTATIC(name, data)                LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define GUI_LSCS_PROPERTY_CONSTANT(name)                            LSCS_PROPERTY_CONSTANT(name)
#define GUI_LSCS_PROPERTY_FINAL(name)                               LSCS_PROPERTY_FINAL(name)

#else
#define GUI_LSCS_OBJECT(className)                                  LSCS_OBJECT_OUTSIDE(className)
#define GUI_LSCS_OBJECT_MULTIPLE(className, parentX)                LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define GUI_LSCS_GADGET(className)                                  LSCS_GADGET_OUTSIDE(className)

#define GUI_LSCS_CLASSINFO(name, data)

#define GUI_LSCS_SLOT_1(access, ...)                                __VA_ARGS__;
#define GUI_LSCS_SLOT_2(slotName)
#define GUI_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define GUI_LSCS_SIGNAL_1(access, ...)                              __VA_ARGS__;
#define GUI_LSCS_SIGNAL_2(signalName, ...)
#define GUI_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#define GUI_LSCS_ENUM(name)
#define GUI_LSCS_REGISTER_ENUM(...)                                 __VA_ARGS__           // do not add ;
#define GUI_LSCS_FLAG(enumName, flagName)

#define GUI_LSCS_PROPERTY_READ(name, method)
#define GUI_LSCS_PROPERTY_WRITE(name, method)
#define GUI_LSCS_PROPERTY_NOTIFY(name, method)
#define GUI_LSCS_PROPERTY_RESET(name, method)
#define GUI_LSCS_PROPERTY_REVISION(name, data)
#define GUI_LSCS_PROPERTY_DESIGNABLE(name, data)
#define GUI_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define GUI_LSCS_PROPERTY_SCRIPTABLE(name, data)
#define GUI_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define GUI_LSCS_PROPERTY_STORED(name, data)
#define GUI_LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define GUI_LSCS_PROPERTY_USER(name, data)
#define GUI_LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define GUI_LSCS_PROPERTY_CONSTANT(name)
#define GUI_LSCS_PROPERTY_FINAL(name)

#endif

// ** 3
#if defined(QT_BUILD_MULTIMEDIA_LIB) || defined(Q_OS_DARWIN)

#define MULTI_LSCS_OBJECT(className)                                LSCS_OBJECT(className)
#define MULTI_LSCS_OBJECT_MULTIPLE(className, parentX)              LSCS_OBJECT_MULTIPLE(className, parentX)
#define MULTI_LSCS_GADGET(className)                                LSCS_GADGET(className)

#define MULTI_LSCS_CLASSINFO(name, data)                            LSCS_CLASSINFO(name, data)

#define MULTI_LSCS_SLOT_1(access, ...)                              LSCS_SLOT_1(access, __VA_ARGS__)
#define MULTI_LSCS_SLOT_2(slotName)                                 LSCS_SLOT_2(slotName)
#define MULTI_LSCS_SLOT_OVERLOAD(slotName, argTypes)                LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define MULTI_LSCS_SIGNAL_1(access, ...)                            LSCS_SIGNAL_1(access, __VA_ARGS__)
#define MULTI_LSCS_SIGNAL_2(signalName, ...)                        LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define MULTI_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)       LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#define MULTI_LSCS_ENUM(name)                                       LSCS_ENUM(name)

#define MULTI_LSCS_PROPERTY_READ(name, method)                      LSCS_PROPERTY_READ(name, method)
#define MULTI_LSCS_PROPERTY_WRITE(name, method)                     LSCS_PROPERTY_WRITE(name, method)
#define MULTI_LSCS_PROPERTY_NOTIFY(name, method)                    LSCS_PROPERTY_NOTIFY(name, method)
#define MULTI_LSCS_PROPERTY_RESET(name, method)                     LSCS_PROPERTY_RESET(name, method)
#define MULTI_LSCS_PROPERTY_REVISION(name, da)                      LSCS_PROPERTY_REVISION(name, data)
#define MULTI_LSCS_PROPERTY_DESIGNABLE(namedata)                    LSCS_PROPERTY_DESIGNABLE(name, data)
#define MULTI_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)        LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define MULTI_LSCS_PROPERTY_SCRIPTABLE(namedata)                    LSCS_PROPERTY_SCRIPTABLE(name, data)
#define MULTI_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)        LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define MULTI_LSCS_PROPERTY_STORED(name, data)                      LSCS_PROPERTY_STORED(name, data)
#define MULTI_LSCS_PROPERTY_STORED_NONSTATIC(name, data)            LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define MULTI_LSCS_PROPERTY_USER(name, data)                        LSCS_PROPERTY_USER(name, data)
#define MULTI_LSCS_PROPERTY_USER_NONSTATIC(name, data)              LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define MULTI_LSCS_PROPERTY_CONSTANT(name)                          LSCS_PROPERTY_CONSTANT(name)
#define MULTI_LSCS_PROPERTY_FINAL(name)                             LSCS_PROPERTY_FINAL(name)

#else
#define MULTI_LSCS_OBJECT(className)                                LSCS_OBJECT_OUTSIDE(className)
#define MULTI_LSCS_OBJECT_MULTIPLE(className, parentX)              LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define MULTI_LSCS_GADGET(className)                                LSCS_GADGET_OUTSIDE(className)

#define MULTI_LSCS_CLASSINFO(name, data)

#define MULTI_LSCS_SLOT_1(access, ...)                              __VA_ARGS__;
#define MULTI_LSCS_SLOT_2(slotName)
#define MULTI_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define MULTI_LSCS_SIGNAL_1(access, ...)                            __VA_ARGS__;
#define MULTI_LSCS_SIGNAL_2(signalName, ...)
#define MULTI_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#define MULTI_LSCS_ENUM(name)

#define MULTI_LSCS_PROPERTY_READ(name, method)
#define MULTI_LSCS_PROPERTY_WRITE(name, method)
#define MULTI_LSCS_PROPERTY_NOTIFY(name, method)
#define MULTI_LSCS_PROPERTY_RESET(name, method)
#define MULTI_LSCS_PROPERTY_REVISION(name, da)
#define MULTI_LSCS_PROPERTY_DESIGNABLE(namedata)
#define MULTI_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define MULTI_LSCS_PROPERTY_SCRIPTABLE(namedata)
#define MULTI_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define MULTI_LSCS_PROPERTY_STORED(name, data)
#define MULTI_LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define MULTI_LSCS_PROPERTY_USER(name, data)
#define MULTI_LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define MULTI_LSCS_PROPERTY_CONSTANT(name)
#define MULTI_LSCS_PROPERTY_FINAL(name)

#endif

// ** 4
#if defined(QT_BUILD_NETWORK_LIB) || defined(Q_OS_DARWIN)

#define NET_LSCS_OBJECT(className)                                  LSCS_OBJECT(className)
#define NET_LSCS_OBJECT_MULTIPLE(className, parentX)                LSCS_OBJECT_MULTIPLE(className, parentX)
#define NET_LSCS_GADGET(className)                                  LSCS_GADGET(className)

#define NET_LSCS_SLOT_1(access, ...)                                LSCS_SLOT_1(access, __VA_ARGS__)
#define NET_LSCS_SLOT_2(slotName)                                   LSCS_SLOT_2(slotName)
#define NET_LSCS_SLOT_OVERLOAD(slotName, argTypes)                  LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define NET_LSCS_SIGNAL_1(access, ...)                              LSCS_SIGNAL_1(access, __VA_ARGS__)
#define NET_LSCS_SIGNAL_2(signalName, ...)                          LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define NET_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)         LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#define NET_LSCS_INVOKABLE_METHOD_1(access, ...)                    LSCS_INVOKABLE_METHOD_1(access, __VA_ARGS__)
#define NET_LSCS_INVOKABLE_METHOD_2(methodName)                     LSCS_INVOKABLE_METHOD_2(methodName)

#define NET_LSCS_ENUM(name)                                         LSCS_ENUM(name)
#define NET_LSCS_REGISTER_ENUM(...)                                 LSCS_REGISTER_ENUM(__VA_ARGS__)

#define NET_LSCS_PROPERTY_READ(name, method)                        LSCS_PROPERTY_READ(name, method)
#define NET_LSCS_PROPERTY_WRITE(name, method)                       LSCS_PROPERTY_WRITE(name, method)
#define NET_LSCS_PROPERTY_NOTIFY(name, method)                      LSCS_PROPERTY_NOTIFY(name, method)
#define NET_LSCS_PROPERTY_RESET(name, method)                       LSCS_PROPERTY_RESET(name, method)
#define NET_LSCS_PROPERTY_REVISION(name, data)                      LSCS_PROPERTY_REVISION(name, data)
#define NET_LSCS_PROPERTY_DESIGNABLE(name, data)                    LSCS_PROPERTY_DESIGNABLE(name, data)
#define NET_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)          LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define NET_LSCS_PROPERTY_SCRIPTABLE(name, data)                    LSCS_PROPERTY_SCRIPTABLE(name, data)
#define NET_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)          LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define NET_LSCS_PROPERTY_STORED(name, data)                        LSCS_PROPERTY_STORED(name, data)
#define NET_LSCS_PROPERTY_STORED_NONSTATIC(name, data)              LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define NET_LSCS_PROPERTY_USER(name, data)                          LSCS_PROPERTY_USER(name, data)
#define NET_LSCS_PROPERTY_USER_NONSTATIC(name, data)                LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define NET_LSCS_PROPERTY_CONSTANT(name)                            LSCS_PROPERTY_CONSTANT(name)
#define NET_LSCS_PROPERTY_FINAL(name)                               LSCS_PROPERTY_FINAL(name)

#else
#define NET_LSCS_OBJECT(className)                                  LSCS_OBJECT_OUTSIDE(className)
#define NET_LSCS_OBJECT_MULTIPLE(className, parentX)                LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define NET_LSCS_GADGET(className)                                  LSCS_GADGET_OUTSIDE(className)

#define NET_LSCS_SLOT_1(access, ...)                                __VA_ARGS__;
#define NET_LSCS_SLOT_2(slotName)
#define NET_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define NET_LSCS_SIGNAL_1(access, ...)                              __VA_ARGS__;
#define NET_LSCS_SIGNAL_2(signalName, ...)
#define NET_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#define NET_LSCS_INVOKABLE_METHOD_1(access, ...)                    __VA_ARGS__;
#define NET_LSCS_INVOKABLE_METHOD_2(methodName)

#define NET_LSCS_ENUM(name)
#define NET_LSCS_REGISTER_ENUM(...)                                 __VA_ARGS__           // do not add ;

#define NET_LSCS_PROPERTY_READ(name, method)
#define NET_LSCS_PROPERTY_WRITE(name, method)
#define NET_LSCS_PROPERTY_NOTIFY(name, method)
#define NET_LSCS_PROPERTY_RESET(name, method)
#define NET_LSCS_PROPERTY_REVISION(name, data)
#define NET_LSCS_PROPERTY_DESIGNABLE(name, data)
#define NET_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define NET_LSCS_PROPERTY_SCRIPTABLE(name, data)
#define NET_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define NET_LSCS_PROPERTY_STORED(name, data)
#define NET_LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define NET_LSCS_PROPERTY_USER(name, data)
#define NET_LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define NET_LSCS_PROPERTY_CONSTANT(name)
#define NET_LSCS_PROPERTY_FINAL(name)

#endif

// ** 5
#if defined(QT_BUILD_OPENGL_LIB) || defined(Q_OS_DARWIN)

#define OPENGL_LSCS_OBJECT(className)                               LSCS_OBJECT(className)
#define OPENGL_LSCS_OBJECT_MULTIPLE(className, parentX)             LSCS_OBJECT_MULTIPLE(className, parentX)
#define OPENGL_LSCS_GADGET(className)                               LSCS_GADGET(className)

#define OPENGL_LSCS_SLOT_1(access, ...)                             LSCS_SLOT_1(access, __VA_ARGS__)
#define OPENGL_LSCS_SLOT_2(slotName)                                LSCS_SLOT_2(slotName)
#define OPENGL_LSCS_SLOT_OVERLOAD(slotName, argTypes)               LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define OPENGL_LSCS_SIGNAL_1(access, ...)                           LSCS_SIGNAL_1(access, __VA_ARGS__)
#define OPENGL_LSCS_SIGNAL_2(signalName, ...)                       LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define OPENGL_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)      LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#else
#define OPENGL_LSCS_OBJECT(className)                               LSCS_OBJECT_OUTSIDE(className)
#define OPENGL_LSCS_OBJECT_MULTIPLE(className, parentX)             LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define OPENGL_LSCS_GADGET(className)                               LSCS_GADGET_OUTSIDE(className)

#define OPENGL_LSCS_SLOT_1(access, ...)                             __VA_ARGS__;
#define OPENGL_LSCS_SLOT_2(slotName)
#define OPENGL_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define OPENGL_LSCS_SIGNAL_1(access, ...)                           __VA_ARGS__;
#define OPENGL_LSCS_SIGNAL_2(signalName, ...)
#define OPENGL_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#endif

// ** 6
#if defined(QT_BUILD_SCRIPT_LIB) || defined(Q_OS_DARWIN)

#define SCRIPT_LSCS_OBJECT(className)                               LSCS_OBJECT(className)
#define SCRIPT_LSCS_OBJECT_MULTIPLE(className, parentX)             LSCS_OBJECT_MULTIPLE(className, parentX)
#define SCRIPT_LSCS_GADGET(className)                               LSCS_GADGET(className)

#define SCRIPT_LSCS_SLOT_1(access, ...)                             LSCS_SLOT_1(access, __VA_ARGS__)
#define SCRIPT_LSCS_SLOT_2(slotName)                                LSCS_SLOT_2(slotName)
#define SCRIPT_LSCS_SLOT_OVERLOAD(slotName, argTypes)               LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define SCRIPT_LSCS_SIGNAL_1(access, ...)                           LSCS_SIGNAL_1(access, __VA_ARGS__)
#define SCRIPT_LSCS_SIGNAL_2(signalName, ...)                       LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define SCRIPT_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)      LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#else
#define SCRIPT_LSCS_OBJECT(className)                               LSCS_OBJECT_OUTSIDE(className)
#define SCRIPT_LSCS_OBJECT_MULTIPLE(className, parentX)             LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define SCRIPT_LSCS_GADGET(className)                               LSCS_GADGET_OUTSIDE(className)

#define SCRIPT_LSCS_SLOT_1(access, ...)                             __VA_ARGS__;
#define SCRIPT_LSCS_SLOT_2(slotName)
#define SCRIPT_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define SCRIPT_LSCS_SIGNAL_1(access, ...)                           __VA_ARGS__;

#define SCRIPT_LSCS_SIGNAL_2(signalName, ...)
#define SCRIPT_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#endif

// ** 7
#if defined(QT_BUILD_SCRIPTTOOLS_LIB) || defined(Q_OS_DARWIN)

#define SCRIPT_T_LSCS_OBJECT(className)                             LSCS_OBJECT(className)
#define SCRIPT_T_LSCS_OBJECT_MULTIPLE(className, parentX)           LSCS_OBJECT_MULTIPLE(className, parentX)
#define SCRIPT_T_LSCS_GADGET(className)                             LSCS_GADGET(className)

#define SCRIPT_T_LSCS_SLOT_1(access, ...)                           LSCS_SLOT_1(access, __VA_ARGS__)
#define SCRIPT_T_LSCS_SLOT_2(slotName)                              LSCS_SLOT_2(slotName)
#define SCRIPT_T_LSCS_SLOT_OVERLOAD(slotName, argTypes)             LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define SCRIPT_T_LSCS_SIGNAL_1(access, ...)                         LSCS_SIGNAL_1(access, __VA_ARGS__)
#define SCRIPT_T_LSCS_SIGNAL_2(signalName, ...)                     LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define SCRIPT_T_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)    LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#else
#define SCRIPT_T_LSCS_OBJECT(className)                             LSCS_OBJECT_OUTSIDE(className)
#define SCRIPT_T_LSCS_OBJECT_MULTIPLE(className, parentX)           LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define SCRIPT_T_LSCS_GADGET(className)                             LSCS_GADGET_OUTSIDE(className)

#define SCRIPT_T_LSCS_SLOT_1(access, ...)                           __VA_ARGS__;
#define SCRIPT_T_LSCS_SLOT_2(slotName)
#define SCRIPT_T_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define SCRIPT_T_LSCS_SIGNAL_1(access, ...)                         __VA_ARGS__;
#define SCRIPT_T_LSCS_SIGNAL_2(signalName, ...)
#define SCRIPT_T_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#endif

// ** 8
#if defined(QT_BUILD_SQL_LIB) || defined(Q_OS_DARWIN)

#define SQL_LSCS_OBJECT(className)                                  LSCS_OBJECT(className)
#define SQL_LSCS_OBJECT_MULTIPLE(className, parentX)                LSCS_OBJECT_MULTIPLE(className, parentX)
#define SQL_LSCS_GADGET(className)                                  LSCS_GADGET(className)

#define SQL_LSCS_SLOT_1(access, ...)                                LSCS_SLOT_1(access, __VA_ARGS__)
#define SQL_LSCS_SLOT_2(slotName)                                   LSCS_SLOT_2(slotName)
#define SQL_LSCS_SLOT_OVERLOAD(slotName, argTypes)                  LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define SQL_LSCS_SIGNAL_1(access, ...)                              LSCS_SIGNAL_1(access, __VA_ARGS__)
#define SQL_LSCS_SIGNAL_2(signalName, ...)                          LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define SQL_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)         LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#else
#define SQL_LSCS_OBJECT(className)                                  LSCS_OBJECT_OUTSIDE(className)
#define SQL_LSCS_OBJECT_MULTIPLE(className, parentX)                LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define SQL_LSCS_GADGET(className)                                  LSCS_GADGET_OUTSIDE(className)

#define SQL_LSCS_SLOT_1(access, ...)                                __VA_ARGS__;
#define SQL_LSCS_SLOT_2(slotName)
#define SQL_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define SQL_LSCS_SIGNAL_1(access, ...)                              __VA_ARGS__;
#define SQL_LSCS_SIGNAL_2(signalName, ...)
#define SQL_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#endif

// ** 9
#if defined(QT_BUILD_SVG_LIB) || defined(Q_OS_DARWIN)

#define SVG_LSCS_OBJECT(className)                                  LSCS_OBJECT(className)
#define SVG_LSCS_OBJECT_MULTIPLE(className, parentX)                LSCS_OBJECT_MULTIPLE(className, parentX)
#define SVG_LSCS_GADGET(className)                                  LSCS_GADGET(className)

#define SVG_LSCS_SLOT_1(access, ...)                                LSCS_SLOT_1(access, __VA_ARGS__)
#define SVG_LSCS_SLOT_2(slotName)                                   LSCS_SLOT_2(slotName)
#define SVG_LSCS_SLOT_OVERLOAD(slotName, argTypes)                  LSCS_SLOT_OVERLOAD(slotName, argTypes)
#define SVG_LSCS_SLOT_OVERLOAD_BOOL(slotName, argTypes)             LSCS_SLOT_OVERLOAD_BOOL(slotName, argTypes)

#define SVG_LSCS_SIGNAL_1(access, ...)                              LSCS_SIGNAL_1(access, __VA_ARGS__)
#define SVG_LSCS_SIGNAL_2(signalName, ...)                          LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define SVG_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)         LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#define SVG_LSCS_PROPERTY_READ(name, method)                        LSCS_PROPERTY_READ(name, method)
#define SVG_LSCS_PROPERTY_WRITE(name, method)                       LSCS_PROPERTY_WRITE(name, method)
#define SVG_LSCS_PROPERTY_NOTIFY(name, method)                      LSCS_PROPERTY_NOTIFY(name, method)
#define SVG_LSCS_PROPERTY_RESET(name, method)                       LSCS_PROPERTY_RESET(name, method)
#define SVG_LSCS_PROPERTY_REVISION(name, data)                      LSCS_PROPERTY_REVISION(name, data)
#define SVG_LSCS_PROPERTY_DESIGNABLE(name, data)                    LSCS_PROPERTY_DESIGNABLE(name, data)
#define SVG_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)          LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define SVG_LSCS_PROPERTY_SCRIPTABLE(name, data)                    LSCS_PROPERTY_SCRIPTABLE(name, data)
#define SVG_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)          LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define SVG_LSCS_PROPERTY_STORED(name, data)                        LSCS_PROPERTY_STORED(name, data)
#define SVG_LSCS_PROPERTY_STORED_NONSTATIC(name, data)              LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define SVG_LSCS_PROPERTY_USER(name, data)                          LSCS_PROPERTY_USER(name, data)
#define SVG_LSCS_PROPERTY_USER_NONSTATIC(name, data)                LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define SVG_LSCS_PROPERTY_CONSTANT(name)                            LSCS_PROPERTY_CONSTANT(name)
#define SVG_LSCS_PROPERTY_FINAL(name)                               LSCS_PROPERTY_FINAL(name)

#else
#define SVG_LSCS_OBJECT(className)                                  LSCS_OBJECT_OUTSIDE(className)
#define SVG_LSCS_OBJECT_MULTIPLE(className, parentX)                LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define SVG_LSCS_GADGET(className)                                  LSCS_GADGET_OUTSIDE(className)

#define SVG_LSCS_SLOT_1(access, ...)                                __VA_ARGS__;
#define SVG_LSCS_SLOT_2(slotName)
#define SVG_LSCS_SLOT_OVERLOAD(slotName, argTypes)
#define SVG_LSCS_SLOT_OVERLOAD_BOOL(slotName, argTypes)

#define SVG_LSCS_SIGNAL_1(access, ...)                              __VA_ARGS__;
#define SVG_LSCS_SIGNAL_2(signalName, ...)
#define SVG_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#define SVG_LSCS_PROPERTY_READ(name, method)
#define SVG_LSCS_PROPERTY_WRITE(name, method)
#define SVG_LSCS_PROPERTY_NOTIFY(name, method)
#define SVG_LSCS_PROPERTY_RESET(name, method)
#define SVG_LSCS_PROPERTY_REVISION(name, data)
#define SVG_LSCS_PROPERTY_DESIGNABLE(name, data)
#define SVG_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define SVG_LSCS_PROPERTY_SCRIPTABLE(name, data)
#define SVG_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define SVG_LSCS_PROPERTY_STORED(name, data)
#define SVG_LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define SVG_LSCS_PROPERTY_USER(name, data)
#define SVG_LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define SVG_LSCS_PROPERTY_CONSTANT(name)
#define SVG_LSCS_PROPERTY_FINAL(name)

#endif

// ** 10
#if defined(QT_BUILD_VULKAN_LIB) || defined(Q_OS_DARWIN)

#define VULKAN_LSCS_OBJECT(className)                               LSCS_OBJECT(className)
#define VULKAN_LSCS_OBJECT_MULTIPLE(className, parentX)             LSCS_OBJECT_MULTIPLE(className, parentX)

#define VULKAN_LSCS_SIGNAL_1(access, ...)                           LSCS_SIGNAL_1(access, __VA_ARGS__)
#define VULKAN_LSCS_SIGNAL_2(signalName, ...)                       LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define VULKAN_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)      LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#else
#define VULKAN_LSCS_OBJECT(className)                               LSCS_OBJECT_OUTSIDE(className)
#define VULKAN_LSCS_OBJECT_MULTIPLE(className, parentX)             LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)

#define VULKAN_LSCS_SIGNAL_1(access, ...)                           __VA_ARGS__;
#define VULKAN_LSCS_SIGNAL_2(signalName, ...)
#define VULKAN_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#endif

// ** 11
#if defined(QT_BUILD_XMLPATTERNS_LIB) || defined(Q_OS_DARWIN)

#define XMLP_LSCS_OBJECT(className)                                 LSCS_OBJECT(className)
#define XMLP_LSCS_OBJECT_MULTIPLE(className, parentX)               LSCS_OBJECT_MULTIPLE(className, parentX)
#define XMLP_LSCS_GADGET(className)                                 LSCS_GADGET(className)

#define XMLP_LSCS_SLOT_1(access, ...)                               LSCS_SLOT_1(access, __VA_ARGS__)
#define XMLP_LSCS_SLOT_2(slotName)                                  LSCS_SLOT_2(slotName)
#define XMLP_LSCS_SLOT_OVERLOAD(slotName, argTypes)                 LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define XMLP_LSCS_SIGNAL_1(access, ...)                             LSCS_SIGNAL_1(access, __VA_ARGS__)
#define XMLP_LSCS_SIGNAL_2(signalName, ...)                         LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define XMLP_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)        LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#else
#define XMLP_LSCS_OBJECT(className)                                 LSCS_OBJECT_OUTSIDE(className)
#define XMLP_LSCS_OBJECT_MULTIPLE(className, parentX)               LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define XMLP_LSCS_GADGET(className)                                 LSCS_GADGET_OUTSIDE(className)

#define XMLP_LSCS_SLOT_1(access, ...)                               __VA_ARGS__;
#define XMLP_LSCS_SLOT_2(slotName)
#define XMLP_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define XMLP_LSCS_SIGNAL_1(access, ...)                             __VA_ARGS__;
#define XMLP_LSCS_SIGNAL_2(signalName, ...)
#define XMLP_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#endif

// ** 12
#if defined(BUILDING_WEBKIT) || defined(Q_OS_DARWIN)

#define WEB_LSCS_OBJECT(className)                                  LSCS_OBJECT(className)
#define WEB_LSCS_OBJECT_MULTIPLE(className, parentX)                LSCS_OBJECT_MULTIPLE(className, parentX)
#define WEB_LSCS_GADGET(className)                                  LSCS_GADGET(className)

#define WEB_LSCS_SLOT_1(access, ...)                                LSCS_SLOT_1(access, __VA_ARGS__)
#define WEB_LSCS_SLOT_2(slotName)                                   LSCS_SLOT_2(slotName)
#define WEB_LSCS_SLOT_OVERLOAD(slotName, argTypes)                  LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define WEB_LSCS_SIGNAL_1(access, ...)                              LSCS_SIGNAL_1(access, __VA_ARGS__)
#define WEB_LSCS_SIGNAL_2(signalName, ...)                          LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define WEB_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)         LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#define WEB_LSCS_INVOKABLE_METHOD_1(access, ...)                    LSCS_INVOKABLE_METHOD_1(access, __VA_ARGS__)
#define WEB_LSCS_INVOKABLE_METHOD_2(methodName)                     LSCS_INVOKABLE_METHOD_2(methodName)

#define WEB_LSCS_ENUM(name)                                         LSCS_ENUM(name)
#define WEB_LSCS_REGISTER_ENUM(...)                                 LSCS_REGISTER_ENUM(__VA_ARGS__)
#define WEB_LSCS_FLAG(enumName, flagName)                           LSCS_FLAG(enumName, flagName)

#define WEB_LSCS_PROPERTY_READ(name, method)                        LSCS_PROPERTY_READ(name, method)
#define WEB_LSCS_PROPERTY_WRITE(name, method)                       LSCS_PROPERTY_WRITE(name, method)
#define WEB_LSCS_PROPERTY_NOTIFY(name, method)                      LSCS_PROPERTY_NOTIFY(name, method)
#define WEB_LSCS_PROPERTY_RESET(name, method)                       LSCS_PROPERTY_RESET(name, method)
#define WEB_LSCS_PROPERTY_REVISION(name, data)                      LSCS_PROPERTY_REVISION(name, data)
#define WEB_LSCS_PROPERTY_DESIGNABLE(name, data)                    LSCS_PROPERTY_DESIGNABLE(name, data)
#define WEB_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)          LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define WEB_LSCS_PROPERTY_SCRIPTABLE(name, data)                    LSCS_PROPERTY_SCRIPTABLE(name, data)
#define WEB_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)          LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define WEB_LSCS_PROPERTY_STORED(name, data)                        LSCS_PROPERTY_STORED(name, data)
#define WEB_LSCS_PROPERTY_STORED_NONSTATIC(name, data)              LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define WEB_LSCS_PROPERTY_USER(name, data)                          LSCS_PROPERTY_USER(name, data)
#define WEB_LSCS_PROPERTY_USER_NONSTATIC(name, data)                LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define WEB_LSCS_PROPERTY_CONSTANT(name)                            LSCS_PROPERTY_CONSTANT(name)
#define WEB_LSCS_PROPERTY_FINAL(name)                               LSCS_PROPERTY_FINAL(name)

#else
#define WEB_LSCS_OBJECT(className)                                  LSCS_OBJECT_OUTSIDE(className)
#define WEB_LSCS_OBJECT_MULTIPLE(className, parentX)                LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define WEB_LSCS_GADGET(className)                                  LSCS_GADGET_OUTSIDE(className)

#define WEB_LSCS_SLOT_1(access, ...)                                __VA_ARGS__;
#define WEB_LSCS_SLOT_2(slotName)
#define WEB_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define WEB_LSCS_SIGNAL_1(access, ...)                              __VA_ARGS__;
#define WEB_LSCS_SIGNAL_2(signalName, ...)
#define WEB_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#define WEB_LSCS_INVOKABLE_METHOD_1(access, ...)                    __VA_ARGS__;
#define WEB_LSCS_INVOKABLE_METHOD_2(methodName)

#define WEB_LSCS_ENUM(name)
#define WEB_LSCS_REGISTER_ENUM(...)                                 __VA_ARGS__           // do not add ;
#define WEB_LSCS_FLAG(enumName, flagName)

#define WEB_LSCS_PROPERTY_READ(name, method)
#define WEB_LSCS_PROPERTY_WRITE(name, method)
#define WEB_LSCS_PROPERTY_NOTIFY(name, method)
#define WEB_LSCS_PROPERTY_RESET(name, method)
#define WEB_LSCS_PROPERTY_REVISION(name, data)
#define WEB_LSCS_PROPERTY_DESIGNABLE(name, data)
#define WEB_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define WEB_LSCS_PROPERTY_SCRIPTABLE(name, data)
#define WEB_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define WEB_LSCS_PROPERTY_STORED(name, data)
#define WEB_LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define WEB_LSCS_PROPERTY_USER(name, data)
#define WEB_LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define WEB_LSCS_PROPERTY_CONSTANT(name)
#define WEB_LSCS_PROPERTY_FINAL(name)

#endif

// ** 13
#if defined(QT_BUILD_DECLARE_LIB) || defined(Q_OS_DARWIN)

#define DECL_LSCS_OBJECT(className)                                 LSCS_OBJECT(className)
#define DECL_LSCS_OBJECT_MULTIPLE(className, parentX)               LSCS_OBJECT_MULTIPLE(className, parentX)
#define DECL_LSCS_GADGET(className)                                 LSCS_GADGET(className)

#define DECL_LSCS_CLASSINFO(name, data)                             LSCS_CLASSINFO(name, data)

#define DECL_LSCS_SLOT_1(access, ...)                               LSCS_SLOT_1(access, __VA_ARGS__)
#define DECL_LSCS_SLOT_2(slotName)                                  LSCS_SLOT_2(slotName)
#define DECL_LSCS_SLOT_OVERLOAD(slotName, argTypes)                 LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define DECL_LSCS_SIGNAL_1(access, ...)                             LSCS_SIGNAL_1(access, __VA_ARGS__)
#define DECL_LSCS_SIGNAL_2(signalName, ...)                         LSCS_SIGNAL_2(signalName, ## __VA_ARGS__)
#define DECL_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)        LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ## __VA_ARGS__)

#define DECL_LSCS_INVOKABLE_METHOD_1(access, ...)                   LSCS_INVOKABLE_METHOD_1(access, __VA_ARGS__)
#define DECL_LSCS_INVOKABLE_METHOD_2(methodName)                    LSCS_INVOKABLE_METHOD_2(methodName)
#define DECL_LSCS_REVISION(methodName,revision)                     LSCS_REVISION(methodName,revision)
#define DECL_LSCS_REVISION_OVERLOAD(methodName, revision, argTypes) LSCS_REVISION_OVERLOAD(methodName, revision, argTypes)

#define DECL_LSCS_ENUM(name)                                        LSCS_ENUM(name)
#define DECL_LSCS_REGISTER_ENUM(...)                                LSCS_REGISTER_ENUM(__VA_ARGS__)

#define DECL_LSCS_PROPERTY_READ(name, method)                       LSCS_PROPERTY_READ(name, method)
#define DECL_LSCS_PROPERTY_WRITE(name, method)                      LSCS_PROPERTY_WRITE(name, method)
#define DECL_LSCS_PROPERTY_NOTIFY(name, method)                     LSCS_PROPERTY_NOTIFY(name, method)
#define DECL_LSCS_PROPERTY_RESET(name, method)                      LSCS_PROPERTY_RESET(name, method)
#define DECL_LSCS_PROPERTY_REVISION(name, data)                     LSCS_PROPERTY_REVISION(name, data)
#define DECL_LSCS_PROPERTY_DESIGNABLE(name, data)                   LSCS_PROPERTY_DESIGNABLE(name, data)
#define DECL_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)         LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define DECL_LSCS_PROPERTY_SCRIPTABLE(name, data)                   LSCS_PROPERTY_SCRIPTABLE(name, data)
#define DECL_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)         LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define DECL_LSCS_PROPERTY_STORED(name, data)                       LSCS_PROPERTY_STORED(name, data)
#define DECL_LSCS_PROPERTY_STORED_NONSTATIC(name, data)             LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define DECL_LSCS_PROPERTY_USER(name, data)                         LSCS_PROPERTY_USER(name, data)
#define DECL_LSCS_PROPERTY_USER_NONSTATIC(name, data)               LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define DECL_LSCS_PROPERTY_CONSTANT(name)                           LSCS_PROPERTY_CONSTANT(name)
#define DECL_LSCS_PROPERTY_FINAL(name)                              LSCS_PROPERTY_FINAL(name)

#else
#define DECL_LSCS_OBJECT(className)                                 LSCS_OBJECT_OUTSIDE(className)
#define DECL_LSCS_OBJECT_MULTIPLE(className, parentX)               LSCS_OBJECT_MULTIPLE_OUTSIDE(className, parentX)
#define DECL_LSCS_GADGET(className)                                 LSCS_GADGET_OUTSIDE(className)

#define DECL_LSCS_CLASSINFO(name, data)

#define DECL_LSCS_SLOT_1(access, ...)                               __VA_ARGS__;
#define DECL_LSCS_SLOT_2(slotName)
#define DECL_LSCS_SLOT_OVERLOAD(slotName, argTypes)

#define DECL_LSCS_SIGNAL_1(access, ...)                             __VA_ARGS__;
#define DECL_LSCS_SIGNAL_2(signalName, ...)
#define DECL_LSCS_SIGNAL_OVERLOAD(signalName, argTypes, ...)

#define DECL_LSCS_INVOKABLE_METHOD_1(access, ...)                   __VA_ARGS__;
#define DECL_LSCS_INVOKABLE_METHOD_2(methodName)
#define DECL_LSCS_REVISION(methodName,revision)
#define DECL_LSCS_REVISION_OVERLOAD(methodName, revision, argTypes)

#define DECL_LSCS_ENUM(name)
#define DECL_LSCS_REGISTER_ENUM(...)                                __VA_ARGS__           // do not add ;

#define DECL_LSCS_PROPERTY_READ(name, method)
#define DECL_LSCS_PROPERTY_WRITE(name, method)
#define DECL_LSCS_PROPERTY_NOTIFY(name, method)
#define DECL_LSCS_PROPERTY_RESET(name, method)
#define DECL_LSCS_PROPERTY_REVISION(name, data)
#define DECL_LSCS_PROPERTY_DESIGNABLE(name, data)
#define DECL_LSCS_PROPERTY_DESIGNABLE_NONSTATIC(name, data)
#define DECL_LSCS_PROPERTY_SCRIPTABLE(name, data)
#define DECL_LSCS_PROPERTY_SCRIPTABLE_NONSTATIC(name, data)
#define DECL_LSCS_PROPERTY_STORED(name, data)
#define DECL_LSCS_PROPERTY_STORED_NONSTATIC(name, data)
#define DECL_LSCS_PROPERTY_USER(name, data)
#define DECL_LSCS_PROPERTY_USER_NONSTATIC(name, data)
#define DECL_LSCS_PROPERTY_CONSTANT(name)
#define DECL_LSCS_PROPERTY_FINAL(name)

#endif

#endif // CSOBJECT_MACRO_H
