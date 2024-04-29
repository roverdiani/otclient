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
