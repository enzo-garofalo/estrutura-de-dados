#include <iostream>
using namespace std;


void get_vec(int vec[], int size){
    for(int i = 0; i < size; i++){
        cout << "\nPosição [" << i <<"]: " << vec[i];
    }
}

int check_lengths(int vec[], int size, int pivo, int *len_maior, int *len_menor){
    *len_maior = 0;
    *len_menor = 0;
    for(int i = 1; i < size; i++){
        if(vec[i] <= pivo){
            (*len_maior)++;
        }else{
            (*len_menor)++;
        } 
    }
}
// perguntar para o PC!!!!!
void quicksort(int vec[], int size){
    if(size < 2) return;
    int *len_maior = new int; 
    int *len_menor = new int;
    int pivo = vec[0];

    check_lengths(vec, size, pivo, len_maior, len_menor);

    int maiores[*len_maior];
    int menores[*len_menor];
    for(int i = 1; i < *len_menor; i++){
        if(vec[i] <= pivo) menores[i] = vec[i];
    }
    for(int i = 1; i < *len_maior; i++){
        if(vec[i] > pivo) maiores[i] = vec[i];
    }

    quicksort(menores, *len_menor);  
    quicksort(maiores, *len_maior);
}

int main(){
    int vec[] = {18, 34, 123, 6, 45, 0, 12, 76, 90, 9};
    get_vec(vec, 10);
    cout << "\n==============================\n";
    quicksort(vec, 10);
    get_vec(vec, 10);

    return 0;
}