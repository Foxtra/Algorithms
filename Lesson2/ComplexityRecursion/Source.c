/*
1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
2. Реализовать функцию возведения числа a в степень b:
a. без рекурсии;
b. рекурсивно;
c. *рекурсивно, используя свойство четности степени.
3. Реализовать меню с выбором варианта заполнения массива: из файла, случайными числами, с клавиатуры.

Сергей Ткачёв
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define arrLength 10

int divisionByTwo(int dec);
void toBinary();
void toPower();
void arrMenu();
void menu();

int main() {
	int sel = 0;
	char * locale = setlocale(LC_ALL, "");
	do {
		menu();
		scanf("%d", &sel);
		switch (sel) {
		case 1:
			toBinary();
			break;
		case 2:
			toPower();
			break;
		case 3:
			arrMenu();
			break;
		default:
			if (sel != 0)
				printf("Неверный ввод. Повторите\n");
		}
	} while (sel != 0);
	return 0;
}

void toBinary() {
	int decimal = 0;
	printf("Введите десятичное число: ");
	scanf("%d", &decimal);
	printf("Двоичное число: ");
	divisionByTwo(decimal);
	printf("\n");
}

int divisionByTwo(int dec) {
	int temp = 0;
	if (dec == 1) {
		printf("1");
		return 1;
	}
	else {
		temp = (divisionByTwo(dec / 2) + dec % (dec / 2));
		printf("%d", temp / 2);
		return temp;
	}
}

void toPower() {
	int a = 0;
	int b = 0;
	printf("Введите целое число: ");
	scanf("%d", &a);
	printf("Введите степень для возведения: ");
	scanf("%d", &b);
	printf("Результат: %d", multiple(a, b, a));
	printf("\n");
}

int multiple(int a, int b, int base) {
	if (b == 1)
		return a;
	else {
		a *= base;
		b--;
		multiple(a, b, base);
	}
}

void arrMenu() {
	srand(time(NULL));
	int select = 0;
	int myArr[arrLength] = { 0 };
	FILE *f;
	printf("\n1 - Выберите как заполнить массив, размера 10.\n");
	do {
		printf("\n1 - из файла\n");
		printf("2 - случайно\n");
		printf("3 - с клавиатуры\n");
		printf("0 - для завершения работы подпрограммы\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			f = fopen("array.txt", "r");
			if (f == NULL) {
				printf("Не удалось открыть файл");
				break;
			}
			printf("Полученный массив из файла:\n");
			printf("[ ");
			for (int i = 0; i < arrLength; i++)
			{
				fscanf(f,"%d", &myArr[i]);
				printf("%d ", *(myArr + i));
			}
			printf("] \n");
			fclose(f);
			break;
		case 2:
			for (int i = 0; i < arrLength; i++)
			{
				myArr[i] = rand() % 100;
				printf("%d\n", *(myArr + i));
			}
			break;
		case 3:
			printf("Вводите по одному элементы массива:\n");
			for (int i = 0; i < arrLength; i++)
			{
				printf("%d: ", i);
				scanf("%d", &myArr[i]);
			}
			printf("Ваш массив: [ ");
			for (int i = 0; i < arrLength; i++)
			{
				printf("%d ", *(myArr + i));
			}
			printf("] \n");
			break;
		default:
			if (select != 0)
				printf("Неверный ввод. Повторите\n");
		}
	} while (select != 0);
}

void menu() {
	printf("\nВы в главном меню.\n");
	printf("1 - Перевод из десятичной системы в двоичную\n");
	printf("2 - Возведение числа в степень\n");
	printf("3 - Заполнение массива\n");
	printf("0 - exit\n");
}