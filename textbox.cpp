#include "textbox.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace genv;

TextBox::TextBox(int x, int y, int m_x, int m_y,string s) : widgets(x,y,m_x,m_y)
{
}

bool TextBox::is_selected( int mouse_x, int mouse_y ) const
{
    return mouse_x>_x && mouse_x<_x+_m_x && mouse_y>_y && mouse_y<_y+_m_y;
}

void TextBox::draw()
{
    gout << move_to(_x, _y) << color(179,255,254) << box(_m_x, _m_y);
    gout << color(0,0,0)<<move_to(_x+8,_y+20) << text(_s);
}

void TextBox::handle(event ev)
{
    cout<<"baszki"<<endl;
    if (ev.type==ev_key && ev.keycode >=0 && ev.keycode < 255 && _x+_s.length()*10<_x+_m_x-20)
    {
        _s+=char(ev.keycode);
    }
    if (ev.type==ev_key && ev.keycode == key_backspace && _s.length()!=0)
    {
        _s.erase(_s.length()-1);
        gout<<move_to(_x+_s.length()*8, _y+20)<<color(0,0,0)<<box(_m_x,_m_y);
    }

}
