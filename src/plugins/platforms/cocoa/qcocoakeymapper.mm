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

#include <qcocoakeymapper.h>

#include <qapplication.h>
#include <qdebug.h>

// Possible modifier states.
// NOTE: The order of these states match the order in updatePossibleKeyCodes()!
static const Qt::KeyboardModifiers ModsTbl[] = {
   Qt::NoModifier,                                             // 0
   Qt::ShiftModifier,                                          // 1
   Qt::ControlModifier,                                        // 2
   Qt::ControlModifier | Qt::ShiftModifier,                    // 3
   Qt::AltModifier,                                            // 4
   Qt::AltModifier | Qt::ShiftModifier,                        // 5
   Qt::AltModifier | Qt::ControlModifier,                      // 6
   Qt::AltModifier | Qt::ShiftModifier | Qt::ControlModifier,  // 7
   Qt::MetaModifier,                                           // 8
   Qt::MetaModifier | Qt::ShiftModifier,                       // 9
   Qt::MetaModifier | Qt::ControlModifier,                    // 10
   Qt::MetaModifier | Qt::ControlModifier | Qt::ShiftModifier,// 11
   Qt::MetaModifier | Qt::AltModifier,                        // 12
   Qt::MetaModifier | Qt::AltModifier | Qt::ShiftModifier,    // 13
   Qt::MetaModifier | Qt::AltModifier | Qt::ControlModifier,  // 14
   Qt::MetaModifier | Qt::AltModifier | Qt::ShiftModifier | Qt::ControlModifier,  // 15
};

bool lscs_mac_eat_unicode_key = false;

void lscs_mac_secure_keyboard(bool b)
{
   static bool secure = false;
   if (b != secure) {
      b ? EnableSecureEventInput() : DisableSecureEventInput();
      secure = b;
   }
}

/* key maps */
struct lscs_mac_enum_mapper {
   int mac_code;
   int lscs_code;

#if defined(LSCS_SHOW_DEBUG_PLATFORM)
#   define LSCS_MAC_MAP_ENUM(x) x, #x
    const char *desc;
#else
#   define LSCS_MAC_MAP_ENUM(x) x
#endif

};

//modifiers
static lscs_mac_enum_mapper lscs_mac_modifier_symbols[] = {
   { shiftKey, LSCS_MAC_MAP_ENUM(Qt::ShiftModifier) },
   { rightShiftKey, LSCS_MAC_MAP_ENUM(Qt::ShiftModifier) },
   { controlKey, LSCS_MAC_MAP_ENUM(Qt::MetaModifier) },
   { rightControlKey, LSCS_MAC_MAP_ENUM(Qt::MetaModifier) },
   { cmdKey, LSCS_MAC_MAP_ENUM(Qt::ControlModifier) },
   { optionKey, LSCS_MAC_MAP_ENUM(Qt::AltModifier) },
   { rightOptionKey, LSCS_MAC_MAP_ENUM(Qt::AltModifier) },
   { kEventKeyModifierNumLockMask, LSCS_MAC_MAP_ENUM(Qt::KeypadModifier) },
   { 0, LSCS_MAC_MAP_ENUM(0) }
};

Qt::KeyboardModifiers lscs_mac_get_modifiers(int keys)
{
#if defined(LSCS_SHOW_DEBUG_PLATFORM)
   qDebug("lscs_mac_get_modifiers() Mapping modifiers = %d (0x%04x)", keys, keys);
#endif

   Qt::KeyboardModifiers ret = Qt::NoModifier;

   for (int i = 0; lscs_mac_modifier_symbols[i].lscs_code; i++) {
      if (keys & lscs_mac_modifier_symbols[i].mac_code) {
         ret |= Qt::KeyboardModifier(lscs_mac_modifier_symbols[i].lscs_code);
      }
   }

   if (qApp->testAttribute(Qt::AA_MacDontSwapCtrlAndMeta)) {
      Qt::KeyboardModifiers oldModifiers = ret;
      ret &= ~(Qt::MetaModifier | Qt::ControlModifier);

      if (oldModifiers & Qt::ControlModifier) {
         ret |= Qt::MetaModifier;
      }

      if (oldModifiers & Qt::MetaModifier) {
         ret |= Qt::ControlModifier;
      }
   }

   return ret;
}

