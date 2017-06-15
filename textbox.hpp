#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED
#include <string>
#include "widgets.h"

class TextBox : public widgets
{
private:
    std::string _s;
    int ido1,ido2;
public:
    TextBox(int x, int y, int m_x, int m_y, std::string s);
    bool is_selected(int mouse_x, int mouse_y) const;
    void draw();
    void handle(genv::event);

};


#endif // TEXTBOX_HPP_INCLUDED
