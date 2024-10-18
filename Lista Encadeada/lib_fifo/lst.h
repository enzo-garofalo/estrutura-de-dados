#ifndef LST_H
#define LST_H

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* first;
    Node* last;
};

namespace ENZ_LIB {
    class Lst {
    public:
        void display(Queue* q);
        void insert(Queue* q, int value);
        void remove(Queue* q);
    };
}

#endif
