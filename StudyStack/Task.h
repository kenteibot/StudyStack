#pragma once

#include "Lecture.h" 

using namespace System;

ref class Task : public Lecture
{
private:
    int progress;

public:
    Task(String^ name, Subject^ owner);

    property int Progress
    {
        int get() { return progress; }
        void set(int value) { progress = value; }
    }
};
