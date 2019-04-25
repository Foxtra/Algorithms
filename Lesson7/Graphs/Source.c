/*
1. �������� �������, ������� ��������� ������� ��������� �� ����� � ������� �� �� �����.
2. �������� ����������� ������� ������ ����� � �������.
3. �������� ������� ������ ����� � ������.
4. *������� ���������� ������� ��� ������ � �������.

������ ������
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
				printf("�������� ����. ���������\n");
		}
	} while (sel != 0);
	return 0;
}

//����� �������� � ������ �������
void loadAndPrint() {
	printf("�� ����� ��������� ��������� �������:");
	printMatrix(loadMatrix("matrix.txt"));
}

//������� �������� ������� �� �����
int* loadMatrix(char* path) {
	int static myArray[arrSize][arrSize];
	int checkOfEnd = 0, numOfStr = 0, numOfRow = 0;
	FILE *in;
	in = fopen(path, "r");
	if (in == NULL) {
		printf("������ ��� �������� �����.");
		return NULL;
	}
	int value;
	checkOfEnd = fscanf(in, "%d", &value);
	if (checkOfEnd == EOF)
		printf("���� ����!\n");
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

//������� ������ ������� �� �����
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
	printf("\n�� ���������� � �������� ����\n");
	printf("1 - ������� �� ����� � ������� �� ����� ������� ���������\n");
	printf("2 - \n");
	printf("3 - \n");
	printf("0 - exit\n");
}