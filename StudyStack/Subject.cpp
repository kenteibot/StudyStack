#include "Subject.h"

Subject::Subject(String^ name, String^ description)
{
    this->name = name;
    this->description = description;
    this->folderPath = "";
}

String^ Subject::ToString()
{
    return this->name;
}