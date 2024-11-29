#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
using namespace std;

struct TreeNode{
     int data;
     TreeNode *left;
     TreeNode *right;
};

struct Tree
{
     TreeNode *root;
};

TreeNode* insertNode(TreeNode *node, int value) {
     if(node == NULL){
          TreeNode *newNode = new TreeNode;
          newNode->data = value;
          newNode->left = NULL;
          newNode->right = NULL;
     }

     if(value < node->data){
          node->left = insertNode(node->left, value);
     }else if(value > node->data){
          node->right = insertNode(node->right, value);
     }
     return node;
}

void insert(Tree *tree, int value){
     tree->root = insertNode(tree->root, value);
}

void printNode(TreeNode *node, int level){
     if(node != NULL){
          char txt[100];
          txt[0] = '\0';
          
          for(int c = 0; c < level-1; c++)
          {
               strcat(txt, "       ");
          }

          if(level > 0) strcat(txt, "...");

          cout << txt << node->data;

          printNode(node->left, level+1);
          printNode(node->right, level+1);
     }
}

void printTree(Tree *tree){
     printNode(tree->root, 0);
     cout << "\n";
}

int isEmpty(Tree *tree){
     return tree->root == NULL;
}

bool searchNode(TreeNode *node, int value){
     if (node == NULL) {
          return false; // não encontrado
     }
     if (node->data == value) {
          return true; // encontrado
     }
     if (value < node->data) {
          return searchNode(node->left, value); //Recursividade.
     }
     else {
          return searchNode(node->right, value); //Recursividade.
     }
}

bool search(Tree *tree, int value){
     return searchNode(tree->root, value);
}

void freeNode(TreeNode *node) {
     if (node != NULL) {
          freeNode(node->left); //Recursividade.
          freeNode(node->right); //Recursividade.
          free(node);
     }
}
void Liberar( Tree *tree) {
     freeNode(tree->root);
     free(tree);
}

TreeNode* removeNode(TreeNode *node, int value) {
     if (node == NULL) 
     {
          return NULL; // Não encontrado
     }

     if (value < node->data) 
     {
          node->left = removeNode(node->left, value);
     }else if (value > node->data) {
          node->right = removeNode(node->right, value);
     }else{
          // No encontrado
          if (node->left == NULL) {
               struct TreeNode *temp = node->right;
               free(node);
               return temp;
          } else if (node->right == NULL) {
               struct TreeNode *temp = node->left;
               free(node);
               return temp;
          }
          // Nó com dois filhos: obter o menor node da subárvore da direita
          struct TreeNode *temp = node->right;
          while (temp && temp->left != NULL) {
               temp = temp->left;
          }
          node->data = temp->data; // Copiar o value do nó
          node->right = removeNode(node->right, temp->data); // remove o nó
     }
     return node;
}
void remove(Tree *tree, int value) {
     tree->root = removeNode(tree->root, value);
}

int main() {
     Tree *myTree = new Tree;
     myTree->root = NULL;

     insert(myTree, 5);
     insert(myTree, 3);
     insert(myTree, 7);
     insert(myTree, 2);
     insert(myTree, 4);
     insert(myTree, 1);
     insert(myTree, 9);
     insert(myTree, 11);
     insert(myTree, 6);
     
     printf("Elementos da árvore:\n");
     printTree(myTree);
     
     printf("A árvore está vazia? %s\n", isEmpty(myTree) ? "Sim" : "Nao");
     printf("Buscar 4: %s\n", search(myTree, 4) ? "Encontrado" : "Nao encontrado");
     
     remove(myTree, 3);
     printf("Após remover 3:\n");
     
     printTree(myTree);
     Liberar(myTree);
     return 0;
}
