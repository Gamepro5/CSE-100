#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void swap(int** arr, int q, int r) {
    int temp = (*arr)[q];
    (*arr)[q] = (*arr)[r];
    (*arr)[r] = temp;
}

int memoizedCutRodAux(float* pricesArr, int pricesArrLength, float* auxArray) {
    float desiredValue;
    if (auxArray[pricesArrLength-1] >= 0) {
        return auxArray[pricesArrLength-1];
    }
    if (pricesArrLength == 0) {
        desiredValue = 0;      
    } else {
        desiredValue = -1 * INFINITY;
        for (int i=1;i<pricesArrLength;i++) {
            desiredValue = max(desiredValue, pricesArr[i] + memoizedCutRodAux(pricesArr, pricesArrLength-1, auxArray));
        }
    }
    auxArray[pricesArrLength-1] = desiredValue;
    return desiredValue;
}

int memoizedCutRod(float* pricesArr, int pricesArrLength) {
    float auxArray[pricesArrLength-1];
    for (int i=0;i<pricesArrLength;i++) {
        auxArray[i] = -1 * INFINITY;
    }
    return memoizedCutRodAux(pricesArr, pricesArrLength, auxArray);
}

float bottomUPCutRod(float* pricesArr, int pricesArrLength) {
    int n = pricesArrLength-1;
    float auxArray[pricesArrLength];
    auxArray[0] = 0;
    for (int j=1;j<=n;j++) {
        float q = -1 * INFINITY;
        for (int i=1;i<=j;i++) {
            q = max(q, pricesArr[i] + auxArray[j-i]);
        }
        auxArray[j] = q;
    }
    return auxArray[n];
}


float oldcutRod(float* price, int index, int n) {
    if (index == 0) {
        cout << n << " ";
        return n * price[0];
    }
    float notCut = oldcutRod(price, index-1, n);
    float cut = -1 * INFINITY;
    int rod_length = index + 1;
    if (rod_length <= n) {
        cut = price[index] + oldcutRod(price, index, n-rod_length);
    }
    
    return max(notCut, cut);
}

struct result {
    int* answerSet;
    int* value;
};
/*
struct result cutRod(int* price, int n) {
    int Table[n+1], Cuts[n+1];
    for (int i=0;i<=n;i++) {
        Table[i] = 0;
    }
    for (int length=0;length<=n;length++) {
        for (int i=0;i<length;i++) {
            int temp = price[i] + Table[length-i]; 
            if (temp > Table[length]) {
                Table[length] = temp;
                Cuts[length] = i;
            }
        }
    }
    vector<int> AnswerSet = {};
    int k = n;
    while (k>0) {
        AnswerSet.push_back(Cuts[k]);
        k -= Cuts[k];
    }
    struct result r;
    r.answerSet = AnswerSet;
    r.value = Table[n];
    return r;
}
*/
struct result extendedBottomUpCutRod(int* p, int n) {
    int s[n+1];
    int r[n+1];
    r[0] = 0;
    for (int j=1;j<=n;j++) {
        double q = -1 * (numeric_limits<double>:: infinity());
        for (int i=1;i<=j;i++) {
            if (q < (double) (p[i] + r[j-i])) {
                q = (double) (p[i] + r[j-i]);
                s[j] = i;
            }
        }
        r[j] = (int) q;
    }
    struct result res;
    res.answerSet = s;
    res.value = r;
    return res;
}
void printCutRodSolution(int* p, int n) {
    struct result r = extendedBottomUpCutRod(p, n);
    while (n>0) {
        cout << r.answerSet[n] << "; ";
        n = n - r.answerSet[n];
    }
}


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char *argv[]) {

    int arrLength = 1;
    
    cin >> arrLength;
    
    int arr[arrLength+1];

    for (int i=1;i<arrLength+1;i++) {
        cin >> arr[i];
    };
  
    struct result r = extendedBottomUpCutRod(arr,arrLength);
    for (int i=0;i<arrLength;i++) {
        cout << r.value[i] << ";  ";
    }
    cout << endl;
    for (int i=0;i<arrLength;i++) {
        cout << r.answerSet[i] << ";  ";
    }
    

    //cout << endl;

    //to run:  cat test.txt | ./a.exe

    

    return 0;
}