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

int randomizedPartition(int* arr, int p, int r) {
    srand((unsigned) time(NULL));
    int i = (rand() % (r - p) +p);//random number from p to r
    swap(&arr, r, i);
    return partition(arr, p, r);
}

int randomizedSelect(int* arr, int p, int r, int i) {
    if (p==r) {
        return arr[p];
    }
    int q = partition(arr, p, r);
    cout << arr[q] << ";";
    int k = q - p + 1;
    if (i==k) { //the pivot value is the answer
        return arr[q];
    } else if (i<k) {
        return randomizedSelect(arr, p, q-1, i);
    } else {
        return randomizedSelect(arr, q+1, r, i-k);
    }
}



int main(int argc, char *argv[]) {

    int arrLength = 1;
    int nth_search;
    //cout << "Sorted array:" << endl;
    cin >> arrLength;
    
    int arr[arrLength];

    cin >> nth_search;

    for (int i=0;i<arrLength;i++) {
        cin >> arr[i];
        //cout << "Added " << sort[i] << " to be sorted.\n";
    };
    //int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << randomizedSelect(arr,0,arrLength-1, nth_search) << ";";

    //cout << endl;

    //to run:  cat test.txt | ./a.exe

    

    return 0;
}