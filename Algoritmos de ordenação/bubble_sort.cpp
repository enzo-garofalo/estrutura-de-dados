#include <iostream>
using namespace std;

void linha(){
    cout << "\n==============================\n";
}


void get_vec(int vec[], int size){
    for(int i = 0; i < size; i++){
        cout << "\nPosição [" << i <<"]: " << vec[i];
    }
}

void swap(int vec[], int i, int j){
    int aux = vec[j];
    vec[j] = vec[i],
    vec[i] = aux; 
}

void bubble_sort(int vec[], int size){
    if(size == 1) return;
    bool trocou = false;
    for(int i = 0; i < size-1; i++){
        if(vec[i] > vec[i+1]){
            swap(vec, i, (i+1));
            trocou = true;
        }
    }

    if (trocou){
        bubble_sort(vec, size-1);
    }else{
        return;
    } 

}

int main(){
    int vec[] = {18, 34, 123, 6, 45, 0, 12, 76, 90, 9};
    get_vec(vec, 10);
    bubble_sort(vec, 10);
    get_vec(vec, 10);

    return 0;
}