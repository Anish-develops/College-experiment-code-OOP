#include <iostream>
using namespace std;

// User-defined function template to calculate the square of a number
template <typename T> T square(T num) {
    return num * num;
}

int main() {
    // Declare variables for different data types
    int int_num;
    double double_num;
    float float_num;

    // Prompt the user to input values
    cout << "Enter an integer: ";
    cin >> int_num;
    cout << "Enter a double: ";
    cin >> double_num;
    cout << "Enter a float: ";
    cin >> float_num;
    cout << endl;

    // Calculate and display the square of the inputs
    cout << "Square of " << int_num << " is: " << square(int_num) << endl;
    cout << "Square of " << double_num << " is: " << square(double_num) << endl;
    cout << "Square of " << float_num << " is: " << square(float_num) << endl;

    return 0;
}