static int lscs_mac_get_mac_modifiers(Qt::KeyboardModifiers keys)
{
#if defined(LSCS_SHOW_DEBUG_PLATFORM)
   qDebug("lscs_mac_get_mac_modifiers() Mapping modifiers = %d (0x%04x)", (int)keys, (int)keys);
#endif

   int ret = 0;

   for (int i = 0; lscs_mac_modifier_symbols[i].lscs_code; i++) {
      if (keys & lscs_mac_modifier_symbols[i].lscs_code) {
         ret |= lscs_mac_modifier_symbols[i].mac_code;
      }
   }

   if (qApp->testAttribute(Qt::AA_MacDontSwapCtrlAndMeta)) {
      int oldModifiers = ret;
      ret &= ~(controlKeyBit | cmdKeyBit);

      if (oldModifiers & controlKeyBit) {
         ret |= cmdKeyBit;
      }

      if (oldModifiers & cmdKeyBit) {
         ret |= controlKeyBit;
      }
   }
   return ret;
}

//keyboard keys (non-modifiers)
static lscs_mac_enum_mapper lscs_mac_keyboard_symbols[] = {
   { kHomeCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Home) },
   { kEnterCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Enter) },
   { kEndCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_End) },
   { kBackspaceCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Backspace) },
   { kTabCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Tab) },
   { kPageUpCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_PageUp) },
   { kPageDownCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_PageDown) },
   { kReturnCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Return) },
   { kEscapeCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Escape) },
   { kLeftArrowCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Left) },
   { kRightArrowCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Right) },
   { kUpArrowCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Up) },
   { kDownArrowCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Down) },
   { kHelpCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Help) },
   { kDeleteCharCode, LSCS_MAC_MAP_ENUM(Qt::Key_Delete) },
   //ascii maps, for debug
   { ':', LSCS_MAC_MAP_ENUM(Qt::Key_Colon) },
   { ';', LSCS_MAC_MAP_ENUM(Qt::Key_Semicolon) },
   { '<', LSCS_MAC_MAP_ENUM(Qt::Key_Less) },
   { '=', LSCS_MAC_MAP_ENUM(Qt::Key_Equal) },
   { '>', LSCS_MAC_MAP_ENUM(Qt::Key_Greater) },
   { '?', LSCS_MAC_MAP_ENUM(Qt::Key_Question) },
   { '@', LSCS_MAC_MAP_ENUM(Qt::Key_At) },
   { ' ', LSCS_MAC_MAP_ENUM(Qt::Key_Space) },
   { '!', LSCS_MAC_MAP_ENUM(Qt::Key_Exclam) },
   { '"', LSCS_MAC_MAP_ENUM(Qt::Key_QuoteDbl) },
   { '#', LSCS_MAC_MAP_ENUM(Qt::Key_NumberSign) },
   { '$', LSCS_MAC_MAP_ENUM(Qt::Key_Dollar) },
   { '%', LSCS_MAC_MAP_ENUM(Qt::Key_Percent) },
   { '&', LSCS_MAC_MAP_ENUM(Qt::Key_Ampersand) },
   { '\'', LSCS_MAC_MAP_ENUM(Qt::Key_Apostrophe) },
   { '(', LSCS_MAC_MAP_ENUM(Qt::Key_ParenLeft) },
   { ')', LSCS_MAC_MAP_ENUM(Qt::Key_ParenRight) },
   { '*', LSCS_MAC_MAP_ENUM(Qt::Key_Asterisk) },
   { '+', LSCS_MAC_MAP_ENUM(Qt::Key_Plus) },
   { ',', LSCS_MAC_MAP_ENUM(Qt::Key_Comma) },
   { '-', LSCS_MAC_MAP_ENUM(Qt::Key_Minus) },
   { '.', LSCS_MAC_MAP_ENUM(Qt::Key_Period) },
   { '/', LSCS_MAC_MAP_ENUM(Qt::Key_Slash) },
   { '[', LSCS_MAC_MAP_ENUM(Qt::Key_BracketLeft) },
   { ']', LSCS_MAC_MAP_ENUM(Qt::Key_BracketRight) },
   { '\\', LSCS_MAC_MAP_ENUM(Qt::Key_Backslash) },
   { '_', LSCS_MAC_MAP_ENUM(Qt::Key_Underscore) },
   { '`', LSCS_MAC_MAP_ENUM(Qt::Key_QuoteLeft) },
   { '{', LSCS_MAC_MAP_ENUM(Qt::Key_BraceLeft) },
   { '}', LSCS_MAC_MAP_ENUM(Qt::Key_BraceRight) },
   { '|', LSCS_MAC_MAP_ENUM(Qt::Key_Bar) },
   { '~', LSCS_MAC_MAP_ENUM(Qt::Key_AsciiTilde) },
   { '^', LSCS_MAC_MAP_ENUM(Qt::Key_AsciiCircum) },
   {   0, LSCS_MAC_MAP_ENUM(0) }
};

