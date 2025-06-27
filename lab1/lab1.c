#include <stdio.h>

// you can compile this program using the command:
// gcc -o lab1 lab1.c
// and run it using the command:
// ./lab1
int main(){
    int given_number = 10;
    scanf("%d", &given_number);
    for(int i = 2; i < given_number; i++) {
        if(given_number % i == 0) {
            printf("%d is not a prime number.\n", given_number);
            return 0;
        }
    }
    printf("%d is a prime number.\n", given_number);
    return 0;
}