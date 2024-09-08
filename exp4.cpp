#include <iostream>
#include <cstring>
#include <cctype>

class MyString
{
private:
    char *str;

public:
    // Constructor
    MyString(const char *s = "")
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy Constructor
    MyString(const MyString &s)
    {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }

    // Overload + operator to concatenate strings
    MyString operator+(const MyString &s) const
    {
        char *tempStr = new char[strlen(str) + strlen(s.str) + 1];
        strcpy(tempStr, str);
        strcat(tempStr, s.str);
        return MyString(tempStr);
    }

    // Overload = operator to copy string
    MyString &operator=(const MyString &s)
    {
        if (this != &s)
        {
            delete[] str;
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        return *this;
    }

    // Overload <= operator to compare strings
    bool operator<=(const MyString &s) const
    {
        return strcmp(str, s.str) <= 0;
    }

    // Function to display the length of the string
    int length() const
    {
        return strlen(str);
    }

    // Function to convert uppercase letters to lowercase
    void toLower()
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            str[i] = tolower(str[i]);
        }
    }

    // Function to convert lowercase letters to uppercase
    void toUpper()
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            str[i] = toupper(str[i]);
        }
    }

    // Function to display the string
    void display() const
    {
        std::cout << str << std::endl;
    }

    // Destructor
    ~MyString()
    {
        delete[] str;
    }
};

int main()
{
    MyString str1, str2, result;
    int choice;
    char temp[100];
    bool exit = false;

    while (!exit)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Enter first string\n";
        std::cout << "2. Enter second string\n";
        std::cout << "3. Concatenate strings\n";
        std::cout << "4. Copy string\n";
        std::cout << "5. Compare strings\n";
        std::cout << "6. Display length of a string\n";
        std::cout << "7. Convert to lowercase\n";
        std::cout << "8. Convert to uppercase\n";
        std::cout << "9. Display strings\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter first string: ";
            std::cin.ignore(); // To ignore the leftover newline character
            std::cin.getline(temp, 100);
            str1 = MyString(temp);
            break;
        case 2:
            std::cout << "Enter second string: ";
            std::cin.ignore();
            std::cin.getline(temp, 100);
            str2 = MyString(temp);
            break;
        case 3:
            result = str1 + str2;
            std::cout << "Concatenated string: ";
            result.display();
            break;
        case 4:
            result = str1;
            std::cout << "Copied string: ";
            result.display();
            break;
        case 5:
            if (str1 <= str2)
                std::cout << "First string is less than or equal to the second string\n";
            else
                std::cout << "First string is greater than the second string\n";
            break;
        case 6:
            std::cout << "Length of first string: " << str1.length() << std::endl;
            std::cout << "Length of second string: " << str2.length() << std::endl;
            break;
        case 7:
            str1.toLower();
            str2.toLower();
            std::cout << "Converted both strings to lowercase.\n";
            break;
        case 8:
            str1.toUpper();
            str2.toUpper();
            std::cout << "Converted both strings to uppercase.\n";
            break;
        case 9:
            std::cout << "First string: ";
            str1.display();
            std::cout << "Second string: ";
            str2.display();
            break;
        case 0:
            exit = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