static lscs_mac_enum_mapper lscs_mac_keyvkey_symbols[] = { //real scan codes
   { kVK_F1, LSCS_MAC_MAP_ENUM(Qt::Key_F1) },
   { kVK_F2, LSCS_MAC_MAP_ENUM(Qt::Key_F2) },
   { kVK_F3, LSCS_MAC_MAP_ENUM(Qt::Key_F3) },
   { kVK_F4, LSCS_MAC_MAP_ENUM(Qt::Key_F4) },
   { kVK_F5, LSCS_MAC_MAP_ENUM(Qt::Key_F5) },
   { kVK_F6, LSCS_MAC_MAP_ENUM(Qt::Key_F6) },
   { kVK_F7, LSCS_MAC_MAP_ENUM(Qt::Key_F7) },
   { kVK_F8, LSCS_MAC_MAP_ENUM(Qt::Key_F8) },
   { kVK_F9, LSCS_MAC_MAP_ENUM(Qt::Key_F9) },
   { kVK_F10, LSCS_MAC_MAP_ENUM(Qt::Key_F10) },
   { kVK_F11, LSCS_MAC_MAP_ENUM(Qt::Key_F11) },
   { kVK_F12, LSCS_MAC_MAP_ENUM(Qt::Key_F12) },
   { kVK_F13, LSCS_MAC_MAP_ENUM(Qt::Key_F13) },
   { kVK_F14, LSCS_MAC_MAP_ENUM(Qt::Key_F14) },
   { kVK_F15, LSCS_MAC_MAP_ENUM(Qt::Key_F15) },
   { kVK_F16, LSCS_MAC_MAP_ENUM(Qt::Key_F16) },
   { kVK_Return, LSCS_MAC_MAP_ENUM(Qt::Key_Return) },
   { kVK_Tab, LSCS_MAC_MAP_ENUM(Qt::Key_Tab) },
   { kVK_Escape, LSCS_MAC_MAP_ENUM(Qt::Key_Escape) },
   { kVK_Help, LSCS_MAC_MAP_ENUM(Qt::Key_Help) },
   { kVK_UpArrow, LSCS_MAC_MAP_ENUM(Qt::Key_Up) },
   { kVK_DownArrow, LSCS_MAC_MAP_ENUM(Qt::Key_Down) },
   { kVK_LeftArrow, LSCS_MAC_MAP_ENUM(Qt::Key_Left) },
   { kVK_RightArrow, LSCS_MAC_MAP_ENUM(Qt::Key_Right) },
   { kVK_PageUp, LSCS_MAC_MAP_ENUM(Qt::Key_PageUp) },
   { kVK_PageDown, LSCS_MAC_MAP_ENUM(Qt::Key_PageDown) },
   {   0, LSCS_MAC_MAP_ENUM(0) }
};

