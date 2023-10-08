#include "Task.h"

Task::Task(String^ name, Subject^ owner)
    : Lecture(name, owner)
{
    this->progress = 0;
}

