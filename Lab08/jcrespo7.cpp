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

struct resultType {
	int* r;
	int* s;
	int total;
};

resultType bottomUpCutRod(int *p, int n){

	resultType result;
	result.r = new int[n+1];
	result.s = new int[n+1];

	for (int i=0;i<n+1;i++) {
		result.s[i] = 0;
		result.r[i] = 0;
	}
	result.r[0] = 0;
	
	for(int j = 1; j <= n; j++){

		double q = -1 * (numeric_limits<double>::infinity());
		for(int i = 1; i <= j; i++){
			
			double temp = p[i] + result.r[j-i];
			if(q < temp){
				q = temp;
				result.total = (int)q;
				result.s[j] = i;
			}
		}
		result.r[j] = (int)q;
	}

	//result.total = r[n];
	return result;
}

void printCutRodSolution(resultType result, int rodlength) {
	int k = rodlength;
	while (k > 0) {
		cout << result.s[k] << " ";
		k = k - result.s[k];
	}
	cout << "-1" << endl;
}

int main(){
	
	int size;
	
	cin >> size;
	
	int p[size + 1];
	
	for(int i = 1; i <= size; i++){
		cin >> p[i];
	}
	
	
	
	resultType result = bottomUpCutRod(p, size);
/*
	for (int i=0;i<size+1;i++) {
		cout << result.r[i] << ";";
	}
	cout << endl;
	for (int i=0;i<size+1;i++) {
		cout << result.s[i] << ";";
	}
	cout << endl;
	*/
	cout << result.total << endl;
	printCutRodSolution(result, size);
	
	//to run:  cat test.txt | ./a.exe
	
	return 0;
}
