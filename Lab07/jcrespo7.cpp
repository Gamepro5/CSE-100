#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stdlib.h>
#include <string>
using namespace std;

int hashSize;

int getiteminlist(std::list<int> l, int n) {
  for (int i=0;i<n;n++) {
    
  }
}

int hashf(int key) {
  return key % hashSize;
}

int main(int argc, char const *argv[]) {

  int number =  0;
  bool repeat = true;

  vector<std::list<int>> Table;
  string input = "";
  cin >> hashSize;

  for (int i=0;i<hashSize;i++) {
    std::list<int> temp = {};
    Table.push_back(temp);
  }
  //

  do{
      number = 0;
      cin >> input;
      //Create integer if required by function
      if (input[0] != 'o' || input[0] != 'e'){
        for (int i = 1; i < input.size(); i++){
          int digit = input[i] - '0';
          number = 10 * number + digit;
        }
      }

      if(input[0] == 'i'){
       int bucket = hashf(number);
       Table[bucket].push_front(number);
      }else if(input[0] == 'd'){
       int bucket = hashf(number);
       if (Table[bucket].size() == 0) {
        std::cout << "(" << number << "):DELETE_FAILED;";
       } else {
        Table[bucket].pop_front();
        std::cout << "(" << number << "):DELETED;";
       }
      }else if(input[0] == 's'){
       int bucket = hashf(number);
       bool found = false;
       for (int i=0;i<Table[bucket].size();i++) {
        if (Table[bucket][i] == number) {
          std::cout << "(" << number << "):FOUND_AT" << bucket << "," << i << ";";
          found = true;
        }
        if (!found) {
          std::cout << "(" << number << "):NOT_FOUND;";
        }
       }
      }else if(input[0] == 'o'){
       // ...
      }else if(input[0] == 'e'){
        repeat = false;
      }else{
        cout << "Wrong input" << endl;
      }
  }while(repeat);

  return 0;
}