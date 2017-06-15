#include "field.hpp"
#include "roll.h"
#include "statiktext.hpp"
#include "counter.h"
#include "textbox.hpp"
#include "widgets.h"
#include <iostream>

using namespace std;
using namespace genv;

const int XX =600;
const int YY =600;

void Field::event_loop()
{
    gout.open(XX,YY);
    event ev;
    int focus = -1;
    bool allit=false;

    r.push_back(new counter(XX/12,YY/6,100,40,6,0,23,false));
    r.push_back(new counter(XX/2,YY/6,100,40,10,0,59,true));
    r.push_back(new Statik(100,500,150,540,"valami"));
    r.push_back(new TextBox(50,200,140,40,"asd"));
    std::vector <std::string> elements;
    elements.push_back("Easy");
    elements.push_back("Medium");
    elements.push_back("Hard");
    roll* ez=(new roll(XX/2,YY/3,200,30,elements));
    r.push_back(ez);

    while(gin >> ev && ev.keycode!= key_escape)
    {
        if( ev.type == ev_mouse && ev.button==btn_left)
        {

            for(int i=0; i<r.size(); i++)
            {
                if(r[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                    allit=true;
                }
            }
            if(allit==false)
            {
                focus=-1;
            }
        }

        if(focus!=-1)
        {
            r[focus]->handle(ev);
           // focus=-1;
        }

        for(int i=0; i<r.size(); i++)
        {
            r[i]->draw();
        }
        allit=false;
        gout << refresh;
    }

}
