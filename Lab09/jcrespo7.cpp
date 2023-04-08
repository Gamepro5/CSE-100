#include <iostream>
#include <string>
#include <limits>

using namespace std;

int len = 6;

struct node {
    int frequency;
    node* right;
    node* left;
};

void minHeapInsert(node** arr, int size, node* key) {
    size++;
    arr[size] = key;
    while ((size>1) && (arr[size/2]->frequency > arr[size]->frequency)) {
        node* temp = arr[size];
        arr[size] = arr[size/2];
        arr[size/2] = temp;
        size = size/2;
    }

}

void minHeapify(node** arr, int i) {
    int min = i;
    int leftChild = (2*i) + 1;
    int rightChild = (2*i) + 2;
    if ((leftChild < len) && (arr[leftChild]->frequency < arr[min]->frequency)) {
        min = leftChild;
    }
    if ((rightChild < len) && (arr[rightChild]->frequency < arr[min]->frequency)) {
        min = rightChild;
    }
    if (min != i) {
        node* temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        minHeapify(arr, len, min);
    }
}

void buildMinHeap(node** arr, int size) {
    for(int i=len/2 -1;i>=0;i--){
       minHeapify(arr,size,i);
    }
}

node* heapExtractMin(node** A, int size) {
    
    node* min = A[1];
    A[1] = A[len];
    buildMinHeap(A, size-1);
    return min;
}

node* huffman(node* C, int size) {
    int tempSize = size;
    for (int i=1;i<size-1;i++) {
        node* temp = new node;

        temp->left = heapExtractMin(C, size);
        size--;
        temp->right = heapExtractMin(C, size);
        size--;
        temp->frequency = temp->left->frequency + temp->right->frequency;
        minHeapInsert(C, size, temp);
    }
}

int main(int argc, char *argv[]) {

    int arrLength = 6;
    //cout << "Sorted array:" << endl;
    //cin >> arrLength;

   int intArr[arrLength];
   node* nodeArr[arrLength];
   for (int i=0;i<arrLength;i++) {
        node* myNode = new node;
        nodeArr[i] = myNode;
   }

    for (int i=0;i<arrLength;i++) {
        cin >> nodeArr[i]->frequency;
        intArr[i] = nodeArr[i]->frequency;
        //cout << "Added " << sort[i] << " to be sorted.\n";
    };
    buildMinHeap(nodeArr, arrLength);

    node* head = huffman(nodeArr, arrLength);
    

    //int sum = 0;
    for (int i=0;i<arrLength;i++) {
       std::cout << arr[i] << ";";
       //sum += arr[i];
    }
    //cout << endl;

    //to run:  cat test.txt | ./a.exe

    

    return 0;
}