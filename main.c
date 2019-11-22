#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define numbercount 10

double max_value (double *numbers, int length);
double arith_mean(double *numbers, int length);

int main() {
    char intreadout[255] = "";
    double a_mean = 0, biggest_number = 0, entered_numbers[numbercount];

    // printf shows a message asking you to enter a positive number
    printf("\nPlease enter %i positive numbers (f.e. 202 or 45.98) (enter after each number): ", numbercount);

    for (int x = 0; x < numbercount; x++) {
        //scanf writes the input into a string (char array)
        scanf("%s", intreadout);
        // strspan checks how many of the specified character are inside the string and gives an integer
        // strlen checks how long the string (char array) is and gives an integer
        // if they are the same then there are only allowed characters in the string
        if (strspn(intreadout, "0123456789.") == strlen(intreadout)) {
            // write the input into an array
            entered_numbers[x] = (double) atoll(intreadout);
        } else {
            //shows error message
            printf("invalid input");
        }
    }

    //calls function to find the max value of an array
    biggest_number = max_value(entered_numbers,numbercount);

    //calls function to find the arithmetic mean of all the numbers in the array
    a_mean = arith_mean(entered_numbers,numbercount);

    //displays msg
    printf("The arithmetic mean of your 10 numbers is: %.2lf\nThe biggest number given was: %.2lf\n", a_mean, biggest_number);

    //displays all numbers bigger than the arith mean
    printf("All numbers bigger than the arithmetic mean are:");
    //checks each number of the array if it is bigger than the arith mean and if it is it gets displayed
    for (int x = 0; x < numbercount; x++){
        if (entered_numbers[x] > a_mean)
            printf("\n%.2lf",entered_numbers[x]);
    }
}

//searches an array and finds the biggest value
double max_value(double *numbers, int length) {

    //initiates the variable with the first value of the array
    double value = numbers[0];

    //goes through the rest of the array
    for(int x = 1;  x < length; x++){
        //checks if the new value is bigger than the old one and if so it overrides the variable
        if (value < numbers[x])
            value = numbers[x];
    }
    return value;
}

//finds the arithmetic mean of all number inside an array
double arith_mean(double *numbers, int length) {
    //initiates variable
    double a_mean = 0;

    //adds up all numbers
    for (int x = 0; x < length; x++)
        a_mean += numbers[x];

    //calculates the arith mean and returns it
    return a_mean/length;
}