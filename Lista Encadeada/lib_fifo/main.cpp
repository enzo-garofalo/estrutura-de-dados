#include "lst.h"
#include <iostream>
using namespace ENZ_LIB;

int main() {
    Queue q;
    q.first = nullptr;
    q.last = nullptr;

    Lst lst;

    lst.insert(&q, 10);
    lst.insert(&q, 20);
    lst.insert(&q, 30);

    lst.display(&q);

    lst.remove(&q);

    lst.display(&q);

    return 0;
}
