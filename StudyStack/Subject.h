#pragma once

using namespace System;

ref class Subject //study subjects
{
private:
    String^ name;
    String^ description;
    String^ folderPath;

public:
    property String^ Name
    {
        String^ get() { return name; }
        void set(String^ value) { name = value; }
    }

    property String^ Description
    {
        String^ get() { return description; }
        void set(String^ value) { description = value; }
    }

    property String^ FolderPath
    {
        String^ get() { return folderPath; }
    }

    Subject(String^ name, String^ description);
};
