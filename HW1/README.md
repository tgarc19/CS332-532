#Compilation Instructions:
If you're a make file ```bash make #compiles all the files
make run #runs all the files

If you are not using a make file:
gcc -o *filename* *filename.c* #this would compile the file and spit out an exe file called *filename*
in this case the filename.c is tgarc19_HW1.c which contains:

primeOrFactorial: This function says the input integer is prime or prints the factorial of the input

UABIndexSum: This function gets the sum of all indexes in the inputted array

replaceEvenWithZero: This function replaces even numbers in an array with zeros

evenSquare: This function finds if the integer is an even square (whether it is a product of an even number multiplied to itself)

arrayDetails: This function takes in an array of integers then prints a resulting array for each of it's details: Min Value, # of Elements, Min Index, Mean, Max Value, Max Index.

#Output Screenshot

    Screenshot of a terminal window displaying the output of several C functions being tested. The output includes:

    Testing primeOrFactorial function:
    Prime Number
    6
    Prime Number
    invalid input
    Prime Number
    invalid input
    Prime Number

    Testing UABIndexSum function:
    UABIndexSum for arr1: 6
    UABIndexSum for arr2: 6
    UABIndexSum for arr3: 6

    Testing replaceEvenWithZero function:
    Modified arr1: 1 0 3 0
    Modified arr2: 0 0 0
    Modified arr3: 1 3 5

    Testing evenSquare function:
    Is 16 a perfect square of an even number? Yes
    Is 15 a perfect square of an even number? No
    Is 25 a perfect square of an even number? No
    Is 36 a perfect square of an even number? Yes

    Testing arrayDetails function:
    Array Details:
    Min Value: -41
    Min Index: 9
    Max Value: 631
    Max Index: 7
    Mean Value: 62
    Size: 11

    The environment is a standard code output window with a neutral and informative tone, focusing on displaying the results of function tests for a programming assignment.

#References
none