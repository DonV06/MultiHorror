//
// Created by DonV06 on 18.06.2023.
//


#include "ScreenManager.h"
#include "Vector2f.h"
#include "Window.h"
bool isIndexAvailable(const std::vector<int>& vec, int index) {
    return (index >= 0 && index < vec.size());
}


int ScreenManager::createWindow(Vector2f loc, Vector2f size) {
    Window newwindow(loc, size);
    windows.push_back(newwindow);

}

std::vector<Window> ScreenManager::getwindows() {
    return windows;
}

Window ScreenManager::getWindow(int id) {
    return windows[id];
}

ScreenManager::ScreenManager() {

}

ScreenManager::~ScreenManager() {
    for (Window currentwin: windows) {
        SDL_DestroyWindow(currentwin.getSDLwindow());
        SDL_DestroyRenderer(currentwin.getsdlRenderer());
    }
}

void ScreenManager::destroy() {
    for (Window currentwin: windows) {
        SDL_DestroyWindow(currentwin.getSDLwindow());
        SDL_DestroyRenderer(currentwin.getsdlRenderer());

    }
}

void ScreenManager::destroyWindow(int id) {
    Window curr = windows[id];


}


