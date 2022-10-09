/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#include <tcMenu.h>
#include "nokia5110_menu.h"
#include "ThemeMonoInverse.h"

// Global variable declarations
const PROGMEM  ConnectorLocalInfo applicationInfo = { "Security App", "0e68e7f6-2932-43f0-aae3-d4f885b7561d" };
TcMenuRemoteServer remoteServer(applicationInfo);
AvrEeprom glAvrRom;
EepromAuthenticatorManager authManager(6);
Adafruit_PCD8544 gfx(35, 34, 38, 37, 36);
AdafruitDrawable gfxDrawable(&gfx);
GraphicsDeviceRenderer renderer(30, applicationInfo.name, &gfxDrawable);
EthernetServer server(3333);
EthernetInitialisation ethernetInitialisation(&server);
EthernetTagValTransport ethernetTransport;
TagValueRemoteServerConnection ethernetConnection(ethernetTransport, ethernetInitialisation);

// Global Menu Item declarations
const PROGMEM char pgmStrAuthenticatorText[] = { "Authenticator" };
EepromAuthenticationInfoMenuItem menuAuthenticator(pgmStrAuthenticatorText, NO_CALLBACK, 19, NULL);
const PROGMEM char pgmStrIoTMonitorText[] = { "IoT Monitor" };
RemoteMenuItem menuIoTMonitor(pgmStrIoTMonitorText, 18, &menuAuthenticator);
RENDERING_CALLBACK_NAME_INVOKE(fnIPRtCall, ipAddressRenderFn, "IP", 13, NO_CALLBACK)
IpAddressMenuItem menuIP(fnIPRtCall, 16, &menuIoTMonitor);
RENDERING_CALLBACK_NAME_INVOKE(fnConnectivityRtCall, backSubItemRenderFn, "Connectivity", -1, NO_CALLBACK)
const PROGMEM SubMenuInfo minfoConnectivity = { "Connectivity", 15, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackConnectivity(fnConnectivityRtCall, &menuIP);
SubMenuItem menuConnectivity(&minfoConnectivity, &menuBackConnectivity, NULL);
RENDERING_CALLBACK_NAME_INVOKE(fnTxtRtCall, textItemRenderFn, "Txt", -1, NO_CALLBACK)
TextMenuItem menuTxt(fnTxtRtCall, 14, 6, NULL);
const PROGMEM FloatMenuInfo minfoCurrent = { "Current", 10, 0xffff, 2, NO_CALLBACK };
FloatMenuItem menuCurrent(&minfoCurrent, &menuTxt);
const PROGMEM FloatMenuInfo minfoVoltsIn = { "Volts in", 9, 0xffff, 2, NO_CALLBACK };
FloatMenuItem menuVoltsIn(&minfoVoltsIn, &menuCurrent);
RENDERING_CALLBACK_NAME_INVOKE(fnStatusRtCall, backSubItemRenderFn, "Status", -1, NO_CALLBACK)
const PROGMEM SubMenuInfo minfoStatus = { "Status", 8, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackStatus(fnStatusRtCall, &menuVoltsIn);
SubMenuItem menuStatus(&minfoStatus, &menuBackStatus, &menuConnectivity);
RENDERING_CALLBACK_NAME_INVOKE(fnRGBRtCall, rgbAlphaItemRenderFn, "RGB", 17, NO_CALLBACK)
Rgb32MenuItem menuRGB(17, fnRGBRtCall, true, NULL);
const PROGMEM AnyMenuInfo minfoShutdownNow = { "Shutdown now", 11, 0xffff, 0, onPowerDownDetected };
ActionMenuItem menuShutdownNow(&minfoShutdownNow, &menuRGB);
const PROGMEM AnalogMenuInfo minfoDelay = { "Delay", 7, 11, 10, NO_CALLBACK, 0, 1, "S" };
AnalogMenuItem menuDelay(&minfoDelay, 0, &menuShutdownNow);
const PROGMEM BooleanMenuInfo minfoPwrDelay = { "Pwr Delay", 6, 10, 1, NO_CALLBACK, NAMING_YES_NO };
BooleanMenuItem menuPwrDelay(&minfoPwrDelay, false, &menuDelay);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsRtCall, backSubItemRenderFn, "Settings", -1, NO_CALLBACK)
const PROGMEM SubMenuInfo minfoSettings = { "Settings", 5, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackSettings(fnSettingsRtCall, &menuPwrDelay);
SubMenuItem menuSettings(&minfoSettings, &menuBackSettings, &menuStatus);
const char enumStrOnAlm_0[] PROGMEM = "All On";
const char enumStrOnAlm_1[] PROGMEM = "Silient";
const char* const enumStrOnAlm[] PROGMEM  = { enumStrOnAlm_0, enumStrOnAlm_1 };
const PROGMEM EnumMenuInfo minfoOnAlm = { "On Alm", 4, 8, 1, NO_CALLBACK, enumStrOnAlm };
EnumMenuItem menuOnAlm(&minfoOnAlm, 0, &menuSettings);
const PROGMEM AnalogMenuInfo minfoKitchen = { "Kitchen", 3, 6, 100, onKitchenLight, 0, 1, "%" };
AnalogMenuItem menuKitchen(&minfoKitchen, 0, &menuOnAlm);
const PROGMEM AnalogMenuInfo minfoLiving = { "Living", 2, 4, 100, onLivingRoomLight, 0, 1, "%" };
AnalogMenuItem menuLiving(&minfoLiving, 0, &menuKitchen);
const PROGMEM AnalogMenuInfo minfoHall = { "Hall", 1, 2, 100, onHallLight, 0, 1, "%" };
AnalogMenuItem menuHall(&minfoHall, 0, &menuLiving);

void setupMenu() {
    // First we set up eeprom and authentication (if needed).
    menuMgr.setEepromRef(&glAvrRom);
    authManager.initialise(menuMgr.getEepromAbstraction(), 100);
    menuMgr.setAuthenticator(&authManager);
    // Now add any readonly, non-remote and visible flags.
    menuConnectivity.setLocalOnly(true);
    menuConnectivity.setSecured(true);

    // Code generated by plugins.
    gfx.begin();
    gfx.setRotation(0);
    renderer.setUpdatesPerSecond(4);
    renderer.setUseSliderForAnalog(false);
    switches.init(internalDigitalIo(), SWITCHES_POLL_EVERYTHING, true);
    menuMgr.initForEncoder(&renderer, &menuHall, 2, 3, 4);
    remoteServer.addConnection(&ethernetConnection);
    renderer.setTitleMode(BaseGraphicalRenderer::TITLE_FIRST_ROW);
    renderer.setUseSliderForAnalog(false);
    installMonoInverseTitleTheme(renderer, MenuFontDef(nullptr, 1), MenuFontDef(nullptr, 1), true);

    // We have an IoT monitor, register the server
    menuIoTMonitor.setRemoteServer(remoteServer);

    // We have an EEPROM authenticator, it needs initialising
    menuAuthenticator.init();
}

