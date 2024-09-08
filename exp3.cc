#include <iostream>
using namespace std;

// Forward declaration of class B
class B;

class A
{
private:
    int numA;

public:
    // Constructor to initialize numA
    A(int n) : numA(n) {}

    // Friend function declaration
    friend int findGreatest(A, B);
};

class B
{
private:
    int numB;

public:
    // Constructor to initialize numB
    B(int n) : numB(n) {}

    // Friend function declaration
    friend int findGreatest(A, B);
};

// Friend function definition
int findGreatest(A objA, B objB)
{
    if (objA.numA > objB.numB)
    {
        return objA.numA;
    }
    else
    {
        return objB.numB;
    }
}

int main()
{
    int a, b;

    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    A objA(a);
    B objB(b);

    int greatest = findGreatest(objA, objB);

    cout << "The greatest number is: " << greatest << endl;

    return 0;
}
