#include "examplecheckbox.hpp"
#include <string>

using namespace genv;
using namespace std;

examplecheckbox::examplecheckbox(int x, int y, int m_x, int m_y, string s): widgets(x,y,m_x,m_y)
{
    _s=s;
}

void examplecheckbox::draw()
{
    gout<<color(170,170,170)<<move_to(_x,_y)<<box(_m_x,_m_y)<<move_to(_x+5,_y+(_m_y/2)+gout.cascent()/2)
    <<color(255,255,255)<<text(_s);
}

void examplecheckbox::handle(event ev)
{

}
