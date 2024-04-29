/*
 * Copyright (c) 2010-2016 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "sdlwindow.h"
#include <framework/core/resourcemanager.h>
#include <framework/graphics/image.h>
#include <unistd.h>

#define LSB_BIT_SET(p, n) (p[(n)/8] |= (1 <<((n)%8)))

SDLWindow::SDLWindow()
{
    internalBuildKeyMap();
}

void SDLWindow::internalBuildKeyMap()
{
    // TODO: there are some keys missing the SDL KeyCode
    m_keyMap[SDLK_ESCAPE] = Fw::KeyEscape;
    m_keyMap[SDLK_TAB] = Fw::KeyTab;
    m_keyMap[SDLK_RETURN] = Fw::KeyEnter;
    m_keyMap[SDLK_BACKSPACE] = Fw::KeyBackspace;

    m_keyMap[SDLK_PAGEUP] = Fw::KeyPageUp;
    m_keyMap[SDLK_PAGEDOWN] = Fw::KeyPageDown;
    m_keyMap[SDLK_HOME] = Fw::KeyHome;
    m_keyMap[SDLK_END] = Fw::KeyEnd;
    m_keyMap[SDLK_INSERT] = Fw::KeyInsert;
    m_keyMap[SDLK_DELETE] = Fw::KeyDelete;

    m_keyMap[SDLK_UP] = Fw::KeyUp;
    m_keyMap[SDLK_DOWN] = Fw::KeyDown;
    m_keyMap[SDLK_LEFT] = Fw::KeyLeft;
    m_keyMap[SDLK_RIGHT] = Fw::KeyRight;

    m_keyMap[SDLK_NUMLOCKCLEAR] = Fw::KeyNumLock;
    m_keyMap[SDLK_SCROLLLOCK] = Fw::KeyScrollLock;
    m_keyMap[SDLK_CAPSLOCK] = Fw::KeyCapsLock;
    m_keyMap[SDLK_PRINTSCREEN] = Fw::KeyPrintScreen;
    m_keyMap[SDLK_PAUSE] = Fw::KeyPause;

    m_keyMap[SDLK_LCTRL] = Fw::KeyCtrl;
    m_keyMap[SDLK_RCTRL] = Fw::KeyCtrl;
    m_keyMap[SDLK_RSHIFT] = Fw::KeyShift;
    m_keyMap[SDLK_LSHIFT] = Fw::KeyShift;
    m_keyMap[SDLK_RALT] = Fw::KeyAlt;
    m_keyMap[SDLK_LALT] = Fw::KeyAlt;
    // m_keyMap[XK_Meta_L] = Fw::KeyMeta;
    // m_keyMap[XK_Meta_R] = Fw::KeyMeta;
    m_keyMap[SDLK_MENU] = Fw::KeyMenu;

#if defined(__APPLE__)
    m_keyMap[65406] = Fw::KeyAlt;// Option
    m_keyMap[65511] = Fw::KeyMeta;// Command
#endif

    // ascii characters
    m_keyMap[SDLK_SPACE] = Fw::KeySpace;
    m_keyMap[SDLK_EXCLAIM] = Fw::KeyExclamation;
    m_keyMap[SDLK_QUOTEDBL] = Fw::KeyQuote;
    //m_keyMap[XK_numbersign] = Fw::KeyNumberSign;
    m_keyMap[SDLK_DOLLAR] = Fw::KeyDollar;
    m_keyMap[SDLK_PERCENT] = Fw::KeyPercent;
    m_keyMap[SDLK_AMPERSAND] = Fw::KeyAmpersand;
    //m_keyMap[XK_apostrophe] = Fw::KeyApostrophe;
    m_keyMap[SDLK_LEFTPAREN] = Fw::KeyLeftParen;
    m_keyMap[SDLK_RIGHTPAREN] = Fw::KeyRightParen;
    m_keyMap[SDLK_ASTERISK] = Fw::KeyAsterisk;
    m_keyMap[SDLK_PLUS] = Fw::KeyPlus;
    m_keyMap[SDLK_COMMA] = Fw::KeyComma;
    m_keyMap[SDLK_MINUS] = Fw::KeyMinus;
    m_keyMap[SDLK_PERIOD] = Fw::KeyPeriod;
    m_keyMap[SDLK_SLASH] = Fw::KeySlash;
    m_keyMap[SDLK_1] = Fw::Key1;
    m_keyMap[SDLK_2] = Fw::Key2;
    m_keyMap[SDLK_3] = Fw::Key3;
    m_keyMap[SDLK_4] = Fw::Key4;
    m_keyMap[SDLK_5] = Fw::Key5;
    m_keyMap[SDLK_6] = Fw::Key6;
    m_keyMap[SDLK_7] = Fw::Key7;
    m_keyMap[SDLK_8] = Fw::Key8;
    m_keyMap[SDLK_9] = Fw::Key9;
    m_keyMap[SDLK_0] = Fw::Key0;
    m_keyMap[SDLK_COLON] = Fw::KeyColon;
    m_keyMap[SDLK_SEMICOLON] = Fw::KeySemicolon;
    m_keyMap[SDLK_LESS] = Fw::KeyLess;
    m_keyMap[SDLK_EQUALS] = Fw::KeyEqual;
    m_keyMap[SDLK_GREATER] = Fw::KeyGreater;
    m_keyMap[SDLK_QUESTION] = Fw::KeyQuestion;
    m_keyMap[SDLK_AT] = Fw::KeyAtSign;
    m_keyMap[SDLK_a] = Fw::KeyA;
    m_keyMap[SDLK_b] = Fw::KeyB;
    m_keyMap[SDLK_c] = Fw::KeyC;
    m_keyMap[SDLK_d] = Fw::KeyD;
    m_keyMap[SDLK_e] = Fw::KeyE;
    m_keyMap[SDLK_f] = Fw::KeyF;
    m_keyMap[SDLK_g] = Fw::KeyG;
    m_keyMap[SDLK_h] = Fw::KeyH;
    m_keyMap[SDLK_i] = Fw::KeyI;
    m_keyMap[SDLK_j] = Fw::KeyJ;
    m_keyMap[SDLK_k] = Fw::KeyK;
    m_keyMap[SDLK_l] = Fw::KeyL;
    m_keyMap[SDLK_m] = Fw::KeyM;
    m_keyMap[SDLK_n] = Fw::KeyN;
    m_keyMap[SDLK_o] = Fw::KeyO;
    m_keyMap[SDLK_p] = Fw::KeyP;
    m_keyMap[SDLK_q] = Fw::KeyQ;
    m_keyMap[SDLK_r] = Fw::KeyR;
    m_keyMap[SDLK_s] = Fw::KeyS;
    m_keyMap[SDLK_t] = Fw::KeyT;
    m_keyMap[SDLK_u] = Fw::KeyU;
    m_keyMap[SDLK_v] = Fw::KeyV;
    m_keyMap[SDLK_w] = Fw::KeyW;
    m_keyMap[SDLK_x] = Fw::KeyX;
    m_keyMap[SDLK_y] = Fw::KeyY;
    m_keyMap[SDLK_z] = Fw::KeyZ;
    // m_keyMap[XK_bracketleft] = Fw::KeyLeftBracket;
    // m_keyMap[XK_backslash] = Fw::KeyBackslash;
    // m_keyMap[XK_bracketright] = Fw::KeyRightBracket;
    // m_keyMap[XK_asciicircum] = Fw::KeyCaret;
    // m_keyMap[XK_underscore] = Fw::KeyUnderscore;
    // m_keyMap[XK_grave] = Fw::KeyGrave;
    // m_keyMap[XK_braceleft] = Fw::KeyLeftCurly;
    // m_keyMap[XK_bar] = Fw::KeyBar;
    // m_keyMap[XK_braceright] = Fw::KeyRightCurly;
    // m_keyMap[XK_asciitilde] = Fw::KeyTilde;

    // keypad
    /*
    m_keyMap[XK_KP_Add] = Fw::KeyPlus;
    m_keyMap[XK_KP_Subtract] = Fw::KeyMinus;
    m_keyMap[XK_KP_Decimal] = Fw::KeyPeriod;
    m_keyMap[XK_KP_Divide] = Fw::KeySlash;
    m_keyMap[XK_KP_Multiply] = Fw::KeyAsterisk;
    */
    m_keyMap[SDLK_KP_ENTER] = Fw::KeyEnter;

    // keypad with numlock off
    // m_keyMap[XK_KP_Insert] = Fw::KeyNumpad0;
    // m_keyMap[XK_KP_End] = Fw::KeyNumpad1;
    // m_keyMap[XK_KP_Down] = Fw::KeyNumpad2;
    // m_keyMap[XK_KP_Page_Down] = Fw::KeyNumpad3;
    // m_keyMap[XK_KP_Left] = Fw::KeyNumpad4;
    // m_keyMap[XK_KP_Begin] = Fw::KeyNumpad5;
    // m_keyMap[XK_KP_Right] = Fw::KeyNumpad6;
    // m_keyMap[XK_KP_Home] = Fw::KeyNumpad7;
    // m_keyMap[XK_KP_Up] = Fw::KeyNumpad8;
    // m_keyMap[XK_KP_Page_Up] = Fw::KeyNumpad9;
    // m_keyMap[XK_KP_Delete] = Fw::KeyDelete;

    // keypad with numlock on
    m_keyMap[SDLK_KP_0] = Fw::Key0;
    m_keyMap[SDLK_KP_1] = Fw::Key1;
    m_keyMap[SDLK_KP_2] = Fw::Key2;
    m_keyMap[SDLK_KP_3] = Fw::Key3;
    m_keyMap[SDLK_KP_4] = Fw::Key4;
    m_keyMap[SDLK_KP_5] = Fw::Key5;
    m_keyMap[SDLK_KP_6] = Fw::Key6;
    m_keyMap[SDLK_KP_7] = Fw::Key7;
    m_keyMap[SDLK_KP_8] = Fw::Key8;
    m_keyMap[SDLK_KP_9] = Fw::Key9;

    m_keyMap[SDLK_F1] = Fw::KeyF1;
    m_keyMap[SDLK_F2] = Fw::KeyF2;
    m_keyMap[SDLK_F3] = Fw::KeyF3;
    m_keyMap[SDLK_F4] = Fw::KeyF4;
    m_keyMap[SDLK_F5] = Fw::KeyF5;
    m_keyMap[SDLK_F6] = Fw::KeyF6;
    m_keyMap[SDLK_F7] = Fw::KeyF7;
    m_keyMap[SDLK_F8] = Fw::KeyF8;
    m_keyMap[SDLK_F9] = Fw::KeyF9;
    m_keyMap[SDLK_F10] = Fw::KeyF10;
    m_keyMap[SDLK_F11] = Fw::KeyF11;
    m_keyMap[SDLK_F12] = Fw::KeyF12;
}

