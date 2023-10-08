#include "FolderManager.h"

using namespace System;
using namespace System::IO;
using namespace System::Text::RegularExpressions;

String^ FolderManager::CreateFolder(String^ folderName)
{
    String^ documentsPath = Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments), "Study Stack");
    String^ folderPath = Path::Combine(documentsPath, folderName);

    try
    {
        Directory::CreateDirectory(folderPath);
        return folderPath;
    }
    catch (Exception^ e)
    {
        return nullptr;
    }
}

String^ FolderManager::ClearName(String^ rawFoldersName)
{
    Regex^ regex = gcnew Regex("[^a-zA-Zà-ÿÀ-ß]");
    return regex->Replace(rawFoldersName, "");
}
