#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time{
    public:
        int time;

        Time(int hour);
        virtual ~Time();

        void print();
        int get();

    protected:

    private:
};

#endif // TIME_H
