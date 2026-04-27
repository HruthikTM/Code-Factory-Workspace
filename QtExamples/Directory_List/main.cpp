#include <iostream>
#include <filesystem>
#include <string>


namespace fs = std::filesystem;

int main()
{
    std::string dirPath;
    std::cout << "Enter directory path: ";
    std::getline(std::cin, dirPath);

    try
    {
        if (!fs::exists(dirPath))
        {
            std::cout << "Directory does not exist.\n";
            return 1;
        }

        if (!fs::is_directory(dirPath))
        {
            std::cout << "Path is not a directory.\n";
            return 1;
        }

        for (const auto& entry : fs::directory_iterator(dirPath))
        {
            if (entry.is_directory())
                std::cout << "[D] ";
            else if (entry.is_regular_file())
                std::cout << "[F] ";
            else
                std::cout << "[?] ";

            std::cout << entry.path().filename().string() << "\n";
        }
    }
    catch (const fs::filesystem_error& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