static lscs_mac_enum_mapper lscs_mac_private_unicode[] = {
   { 0xF700, LSCS_MAC_MAP_ENUM(Qt::Key_Up) },            //NSUpArrowFunctionKey
   { 0xF701, LSCS_MAC_MAP_ENUM(Qt::Key_Down) },          //NSDownArrowFunctionKey
   { 0xF702, LSCS_MAC_MAP_ENUM(Qt::Key_Left) },          //NSLeftArrowFunctionKey
   { 0xF703, LSCS_MAC_MAP_ENUM(Qt::Key_Right) },         //NSRightArrowFunctionKey
   { 0xF727, LSCS_MAC_MAP_ENUM(Qt::Key_Insert) },        //NSInsertFunctionKey
   { 0xF728, LSCS_MAC_MAP_ENUM(Qt::Key_Delete) },        //NSDeleteFunctionKey
   { 0xF729, LSCS_MAC_MAP_ENUM(Qt::Key_Home) },          //NSHomeFunctionKey
   { 0xF72B, LSCS_MAC_MAP_ENUM(Qt::Key_End) },           //NSEndFunctionKey
   { 0xF72C, LSCS_MAC_MAP_ENUM(Qt::Key_PageUp) },        //NSPageUpFunctionKey
   { 0xF72D, LSCS_MAC_MAP_ENUM(Qt::Key_PageDown) },      //NSPageDownFunctionKey
   { 0xF72F, LSCS_MAC_MAP_ENUM(Qt::Key_ScrollLock) },    //NSScrollLockFunctionKey
   { 0xF730, LSCS_MAC_MAP_ENUM(Qt::Key_Pause) },         //NSPauseFunctionKey
   { 0xF731, LSCS_MAC_MAP_ENUM(Qt::Key_SysReq) },        //NSSysReqFunctionKey
   { 0xF735, LSCS_MAC_MAP_ENUM(Qt::Key_Menu) },          //NSMenuFunctionKey
   { 0xF738, LSCS_MAC_MAP_ENUM(Qt::Key_Print) },         //NSPrintFunctionKey
   { 0xF73A, LSCS_MAC_MAP_ENUM(Qt::Key_Clear) },         //NSClearDisplayFunctionKey
   { 0xF73D, LSCS_MAC_MAP_ENUM(Qt::Key_Insert) },        //NSInsertCharFunctionKey
   { 0xF73E, LSCS_MAC_MAP_ENUM(Qt::Key_Delete) },        //NSDeleteCharFunctionKey
   { 0xF741, LSCS_MAC_MAP_ENUM(Qt::Key_Select) },        //NSSelectFunctionKey
   { 0xF742, LSCS_MAC_MAP_ENUM(Qt::Key_Execute) },       //NSExecuteFunctionKey
   { 0xF746, LSCS_MAC_MAP_ENUM(Qt::Key_Help) },          //NSHelpFunctionKey
   { 0xF747, LSCS_MAC_MAP_ENUM(Qt::Key_Mode_switch) },   //NSModeSwitchFunctionKey
   {   0,    LSCS_MAC_MAP_ENUM(0) }
};

