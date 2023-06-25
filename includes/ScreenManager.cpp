//
// Created by DonV06 on 18.06.2023.
//


#include "ScreenManager.h"
#include "vector2f.h"
#include "window.h"
bool isIndexAvailable(const std::vector<int>& vec, int index) {
    return (index >= 0 && index < vec.size());
}


int ScreenManager::createWindow(vector2f loc, vector2f size) {
    window newwindow(loc, size);
    windows.push_back(newwindow);

}

std::vector<window> ScreenManager::getwindows() {
    return windows;
}

window ScreenManager::getWindow(int id) {
    return windows[id];
}

ScreenManager::ScreenManager() {

}

ScreenManager::~ScreenManager() {
    for (window currentwin: windows) {
        SDL_DestroyWindow(currentwin.getSDLwindow());
        SDL_DestroyRenderer(currentwin.getsdlRenderer());
    }
}

void ScreenManager::destroy() {
    for (window currentwin: windows) {
        SDL_DestroyWindow(currentwin.getSDLwindow());
        SDL_DestroyRenderer(currentwin.getsdlRenderer());

    }
}

void ScreenManager::destroyWindow(int id) {
    window curr = windows[id];


}


