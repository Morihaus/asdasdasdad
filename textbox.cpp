#include "textbox.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace genv;

TextBox::TextBox(int x, int y, int m_x, int m_y,string s) : widgets(x,y,m_x,m_y)
{
    _s=s;
}

bool TextBox::is_selected( int mouse_x, int mouse_y ) const
{
    return mouse_x>_x && mouse_x<_x+_m_x && mouse_y>_y && mouse_y<_y+_m_y;
}

void TextBox::draw()
{
    seged_s=_s;
    while (gout.twidth(seged_s)>_m_x-5)
    {
        seged_s=seged_s.substr(1,_s.length());
    }
    gout << move_to(_x, _y) << color(179,255,254) << box(_m_x, _m_y);
    gout << color(0,0,0)<<move_to(_x+8,_y+20)<<text(seged_s);

}

void TextBox::handle(event ev)
{
    if (ev.type==ev_key && ev.keycode >=32 && ev.keycode < 255)
    {
        _s+=ev.keycode;
    }
    if (ev.type==ev_key && ev.keycode == key_backspace && _s.length()>0)
    {
        _s.erase(_s.end()-1);
    }
}
