#include <iostream>
using namespace std;

// Class template for comparison
template <typename T>
class Compare
{
private:
    T num1, num2; // Two numbers of generic type T

public:
    // Constructor to initialize the two numbers
    Compare(T n1, T n2) : num1(n1), num2(n2)
    {
        cout << "Constructor: Two numbers are initialized." << endl;
    }

    // Function to find the bigger number
    T findBigger()
    {
   
        return (num1 > num2) ? num1 : num2;
    }

    // Destructor
    ~Compare()
    {
        cout << "Destructor: Object is being destroyed." << endl;
    }
};

int main()
{
    // User input
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Creating an object of Compare for int type
    Compare<int> comp(a, b);

    // Finding the bigger number
    cout << "The bigger number is: " << comp.findBigger() << endl;

    // Object comp goes out of scope, destructor will be called
    return 0;
}
