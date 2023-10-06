#pragma once

#include "Subject.h"

using namespace System;

ref class Lecture
{
protected:
	String^ name;
	DateTime creationDate;
	Subject^ owner;
    String^ folderPath;

public:
    property String^ Name
    {
        String^ get() { return name; }
        void set(String^ value) { name = value; }
    }

    property String^ FolderPath
    {
        String^ get() { return folderPath; }
    }

    property DateTime CreationDate
    {
        DateTime get() { return creationDate; }
    }

    Lecture(String^ name, Subject^ owner);
};

