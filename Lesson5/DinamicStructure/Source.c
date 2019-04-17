/*
1. ����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����.
2. �������� � ��������� ����������� ����� �� ������ ������������ ������ �������� �� ��������� ������. 
���� ������ �� ����������, �� ��������� ��������������� ���������. ������������ ������� ��������, 
����� ������ �� ����� ���������� (����������� �������� ���������� ������).
3. �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ ����������. 
������� ���������� ��������� ���������: (), ([])(), {}(), ([{}]), ������������ � )(, ())({), (, ])}), ([(]) ��� ������ [,(,{.
>��������: (2+(2*2)) ��� [2/{5*(4+7)}]
4. *������� �������, ���������� ����������� ������ (�� ���� ������� � ������ ����� ������������ ������, �� ������ ������ ������).
5. **����������� �������� �������� �� ��������� ������ ��������������� ��������� � �����������.
6. *����������� �������.

������ ������
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct TNode
{
	int value;
	struct TNode *next;
};

typedef struct TNode Node;

struct Stack
{
	Node *head;
	int size;
	int maxSize;
};

struct Stack stack;

void Push(int value);
int Pop();
void PrintStack();
void toBinary();
void braketsInterface();
int checkBrakets(char* str);
void pushUnlimetted(int val);
void menu();

int main() {
	int sel = 0;
	char * locale = setlocale(LC_ALL, "");
	stack.head = NULL;
	stack.maxSize = 100;
	do {
		menu();
		scanf("%d", &sel);
		switch (sel) {
		case 1:
			toBinary();
			break;
		case 2:
			braketsInterface();
			break;
		case 3:
			pushUnlimetted(1);
			break;
		default:
			if (sel != 0)
				printf("�������� ����. ���������\n");
		}
	} while (sel != 0);
	return 0;
}

//������� ���������� �������� � ����
void Push(int value) {
	if (stack.size >= stack.maxSize) {
		printf("Error stack size");
		return;
	}
	Node *tmp;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = stack.head;
	stack.head = tmp;
	stack.size++;
}

void pushUnlimetted(int val) {
	while (1)
	{
		Node *tmp;
		tmp = (Node*)malloc(sizeof(Node));
		if (tmp == NULL) { printf("������, ������ �� ��������"); break; }
		tmp->value = val;
		tmp->next = stack.head;
		stack.head = tmp;
		stack.size++;
	}
	printf("������ �����: %d\n", stack.size);
}

//������� ������ �������� �� �����
int Pop() {
	if (stack.size == 0) {
		printf("Stack is empty");
		return;
	}
	Node* next = NULL;
	int value;
	value = stack.head->value;
	next = stack.head;
	stack.head = stack.head->next;
	free(next);
	stack.size--;
	return value;
}

//������� ������ ���� ��������� �����
void PrintStack() {
	Node *current = stack.head;
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
}

//������� �������� � �������� �����, ��������� ����
void toBinary() {
	int decimal = 0;
	int remainder = 0;
	printf("������� ���������� �����: ");
	scanf("%d", &decimal);
	printf("�������� �����: ");
	while (decimal != 1) {
		Push(decimal % 2);
		decimal /= 2;
	}
	printf("1");
	while (stack.size != 0)
	{
		printf("%d", Pop());
	}
	printf("\n");
}

//��������� ��������� � ������� �������� ������������ ������
void braketsInterface() {
 	char string[65];
	printf("������� ��������� ���������: ");
	scanf("%64s", string);
	if (checkBrakets(string)) {
		printf("������������������ �����!\n");
	}
	else {
		printf("������������������ �������� � ��������!\n");
	}
}

//������� �������� ������������ ���������� ���������
int checkBrakets(char* str) {
	int openRound = 0;
	int closeRound = 0;
	int openSquare = 0;
	int closeSquare = 0;
	int openBraces = 0;
	int closeBrases = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '(') {
			openRound++;
		}
		else if (str[i] == '[') {
			openSquare++;
		}
		else if (str[i] == '{') {
			openBraces++;
		}
		else if (str[i] == ')') {
			closeRound++;
			if (closeRound > openRound)
				return 0;
		}
		else if (str[i] == ']') {
			closeSquare++;
			if (closeSquare > openSquare)
				return 0;
		}
		else if (str[i] == '}') {
			closeBrases++;
			if (closeBrases > openBraces)
				return 0;
		}
	}
	if (openBraces > closeBrases || openRound > closeRound || openSquare > closeSquare)
		return 0;
	return 1;
}

void menu() {
	printf("\n�� ���������� � �������� ����\n");
	printf("1 - ������� �� ���������� ������� ��������� � ��������\n");
	printf("2 - ����������� ������������ ��������� ������������������\n");
	printf("3 - ������� ������� ������ ��������� ������\n");
	printf("0 - exit\n");
}