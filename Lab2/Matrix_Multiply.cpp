#include <iostream>
#include "Matrix_Multiply.h"
using namespace std;

void multiplyArrays(int **matrix1, int **matrix2, int row1, int col1, int row2, int col2) {
    if (col1 != row2) {
        cout << "Multiplication not possible\n";
        return;
    }
    int **newMatrix = new int*[row1];
    for (int i = 0; i < row1; i++) {
        newMatrix[i] = new int[col2]{0};//initializing to 0
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                newMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < row1; i++) {
        delete[] newMatrix[i];
    }
    delete[] newMatrix;
}
