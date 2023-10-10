#include "StudyManager.h"

static StudyStack::StudyManager::StudyManager()
{
    subjects = gcnew List<Subject^>();
    lectures = gcnew Dictionary<Subject^, List<Lecture^>^>();
    tasks = gcnew Dictionary<Subject^, List<Task^>^>();
}

void StudyStack::StudyManager::AddSubject(Subject^ subject)
{
    if (!subjects->Contains(subject))
    {
        subjects->Add(subject);
        lectures[subject] = gcnew List<Lecture^>();
        tasks[subject] = gcnew List<Task^>();
    }
}

void StudyStack::StudyManager::RemoveSubject(Subject^ subject)
{
    subjects->Remove(subject);
}

List<Subject^>^ StudyStack::StudyManager::GetSubjects()
{
    return subjects;
}

void StudyStack::StudyManager::AddLecture(Subject^ lectureSubject, Lecture^ lecture)
{
    if (subjects->Contains(lectureSubject))
    {
        List<Lecture^>^ lectureList = lectures[lectureSubject];

        if (lectureList == nullptr)
        {
            lectureList = gcnew List<Lecture^>();
            lectures[lectureSubject] = lectureList;
        }
        lectureList->Add(lecture);
    }
    else
    {
        throw gcnew System::InvalidOperationException("Subject not found");
    }
}

void StudyStack::StudyManager::RemoveLecture(Subject^ lectureSubject, Lecture^ lecture)
{
    if (subjects->Contains(lectureSubject))
    {
        List<Lecture^>^ lectureList = lectures[lectureSubject];
        if (lectureList != nullptr)
        {
            lectureList->Remove(lecture);
        }
    }
}

List<Lecture^>^ StudyStack::StudyManager::GetLectures(Subject^ lectureSubject)
{
    if (lectures->ContainsKey(lectureSubject))
    {
        return lectures[lectureSubject];
    }
    
    return nullptr;
}

void StudyStack::StudyManager::AddTask(Subject^ taskSubject, Task^ task)
{
    if (subjects->Contains(taskSubject))
    {
        List<Task^>^ taskList = tasks[taskSubject];
        if (taskList == nullptr)
        {
            taskList = gcnew List<Task^>();
            tasks[taskSubject] = taskList;
        }
        taskList->Add(task);
    }
    else
    {
        throw gcnew System::InvalidOperationException("Subject not found");
    }
}

void StudyStack::StudyManager::RemoveTask(Subject^ taskSubject, Task^ task)
{
    if (subjects->Contains(taskSubject))
    {
        List<Lecture^>^ taskList = lectures[taskSubject];
        if (taskList != nullptr)
        {
            taskList->Remove(task);
        }
    }
}

List<Task^>^ StudyStack::StudyManager::GetTasks(Subject^ taskSubject)
{
    if (tasks->ContainsKey(taskSubject))
    {
        return tasks[taskSubject];
    }

    return nullptr;
}
