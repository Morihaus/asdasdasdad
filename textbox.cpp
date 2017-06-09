#include "textbox.hpp"
#include <string>
using namespace std;
using namespace genv;

TextBox::TextBox(int x, int y, int m_x, int m_y, string s) : widgets(x,y,m_x,m_y)
{
    _s=s;
}
void TextBox::draw()
{
    gout << move_to(get_x(), get_y()) << color(179,255,254) << box(get_m_x(), get_m_y());
    gout << color(0,0,0)<<move_to(get_x()+8, get_y()+20) << text(_s);
}
void TextBox::handle(event ev)
{
    if (ev.type == ev_key && ev.pos_x>get_x() && ev.pos_x<get_x()+get_m_x() && ev.pos_y>=get_y() && ev.pos_y<get_y()+(get_m_y()))
    {
        if (ev.keycode >= ' ' && ev.keycode < 255)
        {
            _s += ev.keycode;
            if (get_m_x() < 10+gout.twidth(_s) )
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
