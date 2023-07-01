//
// Created by DonV06 on 18.06.2023.
//

#ifndef HORRORGAME_SCREENMANAGER_H
#define HORRORGAME_SCREENMANAGER_H
#include "../libs/SDL2_base/include/SDL2/SDL.h"

#include <vector>
#include "Vector2f.h"
#include "Window.h"
class ScreenManager
{
public:
    bool isIndexAvailable(const std::vector<int>& vec, int index) {
        return (index >= 0 && index < vec.size());
    }
    int createWindow(Vector2f loc, Vector2f size) {
        Window newwindow(loc, size);
        windows.push_back(newwindow);

    }
    std::vector<Window> getwindows() {
        return windows;
    }
    Window getWindow(int id) {
        return windows[id];
    }
    ScreenManager() {

    }
    ~ScreenManager() {
        for (Window currentwin: windows) {
            SDL_DestroyWindow(currentwin.getSDLwindow());
            SDL_DestroyRenderer(currentwin.getsdlRenderer());
        }
    }
    void destroy() {
        for (Window currentwin: windows) {
            SDL_DestroyWindow(currentwin.getSDLwindow());
            SDL_DestroyRenderer(currentwin.getsdlRenderer());

        }
    }
    void destroyWindow(int id) {
        Window curr = windows[id];


    }
private:
    std::vector<Window> windows;

};


#endif //HORRORGAME_SCREENMANAGER_H
