#include <iostream>
using namespace std;
class Array
{
private:
    int *arr;
    int size;

public:
    Array(int size) : size(size)
    {
        arr = new int[size];
    }
    ~Array()
    {
        delete[] arr;
    }

    void setValue(int index, int value)
    {

        if (index < 0 || index > size)
        {
            throw out_of_range("\nindex out of bounds ");
        }

        arr[index] = value;
    }
    int getValue(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("\nindex out of bounds ");
        }
        return arr[index];
    }
};
int main()
{

    try
    {
        Array myArray(5);
        myArray.setValue(0, 10);
        myArray.setValue(1, 20);
        myArray.setValue(2, 30);
        myArray.setValue(3, 40);
        myArray.setValue(4, 50);

        for (int i = 0; i < 5; i++)
        {
            cout << myArray.getValue(i);
            cout << endl;
        }

        cout << endl;
        cout << myArray.getValue(5);
    }
    catch (const out_of_range &e)
    {
        cout << "exception caught" << e.what() << '\n';
    }

    return 0;
}