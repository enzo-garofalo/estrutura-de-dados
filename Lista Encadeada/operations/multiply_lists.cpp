/* Fazer um programa que faz a leitura de duas listas X e Y, ambas com
N reais (N deve ser lido tb). Efetue a multiplicação dos respectivos
pares de elementos de X por Y, gerando uma terceira lista Z.
Imprima as listas X, Y e Z. */

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};

Node* initialize(){
    return NULL;
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

void display(Node *list){
    Node *temp = list;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
//
void set_list(Node *&list, int num_elements){
    for(int i = 0; i < num_elements; i++){
        int value;
        cout << "Digite o valor para a posicao ["<< (i) <<"]: ";
        cin >> value;
        list = insertAtEnd(list, value);   
    }
    cout << "======================================\n";
}

void set_list_z(Node *list_x, Node *list_y, Node *&list_z){
    Node *temp_x = list_x;
    Node *temp_y = list_y;

    Node *newNode = new Node();
    newNode->next = list_z;
    
    while(temp_x != NULL){
        int product = (temp_x->data*temp_y->data);
        list_z = insertAtEnd(list_z, product);
        temp_y = temp_y->next;
        temp_x = temp_x->next;
    }

}

int main(){
    Node *list_x = initialize();
    Node *list_y = initialize();
    Node *list_z = initialize();

    int num_elements;
    cout << "Digite o número de elementos na lista: ";
    cin >> num_elements;
    
    //Inserindo Elementos no começo da lista!
    cout << "======================================\n";
    cout << "\t   Preencha Lista X\n";
    cout << "======================================\n";
    set_list(list_x, num_elements);
    cout << "\t   Preencha Lista Y\n";
    cout << "======================================\n";
    set_list(list_y, num_elements);
   
    cout << "Lista X: ";
    display(list_x);
    cout << "======================================\n";
    cout << "Lista Y: ";
    display(list_y);

    set_list_z(list_x, list_y, list_z);

    cout << "======================================\n";
    cout << "Lista Z: ";
    display(list_z);
    cout << "======================================\n";

    return 0;
}