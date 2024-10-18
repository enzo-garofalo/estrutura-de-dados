/*
Fazer um programa que faz a leitura de uma lista X, com N
inteiros (N deverá ser lido). Gere uma segunda lista com os
valores de X em ordem inversa. Imprimir X e a lista com a
ordem inversa.
*/
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* insertAtBeginning(Node *list, int value){
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = list;
    return newNode;
}

void display(Node *list) {
    Node *temp = list;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void set_list(Node *&list, int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        int value;
        cout << "Digite o valor para a posicao [" << (i) << "]: ";
        cin >> value;
        list = insertAtBeginning(list, value);
    }
    cout << "======================================\n";
}

int main(){
    Node *list_x = NULL;
    Node *inverse_list = NULL;

    int num_elements;
    cout << "Digite o número de elementos na lista: ";
    cin >> num_elements;

    // Inserindo elementos na lista
    cout << "======================================\n";
    cout << "\t   Preencha Lista X\n";
    cout << "======================================\n";
    set_list(list_x, num_elements);

    cout << "Lista X: ";
    display(list_x);

    Node *temp = list_x;
    while (temp != NULL){
        inverse_list = insertAtBeginning(inverse_list, temp->data);
        temp = temp->next; 
    }
    cout << "======================================\n";
    cout << "Inversa: ";
    display(inverse_list);
    return 0;
}