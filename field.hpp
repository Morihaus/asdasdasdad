#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "widgets.h"
#include <vector>

using namespace std;

class Field
{
private:
    vector<widgets*> r;
public:
    //void beolvas();
    void event_loop();

};


#endif // FIELD_HPP_INCLUDED
