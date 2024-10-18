#include "lst.h"
#include <iostream>
using namespace std;

namespace ENZ_LIB {
    void Lst::display(Queue* q) {
        if (q->first == NULL) {
            cout << "Fila está vazia" << endl;
            return;
        }

        Node* current = q->first;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    void Lst::insert(Queue* q, int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (q->last == NULL) {
            q->first = q->last = newNode;
        } else {
            q->last->next = newNode;
            q->last = newNode;
        }
    }

    void Lst::remove(Queue* q) {
        if (q->first == NULL) {
            cout << "Fila está vazia, nada para remover" << endl;
            return;
        }

        Node* temp = q->first;
        q->first = q->first->next;

        if (q->first == NULL) {
            q->last = NULL;
        }

        delete temp;
    }
}
