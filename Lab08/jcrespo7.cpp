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

struct Rod{
	int piece1;
	int piece2;
	int total;
};

Rod bottomUpCutRod(int *p, int n){

	Rod rod;
	rod.piece1 = 0;
	rod.piece2 = 0;
	rod.total = 0;

	int r[n + 1];
	r[0] = 0;
	
	for(int j = 1; j <= n; j++){

		int q = INT_MIN;
		for(int i = 1; i <= j; i++){
			
			int temp = p[i] + r[j-i];
			if(q < temp){
				q = temp;
				rod.piece1 = i;
				rod.piece2 = n - i;
				rod.total = (int)q;
			}
		}
		r[j] = q;
	}
	
	return rod;
}

int main(){
	
	int size;
	
	cin >> size;
	
	int p[size + 1];
	
	for(int i = 1; i <= size; i++){
	
		cin >> p[i];
	}
	
	Rod fin = bottomUpCutRod(p, size);
	
	cout << fin.total << endl;
	cout << fin.piece1 << " ";
	
	if(fin.piece2 != 0){
		cout << fin.piece2 << " ";
	}
	
	cout << "-1" << endl;

	//to run:  cat test.txt | ./a.exe
	
	return 0;
}
