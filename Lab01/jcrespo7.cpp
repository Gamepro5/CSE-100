#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    int sortLength = 1;
    cout << "Sorted array:" << endl;
    cin >> sortLength;
    int sort[sortLength];

    for (int i=0;i<sortLength;i++) {
        cin >> sort[i];
        //cout << "Added " << sort[i] << " to be sorted.\n";
    };

    for (int i=1; i<sortLength; i++) {
        int j = i;
        while (j > 0 && sort[j-1] > sort[j]) {
            int temp = sort[j];
            sort[j] = sort[j-1];
            sort[j-1] = temp;
            j -= 1;
        }
        for (int k=0;k<i+1;k++) {
            cout << sort[k] << ";";
        }
        cout << endl;

    }
    cout << endl;

    //to run:  cat test.txt | ./a.exe

    

    return 0;
}