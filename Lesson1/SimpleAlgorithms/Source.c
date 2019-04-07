/*
1. ������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h); 
��� m-����� ���� � �����������, h - ���� � ������.
2. ����� ������������ �� ������� �����. ������� �� ������������.
3. �������� ��������� ������ ���������� ���� ������������� ����������:
a. � �������������� ������� ����������;
b. *��� ������������� ������� ����������.
4. �������� ��������� ���������� ������ ��������� ����������� ���������.
5. � ���������� �������� ����� ������. ��������� ����������, � ������ ������� ���� �� ���������.
6. ������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����.
7. � ���������� �������� �������� ���������� ���� ����� ��������� ����� (x1,y1,x2,y2). ��������� ����������, 
��������� ���� � ������ ����� ��� ���.
8. ������ a � b � ������� �������� � ���� ����� �� a �� b.
9. ���� ����� ������������� ����� N � K. ��������� ������ �������� �������� � ���������, 
����� ������� �� ������� ������ N �� K, � ����� ������� �� ����� �������.
10. ���� ����� ����� N (> 0). � ������� �������� ������� ������ � ������ ������� �� ������� ����������, 
������� �� � ������ ����� N �������� �����. ���� �������, �� ������� True, ���� ��� � ������� False.
11. � ���������� �������� �����, ���� �� ����� ������ 0. ���������� ������� �������������� ���� ������������� ������ �����, 
�������������� �� 8.
12. �������� ������� ���������� ������������� �� ���� �����.
13. * �������� �������, ������������ ��������� ����� �� 1 �� 100.
�) � �������������� ����������� ������� rand()
�) ��� ������������� ����������� ������� rand()
14. *����������� �����. ����������� ����� ���������� �����������, ���� ��� ����� ��������� ������ ������ ��������. 
��������, 25^2 = 625. �������� ���������, ������� ������ ����������� ����� N � ������� �� ����� ��� ����������� �����, 
�� ������������� N.

������ ������

*/

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#define arrLength 3

void bmi();
void maxOfFourNumbers();
void changeValues();
void findSquareEquationRoots();
void getTimeOfTheYear();
void useRightFormOfWord();
void checkColorOfCell();
void powerFromAtoB();
void divisionNonK();
void isOddNumberHere();
void average();
void maxOfThree();
void randNumber();
void amorphNumber();
void menu();

int main() {
	int sel = 0;
	char * locale = setlocale(LC_ALL, "");
	do {
		menu();
		scanf("%d", &sel);
		switch (sel) {
			case 1:
				bmi();
				break;
			case 2:
				maxOfFourNumbers();
				break;
			case 3:
				changeValues();
				break;
			case 4:
				findSquareEquationRoots();
				break;
			case 5:
				getTimeOfTheYear();
				break;
			case 6:
				useRightFormOfWord();
				break;
			case 7:
				checkColorOfCell();
				break;
			case 8:
				powerFromAtoB();
				break;
			case 9:
				divisionNonK();
				break;
			case 10:
				isOddNumberHere();
				break;
			case 11:
				average();
				break;
			case 12:
				maxOfThree();
				break;
			case 13:
				randNumber();
				break;
			case 14:
				amorphNumber();
				break;
			default:
				if(sel != 0)
					printf("�������� ����. ���������\n");
		}
	} while (sel != 0);
	return 0;
}

void bmi() {
	float mass = 0;
	float height = 0;
	float index = 0;
	printf("��� �������� ������� ����� ���� �������\n");
	printf("��� � ��: ");
	scanf("%f", &mass);
	printf("���� � c�: ");
	scanf("%f", &height);
	height /= 100;
	index = mass / (height*height);
	printf("������ ����� ���� = %.2f \n",index);
}

void maxOfFourNumbers() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int max = 0;
	printf("��� ������ ������������� ������� 4 ����� ����� ����� ������\n");
	scanf("%d %d %d %d", &a, &b, &c, &d );
	
	if (a > b && a > c && a > d)
		max = a;
	else  if (b > a && b > c && b > d)
		max = b;
	else  if (c > a && c > b && c > d)
		max = c;
	else  if (d > a && d > b && d > c)
		max = d;
	else
		max = -1;
	if (max == -1)
		printf("�� ������� ���������� ���������� �� �����. \n");
	else
		printf("���������� �����: %d \n", max);
}

