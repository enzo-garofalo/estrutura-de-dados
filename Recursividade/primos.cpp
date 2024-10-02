/*
Fazer um programa com função recursiva que
retorna se um inteiro é ou não primo.
*/
#include <iostream>
#include <math.h>
using namespace std;

bool primo(int num, int divisor){
    if(divisor == 1) return false;
    if(num%divisor == 0) return true;
    return primo(num, (divisor-1));
}

int main(){
    int num;
    cout << "Digite um inteiro: ";
    cin >> num;

    if(num <= 1){
        cout << "Não eh primo!";
    }else if(primo(num, sqrt(num))){
        cout << num <<" Nao Eh primo!";
    }else{
        cout << num <<" Eh primo!";
    }
    return 0;
}