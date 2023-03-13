#include <iostream>

using namespace std;

class record{
  public:
    int key[11];

  record()
  {
    for(int i=1;i<=10;i++)
    key[i] = 0;
  }
};

// Global variables that can be accessed anywhere. Not recommend for serious programming. 

record* A;
int* C; 
record* B;
int k = 4;
int arraySize;

void CountSort(int r){  // r will be used to refer to key[r]
  // TBD
    C = new int[k];
    for (int i=0;i<k;i++) {
        C[i] = 0;
    }

    for (int j=1;j<=arraySize;j++) {
        C[A[j].key[r]] = C[A[j].key[r]] + 1; 
    }
    for (int i=1;i<k;i++) {
        C[i] = C[i] + C[i-1];
    }
    for (int j=arraySize; j >= 1; j--) {
        B[C[A[j].key[r]]] = A[j];
        C[A[j].key[r]] = C[A[j].key[r]] - 1;
    }
 
    delete[] C;

}
void radixSort() {
    for (int i=10;i>=1;i--) {
        CountSort(i);
        for (int i=1;i<=arraySize;i++) {
            A[i] = B[i];
        }
    }
}

int main(int argc,char **argv) {

  // Get the size of the sequence
  cin >> arraySize;

    A = new record[arraySize+1];
    B = new record[arraySize+1];
  // Continue reading sequences until there is no more
  for(int i=1;i<=arraySize;i++)
  {
    for(int j=1;j<=10;j++)
    {
       cin >> A[i].key[j];
    }
  } 
  // Radix Sort: TBD
  radixSort();
  //output 
  for(int i=1;i<=arraySize;i++)
  {
    for(int j=1;j<=10;j++)
       cout << A[i].key[j] << ";";
    cout << endl;
  } 


   // Free allocated space
  delete[] A;
  delete[] B;
  return 1;
}