void changeValues() {
	int a = 0;
	int b = 0;
	int c = 0;
	printf("��� ������ ���������� ���������� �������\n");
	printf("� = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	c = a;
	a = b;
	b = c;
	printf("a = %d \n", a);
	printf("b = %d \n", b);
}

void findSquareEquationRoots() {
	float a = 0;
	float b = 0;
	float c = 0;
	float D = 0;
	float x1 = 0;
	float x2 = 0;
	printf("������� ������������ ����������� ��������� ax2 + bx + c = 0 ����� ������\n");
	printf("� = ");
	scanf("%f", &a);
	printf("b = ");
	scanf("%f", &b);
	printf("� = ");
	scanf("%f", &c);

	D = (b * b) - (4 * a * c);
	printf("������������ ��������� = %.2f\n", D);
	if (D > 0)
	{
		D = sqrt(D);
		x1 = (-b + D) / (2 * a);
		x2 = (-b - D) / (2 * a);
		printf("��������� ����� ��� �����:\n");
		printf("x1 = %.2f \n", x1);
		printf("x2 = %.2f \n", x2);
	}
	else if(D < 0)
		printf("��������� �� ����� ������\n");
	else {
		x1 = (-b) / (2 * a);
		printf("��������� ����� ���� ������:\n");
		printf("x1 = %.2f \n", x1);
	}
}

void getTimeOfTheYear() {
	int month = 0;
	printf("������� ����� ������, ����� ���������� ����� ����\n");
	printf("����� = ");
	scanf("%d", &month);

	if (month > 2 && month < 6)
		printf("�� ����� �����\n");
	else if (month > 5 && month < 9)
		printf("�� ����� ����\n");
	else if (month > 8 && month < 12)
		printf("�� ����� �����\n");
	else if ((month > 0 && month < 3) || month == 12)
		printf("�� ����� ����\n");
	else {
		printf("����� ����� �����������\n");
	}
}

void useRightFormOfWord() {
	int age = 0;
	printf("������� ������� �������� �� 0 �� 150, ����� ������ ��������� ���������\n");
	printf("������� = ");
	scanf("%d", &age);

	// ���, ����� ������������� �� ����, ����� 11.
	if (age % 10 == 1 && age != 11) printf("���\n ");
	else
		// ����
		if ((age >= 2 && age <= 4) || (age >= 22 && age <= 24) || (age >= 32 && age <= 34) || (age > 41 && age < 45)) printf("����\n ");
		else
			// ���
			if ((age == 11) || (age >= 5 && age <= 20) || (age >= 25 && age <= 30) || (age >= 35 && age < 41) || (age > 44 && age < 51)) printf("���\n ");
}

void checkColorOfCell() {
	int firstEven = 0;
	int secondEven = 0;
	int y2 = 0;
	int y1 = 0;
	int x1 = 0;
	int x2 = 0;
	printf("������� ���������� ������ ������ x1 y1: ");
	scanf("%d %d", &x1, &y1);
	printf("������� ���������� ������ ������ x2 y2: ");
	scanf("%d %d", &x2, &y2);
	
	x1 = x1 % 2;
	x2 = x2 % 2;
	y1 = y1 % 2;
	y2 = y2 % 2;

	if (x1 == y1)
		firstEven = 1;
	else
		firstEven = 0;
	if (x2 == y2)
		secondEven = 1;
	else
		secondEven = 0;
	
	if (firstEven == secondEven)
		printf("������ ������ �����\n");
	else
		printf("������ ������ ������\n");
}

void powerFromAtoB() {
	int a = 0;
	int b = 0;
	int pOfTwo = 0;
	int pOfThree = 0;
	printf("������� ����� a b ����� ������: ");
	scanf("%d %d", &a, &b);

	for (int i = a; i <= b; i++)
	{
		pOfTwo = i * i;
		pOfThree = pOfTwo * i;
		printf("������� ����� %d = %d, ", i, pOfTwo);
		printf("��� = %d\n", pOfThree);
	}
}

void divisionNonK() {
	int N = 0;
	int K = 0;
	int remainder = 0;
	int result = 0;
	int count = 0;
	printf("������� ����� N � K ����� ������: ");
	scanf("%d %d", &N, &K);

	while (N >= K)
	{
		N -= K;
		count++;
	}

	printf("N / K = %d � %d � ������� \n", count, N);
}

void isOddNumberHere() {
	int N = 0;
	int checkOdd = 0;
	int remainder = 0;
	printf("������� ����� N (> 0): ");
	scanf("%d", &N);

	while (N > 0)
	{
		remainder = N % 10;
		N /= 10;
		if (remainder % 2) {
			checkOdd = 1;
			break;
		}
	}
	if(checkOdd)
		printf("True\n");
	else
		printf("False\n");
}

void average() {
	float average = 0;
	int checkOdd = 0;
	int remainder = 0;
	int currentNum = 0;
	int count = 0;

	printf("����� ��������� ������� �������������� ���� ������������� ������ �����, �������������� �� 8, - ������� ����� �� ������, ��� ���������� ������� 0:\n");
	do
	{
		scanf("%d", &currentNum);
		if (currentNum > 0) {
			checkOdd = currentNum % 2;
			if (!(checkOdd)) {
				remainder = currentNum % 10;
				if (remainder == 8) {
					average += currentNum;
					count++;
				}
			}
		}
		
	} while (currentNum);

	average /= count;
	printf("������� ��������������: %.2f\n", average);
}

void maxOfThree() {
	
	int myArr[arrLength] = { 0 };
	int max = 0;

	printf("������� ��� ����� ����� ����� ������: ");
	for (int i = 0; i < arrLength; i++)
	{
		scanf("%d", myArr + i);
	}
	for (int i = 0; i < arrLength; i++)
	{
		if (myArr[i] > max)
			max = myArr[i];
	}
	printf("������������ ��������: %d\n", max);
}

void randNumber() {   
	srand(time(NULL));
	int x, a, b, m;
	m = 100;
	b = 3;
	a = 2;
	x = rand() % 100;
	x = (a * x + b) % m;
	printf("��������� ����� %d \n", x);
}

void amorphNumber() {
	int N;
	int checkAmorph = 0;
	int temp = 0;
	int remainder = 0;
	int countOfTens = 0;
	int powTwo = 0;
	int multiplier = 1;
	printf("������� ����� ������������� �����: ");
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		temp = i;
		while (temp > 0) {
			temp /= 10;
			countOfTens++;
		}
		powTwo = i * i;
		for (int j = 0; j < countOfTens; j++)
			multiplier *= 10;
		remainder = powTwo % (multiplier);
		if(remainder == i)
			printf("������� ����� %d ��������� %d \n", i, powTwo);
		countOfTens = 0;
		multiplier = 1;
	}
	
}

void menu() {
	printf("\n1 - ������� ������� �����\n");
	printf("2 - ����� ������������� �� ������ �����\n");
	printf("3 - ����� ����������\n");
	printf("4 - ����� ������ ����������� ���������\n");
	printf("5 - ����������� ������� ���� �� ������\n");
	printf("6 - ��������� ����� \"���\" \n");
	printf("7 - ����������� ����� ������ �� ��������� ����� \n");
	printf("8 - ����� ��������� � ����� ����� �� a �� b \n");
	printf("9 - ����� �������� �� ������� N �� K, � ����� �������, ��������� ������ �������� � ���������. \n");
	printf("10 - ����������, ������� �� � ������ ����� N �������� �����. \n");
	printf("11 - ������� �������������� �����, �������������� �� 8. \n");
	printf("12 - ����� ������������� �� ���� �����. \n");
	printf("13 - ��������� ���������� ����� �� 0 �� 100. \n");
	printf("14 - ����� �� ����� ���� ����������� �����, �� ������������� ���������. \n");
	printf("0 - exit\n");
}