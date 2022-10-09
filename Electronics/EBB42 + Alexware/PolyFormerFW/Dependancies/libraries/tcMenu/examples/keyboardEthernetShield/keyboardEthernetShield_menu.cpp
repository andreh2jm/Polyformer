/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#include <tcMenu.h>
#include "keyboardEthernetShield_menu.h"

// Global variable declarations
const PROGMEM  ConnectorLocalInfo applicationInfo = { "Keyboard Ethernet", "b6ee8e21-449c-4f8a-bab6-a89e3f2c68d9" };
TcMenuRemoteServer remoteServer(applicationInfo);
IoAbstractionRef ioexp_io23017 = ioFrom23017(0x20, ACTIVE_LOW_OPEN, 2);
AvrEeprom glAvrRom;
EepromAuthenticatorManager authManager(6);
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
LiquidCrystalRenderer renderer(lcd, 20, 4);
MatrixKeyboardManager keyboard;
const char keyboardKeys[] PROGMEM  = "123456789*0#";
KeyboardLayout keyboardLayout(4, 3, keyboardKeys);
MenuEditingKeyListener tcMenuKeyListener('*', '#', 'A', 'B');
EthernetServer server(3333);
EthernetInitialisation ethernetInitialisation(&server);
EthernetTagValTransport ethernetTransport;
TagValueRemoteServerConnection ethernetConnection(ethernetTransport, ethernetInitialisation);
EthernetServer server2(3334);
EthernetInitialisation ethernetInitialisation2(&server2);
EthernetTagValTransport ethernetTransport2;
TagValueRemoteServerConnection ethernetConnection2(ethernetTransport2, ethernetInitialisation2);

