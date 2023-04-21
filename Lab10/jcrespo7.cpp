#include <iostream>
#include <string>
#include <limits>
#include <vector>

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


class NodeList{															
	public:			
	NodeList(){}

    Matrix matrixMultiply(Matrix A, Matrix B) {
        if (A.cols != B.rows) {
            cout << "Incompatable Dimensions!" << endl;
            return;
        }
        Matrix C(A.rows, A.cols);
        for (int i=0;i<A.rows;i++) {
            for (int j=0;j<B.cols;j++) {
                C.matrix[i][j] = 0;
                for (int k=0;k<A.cols;k++) {
                    C.matrix[i][j] = C.matrix[i][j] + A.matrix[i][k] * B.matrix[k][j];
                }
            }
        }
        return C;
    }

    Matrix* matrixChainOrder(Matrix* p, int pLength) {
        int n = pLength - 1;
        Matrix* result[2];
        Matrix m(A.rows, A.cols);
        result[0] =  m;// this is m

    }
    
};

int main(int argc, char *argv[]) {

    int frequency[6];											
	for(int i = 0; i < 6; i++){	cin >> frequency[i]; }			

	NodeList list;
    char temp[6] = {'A','B','C','D','E','F'};
	list.makeList(temp,frequency);		
	list.huffman();
    list.printPaths();

  	return 0;

    //to run:  cat test.txt | ./a.exe

    

    return 0;
}