static int lscs_mac_get_key(int modif, const QChar &key, int virtualKey)
{
#if defined(LSCS_SHOW_DEBUG_PLATFORM)
   qDebug("lscs_mac_get_key() Mapping key = %d (0x%04x) - %d (0x%04x)",
         key.unicode(), key.unicode(), virtualKey, virtualKey);
#endif

   if (key == kClearCharCode && virtualKey == 0x47) {
      return Qt::Key_Clear;
   }

   if (key.isDigit()) {
#if defined(LSCS_SHOW_DEBUG_PLATFORM)
      qDebug("lscs_mac_get_key() digit key = %d", key.digitValue());
#endif

      return key.digitValue() + Qt::Key_0;
   }

   if (key.isLetter()) {
#if defined(LSCS_SHOW_DEBUG_PLATFORM)
      qDebug("lscs_mac_get_key() letter key = %d", key.toUpper()[0].unicode() - 'A');
#endif

      return (key.toUpper()[0].unicode() - 'A') + Qt::Key_A;
   }

   if (key.isSymbol()) {
#if defined(LSCS_SHOW_DEBUG_PLATFORM)
      qDebug("lscs_mac_get_key() symbol key = %d", key.unicode());
#endif
      return key.unicode();
   }

   for (int i = 0; lscs_mac_keyboard_symbols[i].lscs_code; i++) {
      if (lscs_mac_keyboard_symbols[i].mac_code == key) {

         // To work like X11 we issue Backtab when Shift + Tab are pressed
         if (lscs_mac_keyboard_symbols[i].lscs_code == Qt::Key_Tab && (modif & Qt::ShiftModifier)) {

#if defined(LSCS_SHOW_DEBUG_PLATFORM)
            qDebug("lscs_mac_get_key() key = Qt::Key_Backtab");
#endif
            return Qt::Key_Backtab;
         }

#if defined(LSCS_SHOW_DEBUG_PLATFORM)
         qDebug("lscs_mac_get_key() symbol key = %s", lscs_mac_keyboard_symbols[i].desc);
#endif
         return lscs_mac_keyboard_symbols[i].lscs_code;
      }
   }

   // last ditch try to match the scan code
   for (int i = 0; lscs_mac_keyvkey_symbols[i].lscs_code; i++) {
      if (lscs_mac_keyvkey_symbols[i].mac_code == virtualKey) {

#if defined(LSCS_SHOW_DEBUG_PLATFORM)
         qDebug("lscs_mac_get_key() symbol key = %s", lscs_mac_keyvkey_symbols[i].desc);
#endif

         return lscs_mac_keyvkey_symbols[i].lscs_code;
      }
   }

   // check if they belong to key codes in private unicode range
   if (key >= 0xf700 && key <= 0xf747) {
      if (key >= 0xf704 && key <= 0xf726) {
         return Qt::Key_F1 + (key.unicode() - 0xf704) ;
      }

      for (int i = 0; lscs_mac_private_unicode[i].lscs_code; i++) {
         if (lscs_mac_private_unicode[i].mac_code == key) {
            return lscs_mac_private_unicode[i].lscs_code;
         }
      }

   }

#if defined(LSCS_SHOW_DEBUG_PLATFORM)
   qDebug("lscs_mac_get_key() key = %d,  latin1 = %d, virtual key = %d", key.unicode(), key.toLatin1(), virtualKey);
#endif

   return Qt::Key_unknown;
}

QCocoaKeyMapper::QCocoaKeyMapper()
{
   memset(keyLayout, 0, sizeof(keyLayout));
   keyboard_layout_format.unicode = nullptr;
   currentInputSource = nullptr;
}

QCocoaKeyMapper::~QCocoaKeyMapper()
{
   deleteLayouts();
}

Qt::KeyboardModifiers QCocoaKeyMapper::queryKeyboardModifiers()
{
   return lscs_mac_get_modifiers(GetCurrentEventKeyModifiers());
}

bool QCocoaKeyMapper::updateKeyboard()
{
   const UCKeyboardLayout *uchrData = nullptr;
   QCFType<TISInputSourceRef> source = TISCopyCurrentKeyboardInputSource();

   if (keyboard_mode != NullMode && source == currentInputSource) {
      return false;
   }

   Q_ASSERT(source != nullptr);
   CFDataRef data = static_cast<CFDataRef>(TISGetInputSourceProperty(source, kTISPropertyUnicodeKeyLayoutData));
   uchrData = data ? reinterpret_cast<const UCKeyboardLayout *>(CFDataGetBytePtr(data)) : nullptr;

   keyboard_kind = LMGetKbdType();
   if (uchrData) {
      keyboard_layout_format.unicode = uchrData;
      keyboard_mode = UnicodeMode;
   }
   currentInputSource = source;
   keyboard_dead = 0;
   CFStringRef iso639Code;

   CFArrayRef array = static_cast<CFArrayRef>(TISGetInputSourceProperty(currentInputSource, kTISPropertyInputSourceLanguages));
   iso639Code = static_cast<CFStringRef>(CFArrayGetValueAtIndex(array, 0)); // Actually a RFC3066bis, but it's close enough

   if (iso639Code) {
      keyboardInputLocale = QLocale(QCFString::toQString(iso639Code));
      keyboardInputDirection = keyboardInputLocale.textDirection();
   } else {
      keyboardInputLocale = QLocale::c();
      keyboardInputDirection = Qt::LeftToRight;
   }

   return true;
}

