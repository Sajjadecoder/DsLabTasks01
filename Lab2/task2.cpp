#include <iostream>
#include "Matrix_Multiply.cpp"
using namespace std;

int main() {
    int row1 = 2, col1 = 2;
    int row2 = 2, col2 = 2;

    int **matrix1 = new int*[row1];
    int **matrix2 = new int*[row2];
    
    for (int i = 0; i < row2; i++) {
        matrix2[i] = new int[col2];
        matrix1[i] = new int[col1];
    
    }


    int cnt = 0;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            matrix1[i][j] = cnt++;
        }
    }

    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            matrix2[i][j] = cnt++;
        }
    }

    cout << "Matrix 1:\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatrix 2:\n";
    for (int i = 0; i < row2; ++i) {
        for (int j = 0; j < col2; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nResultant Matrix:\n";
    multiplyArrays(matrix1, matrix2, row1, col1, row2, col2);

    for (int i = 0; i < row1; i++) {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < row2; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    return 0;
}
