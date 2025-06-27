#include <stdio.h>


int main(){
    printf("Please enter number of elements in the array:\n");
    int n;
    scanf("%d", &n);

    printf("Please enter some numbers (press enter after each element)\n");
    int input[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &input[i]);
    }

    printf("The input array is:\n");
    // Print the input array
    for(int i = 0; i < n; i++){
        printf("%d, ", input[i]);
        if(i % 10 == 9) {
            printf("\n");
        }
    }
    printf("\n");

    int temp, currLoc;
    // Insertion Sort Algorithm
    // The algorithm iterates through the array, and for each element,
    for(int i = 1; i < n; i++){
        currLoc = i;
        while (currLoc > 0 && input[currLoc - 1] > input[currLoc]){
            // Swap the current element with the previous one if it is smaller
            temp = input[currLoc];
            input[currLoc] = input[currLoc - 1];
            input[currLoc - 1] = temp;
            currLoc--;
        }
    }
    printf("The sorted array is:\n");
    // Print the sorted array
    for(int i = 0; i < n; i++){
        printf("%d, ", input[i]);
        if(i % 10 == 9) {
            printf("\n");
        }
    }

    return 0;
}