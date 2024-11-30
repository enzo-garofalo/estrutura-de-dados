// Você está desenvolvendo um programa para gerenciar pacientes em uma clínica médica. 
// O sistema deve ter as seguintes funcionalidades:

// Registrar um paciente na lista de espera:
// Use uma fila para registrar pacientes que aguardam por atendimento.
// Cada paciente tem um ID único e um nome.

// Mover paciente para triagem:
// O primeiro paciente da fila deve ser removido e adicionado a uma pilha que representa os pacientes em triagem.

// Finalizar triagem:
// O paciente no topo da pilha de triagem é removido e adicionado a uma lista encadeada de pacientes atendidos.

// Exibir status atual:
// Liste todos os pacientes na fila de espera, triagem e os já atendidos.

#include <iostream>
#include <string>
using namespace std;

// Nós que representam pacientes
struct Node
{
     int id;
     string name;
     Node *next;
};

// Fila de espera por atendimento
struct Queue{
     Node *first;
     Node *last;
};

// Pilha de triagem
struct Stack{
     Node *top;
};

// Lista de pacientes Atendidos
struct List{
     Node *head;
};

// Inserindo na Fila de espera
void awaitQueue(Queue *Q, int id, string name)
{
     Node *newPatient = new Node();
     newPatient->id = id;
     newPatient->name = name;

     if(Q->first == NULL){
          Q->first = newPatient;
     }else{
          newPatient->next = Q->last;
     }
     Q->last = newPatient;
}

// removendo da fila de espera e inserindo na pilha de triagem
void  moveToTriagem(Queue *Q, Stack *S)
{
     if(Q->first == NULL){
          cout << "Lista de espera vazia!" << endl;
          return;
     }
     // Adicionando na pilha de triagem
     Node *sTemp = Q->first;
     sTemp->next = S->top;
     S->top = sTemp;
     // Removendo da fila de espera
     Node *qTemp = Q->first;
     Q->first = Q->first->next;
     
     if(Q->first == NULL) Q->last = NULL;
}

void finishTriagem(Stack *S, List *L)
{
     // Remover da pilha, adicionar na lista
     Node *temp = S->top;
     S->top = S->top->next;

     temp->next = L->head;
     L->head = temp;
}
// Funções para exibir pacientes
void displayQueue(Queue *Q) {
    Node *current = Q->first;
    cout << "Fila de Espera:\n";
    if (current == NULL) {
        cout << "Fila vazia\n";
    } else {
        while (current != NULL) {
            cout << "ID: " << current->id << ", Nome: " << current->name << endl;
            current = current->next;
        }
    }
}

void displayStack(Stack *S) {
    Node *current = S->top;
    cout << "Pilha de Triagem:\n";
    if (current == NULL) {
        cout << "Pilha vazia\n";
    } else {
        while (current != NULL) {
            cout << "ID: " << current->id << ", Nome: " << current->name << endl;
            current = current->next;
        }
    }
}

void displayList(List *L) {
    Node *current = L->head;
    cout << "Pacientes Atendidos:\n";
    if (current == NULL) {
        cout << "Nenhum paciente atendido\n";
    } else {
        while (current != NULL) {
            cout << "ID: " << current->id << ", Nome: " << current->name << endl;
            current = current->next;
        }
    }
}

int main() {
    Queue queue = {NULL, NULL};
    Stack stack = {NULL};
    List list = {NULL};

    int option, id = 1;
    string name;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Registrar paciente na fila de espera\n";
        cout << "2. Mover paciente para triagem\n";
        cout << "3. Finalizar triagem\n";
        cout << "4. Exibir status atual\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> option;

        switch (option) {
        case 1: // Registrar paciente na fila
            cout << "Digite o nome do paciente: ";
            cin.ignore();
            getline(cin, name);
            awaitQueue(&queue, id++, name);
            break;

        case 2: // Mover para triagem
            moveToTriagem(&queue, &stack);
            break;

        case 3: // Finalizar triagem
            finishTriagem(&stack, &list);
            break;

        case 4: // Exibir status atual
            displayQueue(&queue);
            displayStack(&stack);
            displayList(&list);
            break;

        case 5: // Sair
            cout << "Encerrando o programa...\n";
            break;

        default:
            cout << "Opção inválida!\n";
        }
    } while (option != 5);

    return 0;
}