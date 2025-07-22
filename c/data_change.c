#include <stdio.h>
void data_change(int* array,int len){
    for(int i = 0; i < len; i++){
        array[i] = array[i] * 2; // Example operation: double each element
    }
}

int main(){
    int myArray[5] = {1, 2, 3, 4, 5};
    int length = sizeof(myArray) / sizeof(myArray[0]);

    data_change(myArray, length);

    // Output the modified array
    for(int i = 0; i < length; i++){
        printf("%d ", myArray[i]);
    }
    
    return 0;
}