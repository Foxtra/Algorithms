/*
1. Попробовать оптимизировать пузырьковую сортировку.
Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
Написать функции сортировки, которые возвращают количество операций.
2. *Реализовать шейкерную сортировку.
3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
Функция возвращает индекс найденного элемента или - 1, если элемент не найден.
4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.

Сергей Ткачёв

*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define arrSize 20

void bubbleSort();
int* arrayLoad(char* filename);
void arrPrint(int* myarr);
void swap(int *a, int *b);
void binarySearchInterface();
int binarySearch(int* arrPointer, int goal);
void menu();

//глобальная переменная для демонстрации поиска в отсортированном массиве
int *mya = NULL;

int main() {
	int sel = 0;
	char * locale = setlocale(LC_ALL, "");
	do {
		menu();
		scanf("%d", &sel);
		switch (sel) {
		case 1:
			bubbleSort();
			break;
		case 2:
			binarySearchInterface();
			break;
		default:
			if (sel != 0)
				printf("Неверный ввод. Повторите\n");
		}
	} while (sel != 0);
	return 0;
}

//функция сравнения сортировки пузырьком и её улучшенной версии
void bubbleSort() {
	int *myArr;
	int count = 0;
	myArr = (int*)malloc(arrSize * sizeof(int));
	myArr = arrayLoad("array.txt");
	printf("Загружен массив:");
	arrPrint(myArr);

	for (int i = 0; i < arrSize; i++) {
		count++;
		for (int j = 0; j < arrSize - 1; j++) {
			count += 2;
			if (myArr[j] > myArr[j + 1])
			{
				count++;
				swap(&myArr[j], &myArr[j + 1]);
			}
		}
	}
	printf("Обычная сортировка пузырьком:");
	arrPrint(myArr);
	printf("Выполнена за %d операций \n", count);
	count = 0;
	printf("Снова загрузим массив:");
	myArr = arrayLoad("array.txt");
	arrPrint(myArr);
	for (int i = 0; i < arrSize; i++) {
		count++;
		for (int j = arrSize - 1; j > 0 + i; j--) {
			count += 2;
			if (myArr[j] < myArr[0 + i])
			{
				count++;
				swap(&myArr[j], &myArr[0 + i]);
			}
		}
	}
	printf("Улучшенная сортировка пузырьком:");
	arrPrint(myArr);
	printf("Выполнена за %d операций \n", count);
	mya = myArr;
}

//интерфейс для вызова функции бинарного поиска
void binarySearchInterface() {
	if (mya == NULL) {
		puts("Запускайте эту подпрограмму только после сортировки массива(1)");
		return;
	}
	int search = 0;
	int index = 0;
	printf("Введите элемент, индекс которого хотите узнать: ");
	scanf("%d", &search);
	index = binarySearch(mya, search);
	if (index == -1) {
		puts("Введённый элемент отсутсвует в массиве!");
	}
	else {
		printf("Индекс элемента: %d\n", index);
	}

}

//функция бинарного поиска
int binarySearch(int* arrPointer, int goal) {
	int middle;
	int left = 0;
	int right = arrSize;

	while (right >= left) {
		middle = ((right - left) / 2) + left;
		if (goal == arrPointer[middle])
			return middle;
		else {
			if (goal < arrPointer[middle]) {
				right = --middle;
			}
			else {
				left = ++middle;
			}
		}
	}
	return -1;
}

//функция загрузки массива из файла
int* arrayLoad(char* filename) {
	//объявление static - иначе данные затираются при передаче массива в другую функцию
	int static myArray[arrSize];
	FILE *in;
	in = fopen(filename, "r");
	if (in == NULL) {
		printf("Ошибка при открытии файла.");
		return NULL;
	}
	for (int i = 0; i < arrSize; i++)
		fscanf(in, "%d", &myArray[i]);
	fclose(in);
	return myArray;
}

//функция вывода массива на экран
void arrPrint(int* myarr) {
	printf("\n[ ");
	for (int j = 0; j < arrSize; j++)
	{
		printf("%d ", myarr[j]);
	}
	printf("]\n");
}

//функция перемещения значений двух элементов массива
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void menu() {
	printf("\nВы находисесь в основном меню.\n");
	printf("1 - Сравнение сортировок\n");
	printf("2 - Бинарный поиск\n");
	printf("0 - exit\n");
}