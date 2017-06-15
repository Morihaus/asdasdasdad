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

    r.push_back(new counter(XX/12,YY/6,100,40,6,0,23,false));
    r.push_back(new counter(XX/2,YY/6,100,40,10,0,59,true));
    r.push_back(new Statik(100,500,150,540,"valami"));
    r.push_back(new TextBox(50,200,100,40,"asdasd"));


    while(gin >> ev && ev.keycode != key_escape)
    {


    }

}
