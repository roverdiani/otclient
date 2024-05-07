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

#ifndef SDLWINDOW_H
#define SDLWINDOW_H

#include "platformwindow.h"
#include <framework/graphics/glutil.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class SDLWindow : public PlatformWindow
{
    void internalCreateWindow();

    void internalCheckGL();
    void internalChooseGLVisual();
    void internalCreateGLContext();
    void internalDestroyGLContext();
    void internalConnectGLContext();

    void *getExtensionProcAddress(const char *ext);
    bool isExtensionSupported(const char *ext);

    void internalBuildKeyMap();

public:
    SDLWindow();

    void init() override;
    void terminate() override;

    void move(const Point& pos) override;
    void resize(const Size& size) override;
    void show() override;
    void hide() override;
    void maximize() override;
    void poll() override;
    void swapBuffers() override;
    void showMouse() override;
    void hideMouse() override;

    void setMouseCursor(int cursorId) override;
    void restoreMouseCursor() override;

    void setTitle(const std::string& title) override;
    void setMinimumSize(const Size& minimumSize) override;
    void setFullscreen(bool fullscreen) override;
    void setVerticalSync(bool enable) override;
    void setIcon(const std::string& file) override;
    void setClipboardText(const std::string& text) override;

    Size getDisplaySize() override;
    std::string getClipboardText() override;
    std::string getPlatformType() override;

protected:
    int internalLoadMouseCursor(const ImagePtr& image, const Point& hotSpot) override;

private:
    SDL_Window *m_window;

    SDL_GLContext m_glContext;

    SDL_Cursor *m_cursor;
    std::vector<SDL_Cursor*> m_cursors;
};

#endif

