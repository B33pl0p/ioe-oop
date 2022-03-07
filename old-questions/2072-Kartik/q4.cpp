//Develop a program using a class with 3x3 matrix as a data member. overload the * operator to multiply two matrices

#include <iostream>
using namespace std;
class matrix {
  int mat[3][3];
public:
  void input() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> mat[i][j];
      }
    }
  }
  void display() {
    cout << " matrix after multiplication is :" << endl;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << mat[i][j] <<" ";
      }
      cout<<"\n";
    }
  }
  friend matrix operator*(matrix, matrix);
};
matrix operator*(matrix val1, matrix val2) {
  matrix result;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
          result.mat[i][j] = 0;
         for (int k = 0; k < 3; k++)
      result.mat[i][j] += val1.mat[i][k] * val2.mat[k][j];
    }
  }
  return result;
}
int main() {
  matrix m1, m2, product;
  cout<<"Enter matrix 1: "<<endl;
  m1.input();
  cout<<"Enter matrix 2: "<<endl;
  m2.input();
  product = m1 * m2;
  product.display();
}
