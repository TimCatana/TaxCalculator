#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *   Program Name: taxCalculator.c
 *   Author: Tim Catana
 *   Last Update: December 14, 2019
 *   Function: calculate the tax chunk and the final value given an initial value and a tax value
 *   Compilation: gcc -ansi -o tax taxCalculator.c
 *   Execution: ./tax <initialValue> <tax> 
 */

int main ( int argc, char *argv[] ) {

	int i, j;
	char currentInput[100];
	float initial, tax, taxValue, final;

	system("clear");

	if(argc != 3){
		printf("Excecuton: ./tax <initialValue> <tax>\n");
		exit(0);
	}

	/* throw error if letters are found */
	for(i = 1; i < 3; i++){
		for(j = 0; j < strlen(argv[i]); j++){
			if(isdigit(argv[i][j]) == 0){
				printf("ERROR - no letter allowed\n");
				exit(0);
			}
		}
	}

	initial = atof(argv[1]);
	tax = atof(argv[2]);

	if(tax < 0){
		printf("ERROR - tax must be a number greater than 0\n");
		exit(0);
	}

	/* basic tax caluclation */
	tax *= 0.01; 
	taxValue = initial * tax;
	final = initial + taxValue;

	tax /= 0.01; /* for the sake of the print statements below */

	system("clear");

	printf("Initial value: $%0.2f\n", initial);
	printf("Tax: %0.2f%\n", tax);
	printf("Tax chunk: $%0.2f\n", taxValue);
	printf("Final value: $%0.2f\n", final);

	return ( 0 );
}