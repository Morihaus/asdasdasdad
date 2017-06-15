#ifndef STATIKTEXT_HPP_INCLUDED
#define STATIKTEXT_HPP_INCLUDED
#include "graphics.hpp"
#include "widgets.h"

class Statik : public widgets
{
private:
    std::string _s;
public:
    Statik(int x, int y, int m_x, int m_y, std::string s);
    void draw();
    void handle(genv::event);
};


#endif // STATIKTEXT_HPP_INCLUDED
