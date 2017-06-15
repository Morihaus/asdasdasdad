#ifndef WIDGETS_H
#define WIDGETS_H
#include "graphics.hpp"

class widgets
{
protected:
    int _x, _y, _m_y,_m_x;
    int _numb = 0;
public:
    widgets(int x, int y, int m_x, int m_y);
    virtual ~widgets();
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw() {};
    virtual int get_x();
    virtual int get_y();
    virtual int get_m_y();
    virtual int  get_m_x();
    virtual int get_numb();
    virtual void set_numb(int a);
    virtual void handle(genv::event) {};
};
#endif
