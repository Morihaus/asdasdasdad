#ifndef roll_H
#define roll_H
#include "widgets.h"
#include "graphics.hpp"
#include <vector>

class roll : public widgets
{
public:
    roll(int x,int y,int m_x,int m_y, std::vector<std::string> element);
    ~roll();
    bool is_selected(int mouse_x, int mouse_y) const;
    void draw();
    void handle(genv::event);
    // virtual void choose(genv::event);
    std::string get_things();

private:
    std::vector<std::string> elements;
    bool open=false;
    void close();
    void rolling();
    std::string things;
};

#endif // roll_H
