#include "graphics.hpp"
#include "widgets.h"
#include "counter.h"
#include "roll.h"
#include "statiktext.hpp"
#include "textbox.hpp"
#include <fstream>
#include <vector>
#include <iostream>

const int XX =600;
const int YY =600;
using namespace genv;
using namespace std;


int main()
{
    gout.open(XX,YY);
    vector<widgets*> r;
    r.push_back(new counter(XX/12,YY/6,100,40,6,0,23,false));
    r.push_back(new counter(XX/2,YY/6,100,40,10,0,59,true));
    r.push_back(new Statik(100,500,150,540,"valami"));
    std::vector <std::string> elements;
    elements.push_back("Yellow");
    elements.push_back("Red");
    elements.push_back("Blue");
    elements.push_back("Green");
    elements.push_back("Pink");
    elements.push_back("Black");
    elements.push_back("White");
    //r.push_back(new roll((XX/12),YY/3,200,30,elements));
    std::vector <std::string> elements2;
    elements2.push_back("Easy");
    elements2.push_back("Medium");
    elements2.push_back("Hard");
    //r.push_back(new roll(XX/2,YY/3,200,30,elements2));
    r.push_back(new TextBox(50,200,100,40,"asdasd"));

    event ev;
    while(gin >> ev && ev.keycode != key_escape)
    {
        for(int i=0; i<r.size(); i++)
        {
            r[i]->draw();
            if(roll* s = dynamic_cast<roll*> (r[i]))
                s->choose(ev);
            r[i]->handle(ev);
            r[i]->draw();
        }

        if (ev.keycode == key_f1)
        {
            ofstream myfile;
            myfile.open ("proba.txt");
            for (int i=0; i<r.size(); i++)
            {
                if(counter* x = dynamic_cast<counter*> (r[i]))
                    myfile << x->get_numb();
                if (roll* x = dynamic_cast<roll*> (r[i]))
                    myfile << x->get_things();
                myfile << "\n";
            }
            myfile.close();
        }

        gout<<refresh;
    }
    return 0;
}

