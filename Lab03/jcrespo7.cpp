#include <iostream>
#include <string>

using namespace std;

void merge(int arr[], int left, int middle, int right) {
    int leftArrayLength = middle - left + 1;
    int rightArrayLength = right - middle;
    int* leftArray = new int[leftArrayLength];
    int* rightArray = new int[rightArrayLength];

    for (int i=0;i<leftArrayLength;i++) { //copy data into the two subarrays
        leftArray[i] = arr[left + i];
    }
    for (int j=0;j<rightArrayLength;j++) {
        rightArray[j] = arr[middle + j + 1];
    }

    int leftArrayIndex=0, rightArrayIndex=0;

    int mergedArrayIndex = left;

    while (leftArrayIndex < leftArrayLength && rightArrayIndex < rightArrayLength) { //merging
        if (leftArray[leftArrayIndex] <= rightArray[rightArrayIndex]) { //rebuilds the original array by comparing th first element of each subarray
            arr[mergedArrayIndex] = leftArray[leftArrayIndex];
            leftArrayIndex++;
        } else {
            arr[mergedArrayIndex] = rightArray[rightArrayIndex];
            rightArrayIndex++;
        }
        mergedArrayIndex++;
    }

    //copy them back into original array
    while (leftArrayIndex < leftArrayLength) {
        arr[mergedArrayIndex] = leftArray[leftArrayIndex];
        leftArrayIndex++;
        mergedArrayIndex++;
    }
    while (rightArrayIndex < rightArrayLength) {
        arr[mergedArrayIndex] = rightArray[rightArrayIndex];
        rightArrayIndex++;
        mergedArrayIndex++;
    }
    delete[] leftArray;
    delete[] rightArray;
    
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int middle = left + ((right-left)/2);
    mergeSort(arr, left, middle);
    mergeSort(arr, middle+1, right);
    merge(arr, left, middle, right);
}


int main(int argc, char *argv[]) {

    int sortLength = 1;
    //cout << "Sorted array:" << endl;
    cin >> sortLength;
    int sort[sortLength];

    for (int i=0;i<sortLength;i++) {
        cin >> sort[i];
        //cout << "Added " << sort[i] << " to be sorted.\n";
    };

    mergeSort(sort, 0, sortLength-1);

    for (int i=0;i<sortLength;i++) {
        cout << sort[i] << ";";
    }
    //cout << endl;

    //to run:  cat test.txt | ./a.exe

    

    return 0;
}