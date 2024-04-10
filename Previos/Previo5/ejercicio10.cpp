//Arbol
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

//Pre ordenamiento transversal
void preOrderTransversal(struct Node* node){
    if(node == NULL)
        return;
    cout << node->data << "->";
    preOrderTransversal(node->left);
    preOrderTransversal(node->right);
}

//Post ordenamiento transversal
void postOrderTransversal(struct Node* node){
    if(node == NULL)
        return;
    
    postOrderTransversal(node->left);
    postOrderTransversal(node->right);
    cout << node->data << "->";
}

//Post ordenamiento transversal
void inOrderTransversal(struct Node* node){
    if(node == NULL)
        return;
    
    inOrderTransversal(node->left);
    cout << node->data << "->";
    inOrderTransversal(node->right);
    
}

int main() {
    //Lleno el arbol
    struct Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    cout << "inOrderTransversal ";
    inOrderTransversal(root);
    cout << "preOrderTransversal ";
    preOrderTransversal(root);
    cout << "postOrderTransversal ";
    postOrderTransversal(root);
    return 0;
}
