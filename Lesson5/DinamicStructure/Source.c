/*
1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. 
Если память не выделяется, то выводится соответствующее сообщение. Постарайтесь создать ситуацию, 
когда память не будет выделяться (добавлением большого количества данных).
3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. 
Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
>Например: (2+(2*2)) или [2/{5*(4+7)}]
4. *Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, не удаляя первый список).
5. **Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.
6. *Реализовать очередь.

Сергей Ткачёв
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
				printf("Неверный ввод. Повторите\n");
		}
	} while (sel != 0);
	return 0;
}

//Функция добавления элемента в стек
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
		if (tmp == NULL) { printf("Ошибка, память не выделена"); break; }
		tmp->value = val;
		tmp->next = stack.head;
		stack.head = tmp;
		stack.size++;
	}
	printf("Размер стека: %d\n", stack.size);
}

//Функция взятия элемента из стека
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

//Функция вывода всех элементов стека
void PrintStack() {
	Node *current = stack.head;
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
}

//функция перевода в двоичное число, используя стек
void toBinary() {
	int decimal = 0;
	int remainder = 0;
	printf("Введите десятичное число: ");
	scanf("%d", &decimal);
	printf("Двоичное число: ");
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

//Интерфейс обращения к функции проверки правильности скобок
void braketsInterface() {
 	char string[65];
	printf("Введите скобочное выражение: ");
	scanf("%64s", string);
	if (checkBrakets(string)) {
		printf("Последовательность верна!\n");
	}
	else {
		printf("Последовательность записана с ошибками!\n");
	}
}

//Функция проверки правильности скобочного выражения
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
	printf("\nВы находитесь в основном меню\n");
	printf("1 - Перевод из десятичной системы счисления в двоичную\n");
	printf("2 - Определение правильности скобочной последовательности\n");
	printf("3 - Попытка вызвать ошибку выделения памяти\n");
	printf("0 - exit\n");
}