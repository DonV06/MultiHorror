//
// Created by DonV06 on 18.06.2023.
//

#ifndef HORRORGAME_SCREENMANAGER_H
#define HORRORGAME_SCREENMANAGER_H
#include "../libs/SDL2_base/include/SDL2/SDL.h"

#include <vector>
#include "vector2f.h"
#include "window.h"
class ScreenManager
{
public:
    int createWindow(vector2f loc, vector2f size);
    std::vector<window> getwindows();
    window getWindow(int id);
    void destroy();
    void destroyWindow(int id);
    ScreenManager();
    ~ScreenManager();
private:
    std::vector<window> windows;

};


#endif //HORRORGAME_SCREENMANAGER_H
