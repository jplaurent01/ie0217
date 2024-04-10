#include <iostream>
using namespace std;

// Definición de la estructura del nodo del árbol
struct Node {
    int data;          // Valor almacenado en el nodo
    struct Node *left; // Puntero al nodo hijo izquierdo
    struct Node *right;// Puntero al nodo hijo derecho

    // Constructor para inicializar un nodo con un valor dado
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Función para recorrer el árbol en preorden
void preOrderTransversal(struct Node* node){
    if(node == NULL)
        return;
    cout << node->data << "->"; // Imprimir el valor del nodo
    preOrderTransversal(node->left);  // Recorrer el subárbol izquierdo
    preOrderTransversal(node->right); // Recorrer el subárbol derecho
}

// Función para recorrer el árbol en postorden
void postOrderTransversal(struct Node* node){
    if(node == NULL)
        return;
    
    postOrderTransversal(node->left);  // Recorrer el subárbol izquierdo
    postOrderTransversal(node->right); // Recorrer el subárbol derecho
    cout << node->data << "->";        // Imprimir el valor del nodo
}

// Función para recorrer el árbol en inorden
void inOrderTransversal(struct Node* node){
    if(node == NULL)
        return;
    
    inOrderTransversal(node->left);   // Recorrer el subárbol izquierdo
    cout << node->data << "->";       // Imprimir el valor del nodo
    inOrderTransversal(node->right);  // Recorrer el subárbol derecho
}

int main() {
    // Creación de un árbol
    struct Node* root = new Node(1);  // Raíz con valor 1
    root->left = new Node(12);        // Nodo izquierdo con valor 12
    root->right = new Node(9);        // Nodo derecho con valor 9
    root->left->left = new Node(5);   // Nodo izquierdo del subárbol izquierdo con valor 5
    root->left->right = new Node(6);  // Nodo derecho del subárbol izquierdo con valor 6

    // Recorridos del árbol
    cout << "inOrderTransversal ";
    inOrderTransversal(root);   // Impresión en inorden
    cout << "preOrderTransversal ";
    preOrderTransversal(root);  // Impresión en preorden
    cout << "postOrderTransversal ";
    postOrderTransversal(root); // Impresión en postorden

    //Libera de memoria
    delete root;
    return 0;
}
