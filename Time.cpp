#include "Time.h"

Time::Time(int hour)
{
    time = (hour / 100) * 60;
    time += hour % 100;
//    cout << "Time " << hour << " Hour " << (hour / 100) * 60 << " Minutes " << (hour % 100) << " New time = " << time << endl;
}

void Time::print(){
    cout << int(time / 60) << time % 60;
}

int Time::get(){
    return (int(time / 60)) * 100 + (time % 60);
}

Time::~Time()
{
    //dtor
}
