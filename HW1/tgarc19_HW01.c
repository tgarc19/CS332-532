#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void primeOrFactorial(int n){
    //conditions
    //n is a prime number
    //n is not a prime number, return factorial of n
    //n is less than or equal to 1, return invalid input
    int count = 0;
    if(n <= 1){
        printf("invalid input\n");
    }

    for(int i = 2; i <= n; i++){
        if(n%i == 0){
            count++;
        }
    }
    if(count > 1){
        int f = 1;
        for(int i =1; i<n; i++){
            f = f*i;
        }
        printf("%d\n", f);
    }else{
        printf("Prime Number\n");
    }
}

int UABIndexSum(int arr[], int size){
    int indexsum = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] = i){
            indexsum = indexsum + arr[i];
        }
    }
    return indexsum;
}

int* replaceEvenWithZero(int arr[], int size){
    for(int i =0; i < size; i++){
        if(arr[i]%2 == 0){
            arr[i] = 0;
        }
    }
    return arr;
}

bool evenSquare(int n){
    for(int i = 2; i < n ; i=i+2){
       if(i*i == n){
        return true;
       }
    }
    return false;
}

void arrayDetails(int arr[], int size){
    int minvalue;
    int minindex;
    int maxvalue;
    int maxindex;
    int meanvalue;
    int sum = 0;

    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

    for(int i = 0; i < size; i++){
        if(i == 0){
            minvalue = arr[i];
            maxvalue = arr[i];
            minindex = i;
            maxindex = i;
        }else{
            if(arr[i] < minvalue){
                minvalue = arr[i];
                minindex = i;
            }
            if(arr[i] > maxvalue){
                maxvalue = arr[i];
                maxindex = i;
            }
        }
    }

    meanvalue = sum / size;

    static int outputarr[6];
    outputarr[0] = minvalue;
    outputarr[1] = minindex;
    outputarr[2] = maxvalue;
    outputarr[3] = maxindex;
    outputarr[4] = meanvalue;
    outputarr[5] = size;

    // Print the output array
    printf("Array Details:\n");
    printf("Min Value: %d\n", outputarr[0]);
    printf("Min Index: %d\n", outputarr[1]);
    printf("Max Value: %d\n", outputarr[2]);
    printf("Max Index: %d\n", outputarr[3]);
    printf("Mean Value: %d\n", outputarr[4]);
    printf("Size: %d\n", outputarr[5]);
}

int main(){
    // Test primeOrFactorial function
    printf("Testing primeOrFactorial function:\n");
    primeOrFactorial(5);
    primeOrFactorial(4);
    primeOrFactorial(7);
    primeOrFactorial(1);
    primeOrFactorial(-3);
    printf("\n");

    // Test UABIndexSum function
    printf("Testing UABIndexSum function:\n");
    int arr1_uab[] = {1, 2, 3, 3};
    int arr2_uab[] = {0,2,2,4};
    int arr3_uab[] = {3,1,0,4};
    int sum = UABIndexSum(arr1_uab, sizeof(arr1_uab)/sizeof(arr1_uab[0]));
    printf("UABIndexSum for arr1: %d\n", sum);
    sum = UABIndexSum(arr2_uab, sizeof(arr2_uab)/sizeof(arr2_uab[0]));
    printf("UABIndexSum for arr2: %d\n", sum);
    sum = UABIndexSum(arr3_uab, sizeof(arr3_uab)/sizeof(arr3_uab[0]));
    printf("UABIndexSum for arr3: %d\n", sum);
    printf("\n");

    // Test replaceEvenWithZero function
    printf("Testing replaceEvenWithZero function:\n");
    int arr1_even[] = {1, 2, 3, 4};
    int arr2_even[] = {2,4,6};
    int arr3_even[] = {1,3,5};
    int* modifiedArr1 = replaceEvenWithZero(arr1_even, sizeof(arr1_even)/sizeof(arr1_even[0]));
    int* modifiedArr2 = replaceEvenWithZero(arr2_even, sizeof(arr2_even)/sizeof(arr2_even[0]));
    int* modifiedArr3 = replaceEvenWithZero(arr3_even, sizeof(arr3_even)/sizeof(arr3_even[0]));
    printf("Modified arr1: ");
    for(int i = 0; i < sizeof(arr1_even)/sizeof(arr1_even[0]); i++){
        printf("%d ", modifiedArr1[i]);
    }
    printf("\n");
    printf("Modified arr2: ");
    for(int i = 0; i < sizeof(arr2_even)/sizeof(arr2_even[0]); i++){
        printf("%d ", modifiedArr2[i]);
    }
    printf("\n");
    printf("Modified arr3: ");
    for(int i = 0; i < sizeof(arr3_even)/sizeof(arr3_even[0]); i++){
        printf("%d ", modifiedArr3[i]);
    }
    printf("\n");

    // Test evenSquare function
    printf("Testing evenSquare function:\n");
    bool isEvenSquare = evenSquare(16);
    bool isEvenSquare2 = evenSquare(15);
    bool isEvenSquare3 = evenSquare(25);
    bool isEvenSquare4 = evenSquare(36);

    printf("Is 16 a perfect square of an even number? %s\n", isEvenSquare ? "Yes" : "No");
    printf("Is 15 a perfect square of an even number? %s\n", isEvenSquare2 ? "Yes" : "No");
    printf("Is 25 a perfect square of an even number? %s\n", isEvenSquare3 ? "Yes" : "No");
    printf("Is 36 a perfect square of an even number? %s\n", isEvenSquare4 ? "Yes" : "No");

    // Test arrayDetails function
    printf("Testing arrayDetails function:\n");
    int arr1_details[] = {-8,-23,18,103,0,1,-4,631,3,-41,5};
    arrayDetails(arr1_details, sizeof(arr1_details)/sizeof(arr1_details[0]));

    return 0;
}