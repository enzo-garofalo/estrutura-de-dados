#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Node* inicializar(){
    return NULL;
};

// Perguntar, por que devo fazer retorno? 
// tem como isso ser void e fds?
Node* insertAtBeginning(Node *list, int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = list;
    return newNode;
}

void display(Node *list){
    Node *temp = list;
    while (temp !=  NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void search(Node *list, int value){
    Node *temp = list;
    bool found = false;
    while (temp != NULL){
        if(temp->data == value){
            found = true;
            break;
        }
        temp = temp->next;
    }
    if(found){
        cout << value <<" Encontrado!!";
    }else{
        cout << value <<" Nao Encontrado!!";
    }
}

void deleteValue(Node *list, int value){
    Node *preview = NULL;
    Node *temp = list;

    if(temp->data == value){
        list = temp->next;
        delete temp;
        return;
    }

    while(temp != NULL ){
        if(temp->data == value){
            preview->next = temp->next;
            break;
        }
        preview = temp;
        temp = temp->next;
    }
}

void insertAtPosition(Node *list, int value, int position){
    if(position < 1){
        cout << "Impossível alocar na posicao " << position;
        return;
    }else if(position == 1){
        list = insertAtBeginning(list, value);
    }
    
    Node *newNode = new Node();
    newNode->data = value;

    Node *preview = NULL;
    Node *temp = list;

    int position_counter = 0;
    while(position_counter != position){
        preview = temp;
        temp = temp->next;
        position_counter++;
    }

    preview->next = newNode;
    newNode->next = temp;
}

int main(){
    Node *list = inicializar();

    int num_elementos;
    cout << "Digite o número de elementos na lista: ";
    cin >> num_elementos;
    
    //Inserindo Elementos no começo da lista!
    for(int i = 0; i < num_elementos; i++){
        int value;
        cout << "Digite o valor para a posicao ["<< (i) <<"]: ";
        cin >> value;
        list = insertAtBeginning(list, value);   
    }
       // Percorrendo lista
    cout << "--------------------------------------------\n";
    cout << "Lista: ";
    display(list);

    // Inserindo em uma posição específica
    int value, position;
    cout << "--------------------------------------------\n";

    cout << "Digite a posicao para inserir elemento: ";
    cin >> position;
    
    cout << "Digite o elemento: ";
    cin >> value;
    insertAtPosition(list, value, position);

    // Percorrendo lista
    cout << "--------------------------------------------\n";
    cout << "Lista apos insercao: ";
    display(list);

    // Realizando buscas
    cout << "--------------------------------------------\n";
    cout << "Digite um valor para buscar na lista: ";
    cin >> value;
    search(list, value);

    // Removendo ELementos
    cout << "\n--------------------------------------------\n";
    cout << "Digite um valor para deletar da lista: ";
    cin >> value;
    deleteValue(list, value);
    cout << "--------------------------------------------\n";
    cout << "Lista apos remover valor: ";
    display(list);

    return 0;
}