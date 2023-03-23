#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stdlib.h>
#include <string>
using namespace std;

int hashSize;



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
        std::cout << number << ":DELETE_FAILED;\n";
       } else {
        bool found = false;
        for (int i=0;i<Table[bucket].size();i++) {
          list<int>::iterator it = Table[bucket].begin();
          advance(it, i);
          if (*it == number) {
            Table[bucket].erase(it);
            std::cout << number << ":DELETED;\n";
            found = true;
            break;
          }
        }
        if (!found) {
          std::cout << number << ":DELETE_FAILED;\n";
        }
       }
      }else if(input[0] == 's'){
       int bucket = hashf(number);
       bool found = false;
       for (int i=0;i<Table[bucket].size();i++) {
        list<int>::iterator it = Table[bucket].begin();
        advance(it, i);
        if (*it == number) {
          std::cout << number << ":FOUND_AT" << bucket << "," << i << ";\n";
          found = true;
        }
       }
       if (!found) {
          std::cout << number << ":NOT_FOUND;\n";
        }
      }else if(input[0] == 'o'){
       for (int i=0;i<hashSize;i++) {
        cout << i << ":";
        for (int j=0;j<Table[i].size();j++) {
          list<int>::iterator it = Table[i].begin();
          advance(it, j);
          cout << *it << "->";
        }
        cout << ";" << std::endl;
       }
      }else if(input[0] == 'e'){
        repeat = false;
      }else{
        cout << "Wrong input" << endl;
      }
  }while(repeat);

  return 0;
}