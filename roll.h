#ifndef roll_H
#define roll_H
#include "widgets.h"
#include "graphics.hpp"
#include <vector>

class roll : public widgets
{
public:
    roll(int x,int y,int m_x,int m_y, std::vector<std::string> element);
    virtual ~roll();
    void close();
    virtual void draw();
    void rolling();
    virtual void handle(genv::event);
    virtual void choose(genv::event);
    std::string things;
    std::string get_things();

protected:
    std::vector<std::string> elements;
    bool open=false;

private:

};

#endif // roll_H
