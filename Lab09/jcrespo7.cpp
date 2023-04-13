#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

struct Node {
    char letter;
    int frequency;
    Node* parent;
    Node* right;
    Node* left;
    Node(char _letter, int _frequency) {
        letter = _letter;
        frequency = _frequency;
        right = nullptr;
        left = nullptr;
    }
};

class NodeList{															
	public:
	vector<Node*> arr;
    vector<Node*> originalArr;
    bool parentsSet = false;
    Node* root = new Node('A', 3);		//starting value doesn't matter.				
	NodeList(){}


    void makeList(char letter[], int freq[]){							
            for(int i = 0; i < 6; i++){
                Node* temp = new Node(letter[i],freq[i]);
                arr.push_back(temp);
                originalArr.push_back(temp);
            }
        }

    Node* extractMin(){												
            int size = arr.size();											
            Node* smallest = arr[0];										
            for(int i = 1; i < size; i++){								
                if(arr[i]->frequency < smallest->frequency ){
                    smallest = arr[i];
                }
            }

            for(int i = 0; i < size; i++){								
                if(arr[i] == smallest){
                    arr.erase(arr.begin()+i);							
                }
            }
            return smallest;											
        }

    void setNodeParents(Node* currentNode, Node* previousNode) { //takes the root node and reads the whole tree recursively, setting parent nodes along the way.
        currentNode->parent = previousNode;
        if (currentNode->left != nullptr) {
            setNodeParents(currentNode->left, currentNode);
        }
        if (currentNode->right != nullptr) {
            setNodeParents(currentNode->right, currentNode);
        }
    }

    void printPaths() {
        if (parentsSet == false) {
            setNodeParents(root,nullptr);
            parentsSet = true;
        }
        for (int i=0;i<6;i++) {
            cout << originalArr[i]->letter << ":";
            Node* currentNode = originalArr[i];
            string tempString = "";
            while (currentNode->parent != nullptr) {
                if (currentNode == currentNode->parent->left) {
                    tempString = "0" + tempString;
                } else {
                    tempString = "1" + tempString;
                }
                currentNode = currentNode->parent;
            }
            cout << tempString;
            cout << endl;
        }
    }


    void huffman(){														
		for(int i = 0; i < 5; i++){								
			Node* z = new Node('\0',0);									
			z->left = extractMin();									
			z->right = extractMin();									
			z->frequency = z->left->frequency + z->right->frequency;					
			arr.push_back(z);											
		}											
												
		root = extractMin();
														
	}
};

int main(int argc, char *argv[]) {

    int frequency[6];											
	for(int i = 0; i < 6; i++){	cin >> frequency[i]; }			

	NodeList list;
    char temp[6] = {'A','B','C','D','E','F'};
	list.makeList(temp,frequency);		
	list.huffman();
    list.printPaths();

  	return 0;

    //to run:  cat test.txt | ./a.exe

    

    return 0;
}