#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printPermutation(int [], int, int);
void printArr(int[], int);
void swap(int[], int, int);

int main() {

	char input[MAX];
	int arr[MAX];
	int count = 0;

	printf("Unesi niz cijelih brojeva odvojenih razmakom:\t");
	fgets(input, sizeof(input), stdin);

	char* token = strtok(input, " ");

	while (token != NULL) {
		int num = atoi(token);
		arr[count] = num;
		count++;
		token = strtok(NULL, " ");
	}

	printPermutation(arr, 0, count);

	return 0;
}

void printPermutation(int arr[], int index, int length) {
	if (index == length - 1) { // Dosli smo do posljednjeg elementa niza
		printArr(arr, length);
	}
	for (int i = index; i < length; i++) {
		swap(arr, i, index);
		printPermutation(arr, index + 1, length);
		swap(arr, i, index);
	}
}

void printArr(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}