/*
1. Реализовать сортировку подсчетом.
2. Реализовать быструю сортировку.
3. *Реализовать сортировку слиянием.
4. **Реализовать алгоритм сортировки со списком.

Проанализировать время работы каждого из вида сортировок для 100, 10000, 1000000 элементов.
Если самостоятельно реализовать сортировку не получается, разрешается найти сортировку в Интернете. 
Желательно прокомментировать строки программы. Записывайте в начало программы условие и свою фамилию. 
Все решения создавайте в одной программе. Снабдите программу меню.

Сергей Ткачёв
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define arrLength0 100
#define arrLength1 1000
#define arrLength2 10000
#define arrLength3 100000

typedef struct Node{
	int data;
	struct Node* next;
} Node;

void countingSort(int *arr, int length);
int findMax(int *arr, int length);
void fillRandArr(int *arr, int length);
void sortInterface(int selection);
void arrPrint(int* myarr, int length);
void quickSort(int* array, int first, int last);
void swap(int* p, int* q);
void mergeSort(int *m, int l, int r);
void mergeArrays(int *m, int l, int r);
void menu();

int main() {
	int sel = 0;
	char * locale = setlocale(LC_ALL, "");
	do {
		menu();
		scanf("%d", &sel);
		switch (sel) {
		case 1:
			sortInterface(1);
			break;
		case 2:
			sortInterface(2);
			break;
		case 3:
			sortInterface(3);
			break;
		default:
			if (sel != 0)
				printf("Неверный ввод. Повторите\n");
		}
	} while (sel != 0);
	return 0;
}

void sortInterface(int selection) {
	int static myArray[arrLength0] = {0};
	Node static arrOfNodes[arrLength0];
	switch (selection)
	{
	case 1:
		fillRandArr(myArray, arrLength0);
		printf("Сгенерирован массив:");
		arrPrint(myArray, arrLength0);
		printf("\nМассив отсортирован при помощи сортировки подсчётом:");
		countingSort(myArray, arrLength0);
		arrPrint(myArray, arrLength0);
		break;
	case 2:
		fillRandArr(myArray, arrLength0);
		printf("Сгенерирован массив:");
		arrPrint(myArray, arrLength0);
		printf("\nМассив отсортирован при помощи быстрой сортировки:");
		quickSort(myArray, 0, arrLength0-1);
		arrPrint(myArray, arrLength0);
		break;
	case 3:
		fillRandArr(myArray, arrLength0);
		printf("Сгенерирован массив:");
		arrPrint(myArray, arrLength0);
		printf("\nМассив отсортирован при помощи сортировки слиянием:");
		mergeSort(myArray, 0, arrLength0 - 1);
		arrPrint(myArray, arrLength0);
		break;
	default:
		break;
	}
}

//Сортировка подсчётом
void countingSort(int *arr, int length) {
	int freqArr[arrLength0];
	int current = 0;
	/*switch (length)
	{
	case arrLength1:
		freqArr[arrLength1];
		break;
	case arrLength2:
		freqArr[arrLength2];
		break;
	case arrLength3:
		freqArr[arrLength3];
		break;
	default:
		printf("С таким размером массива функция не работает!\n");
		break;
	}*/
	//int max = findMax(arr, length);
	for (int i = 0; i < length; i++)
	{
		freqArr[i] = 0;
	}
	for (int i = 0; i < length; i++)
	{
		freqArr[arr[i]]++;
	}
	for (int j = 0; j < length; j++)
		for (int i = 0; i < freqArr[j]; i++)
		{
			arr[current++] = j;
		}
}

int findMax(int *arr, int length) {
	int max = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

//Заполнение массива случайными значениями
void fillRandArr(int *arr, int length) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % length;
		//printf("%d\n", *(arr + i));
	}
}

//функция вывода массива на экран
void arrPrint(int* myarr, int length) {
	printf("\n[ ");
	for (int j = 0; j < length; j++)
	{
		printf("%d ", myarr[j]);
	}
	printf("]\n");
}

//быстрая сортировка
void quickSort(int* array, int first, int last) {
	int middle = array[(first + last) / 2];
	int i = first, j = last;

	do {
		while (array[i] < middle)
			i++;
		while (array[j] > middle)
			j--;

		if (i <= j) {
			if (array[i] > array[j])
				swap(&array[i], &array[j]);
			i++;
			j--;
		} 
	} while (i <= j);

	if (i < last)
		quickSort(array, i, last);
	if (first < j)
		quickSort(array, first, j);
}

//Перестановка значений
void swap(int* p, int* q) {
	int buf;
	buf = *p;
	*p = *q;
	*q = buf;
}

//Сортировка слиянием
void mergeSort(int *m, int l, int r) {
	//int t;
	if(l < r)
		//Обрабатываемый фрагмент состоит более чем из одного элемента
		if (r - l == 1) {
			//Обрабатываемый фрагмент массива состоит из двух элементов
			if (m[r] < m[l]) {
				swap(&m[r], &m[l]);
				/*t = m[l];
				m[l] = m[r];
				m[r] = t;*/
			}
		}
		else {
			//Разбивка заданного фрагмента на два массива
			//Рекурсивный вызов функции mergeSort
			mergeSort(m, l, l + (r - l) / 2);
			mergeSort(m, l + (r - l) / 2 + 1, r);
			//Соединение массивов
			mergeArrays(m, l, r);
		}
}

//Сортировка объединённых подмассивов
void mergeArrays(int *arr, int l, int r) {
	for (int i = l; i < r; i++)
		for (int j = i+1; j <= r; j++)
		{
			if (arr[j] < arr[i])
				swap(&arr[j], &arr[i]);
		}
}

//Сортировка списка
void listCountingSort(Node* A, int length) {
	Node C [arrLength0];
	for (int i = 0; i < length; i++)
	{
		C[i].data = 0;
		C[i].next = NULL;
	}
	for (int i = 0; i < length; i++)
	{
		C[A[i].data].data++;
		C[A[i].data].next = A[i].next;
	}
	int current = 0;
	Node p;
	for (int j = 0; j < length; j++)
	{
		p.next = C[j].next;
		p.data = C[j].data;
		while (p.next != NULL) {
			A[current++].data = p.data;
			p.data = p.next->data;
			p.next = p.next->next;
		}
	}
}

void menu() {
	printf("\nВы находитесь в основном меню\n");
	printf("1 - Сортировка подсчётом\n");
	printf("2 - Быстрая сортировка\n");
	printf("3 - Сортировка слиянием\n");
	printf("4 - Cортировки со списком\n");
	printf("0 - exit\n");
}