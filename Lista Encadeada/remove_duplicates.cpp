/*
    Given the head of a sorted linked list, 
    delete all duplicates such that each element appears only once. 
    Return the linked list sorted as well.
*/
#include <iostream>
using namespace std;

struct Node
{
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

void RemoveDuplicates(Node *list){
    Node *temp = list;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            Node *duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        }else{
            temp = temp->next;
        }
    }
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
    
    RemoveDuplicates(list_x);
    cout << "Lista Sem duplicatas: ";
    display(list_x);
    return 0;
}