void QCocoaKeyMapper::deleteLayouts()
{
   keyboard_mode = NullMode;
   for (int i = 0; i < 255; ++i) {
      if (keyLayout[i]) {
         delete keyLayout[i];
         keyLayout[i] = nullptr;
      }
   }
}

void QCocoaKeyMapper::clearMappings()
{
   deleteLayouts();
   updateKeyboard();
}

void QCocoaKeyMapper::updateKeyMap(unsigned short macVirtualKey, QChar unicodeKey)
{
   if (updateKeyboard()) {
      // do nothing
   }

   if (keyLayout[macVirtualKey]) {
      return;
   }

   UniCharCount buffer_size = 10;
   UniChar buffer[buffer_size];
   keyLayout[macVirtualKey] = new KeyboardLayoutItem;

   for (int i = 0; i < 16; ++i) {
      UniCharCount out_buffer_size = 0;
      keyLayout[macVirtualKey]->qtKey[i] = 0;

      const UInt32 keyModifier = ((lscs_mac_get_mac_modifiers(ModsTbl[i]) >> 8) & 0xFF);
      OSStatus err = UCKeyTranslate(keyboard_layout_format.unicode, macVirtualKey, kUCKeyActionDown, keyModifier,
            keyboard_kind, 0, &keyboard_dead, buffer_size, &out_buffer_size, buffer);
      if (err == noErr && out_buffer_size) {
         const QChar unicode(buffer[0]);
         int qtkey = lscs_mac_get_key(keyModifier, unicode, macVirtualKey);
         if (qtkey == Qt::Key_unknown) {
            qtkey = unicode.unicode();
         }
         keyLayout[macVirtualKey]->qtKey[i] = qtkey;

      } else {
         int qtkey = lscs_mac_get_key(keyModifier, unicodeKey, macVirtualKey);
         if (qtkey == Qt::Key_unknown) {
            qtkey = unicodeKey.unicode();
         }
         keyLayout[macVirtualKey]->qtKey[i] = qtkey;
      }
   }

#if defined(LSCS_SHOW_DEBUG_PLATFORM)
   qDebug("QCocoaKeyMapper::updateKeyMap() virtual key = 0x%02x", (uint)macVirtualKey);

   for (int i = 0; i < 16; ++i) {
      qDebug("    [%d] (%d,0x%02x,'%c')", i,
         keyLayout[macVirtualKey]->qtKey[i],
         keyLayout[macVirtualKey]->qtKey[i],
         keyLayout[macVirtualKey]->qtKey[i]);
   }
#endif
}

QList<int> QCocoaKeyMapper::possibleKeys(const QKeyEvent *event) const
{
   QList<int> ret;
   const_cast<QCocoaKeyMapper *>(this)->updateKeyMap(event->nativeVirtualKey(), QChar(event->key()));

   KeyboardLayoutItem *kbItem = keyLayout[event->nativeVirtualKey()];

   if (! kbItem) {
      // Key is not in any keyboard layout (e.g. eisu-key on Japanese keyboard)
      return ret;
   }

   int baseKey = kbItem->qtKey[0];
   Qt::KeyboardModifiers keyMods = event->modifiers();

   ret << int(baseKey + keyMods); // The base key is _always_ valid, of course

   for (int i = 1; i < 8; ++i) {
      Qt::KeyboardModifiers neededMods = ModsTbl[i];
      int key = kbItem->qtKey[i];
      if (key && key != baseKey && ((keyMods & neededMods) == neededMods)) {
         ret << int(key + (keyMods & ~neededMods));
      }
   }

   return ret;
}
