/*
Fazer um programa que faz a leitura de uma lista X com N inteiros (N
deve ser lido tb). Multiplique cada elemento de X por um inteiro K
(K também deverá ser lido). Imprimir a lista lida, o valor da variável K
e a lista multiplicada por K.
*/
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};

Node* initialize(){
    return NULL;
};

Node* insertAtBeginning(Node *list, int value){
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = list;
    return newNode;
}

void display(Node *list){
    Node *temp = list;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void set_list(Node *&list, int num_elements){
    for(int i = 0; i < num_elements; i++){
        int value;
        cout << "Digite o valor para a posicao ["<< (i) <<"]: ";
        cin >> value;
        list = insertAtBeginning(list, value);   
    }
    cout << "======================================\n";
}

void set_list_k(Node *&list_k, Node *list_x, int k){
    
    Node *temp = list_x;
    while(temp != NULL){
        int product = temp->data*k;
        list_k = insertAtBeginning(list_k, product);
        temp = temp->next;
    }
}

int main(){
    Node *list_x = initialize();
    Node *list_k = initialize();

    int num_elements;
    cout << "Digite o número de elementos na lista: ";
    cin >> num_elements;
    
    int k;
    cout << "Digite a constante k: ";
    cin >> k;

    //Inserindo Elementos no começo da lista!
    cout << "======================================\n";
    cout << "\t   Preencha Lista X\n";
    cout << "======================================\n";
    set_list(list_x, num_elements);

   
    cout << "Lista X: ";
    display(list_x);
    cout << "======================================\n";
    // I need to learn how to insert at the end of list!
    set_list_k(list_k, list_x, k);
    cout << "Lista K: ";
    display(list_k);


    return 0;
}