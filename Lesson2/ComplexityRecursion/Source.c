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

int divisionByTwo(int dec);
void toBinary();
void toPower();
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
	;
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

void menu() {
	printf("\n1 - ������� �� ���������� ������� � ��������\n");
	printf("2 - ���������� ����� � �������\n");
	printf("0 - exit\n");
}