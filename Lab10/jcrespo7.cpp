#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>

using namespace std;

struct Matrix {
    int cols;
    int rows;
    int** matrix;
    Matrix(int _rows, int _cols) {
        rows = _rows;
        cols = _cols;
        matrix = new int*[rows];
        for (int i=0;i<rows;i++) {
            matrix[i] = new int[cols];
        }

    }
};

void printOptimalParents(int* s, int i, int j, int n) {
	if(i==j){
		cout << "A" << i-1;
	} else {
		cout << "(";
		printOptimalParents(s,i,*((s + i * n)+j),n);
		printOptimalParents(s,*((s + i * n)+j)+1,j,n);
		cout << ")";
	}																	
}

void matrixChainOrder(int p[], int n) {
	int m[n][n];
	int s[n][n];
																		
	for (int i = 1; i < n; i++){											
		m[i][i] = 0;
	}

	for (int l = 2; l < n; l++) {
		for (int i = 1; i < n-l+1; i++) {
			int j = i + l - 1;
			m[i][j] = 999999;
			for (int k = i; k < j; k++) {
				int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
    }
	cout << m[1][n-1] << endl;
	printOptimalParents((int*)s,1,n-1,n);					
	cout << endl;							
}

int main(int argc, char *argv[]) {

    int matrixListSize = 0;
    cin >> matrixListSize;
  	
    int matrixList[matrixListSize+1];										
	for(int i = 0; i < matrixListSize+1; i++){								
		cin >> matrixList[i]; 											
	}
    matrixChainOrder(matrixList, matrixListSize+1);
    //to run:  cat test.txt | ./a.exe

    

    return 0;
}