#include <iostream>
#include <string>
#include "lib/enzo_lib/qLST.h"

using namespace std;
using namespace enzo_lib;


void insertClient(Queue* fila)
{
    Client* newClient = new Client; 
    cout << "\n=================================\n";
    cout << "Digite o ID do Cliente: ";
    cin >> newClient->ID;
    cin.ignore(); 
    cout << "Digite o nome do Cliente: ";
    getline(cin, newClient->name);

    qLST lst;
    lst.insert(fila, newClient);
    cout << "=================================\n";
    cout << "    Novo Cliente na Fila ";
    cout << "\n=================================\n";

}

void attendClient(Queue* fila)
{
    if(fila->first != NULL)
    {
        cout << "\n=================================\n";
        cout << "Atendendo: " << fila->first->client.name;
        cout << "\nID: " << fila->first->client.ID;
        cout << "\n=================================\n";
    
        qLST lst;
        lst.remove(fila);
    }else{
        cout << "\n=================================\n";
        cout << "       Nao ha clientes na fila";
        cout << "\n=================================\n";
    }
    
}

int main()
{
    qLST lst;
    Queue *fila = new Queue;
    fila->first = NULL;
    fila->last = NULL;
    int choice;

    do 
    {
        cout << "Menu:\n";
        cout << "1. Adicionar cliente a fila\n";
        cout << "2. Atender cliente\n";
        cout << "3. Exibir clientes na fila\n";
        cout << "4. Liberar memoria da fila\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
                insertClient(fila);
                break;
            case 2:
                attendClient(fila);
                break;
            case 3:
                if(fila->first == NULL){
                    cout << "\n=================================\n";
                    cout << "       Nao ha clientes na fila";
                    cout << "\n=================================\n";
                }else{
                    lst.display(fila);
                }
                break;
            case 4:
                break;
            case 0:
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
        cout << endl; 
    } while (choice != 0);



    return 0;
}