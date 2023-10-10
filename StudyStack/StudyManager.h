#pragma once

#include "Subject.h"
#include "Lecture.h"
#include "Task.h"

using namespace System::Collections::Generic;


namespace StudyStack
{
	public ref class StudyManager
	{
	private:
		static List<Subject^>^ subjects;
		static Dictionary<Subject^, List<Lecture^>^>^ lectures;
		static Dictionary<Subject^, List<Task^>^>^ tasks;

	public:
		static StudyManager();

		//for manager subjects (after)
		static void AddSubject(Subject^ subject);
		static void RemoveSubject(Subject^ subject);
		static List<Subject^>^ GetSubjects();

		//for manager lectures
		static void AddLecture(Subject^ lectureSubject, Lecture^ lecture);
		static void RemoveLecture(Subject^ lectureSubject, Lecture^ lecture);
		static List<Lecture^>^ GetLectures(Subject^ lectureSubject);

		//for manager tasks
		static void AddTask(Subject^ taskSubject, Task^ task);
		static void RemoveTask(Subject^ taskSubject, Task^ task);
		static List<Task^>^ GetTasks(Subject^ taskSubject);
	};
}
