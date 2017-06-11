#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "roll.h"
#include "statiktext.hpp"
#include "counter.h"
#include "textbox.hpp"
#include <vector>

using namespace std;

class Field
{
protected:
    vector<widgets*> r;
public:
    //void beolvas();
    void event_loop();
    //bool check(int f);
};


#endif // FIELD_HPP_INCLUDED
