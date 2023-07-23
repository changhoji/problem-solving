#include <iostream>
using namespace std;

struct Node{
    char value;
    Node *left;
    Node *right;

    void PreOrderTraverse(){
        cout << value;
        if(left) left->PreOrderTraverse();
        if(right) right->PreOrderTraverse();
    }

    void InOrderTraverse(){
        if(left) left->InOrderTraverse();
        cout << value;
        if(right) right->InOrderTraverse();
    }

    void PostOrderTraverse(){
        if(left) left->PostOrderTraverse();
        if(right) right->PostOrderTraverse();
        cout << value;
    }
};

int main(){
    Node node[26];
    
    int N;
    cin >> N;

    char ch, left, right;
    for(int i = 0; i < N; i++){
        cin >> ch >> left >> right;

        node[ch-'A'].value = ch;

        if(left != '.'){
            node[ch-'A'].left = &node[left-'A'];
        } else{
            node[ch-'A'].left = nullptr;
        }

        if(right != '.'){
            node[ch-'A'].right = &node[right-'A'];
        } else{
            node[ch-'A'].right = nullptr;
        }
    }

    node[0].PreOrderTraverse();
    cout << '\n';
    
    node[0].InOrderTraverse();
    cout << '\n';

    node[0].PostOrderTraverse();
    cout << '\n';

    return 0;
}
