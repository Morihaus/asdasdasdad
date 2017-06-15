#ifndef counter_H
#define counter_H
#include "widgets.h"
#include <sstream>

class counter:public widgets
{
private:
    int _lowerlimit, _upperlimit;
    bool _korbefordul;

protected:
    std::string szoveg;
    std::stringstream ss;

public:
    counter(int x, int y, int m_x, int m_y, int numb, int lowerlimit, int upperlimit, bool korbefordul);
    virtual ~counter();

    int get_upperlimit(), get_lowerlimit();
    bool get_korbefordul();

    virtual void draw();
    virtual  std::string to_string(int szoveg);
    virtual void up();
    virtual void down();
    virtual void handle(genv::event);

};

#endif // counter_H
