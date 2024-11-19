#include <iostream>
#include <string>
using namespace std;


// Estrutura do nó da pilha
struct Node {
    char data;
    Node *next;
};

// Estrutura da pilha
struct Stack {
    Node *top;
};

// Função para empilhar (push)
void push(Stack *S, char value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = S->top;
    S->top = newNode;
}

// Função para desempilhar (pop)
char pop(Stack *S) {
    if (S->top == NULL) {
        return '\0'; // Retorna um caractere especial para sinalizar pilha vazia
    }

    Node *temp = S->top;
    S->top = S->top->next;
    char value = temp->data;
    delete temp;
    return value;
}

// Função para verificar se a expressão está balanceada
bool isValid(string expression, Stack *S) {
    for (size_t i = 0; i < expression.size(); i++) {
        char c = expression[i];

        if (c == '{' || c == '[' || c == '(') {
            push(S, c); // Empilha caracteres de abertura
        } else if (c == '}' || c == ']' || c == ')') {
            char top = pop(S);

            // Verifica se a pilha estava vazia ou se o fechamento não corresponde
            if (top == '\0' || 
               (top != '{' && c == '}') || 
               (top != '[' && c == ']') || 
               (top != '(' && c == ')')) {
                return false; // Expressão inválida
            }
        }
    }

    // Verifica se ainda há elementos na pilha (delimitadores não fechados)
    return S->top == NULL;
}

int main() {
    Stack *S = new Stack();
    S->top = NULL;

    string expression;
    cout << "Digite uma expressão: ";
    getline(cin, expression);

    if (isValid(expression, S)) {
        cout << "Expressão válida\n";
    } else {
        cout << "Expressão inválida\n";
    }

    delete S; // Libera a memória alocada para a pilha
    return 0;
}
