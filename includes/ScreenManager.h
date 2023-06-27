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
    int createWindow(Vector2f loc, Vector2f size);
    std::vector<Window> getwindows();
    Window getWindow(int id);
    void destroy();
    void destroyWindow(int id);
    ScreenManager();
    ~ScreenManager();
private:
    std::vector<Window> windows;

};


#endif //HORRORGAME_SCREENMANAGER_H
