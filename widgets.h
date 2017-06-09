#ifndef WIDGETS_H
#define WIDGETS_H
#include "graphics.hpp"


class widgets
{
private:
    int _x, _y, _m_y,_m_x;
    int _numb = 0;
protected:
    //bool _focused;
public:
    widgets(int x, int y, int m_x, int m_y);
    virtual ~widgets();
    virtual void draw() = 0;
    virtual int get_x();
    virtual int get_y();
    virtual int get_m_y();
    virtual int  get_m_x();
    virtual int get_numb();
    virtual void set_numb(int a);
    virtual void handle(genv::event) =0;
};
#endif
