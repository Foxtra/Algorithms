/*
1. ����������� ������� �������� �� ���������� ������� � ��������, ��������� ��������.
2. ����������� ������� ���������� ����� a � ������� b:
a. ��� ��������;
b. ����������;
c. *����������, ��������� �������� �������� �������.
3. ����������� ���� � ������� �������� ���������� �������: �� �����, ���������� �������, � ����������.

������ ������
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
				printf("�������� ����. ���������\n");
		}
	} while (sel != 0);
	return 0;
}

void toBinary() {
	int decimal = 0;
	printf("������� ���������� �����: ");
	scanf("%d", &decimal);
	printf("�������� �����: ");
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
	printf("������� ����� �����: ");
	scanf("%d", &a);
	printf("������� ������� ��� ����������: ");
	scanf("%d", &b);
	printf("���������: %d", multiple(a, b, a));
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
	printf("\n1 - �������� ��� ��������� ������, ������� 10.\n");
	do {
		printf("\n1 - �� �����\n");
		printf("2 - ��������\n");
		printf("3 - � ����������\n");
		printf("0 - ��� ���������� ������ ������������\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			f = fopen("array.txt", "r");
			if (f == NULL) {
				printf("�� ������� ������� ����");
				break;
			}
			printf("���������� ������ �� �����:\n");
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
			printf("������� �� ������ �������� �������:\n");
			for (int i = 0; i < arrLength; i++)
			{
				printf("%d: ", i);
				scanf("%d", &myArr[i]);
			}
			printf("��� ������: [ ");
			for (int i = 0; i < arrLength; i++)
			{
				printf("%d ", *(myArr + i));
			}
			printf("] \n");
			break;
		default:
			if (select != 0)
				printf("�������� ����. ���������\n");
		}
	} while (select != 0);
}

void menu() {
	printf("\n�� � ������� ����.\n");
	printf("1 - ������� �� ���������� ������� � ��������\n");
	printf("2 - ���������� ����� � �������\n");
	printf("3 - ���������� �������\n");
	printf("0 - exit\n");
}