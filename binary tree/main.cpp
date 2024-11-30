
//Rogério Medina - RA 24008491

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

struct Contato {
    char nome[50];
    char celular[15];
    struct Contato* esquerda;
    struct Contato* direita;
};

// Função de comparação
int compararNomes(char* nome1, char* nome2) {
    return strcmp(nome1, nome2);
}

// Função de inserir contato
struct Contato* inserir(Contato* root, Contato* novo) {
    if (root == NULL) {
        return novo; 
    }
    if (compararNomes(novo->nome, root->nome) < 0) {
        root->esquerda = inserir(root->esquerda, novo); 
    } else if (compararNomes(novo->nome, root->nome) > 0) {
        root->direita = inserir(root->direita, novo); 
    }
    return root;
}

// Função para buscar um contato pelo nome
struct Contato* buscar(Contato* root, const char* nome) {
    if (root == NULL || compararNomes(root->nome, (char*)nome) == 0) {
        return root; 
    }
    if (compararNomes((char*)nome, root->nome) < 0) {
        return buscar(root->esquerda, nome);
    } else {
        return buscar(root->direita, nome); 
    }
}

// Função para encontrar o menor valor da subárvore direita
struct Contato* encontrarMenor(Contato* root) {
    while (root != NULL && root->esquerda != NULL) {
        root = root->esquerda;
    }
    return root;
}

// Função para remover um contato pelo nome
struct Contato* remover(struct Contato* root, const char* nome) {
    if (root == NULL) {
        return NULL; // Árvore vazia ou contato não encontrado
    }

    if (compararNomes((char*)nome, root->nome) < 0) {
        root->esquerda = remover(root->esquerda, nome);
    } else if (compararNomes((char*)nome, root->nome) > 0) {
        root->direita = remover(root->direita, nome);
    } else {
        // Caso 1: Nó com zero ou um filho
        if (root->esquerda == NULL) {
            struct Contato* temp = root->direita;
            free(root);
            return temp;
        } else if (root->direita == NULL) {
            struct Contato* temp = root->esquerda;
            free(root);
            return temp;
        }

        // Caso 2: Nó com dois filhos
        struct Contato* temp = encontrarMenor(root->direita);
        strcpy(root->nome, temp->nome); // Substitui o valor do nó a ser removido
        strcpy(root->celular, temp->celular);
        root->direita = remover(root->direita, temp->nome); // Remove o sucessor
    }
    return root;
}

// Função para listar os contatos em ordem alfabética
void listar(Contato* root) {
    if (root != NULL) {
        listar(root->esquerda);
        cout << "Nome: " << root->nome <<  " | Celular: " << root->celular << endl;
        listar(root->direita); 
    }
}

// Função principal
int main() {
    int opt;
    struct Contato* root = NULL;

    do {
        cout << "--------------------------" << endl;
        cout << "|          Menu          |" << endl;
        cout << "--------------------------" << endl;
        cout << " 1 - Inserir novo Contato" << endl;
        cout << " 2 - Buscar contato" << endl;
        cout << " 3 - Remover contato" << endl;
        cout << " 4 - Listar contatos" << endl;
        cout << " 5 - Sair" << endl;
        cout << "-------------------------" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> opt;
        cin.ignore();
        cout << "-------------------------" << endl;

        switch (opt) {
            case 1: {
               Contato* novo = new Contato;
               cout << "Digite nome: ";
               cin.getline(novo->nome, 50);
               cout << "-------------------------" << endl;
               cout << "Digite celular: ";
               cin.getline(novo->celular, 15);
               cout << "-------------------------" << endl;
               novo->esquerda = NULL;
               novo->direita = NULL;
               root = inserir(root, novo);
               break;
            }
            case 2: {
               char nome[50];
               cout << "Nome para buscar: ";
               cin.getline(nome, 50);
               struct Contato* encontrado = buscar(root, nome);
               if (encontrado) {
               cout << "Contato encontrado: " << encontrado->nome << "| Celular: " << encontrado->celular << endl;
               } else {
               cout << "Contato não encontrado." << endl;
               }
               break;
            }
            case 3: {
               char nome[50];
               cout << "Nome para remover: ";
               cin.getline(nome, 50);
               root = remover(root, nome);
               break;
            }
            case 4: {
               cout << "Contatos da agenda:\n";
               listar(root);
               break;
            }
            case 5:
               cout << "Até mais!" << endl;
               break;
            default:
               cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opt != 5);

    return 0;
}
