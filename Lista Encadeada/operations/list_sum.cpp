/*
Fazer um programa que faz a leitura de uma lista X com N reais
(N deverá ser lido). Calcule o somatório de todos os elementos
da lista. Imprimir a lista lida e o valor do somatório.
*/
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};


Node* insertAtEnd(Node *list, int value){
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(list == NULL) return newNode;
    Node *temp = list;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return list;
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
        list = insertAtEnd(list, value);
    }
    cout << "======================================\n";
}

int get_sum(Node *list){
    Node *temp = list;
    int sum = 0;
    while(temp != NULL){
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int main(){
    Node *list_x = NULL;

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
    cout << "======================================\n";
    cout << "Soma: " << get_sum(list_x);

    return 0;
}