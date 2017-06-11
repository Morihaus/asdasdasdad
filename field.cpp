#include "field.hpp"
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <string>
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

    while(gin >> ev)
    {

    }

}
