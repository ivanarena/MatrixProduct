/* Created by IVAN ARENA @ivanprfbs - 2021 */

#include <iostream>
using namespace std;

void buildMatrix(int* A, int n);
void printMatrix(int* A, int m, int n);
void transpose(int* B, int n, int* BT);
void storeProduct(int* A, int m, int n, int* B, int x, int y, int* AxB);
int multiply(int* A, int m, int n, int* B, int x, int y);

// takes two m*n matrixes of integers as input and find their product
int main() {
    int m, n, x, y;
    
    do {
        cout << "Enter first matrix dimensions: ";
        cin >> m >> n;
        cout << "Enter second matrix dimensions: ";
        cin >> x >> y;
    } while (n != x); // n of columns of the first matrix must be equal to n of rows of the second matrix

    int A[m][n];
    cout << "Input first matrix:" << endl;
    buildMatrix(*A, m*n); // first matrix
    
    int B[x][y];
    cout << "Input second matrix:" << endl;
    buildMatrix(*B, x*y); // second matrix
    
    int BT[y][x];
    for (int i = 0; i < x; i++) { // transposes second matrix to simplify operations
        for (int j = 0; j < y; j++) {
            BT[j][i] = B[i][j];
        }
    } 

    int AxB[m][y]; // creates product matrix
    storeProduct(*A, m, n, *BT, x, y, *AxB); 
    cout << endl;
    printMatrix(*AxB, m, y);
    
    return 0;
}

void buildMatrix(int* A, int n) {
    if (n != 0) {
        cin >> *A;
        buildMatrix(A+1, n-1);
    }
}

void printMatrix(int* A, int m, int n) {
    for (int i = 0; i < m*n; i++) {
        if (i % n == 0) {
            cout << endl;
        }
        cout << *(A + i) << " ";
    }
    cout << endl;
}

void storeProduct(int* A, int m, int n, int* B, int x, int y, int* AxB) { // moves in rows
    if (m != 0) {
        for (int i = 0; i < y; i++) {
            *(AxB + i) = multiply(A, m, n, B+(i*x), x, y);
        }
        storeProduct(A+n, m-1, n, B, x, y, AxB+y);
    }
}

int multiply(int* A, int m, int n, int* B, int x, int y) { // row-column product
    if (!n) {
        return 0;
    } else {
        return *A * *B + multiply(A+1, m, n-1, B+1, x, y);
    }
}

/* TEST: 

2 3
3 2

1 -2 1
2 1 3

2 1
3 2
1 1

*/
