#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 4; //Matrix Size

class Matrix {
private:
    int data[SIZE][SIZE]; // 2D array 
public:
    // File into a matrix
    bool readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error: Could not open file " << filename << endl;
            return false;
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                file >> data[i][j];
            }
        }
        file.close();
        return true;
    }

    //Displays matrix
    void display() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    //Add two matrices; operator overloading for +
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    //Multiply two matrices; operator overloading for *
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = 0; // Initialize element to zero
                for (int m = 0; m < SIZE; ++m) {
                    result.data[i][j] += data[i][m] * other.data[m][j];
                }
            }
        }
        return result;
    }

    //Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const {
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) {
            sum += data[i][i]; // Firsst diagonal
            sum += data[i][SIZE - 1 - i]; // Secondary diagonal
        }
        return sum;
    }

    //Swap rows
    void swapRows(int row1, int row2) {
        if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
            for (int i = 0; i < SIZE; ++i) {
                swap(data[row1][i], data[row2][i]);
            }
        } else {
            cout << "Invalid row " << endl;
        }
    }
};

int main() {
    Matrix mat1, mat2;

    //Read Matrix 1 from a file
    if (!mat1.readFromFile("matrix1.txt")) {
        return 1;
    }
    cout << "Matrix 1:" << endl;
    mat1.display();

    //Read Matrix 2 from a file
    if (!mat2.readFromFile("matrix2.txt")) {
        return 1;
    }
    cout << "Matrix 2:" << endl;
    mat2.display();

    //Add two matrices
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    //Multiply two matrices
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    //Sum of diagonals 
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    //Swap rows
    mat1.swapRows(0, 2); //Row shown in example
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}
