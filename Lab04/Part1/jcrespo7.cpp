#include <iostream>
#include <string>
#include <limits>

using namespace std;

void heapify(int* arr, int n, int i) {
    int max = i;
    int leftChild = (2*i) + 1;
    int rightChild = (2*i) + 2;
    if ((leftChild < n) && (arr[leftChild] > arr[max])) {
        max = leftChild;
    }
    if ((rightChild < n) && (arr[rightChild] > arr[max])) {
        max = rightChild;
    }
    if (max != i) {
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heapify(arr, n, max);
    }
}
void heapSort(int* arr, int arrLength) {
    int n = arrLength;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
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
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=n/2 -1;i>=0;i--){
       heapify(arr,n,i);
    }
    
    heapSort(arr, arrLength);

    //int sum = 0;
    for (int i=0;i<arrLength;i++) {
       std::cout << arr[i] << ";";
       //sum += arr[i];
    }
    //cout << endl;

    //to run:  cat test.txt | ./a.exe

    

    return 0;
}