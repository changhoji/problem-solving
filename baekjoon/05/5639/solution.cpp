#include <iostream>
using namespace std;

struct Node {
    int number;
    struct Node *parent;
    struct Node *left;
    struct Node *right;

    Node(int num, Node *parent): number(num), parent(parent), left(nullptr), right(nullptr) {}

    void PostOrderTraverse(){
        if(this->left){
            this->left->PostOrderTraverse();
        }
        if(this->right){
            this->right->PostOrderTraverse();
        }
        cout << this->number << '\n';
    }
};

int main(){
    int num;

    Node *root = new Node(0, nullptr);
    root->number = 0;

    Node *cur;

    while(cin >> num){
        if(root->number == 0){
            root->number = num;
        } else{
            cur = root;
            while(true){
                if(num < cur->number){
                    if(cur->left){
                        cur = cur->left;
                    } else{
                        cur->left = new Node(num, cur);
                        break;
                    }
                } else{
                    if(cur->right){
                        cur = cur->right;
                    } else{
                        cur->right = new Node(num, cur);
                        break;
                    }
                }
            }
        }
    }

    root->PostOrderTraverse();

    return 0;
}
