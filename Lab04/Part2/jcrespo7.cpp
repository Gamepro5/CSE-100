#include <iostream>
#include <string>
#include <limits>

using namespace std;

void swap(int** arr, int q, int r) {
    int temp = (*arr)[q];
    (*arr)[q] = (*arr)[r];
    (*arr)[r] = temp;
}

int partition(int* arr, int p, int r) {
    int x =  arr[r];
    int i = p-1;
    for (int j=p;j<=r-1;j++) {
        if (arr[j] <= x) {
            i = i+1;
            swap(&arr, i, j);
        }
    }
    swap(&arr, i+1, r);
    return i+1;
}

void quicksort(int* arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
}

int randomizedPartition(int* arr, int p, int r) {
    srand((unsigned) time(NULL));
    int i = (rand() % (r - p) +p);//random number from p to r
    swap(&arr, r, i);
    return partition(arr, p, r);
}

void randomizedQuicksort(int* arr, int p, int r) {
    if (p < r) {
        int q = randomizedPartition(arr, p, r);
        randomizedQuicksort(arr, p, q-1);
        randomizedQuicksort(arr, q+1, r);
    }
}


int main(int argc, char *argv[]) {

    int arrLength = 1;
    //cout << "Sorted array:" << endl;
    cin >> arrLength;
    int arr[arrLength];

    for (int i=0;i<arrLength;i++) {
        cin >> arr[i];
        //cout << "Added " << sort[i] << " to be sorted.\n";
    };
    //int n = sizeof(arr) / sizeof(arr[0]);
    
    randomizedQuicksort(arr,0,arrLength-1);

    //int sum = 0;
    for (int i=0;i<arrLength;i++) {
       std::cout << arr[i] << ";";
       //sum += arr[i];
    }
    //cout << endl;

    //to run:  cat test.txt | ./a.exe

    

    return 0;
}