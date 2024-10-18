#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *first;
    Node *last;
};

void insert(Queue *q, int value){
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    // Se a lista está vazia
    if(q->last == NULL){
        q->first = newNode;
    }else{
        // Aponta o próximo do útimo da fila para o novo nó
        q->last->next = newNode;
    } 
    // Agora o ultimo da fila é o novo nó
    q->last = newNode;
}

int remove(Queue *q){
    // Verifica Se Fila Está vazia
    if(q->first == NULL){
        cout << "Fila Vazia!\n";
        return 0;
    }

    Node *temp = q->first;
    int value = temp->data;

    // Avança lista e verifica se é o ultimo elemento
    q->first = q->first->next;
    if(q->first == NULL) q->last = NULL;

    delete temp;
    return value;
}

void display(Queue *q){
    if (q->first == NULL){
        cout << "Fila está vazia" << endl;
        return;
    }

    Node *current = q->first;
    while (current !=  NULL){
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

int main(){
    Queue *q = new Queue;
    q->first = NULL;
    q->last = NULL;

    int size;
    cout << "Preencha sua fila\nDigite numero de elementos:";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int value;
        cout << "Preencha a posicao " << (i+1) << ": ";
        cin >> value;
        insert(q, value);
    }
    display(q);
    cout << "Valor removido: " << remove(q) << endl;
    display(q);

    return 0;
}