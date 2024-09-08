#include <iostream>
using namespace std;

// create a class
class Matrix
{
  // private data members
private:
  int x[10][10];
  int row, col;

  // public functions
public:
  // getMatrix() function to insert matrix
  void getMatrix(int r, int c)
  {
    // initializing a matrix type variable
    Matrix M1;

    // copying value of parameters in the data members
    row = r;
    col = c;

    // nested for loop for insertion of matrix
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        cout << "Enter x[" << i << "][" << j << "] : ";
        cin >> x[i][j];
      }
    }
  }

  // putMatrix() function to print the matrix
  void putMatrix()
  {
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        cout << x[i][j] << " ";
      }
      cout << "\n";
    }
  }

  // multiply() function to perform multiplication of two matrix
  Matrix multiply(Matrix M2)
  {
    // initializing a Matrix type variable
    Matrix M;

    // copying the value of parameters in the data members
    M.row = row;
    M.col = col;

    // nested for loop to multiply two matrices
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        M.x[i][j] = 0;
        for (int k = 0; k < col; k++)
        {
          M.x[i][j] = M.x[i][j] + ((x[i][k]) * (M2.x[k][j]));
        }
      }
    }

    // returning the resulted matrix
    return (M);
  }
};

int main()
{
  // creating objects
  Matrix M1, M2, M3;

  // inserting matrix using getMatrix() function
  cout << "Enter Matrix A\n"
       << endl;
  M1.getMatrix(2, 2);

  cout << "\nEnter Matrix B\n"
       << endl;
  M2.getMatrix(2, 2);

  // printing the matrix using putMatrix() function
  cout << "\nMatrix A:" << endl;
  M1.putMatrix();

  cout << endl;

  cout << "Matrix B:" << endl;
  M2.putMatrix();

  // calling multiply() function to add two matrix
  M3 = M1.multiply(M2);
  cout << "\nMultiply of A and B matrix\n"
       << endl;

  // printing the resulted matrix
  M3.putMatrix();
  return 0;
}