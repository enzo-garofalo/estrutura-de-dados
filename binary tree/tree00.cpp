#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct NoArvore {
     int info;
     struct NoArvore *esq;
     struct NoArvore *dir;
};

struct Arvore {
     struct NoArvore *raiz;
};

// Função para criar a árvore
struct Arvore* Criar() {
     struct Arvore *arvore = (struct Arvore *)malloc(sizeof(struct Arvore));
     arvore->raiz = NULL;
     return arvore;
}
// Função para inserir um elemento na árvore
struct NoArvore* InserirNo(struct NoArvore *no, int valor) {
     if (no == NULL) {//Se tem nó filho disponível, insere e retorna.
          struct NoArvore *novoNo = (struct NoArvore *)malloc(sizeof(struct NoArvore));
          novoNo->info = valor;
          novoNo->esq = NULL;
          novoNo->dir = NULL;
          return novoNo;
     }
//Se já tem 2 filhos, a busca continua...
     if (valor < no->info) {
          no->esq = InserirNo(no->esq, valor);//Recursividade.
     }else if (valor > no->info) {
          no->dir = InserirNo(no->dir, valor); //Recursividade.
     }
     return no;//Vai retornar o mesmo nó caso o valor seja igual.
}
void Inserir(struct Arvore *arvore, int valor) {
     arvore->raiz = InserirNo(arvore->raiz, valor);
}
// Função para imprimir a árvore em ordem
void ImprimirNo(struct NoArvore *no, int level) {
     if (no != NULL) {
          // Criação do texto de indentação
          char txt[100]; // Tamanho suficiente para a indentação
          txt[0] = '\0'; // Inicializa a string
          for (int c = 0; c < level - 1; c++) {
               strcat(txt, "   "); // Adiciona '   ' para cada nível
          }
          if (level > 0) strcat(txt, "|.."); // Adiciona '...' para cada nível
          // Imprime o nó atual
          printf("%s%d\n", txt, no->info);
          // Chamada recursiva para o filho esquerdo
          ImprimirNo(no->esq, level + 1);
          // Chamada recursiva para o filho direito
          ImprimirNo(no->dir, level + 1);
     }
}
void Imprimir(struct Arvore *arvore) {
     ImprimirNo(arvore->raiz, 0);
     printf("\n");
}
// Função para verificar se a árvore está vazia
int EstaVazia(struct Arvore *arvore) {
     return arvore->raiz == NULL;
}
// Função para buscar um elemento na árvore
bool BuscarNo(struct NoArvore *no, int valor) {
     if (no == NULL) {
          return false; // não encontrado
     }
     if (no->info == valor) {
          return true; // encontrado
     }
     if (valor < no->info) {
          return BuscarNo(no->esq, valor); //Recursividade.
     }
     else {
          return BuscarNo(no->dir, valor); //Recursividade.
     }
}
bool Buscar(struct Arvore *arvore, int valor) {
     return BuscarNo(arvore->raiz, valor);
}
// Função para liberar a memória da árvore
void LiberarNo(struct NoArvore *no) {
     if (no != NULL) {
          LiberarNo(no->esq); //Recursividade.
          LiberarNo(no->dir); //Recursividade.
          free(no);
     }
}
void Liberar(struct Arvore *arvore) {
     LiberarNo(arvore->raiz);
     free(arvore);
}
// Função para remover um elemento da árvore
struct NoArvore* RemoverNo(struct NoArvore *no, int valor) {
     if (no == NULL) 
     {
          return NULL; // Não encontrado
     }

     if (valor < no->info) 
     {
          no->esq = RemoverNo(no->esq, valor);
     }else if (valor > no->info) {
          no->dir = RemoverNo(no->dir, valor);
     }else{
          // No encontrado
          if (no->esq == NULL) {
               struct NoArvore *temp = no->dir;
               free(no);
               return temp;
          } else if (no->dir == NULL) {
               struct NoArvore *temp = no->esq;
               free(no);
               return temp;
          }
          // Nó com dois filhos: obter o menor no da subárvore da direita
          struct NoArvore *temp = no->dir;
          while (temp && temp->esq != NULL) {
               temp = temp->esq;
          }
          no->info = temp->info; // Copiar o valor do nó
          no->dir = RemoverNo(no->dir, temp->info); // Remover o nó
     }
     return no;
}
void Remover(struct Arvore *arvore, int valor) {
     arvore->raiz = RemoverNo(arvore->raiz, valor);
}
// Exemplo de uso
int main() {
     struct Arvore *minhaArvore = Criar();
     Inserir(minhaArvore, 5);
     Inserir(minhaArvore, 3);
     Inserir(minhaArvore, 7);
     Inserir(minhaArvore, 2);
     Inserir(minhaArvore, 4);
     Inserir(minhaArvore, 1);
     Inserir(minhaArvore, 9);
     Inserir(minhaArvore, 11);
     Inserir(minhaArvore, 6);
     printf("Elementos da árvore:\n");
     Imprimir(minhaArvore);
     printf("A árvore está vazia? %s\n", EstaVazia(minhaArvore) ? "Sim" : "Nao");
     printf("Buscar 4: %s\n", Buscar(minhaArvore, 4) ? "Encontrado" : "Nao encontrado");
     Remover(minhaArvore, 3);
     printf("Após remover 3:\n");
     Imprimir(minhaArvore);
     Liberar(minhaArvore);
     return 0;
}

