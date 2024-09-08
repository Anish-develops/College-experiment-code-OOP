#include <iostream>
using namespace std;

class complexNumber
{

private:
    int real = 0;
    int imaginary = 0;

public:
    complexNumber() {};

    complexNumber(int val)
    {
        this->real = val;
        this->imaginary = val;
    }
    complexNumber(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void print()
    {
        cout << this->real << " + i" << this->imaginary << endl;
    }
    complexNumber add(complexNumber nums)
    {

        int realP = this->real + nums.real;
        int imgP = this->imaginary + nums.imaginary;

        complexNumber ans(realP, imgP);
        return ans;
    }
};

int main()
{
    complexNumber first(10);
    complexNumber sec(10, 20);
    complexNumber ans;

    first.print();

    ans = first.add(sec);

    ans.print();

    return 0;
}