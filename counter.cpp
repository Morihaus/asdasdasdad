#include "counter.h"
#include "graphics.hpp"
#include <sstream>
#include <iostream>

using namespace std;
using namespace genv;
counter::counter(int x, int y, int m_x, int m_y, int numb, int lowerlimit,int upperlimit, bool korbefordul): widgets(x,y,m_x,m_y), _lowerlimit(lowerlimit), _upperlimit(upperlimit), _korbefordul(korbefordul)
{
    set_numb(numb);
}
counter::~counter()
{
}

int counter::get_lowerlimit()
{
    return _lowerlimit;
}

int counter::get_upperlimit()
{
    return _upperlimit;
}

bool counter::get_korbefordul()
{
    return _korbefordul;
}

void counter:: up()
{
    if(get_numb()<_upperlimit)
    {
        set_numb(get_numb()+1);
    }
}
void counter :: down()
{
    if(get_numb()>_lowerlimit)
    {
        set_numb(get_numb()-1);
    }
}

string counter::to_string(int _numb)
{
    stringstream SS;
    SS<<_numb;
    SS>>szoveg;
    SS.clear();
    return szoveg;
}

void counter:: draw()
{
    gout<<color(179,255,254)<< move_to(get_x(),get_y()) << box(get_m_x(),get_m_y())<<move_to(get_x()+5,get_y()+get_m_y()/2+4) << color(0,0,0) << text(to_string(get_numb()));
    gout << color(255,179,234) << move_to(get_x()+get_m_x()-20,get_y()) << box(20,get_m_y())<<
         move_to(get_x()+get_m_x()-20,get_y()+get_m_y()/2)<<color(150,150,150)<<line_to(get_x()+get_m_x(),get_y()+get_m_y()/2);
    gout << color(150,150,150) << move_to(get_x()+get_m_x()-11,get_y()+3) << box(2,get_m_y()/2-8)
         << move_to(get_x()+get_m_x()-16,get_y()+get_m_y()/4-2) << box(12,2)
         << move_to(get_x()+get_m_x()-16,get_y()+get_m_y()*3/4-2) << box(12,2);
}


void counter::handle(event ev)
{
    int p_x=ev.pos_x;
    int p_y=ev.pos_y;

    if(p_x>=get_x()+get_m_x()-20&& p_x<=get_x()+get_m_x() && p_y>=get_y() && p_y<get_y()+(get_m_y()/2))
    {
        if( ev.button == btn_left)
        {
            if(get_numb()==_upperlimit && get_korbefordul()==true)
            {
                set_numb(_lowerlimit);
            }
            else
            {
                up();
            }
        }
    }
    if(p_x>=get_x()+get_m_x()-20&& p_x<=get_m_x()+get_x() && p_y>=get_y()+(get_m_y()/2) && p_y<=get_y()+get_m_y())
    {
        if(ev.button==btn_left)
        {
            if(get_numb()==_lowerlimit && get_korbefordul()==true)
            {
                set_numb(_upperlimit);
            }
            else
            {
                down();
            }

        }
    }
}

