#include <iostream>
#include <fstream> // For file handling
using namespace std;

class Student
{
private:
    string name;
    int age;
    char sex;
    float height;
    float weight;

public:
    // Function to take input from the user
    void getData()
    {
        cout << "Enter name: ";
        // cin.ignore(); // To clear the buffer
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter sex (M/F): ";
        cin >> sex;
        cout << "Enter height (in cm): ";
        cin >> height;
        cout << "Enter weight (in kg): ";
        cin >> weight;
    }

    // Function to display the data
    void displayData() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }

    // Function to write data to file
    void writeToFile(ofstream &out)
    {
        out << name << endl;
        out << age << endl;
        out << sex << endl;
        out << height << endl;
        out << weight << endl;
    }

    // Function to read data from file
    void readFromFile(ifstream &in)
    {
        getline(in, name);
        in >> age;
        in >> sex;
        in >> height;
        in >> weight;
        in.ignore(); // Ignore the newline character after reading the last value
    }
};

int main()
{
    Student student;
    ofstream outFile;
    ifstream inFile;

    // Get student data from user
    student.getData();

    // Open file for writing in text mode
    outFile.open("student.txt");
    if (!outFile)
    {
        cout << "Error in opening file for writing!" << endl;
        return 1;
    }

    // Write the student object to the file
    student.writeToFile(outFile);
    outFile.close();

    // Open file for reading in text mode
    inFile.open("student.txt");
    if (!inFile)
    {
        cout << "Error in opening file for reading!" << endl;
        return 1;
    }

    // Read the student object from the file
    Student readStudent;
    readStudent.readFromFile(inFile);
    inFile.close();

    // Display the read data
    cout << "\nData read from file:" << endl;
    readStudent.displayData();

    return 0;
}
