#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <math.h>

using namespace std;
using namespace chrono;

class Node {
    private :
        int value;
        Node *left;
        Node *right;
    
    public :
        Node(int value) {
            this->value = value;
            this->right = this->left = NULL;
        }

        int getValue() {
            return this->value;
        }

        void setValue(int value) {
            this->value = value;
        }

        Node *getLeft() {
            return this->left;
        }

        Node *getRight() {
            return this->right;
        }

        Node *getSuccessor() {
            Node *temp = this->right;

            while (temp != NULL && temp->left != NULL) {
                temp = temp->left;
            }

            return temp;
        }

        Node *insertNode(int value) {
            int curVal = this->getValue();

            if (value > curVal) {
                if (this->right == nullptr) {
                    this->right = new Node(value);
                } else {
                    this->right = this->right->insertNode(value);
                }
            } else if (value < curVal) {
                if (this->left == nullptr) {
                    this->left = new Node(value);
                } else {
                    this->left = this->left->insertNode(value);
                }
            }

            return this;
        }

        Node *deleteNode(int value) {
            cout << this->getValue() << '\n';
            int curVal = this->getValue();
            
            if (value > curVal) {
                // delete at right node
                if (this->right == NULL) {
                    return this;
                }

                this->right = this->right->deleteNode(value);
            } else if (value < curVal) {
                // delete at left node
                if (this->left == NULL) {
                    return this;
                }

                this->left = this->left->deleteNode(value);
            } else {
                // Has no child or has only right child
                if (this->left == NULL) {
                    Node *rightNode = this->right;
                    delete this;

                    return rightNode;
                }

                // Has only left child
                if (this->right == NULL) {
                    Node *leftNode = this->left;
                    delete this;

                    return leftNode;
                }

                // Has 2 children
                Node *succ = this->getSuccessor();

                this->setValue(succ->getValue());
                this->right = this->right->deleteNode(value);
            }

            return this;
        }
}*root;

void solve() {
    int arr[] = {2,1,10,6,3,8,7,13,20};
    // int arr[] = {2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        if (root == NULL) {
            root = new Node(arr[i]);
        } else {
            root = root->insertNode(arr[i]);
        }
    }

    cout << root->getRight()->getValue();
}

int main() {
    auto start_time = high_resolution_clock::now(); 
    
    // code run
    solve();

    auto end_time = high_resolution_clock::now();
    duration<float> duration = end_time - start_time;
    cerr<<'\n'<<fixed<<setprecision(5)<<"Execution time: "<<duration.count()<<" seconds";
    return 0;
}