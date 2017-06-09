#ifndef STATIKTEXT_HPP_INCLUDED
#define STATIKTEXT_HPP_INCLUDED
#include "graphics.hpp"
#include "widgets.h"

class Statik : public widgets
{
protected:
    bool _checked;
    std::string _s;
public:
    Statik(int x, int y, int m_x, int m_y, std::string s);
    virtual void draw();
    virtual void handle(genv::event);
    virtual bool is_checked();
};



#endif // STATIKTEXT_HPP_INCLUDED
