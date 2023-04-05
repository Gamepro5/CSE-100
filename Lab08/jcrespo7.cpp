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

	int r[n + 1];
	int s[n + 1];
	for (int i=0;i<n+1;i++) {
		s[i] = 0;
		r[i] = 0;
	}
	r[0] = 0;
	
	for(int j = 1; j <= n; j++){

		double q = -1 * (numeric_limits<double>::infinity());
		for(int i = 1; i <= j; i++){
			
			double temp = p[i] + r[j-i];
			if(q < temp){
				q = temp;
				result.total = (int)q;
				s[j] = i;
			}
		}
		r[j] = (int)q;
	}

	//result.total = r[n];
	result.r = r;
	result.s = s;
	return result;
}

void printCutRodSolution(resultType result) {
	int k = result.total;
	while (k > 0) {
		cout << result.s[k] << ";";
		k = k - result.s[k];
	}
	cout << endl;
	
}

int main(){
	
	int size;
	
	cin >> size;
	
	int p[size + 1];
	
	for(int i = 1; i <= size; i++){
		cin >> p[i];
	}
	
	
	
	resultType result = bottomUpCutRod(p, size);

	for (int i=0;i<size;i++) {
		cout << result.r[i] << ";";
	}
	cout << endl;
	for (int i=0;i<size;i++) {
		cout << result.s[i] << ";";
	}
	cout << endl;
	cout << result.total << endl;
	printCutRodSolution(result);
	
	
	
	cout << "-1" << endl;

	//to run:  cat test.txt | ./a.exe
	
	return 0;
}
