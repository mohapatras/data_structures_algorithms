#include <stdio.h>
#include <iostream>
using namespace std;

void merge(int *A, int l, int m, int r);
void mergeSort(int *A, int l, int r);
void printArray(int *A, int size);

int main(){
    int B[5] = {1,8,3,5,2};
    int size = sizeof(B)/sizeof(B[0]);
    int* A = B; 

    printArray(A,size);
    mergeSort(A,0,size-1);
    printArray(A,size);

    return 0;

}

void merge(int *A, int l, int m, int r){
    int nL = m - l + 1;
    int nR = r - m;
    int L[nL];
    int R[nR];
    int i,j,k;

    for(i = 0; i<nL; i++){
        L[i] = A[l+i];
    }
    for(j = 0; j<nR; j++){
        R[j] = A[m+1+j];
    }

    i=0;
    j=0;
    k=l;

    while(i < nL && j < nR){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<nL){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<nR){
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *A, int l, int r){
    if (l < r){

    int mid = l + (r - l) / 2;
    mergeSort(A, l, mid);
    mergeSort(A, mid+1, r);
    merge(A, l, mid, r);
    }
}

void printArray(int *A, int size){
    int i=0;
    for(i=0; i<size; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


