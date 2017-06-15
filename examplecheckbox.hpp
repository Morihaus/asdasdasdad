#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED
#include "graphics.hpp"
#include "widgets.h"

using namespace std;

class examplecheckbox : public widgets
{
private:
    string _s;
public:
    examplecheckbox(int x, int y, int m_x, int m_y, string s);
    void draw();
    void handle(genv::event);
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
