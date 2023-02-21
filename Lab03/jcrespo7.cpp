#include <iostream>
#include <string>
#include <limits>

using namespace std;


struct findMaxSubarrayResultType {
    int low;
    int high;
    int sum;
};

findMaxSubarrayResultType findMaxCrossingSubarray(int* arr, int low, int mid, int high) {
    findMaxSubarrayResultType result;
    double leftSum = -1 * (numeric_limits<double>::infinity());
    double sum = 0;
    for (int i=mid;i>=low;i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            result.low = i; // maxLeft
        }
    }
    double rightSum = -1 * (numeric_limits<double>::infinity());
    sum = 0;
    for (int i=mid+1; i<high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            result.high = i; // maxRight
        }
    }
    result.sum = (int) leftSum + rightSum;
    return result;
}


findMaxSubarrayResultType findMaxSubarray(int *arr, int low, int high) {
    if (high == low) {
        findMaxSubarrayResultType result;
        result.low = low;
        result.high = high;
        result.sum = arr[low];
        return result;
    } else {
        int mid = (low+high)/2;
        findMaxSubarrayResultType left = findMaxSubarray(arr, low, mid);
        findMaxSubarrayResultType right = findMaxSubarray(arr, mid+1, high);
        findMaxSubarrayResultType cross = findMaxCrossingSubarray(arr, low, mid, high);
        if (left.sum >= right.sum && left.sum >= cross.sum) {
            return left;
        } else if (right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        } else {
            return cross; 
        }
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

    findMaxSubarrayResultType result = findMaxSubarray(arr, 0, arrLength);

    //int sum = 0;
    //for (int i=result.low;i<result.high;i++) {
    //   std::cout << arr[i] << ";";
    //   sum += arr[i];
    //}
    std::cout << result.sum;
    //cout << endl;

    //to run:  cat test.txt | ./a.exe

    

    return 0;
}