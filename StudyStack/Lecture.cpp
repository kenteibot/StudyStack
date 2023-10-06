#include "Lecture.h"

Lecture::Lecture(String^ name, Subject^ owner)
{
	this->name = name;
	this->owner = owner;
	this->creationDate = DateTime::Now;
	this->folderPath = "0";
}
