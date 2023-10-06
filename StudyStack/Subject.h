#pragma once

using namespace System;

ref class Subject //study subjects
{
private:
    String^ name;
    String^ description;
    String^ lecturesFolder;

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

    property String^ LecturesFolder
    {
        String^ get() { return lecturesFolder; }
        void set(String^ value) { lecturesFolder = value; }
    }

    Subject(String^ name, String^ description, String^ lecturesFolder);
};
