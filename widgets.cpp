#include "widgets.h"
#include "graphics.hpp"
using namespace genv;

widgets::widgets(int x,int y, int m_x, int m_y ): _x(x), _y(y), _m_x(m_x), _m_y(m_y)
{
}
widgets::~widgets()
{
}

bool widgets::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>_x && mouse_x<_x+_m_x && mouse_y>_y && mouse_y<_y+_m_y;
}

int widgets::get_x()
{
    return _x;
}
int widgets::get_y()
{
    return _y;
}
int widgets::get_m_y()
{
    return _m_y;
}
int widgets::get_m_x()
{
    return _m_x;
}
int widgets::get_numb()
{
    return _numb;
}
void widgets::set_numb(int a)
{
    _numb = a;
}
