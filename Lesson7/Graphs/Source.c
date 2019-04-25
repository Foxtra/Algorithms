/*
1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.
2. Написать рекурсивную функцию обхода графа в глубину.
3. Написать функцию обхода графа в ширину.
4. *Создать библиотеку функций для работы с графами.

Сергей Ткачёв
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define arrSize 5

void loadAndPrint();
int* loadMatrix(char* path);
void printMatrix(int matrix[arrSize][arrSize]);
void menu();

int main() {
	int sel = 0;
	char * locale = setlocale(LC_ALL, "");
	do {
		menu();
		scanf("%d", &sel);
		switch (sel) {
		case 1:
			loadAndPrint();
			break;
		case 2:
			//();
			break;
		case 3:
			//();
			break;
		default:
			if (sel != 0)
				printf("Неверный ввод. Повторите\n");
		}
	} while (sel != 0);
	return 0;
}

//Вызов загрузки и вывода матрицы
void loadAndPrint() {
	printf("Из файла загружена следующая матрица:");
	printMatrix(loadMatrix("matrix.txt"));
}

//Функция загрузки матрицы из файла
int* loadMatrix(char* path) {
	int static myArray[arrSize][arrSize];
	int checkOfEnd = 0, numOfStr = 0, numOfRow = 0;
	FILE *in;
	in = fopen(path, "r");
	if (in == NULL) {
		printf("Ошибка при открытии файла.");
		return NULL;
	}
	int value;
	checkOfEnd = fscanf(in, "%d", &value);
	if (checkOfEnd == EOF)
		printf("Файл пуст!\n");
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			myArray[i][j] = value;
			checkOfEnd = fscanf(in, "%d", &value);
		}
	}
	
	fclose(in);
	return myArray;
} 

//Функция вывода матрицы на экран
void printMatrix(int matrix[arrSize][arrSize]) {
	printf("\n");
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void menu() {
	printf("\nВы находитесь в основном меню\n");
	printf("1 - Считать из файла и вывести на экран матрицу смежности\n");
	printf("2 - \n");
	printf("3 - \n");
	printf("0 - exit\n");
}