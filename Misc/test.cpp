#include <stdlib.h>
#include <stdio.h>
#include <cstring>

void fun(int *arr){
    for(int i  = 0 ; i < 2 ; i++){
        for(int j = 0; j < 2 ; j++){
            for(int k = 0 ; k < 2 ; k++){
                printf("%d ", arr[i + (2*j) + (4*k)]);
            }
            printf("\n");
        }
        printf("\n\n\n");
    }
}

int main(){
    int *arr = (int *) malloc(sizeof(int) * 8);

    memset(arr, 1, sizeof(int) * 8);

    fun(arr);

}