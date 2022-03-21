#include <iostream>

using namespace::std;

int list1 [5000];
int list2 [5000];
int list3 [5000];

int i, j;

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n){
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n){
    int min_idx;
    for (i = 0; i < n - 1; i++){
        min_idx = i;
        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

void insertionSort(int arr[], int n){
    int key;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[]){
    for (i = 0; i < 5000; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    //Initializes lists in reverse order in order to be sorted.
    for (i = 4999; i > -1; i--){
        list1[4999-i] = i;
        list2[4999-i] = i;
        list3[4999-i] = i;
    }

    //Bubble Sorts List 1

    bubbleSort(list1, 5000);
    printArray(list1);

    cout << endl << endl << endl;

    //Selection Sorts List 2

    selectionSort(list2, 5000);
    printArray(list2);

    cout << endl << endl << endl;

    //Insertion Sorts List 3

    insertionSort(list3, 5000);
    printArray(list3);

    return 0;
}