#include "textbox.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace genv;

TextBox::TextBox(int x, int y, int m_x, int m_y, string s) : widgets(x,y,m_x,m_y)
{
    _s=s;
}
void TextBox::draw()
{
    gout << move_to(_x, _y) << color(179,255,254) << box(_m_x, _m_y);
    gout << color(0,0,0)<<move_to(_x+8, _y+20) << text(_s);
}
void TextBox::handle(event ev)
{

    if (ev.pos_x>_x && ev.pos_x<_x+_m_x && ev.pos_y>=_y && ev.pos_y<_y+_m_x)
    {
        if (ev.keycode >= ' ' && ev.keycode < 255)
        {
            _s += ev.keycode;
            if (_m_x < 10+gout.twidth(_s) )
            {
                _s = _s.substr(0,_s.length()-1);
            }
        }
        if (ev.keycode == key_backspace)
        {
            _s = _s.substr(0,_s.length()-1);
        }
    }
}
