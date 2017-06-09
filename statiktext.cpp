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
    gout << color(255,255,255)<< move_to(get_x(), get_y())<<text(_s);
}

void Statik::handle(event ev)
{

}
bool Statik::is_checked()
{
    return _checked;
}
