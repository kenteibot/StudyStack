#pragma once

using namespace System;

ref class FolderManager //for working with folders
{
public:
	static String^ CreateFolder(String^ folderName);
	static String^ ClearName(String^ rawFoldersName); //prepares a name for creating a Windows folder
};

