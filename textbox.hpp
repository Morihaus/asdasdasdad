#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED
#include <string>
#include "widgets.h"

class TextBox : public widgets
{
protected:
    std::string _s;
    int ido1,ido2;
public:
    TextBox(int x, int y, int m_x, int m_y, std::string s);
    virtual void draw();
    virtual void handle(genv::event);

};

#endif // TEXTBOX_HPP_INCLUDED
