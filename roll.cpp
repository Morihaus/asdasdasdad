#include "roll.h"
#include <iostream>
using namespace genv;
using namespace std;


roll::roll(int x,int y,int m_x,int m_y, vector<string> element): widgets(x,y,m_x,m_y)
{
    elements=element;
}
roll::~roll()
{
}

bool roll::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>_x && mouse_x<_x+_m_x && mouse_y>_y && mouse_y<_y+_m_y;
}

void roll::close()
{
    gout << move_to(_x,_y+_m_y) << color(0,0,0) << box(_m_x,elements.size()*gout.cascent()*2);
    open=false;
}
void roll::draw()
{
    gout << move_to(_x,_y) << color(179,255,254) << box(_m_x,_m_y);
    gout << move_to(_x+5,_y+(_m_y/2)+gout.cascent()/2) << color(0,0,0) << text(elements[_numb]);
    gout << move_to(_x+_m_x-(_m_x/8),_y) << color(255,179,234) << box(_m_x/8,_m_y)
         << move_to(_x+_m_x-(_m_x/12),_y+(_m_y/2)+gout.cascent()/2) <<color(150,150,150)<<text("V");
}

void roll::rolling()
{
    int py=get_m_y();
    for(int i=0; i<elements.size(); i++)
    {
        gout << move_to(_x,_y+py) << color(179,255,254) << box(_m_x,gout.cascent()*2);
        gout << move_to(_x+5,_y+py+gout.cascent()) << color(0,0,0) << text(elements[i]);
        py=py+20;
    }
    open=true;
}
void roll::handle(event ev)
{
    if(open)
    {
        int yy=_y+_m_y;
        for(int i=0; i<elements.size(); i++)
        {
            if(ev.pos_y>=yy+(20)*i && ev.pos_y<=yy+(20)*(i+1))
            {
                if(ev.type== ev_mouse && ev.button==btn_left)
                {
                    _numb=i;
                    close();
                }
            }
        }
    }
    if(ev.pos_x>=_x+_m_x-20 && ev.pos_x<_x+_m_x && ev.pos_y>_y && ev.pos_y<_y+_m_y)
    {
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            if(open)
            {
                close();
            }
            else
            {
                rolling();
            }
        }
    }

}
/*void roll::choose(event ev)
{
    if(open)
    {
        if(ev.pos_x>=get_x() && ev.pos_x<=get_x()+get_m_x())
        {
            int yy=get_y()+get_m_y();
            for(int i=0; i<elements.size(); i++)
            {
                if(ev.pos_y>=yy+(20)*i && ev.pos_y<=yy+(20)*(i+1))
                {
                    if(ev.type== ev_mouse && ev.button==btn_left)
                    {
                        set_numb(i);
                        close();
                    }
                }
            }
        }
    }
}*/

std::string roll::get_things()
{
    return elements[get_numb()];
}
