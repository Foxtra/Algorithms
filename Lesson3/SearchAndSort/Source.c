/*
1. ����������� �������������� ����������� ����������.
�������� ���������� �������� ��������� ���������������� � �� ���������������� ���������.
�������� ������� ����������, ������� ���������� ���������� ��������.
2. *����������� ��������� ����������.
3. ����������� �������� �������� ������ � ���� �������, ������� ���������� ��������������� ������.
������� ���������� ������ ���������� �������� ��� - 1, ���� ������� �� ������.
4. *���������� ���������� �������� ��� ������ �� ���������� � �������� ��� � ��������������� ���������� ���������.

������ ������

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

//���������� ���������� ��� ������������ ������ � ��������������� �������
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
				printf("�������� ����. ���������\n");
		}
	} while (sel != 0);
	return 0;
}

//������� ��������� ���������� ��������� � � ���������� ������
void bubbleSort() {
	int *myArr;
	int count = 0;
	myArr = (int*)malloc(arrSize * sizeof(int));
	myArr = arrayLoad("array.txt");
	printf("�������� ������:");
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
	printf("������� ���������� ���������:");
	arrPrint(myArr);
	printf("��������� �� %d �������� \n", count);
	count = 0;
	printf("����� �������� ������:");
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
	printf("���������� ���������� ���������:");
	arrPrint(myArr);
	printf("��������� �� %d �������� \n", count);
	mya = myArr;
}

//��������� ��� ������ ������� ��������� ������
void binarySearchInterface() {
	if (mya == NULL) {
		puts("���������� ��� ������������ ������ ����� ���������� �������(1)");
		return;
	}
	int search = 0;
	int index = 0;
	printf("������� �������, ������ �������� ������ ������: ");
	scanf("%d", &search);
	index = binarySearch(mya, search);
	if (index == -1) {
		puts("�������� ������� ���������� � �������!");
	}
	else {
		printf("������ ��������: %d\n", index);
	}

}

//������� ��������� ������
int binarySearch(int* arrPointer, int goal) {
	int middle;
	int left = 0;
	int right = arrSize;

	middle = right / 2;
	while (right > left) {
		if (goal == arrPointer[middle])
			return middle;
		else {
			if (goal < arrPointer[middle]) {
				right = middle--;
				middle = right / 2;
			}
			else {
				left = middle++;
				middle = ((right - left) / 2) + left;
			}
		}
	}
	return -1;
}

//������� �������� ������� �� �����
int* arrayLoad(char* filename) {
	//���������� static - ����� ������ ���������� ��� �������� ������� � ������ �������
	int static myArray[arrSize];
	FILE *in;
	in = fopen(filename, "r");
	if (in == NULL) {
		printf("������ ��� �������� �����.");
		return NULL;
	}
	for (int i = 0; i < arrSize; i++)
		fscanf(in, "%d", &myArray[i]);
	fclose(in);
	return myArray;
}

//������� ������ ������� �� �����
void arrPrint(int* myarr) {
	printf("\n[ ");
	for (int j = 0; j < arrSize; j++)
	{
		printf("%d ", myarr[j]);
	}
	printf("]\n");
}

//������� ����������� �������� ���� ��������� �������
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void menu() {
	printf("\n�� ���������� � �������� ����.\n");
	printf("1 - ��������� ����������\n");
	printf("2 - �������� �����\n");
	printf("0 - exit\n");
}