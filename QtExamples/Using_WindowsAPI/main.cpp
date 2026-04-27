#include <windows.h>
#include <iostream>
#include <string>

int main()
{
    std::string dirPath;
    std::cout << "Enter directory path: ";
    std::getline(std::cin, dirPath);

    dirPath += "\\*";

    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(dirPath.c_str(), &findData);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        std::cout << "Invalid directory.\n";
        return 1;
    }

    do
    {
        std::string name = findData.cFileName;

        if (name == "." || name == "..")
            continue;

        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            std::cout << "[D] ";
        else
            std::cout << "[F] ";

        std::cout << name << "\n";

    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);
    return 0;
}