// Global Menu Item declarations
const PROGMEM AnyMenuInfo minfoRomChoicesSave = { "Save", 23, 0xffff, 0, onSaveValue };
ActionMenuItem menuRomChoicesSave(&minfoRomChoicesSave, NULL);
RENDERING_CALLBACK_NAME_INVOKE(fnRomChoicesValueRtCall, textItemRenderFn, "Value", -1, NO_CALLBACK)
TextMenuItem menuRomChoicesValue(fnRomChoicesValueRtCall, 22, 10, &menuRomChoicesSave);
extern char romSpaceNames[];
RENDERING_CALLBACK_NAME_INVOKE(fnRomChoicesItemNumRtCall, enumItemRenderFn, "Item Num", -1, onItemChange)
ScrollChoiceMenuItem menuRomChoicesItemNum(21, fnRomChoicesItemNumRtCall, 0, romSpaceNames, 7, 10, &menuRomChoicesValue);
RENDERING_CALLBACK_NAME_INVOKE(fnRomChoicesRtCall, backSubItemRenderFn, "Rom Choices", -1, NO_CALLBACK)
const PROGMEM SubMenuInfo minfoRomChoices = { "Rom Choices", 20, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackRomChoices(fnRomChoicesRtCall, &menuRomChoicesItemNum);
SubMenuItem menuRomChoices(&minfoRomChoices, &menuBackRomChoices, NULL);
const PROGMEM BooleanMenuInfo minfoAdditionalBoolFlagFlag4 = { "Flag4", 28, 41, 1, NO_CALLBACK, NAMING_YES_NO };
BooleanMenuItem menuAdditionalBoolFlagFlag4(&minfoAdditionalBoolFlagFlag4, false, NULL);
const PROGMEM BooleanMenuInfo minfoAdditionalBoolFlagFlag3 = { "Flag3", 27, 40, 1, NO_CALLBACK, NAMING_YES_NO };
BooleanMenuItem menuAdditionalBoolFlagFlag3(&minfoAdditionalBoolFlagFlag3, false, &menuAdditionalBoolFlagFlag4);
const PROGMEM BooleanMenuInfo minfoAdditionalBoolFlagFlag2 = { "Flag2", 26, 39, 1, NO_CALLBACK, NAMING_ON_OFF };
BooleanMenuItem menuAdditionalBoolFlagFlag2(&minfoAdditionalBoolFlagFlag2, false, &menuAdditionalBoolFlagFlag3);
const PROGMEM BooleanMenuInfo minfoAdditionalBoolFlagFlag1 = { "Flag1", 25, 38, 1, NO_CALLBACK, NAMING_ON_OFF };
BooleanMenuItem menuAdditionalBoolFlagFlag1(&minfoAdditionalBoolFlagFlag1, false, &menuAdditionalBoolFlagFlag2);
RENDERING_CALLBACK_NAME_INVOKE(fnAdditionalBoolFlagRtCall, backSubItemRenderFn, "Bool Flag", -1, NO_CALLBACK)
const PROGMEM SubMenuInfo minfoAdditionalBoolFlag = { "Bool Flag", 24, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackAdditionalBoolFlag(fnAdditionalBoolFlagRtCall, &menuAdditionalBoolFlagFlag1);
SubMenuItem menuAdditionalBoolFlag(&minfoAdditionalBoolFlag, &menuBackAdditionalBoolFlag, NULL);
ListRuntimeMenuItem menuAdditionalCountList(18, 20, fnAdditionalCountListRtCall, &menuAdditionalBoolFlag);
ScrollChoiceMenuItem menuAdditionalNumChoices(17, fnAdditionalNumChoicesRtCall, 0, 30, &menuAdditionalCountList);
RENDERING_CALLBACK_NAME_INVOKE(fnAdditionalRomChoiceRtCall, enumItemRenderFn, "Rom Choice", 30, NO_CALLBACK)
ScrollChoiceMenuItem menuAdditionalRomChoice(19, fnAdditionalRomChoiceRtCall, 0, 500, 10, 9, &menuAdditionalNumChoices);
RENDERING_CALLBACK_NAME_INVOKE(fnAdditionalRGBRtCall, rgbAlphaItemRenderFn, "RGB", 34, NO_CALLBACK)
Rgb32MenuItem menuAdditionalRGB(15, fnAdditionalRGBRtCall, true, &menuAdditionalRomChoice);
RENDERING_CALLBACK_NAME_INVOKE(fnAdditionalRtCall, backSubItemRenderFn, "Additional", -1, NO_CALLBACK)
const PROGMEM SubMenuInfo minfoAdditional = { "Additional", 14, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackAdditional(fnAdditionalRtCall, &menuAdditionalRGB);
SubMenuItem menuAdditional(&minfoAdditional, &menuBackAdditional, &menuRomChoices);
const PROGMEM char pgmStrConnectivityAuthenticatorText[] = { "Authenticator" };
EepromAuthenticationInfoMenuItem menuConnectivityAuthenticator(pgmStrConnectivityAuthenticatorText, NO_CALLBACK, 30, NULL);
const PROGMEM char pgmStrConnectivityIoTMonitorText[] = { "IoT Monitor" };
RemoteMenuItem menuConnectivityIoTMonitor(pgmStrConnectivityIoTMonitorText, 29, &menuConnectivityAuthenticator);
const PROGMEM AnyMenuInfo minfoConnectivitySaveToEEPROM = { "Save to EEPROM", 10, 0xffff, 0, onSaveToEeprom };
ActionMenuItem menuConnectivitySaveToEEPROM(&minfoConnectivitySaveToEEPROM, &menuConnectivityIoTMonitor);
RENDERING_CALLBACK_NAME_INVOKE(fnConnectivityTextRtCall, textItemRenderFn, "Text", 16, NO_CALLBACK)
TextMenuItem menuConnectivityText(fnConnectivityTextRtCall, 9, 10, &menuConnectivitySaveToEEPROM);
RENDERING_CALLBACK_NAME_INVOKE(fnConnectivityIpAddressRtCall, ipAddressRenderFn, "IpAddress", 12, NO_CALLBACK)
IpAddressMenuItem menuConnectivityIpAddress(fnConnectivityIpAddressRtCall, 7, &menuConnectivityText);
RENDERING_CALLBACK_NAME_INVOKE(fnConnectivityChangePinRtCall, textItemRenderFn, "Change Pin", -1, onChangePin)
TextMenuItem menuConnectivityChangePin(fnConnectivityChangePinRtCall, 11, 15, &menuConnectivityIpAddress);
RENDERING_CALLBACK_NAME_INVOKE(fnConnectivityRtCall, backSubItemRenderFn, "Connectivity", -1, NO_CALLBACK)
const PROGMEM SubMenuInfo minfoConnectivity = { "Connectivity", 6, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackConnectivity(fnConnectivityRtCall, &menuConnectivityChangePin);
SubMenuItem menuConnectivity(&minfoConnectivity, &menuBackConnectivity, &menuAdditional);
const char enumStrFruits_0[] PROGMEM = "Apples";
const char enumStrFruits_1[] PROGMEM = "Oranges";
const char enumStrFruits_2[] PROGMEM = "Pears";
const char enumStrFruits_3[] PROGMEM = "Plums";
const char enumStrFruits_4[] PROGMEM = "Grapes";
const char* const enumStrFruits[] PROGMEM  = { enumStrFruits_0, enumStrFruits_1, enumStrFruits_2, enumStrFruits_3, enumStrFruits_4 };
const PROGMEM EnumMenuInfo minfoFruits = { "Fruits", 8, 26, 4, NO_CALLBACK, enumStrFruits };
EnumMenuItem menuFruits(&minfoFruits, 0, &menuConnectivity);
const PROGMEM AnalogMenuInfo minfoFiths = { "Fiths", 5, 6, 200, onFiths, 0, 5, "A" };
AnalogMenuItem menuFiths(&minfoFiths, 0, &menuFruits);
RENDERING_CALLBACK_NAME_INVOKE(fnLargeNumRtCall, largeNumItemRenderFn, "Large Num", -1, NO_CALLBACK)
EditableLargeNumberMenuItem menuLargeNum(fnLargeNumRtCall, 12, 8, 4, true, &menuFiths);
const PROGMEM AnalogMenuInfo minfoDecimalTens = { "DecimalTens", 4, 28, 1000, NO_CALLBACK, 0, 10, "V" };
AnalogMenuItem menuDecimalTens(&minfoDecimalTens, 0, &menuLargeNum);
const PROGMEM AnalogMenuInfo minfoInteger = { "Integer", 3, 4, 1000, onInteger, 100, 1, "" };
AnalogMenuItem menuInteger(&minfoInteger, 0, &menuDecimalTens);
const PROGMEM BooleanMenuInfo minfoHiddenItem = { "Hidden item", 13, 0xffff, 1, NO_CALLBACK, NAMING_TRUE_FALSE };
BooleanMenuItem menuHiddenItem(&minfoHiddenItem, false, &menuInteger);
const PROGMEM AnalogMenuInfo minfoAnalog1 = { "Analog1", 2, 2, 255, onAnalog1, -180, 2, "dB" };
AnalogMenuItem menuAnalog1(&minfoAnalog1, 0, &menuHiddenItem);
RENDERING_CALLBACK_NAME_INVOKE(fnTimeRtCall, timeItemRenderFn, "Time", 8, NO_CALLBACK)
TimeFormattedMenuItem menuTime(fnTimeRtCall, 1, (MultiEditWireType)3, &menuAnalog1);

void setupMenu() {
    // First we set up eeprom and authentication (if needed).
    menuMgr.setEepromRef(&glAvrRom);
    authManager.initialise(menuMgr.getEepromAbstraction(), 100);
    menuMgr.setAuthenticator(&authManager);
    // Now add any readonly, non-remote and visible flags.
    menuConnectivityAuthenticator.setLocalOnly(true);
    menuConnectivityIoTMonitor.setLocalOnly(true);
    menuConnectivity.setLocalOnly(true);
    menuConnectivity.setSecured(true);
    menuHiddenItem.setVisible(false);

    // Code generated by plugins.
    lcd.setIoAbstraction(ioexp_io23017);
    lcd.begin(20, 4);
    renderer.setUpdatesPerSecond(4);
    switches.init(ioexp_io23017, SWITCHES_NO_POLLING, true);
    menuMgr.initForEncoder(&renderer, &menuTime, 6, 7, 5, FULL_CYCLE);
    keyboardLayout.setRowPin(0, 22);
    keyboardLayout.setRowPin(1, 23);
    keyboardLayout.setRowPin(2, 24);
    keyboardLayout.setRowPin(3, 25);
    keyboardLayout.setColPin(0, 26);
    keyboardLayout.setColPin(1, 27);
    keyboardLayout.setColPin(2, 28);
    keyboard.initialise(internalDigitalIo(), &keyboardLayout, &tcMenuKeyListener, false);
    keyboard.setRepeatKeyMillis(850, 350);
    remoteServer.addConnection(&ethernetConnection);
    remoteServer.addConnection(&ethernetConnection2);

    // We have an IoT monitor, register the server
    menuConnectivityIoTMonitor.setRemoteServer(remoteServer);

    // We have an EEPROM authenticator, it needs initialising
    menuConnectivityAuthenticator.init();
}

