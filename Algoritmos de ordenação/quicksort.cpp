

void print_vec(int vec[], int size){
    for(int i = 0; i < size; i++){
        cout << "\nPosicão [" << i <<"]: " << vec[i];
    }
}

void swap(int vec[], int i, int j){
    int aux = vec[j];
    vec[j] = vec[i],
    vec[i] = aux; 
}

void line(){
    cout << "\n==============================\n";
}

int partition(int vec[], int start, int end){
    int pivot = vec[end];
    int i = (start-1);

    for(int j = start; j < end; j++){
        if(vec[j] <= pivot){
            i++;
            swap(vec, i, j);
        }
    }
    swap(vec, i+1, end);

    return (i + 1);
}


void quicksort(int vec[], int start, int end){
    if(start >= end) return;

    int pivot = partition(vec, start, end);

    quicksort(vec, start, pivot -1);
    quicksort(vec, pivot+ 1, end);

}

int main(){
    int vec[] = {18, 34, 123, 6, 45, 0, 12, 76, 90, 9};
    print_vec(vec, 10);
    cout << "\n==============================\n";
    quicksort(vec, 0, 9);
    print_vec(vec, 10);

    return 0;
}