/*
    Ler uma lista de inteiros de N posições. Escreva a seguir o valor e
    a posição do big e low elementos lidos.
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
    Node *list = NULL;

    int num_elements;
    cout << "Digite o número de elementos na lista: ";
    cin >> num_elements;

    // Inserindo elementos na lista
    cout << "======================================\n";
    cout << "\t   Preencha Lista X\n";
    cout << "======================================\n";
    set_list(list, num_elements);

    cout << "Lista X: ";
    display(list);
    cout << "======================================\n";

    Node *temp = list;
    int big = temp->data, low = temp->data;
    int pos_big = 0, pos_low = 0, current_pos = 0;
    while(temp != NULL){
        if(temp->data > big){
            big = temp->data;
            pos_big = current_pos;
        }
        if(temp->data < low){
            low = temp->data;
            pos_low = current_pos;
        }
        temp = temp->next;
        current_pos++;
    }
    printf("Maior elemento: %d na posição: %d\n", big, pos_big);
    printf("Menor elemento: %d na posição: %d\n", low, pos_low);
    return 0;
}