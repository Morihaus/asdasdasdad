#include "statiktext.hpp"
#include <string>
using namespace genv;
using namespace std;


Statik::Statik(int x, int y, int m_x, int m_y, string s): widgets(x,y,m_x,m_y)
{
    _s=s;
}

void Statik::draw()
{
    gout << color(255,255,255)<< move_to(_x, _y)<<text(_s);
}

void Statik::handle(event ev)
{

}