void SDLWindow::init()
{
    internalOpenDisplay();
    internalCheckGL();
    internalChooseGLVisual();
    internalCreateGLContext();
    internalCreateWindow();
}

void SDLWindow::terminate()
{
}

void SDLWindow::internalOpenDisplay()
{
}

void SDLWindow::internalCreateWindow()
{
}

bool SDLWindow::internalSetupWindowInput()
{
    return false;
}

void SDLWindow::internalCheckGL()
{
}

void SDLWindow::internalChooseGLVisual()
{
}

void SDLWindow::internalCreateGLContext()
{
}

void SDLWindow::internalDestroyGLContext()
{
}

void SDLWindow::internalConnectGLContext()
{
}

void *SDLWindow::getExtensionProcAddress(const char *ext)
{
    return nullptr;
}

bool SDLWindow::isExtensionSupported(const char *ext)
{
    return false;
}

void SDLWindow::move(const Point& pos)
{
}

void SDLWindow::resize(const Size& size)
{
}

void SDLWindow::show()
{
}

void SDLWindow::hide()
{
}

void SDLWindow::maximize()
{
}

void SDLWindow::poll()
{
}

void SDLWindow::swapBuffers()
{
}

void SDLWindow::showMouse()
{
    restoreMouseCursor();
}

void SDLWindow::hideMouse()
{
}

void SDLWindow::setMouseCursor(int cursorId)
{
}

void SDLWindow::restoreMouseCursor()
{
}

int SDLWindow::internalLoadMouseCursor(const ImagePtr& image, const Point& hotSpot)
{
    return 0;
}

void SDLWindow::setTitle(const std::string& title)
{
}

void SDLWindow::setMinimumSize(const Size& minimumSize)
{
}

void SDLWindow::setFullscreen(bool fullscreen)
{
}

void SDLWindow::setVerticalSync(bool enable)
{
}

void SDLWindow::setIcon(const std::string& file)
{
}

void SDLWindow::setClipboardText(const std::string& text)
{
}

Size SDLWindow::getDisplaySize()
{
    return Size(0, 0);
}

std::string SDLWindow::getClipboardText()
{
    return "";
}

std::string SDLWindow::getPlatformType()
{
    return "";
}
