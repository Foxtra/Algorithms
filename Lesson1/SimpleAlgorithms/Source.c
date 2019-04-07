/*
1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); 
где m-масса тела в килограммах, h - рост в метрах.
2. Найти максимальное из четырех чисел. Массивы не использовать.
3. Написать программу обмена значениями двух целочисленных переменных:
a. с использованием третьей переменной;
b. *без использования третьей переменной.
4. Написать программу нахождения корней заданного квадратного уравнения.
5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). Требуется определить, 
относятся поля к одному цвету или нет.
8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, 
найти частное от деления нацело N на K, а также остаток от этого деления.
10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, 
имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, 
оканчивающихся на 8.
12. Написать функцию нахождения максимального из трех чисел.
13. * Написать функцию, генерирующую случайное число от 1 до 100.
а) с использованием стандартной функции rand()
б) без использования стандартной функции rand()
14. *Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. 
Например, 25^2 = 625. Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа, 
не превосходящие N.

Сергей Ткачев

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
					printf("Неверный ввод. Повторите\n");
		}
	} while (sel != 0);
	return 0;
}

void bmi() {
	float mass = 0;
	float height = 0;
	float index = 0;
	printf("Для рассчёта индекса массы тела введите\n");
	printf("Вес в кг: ");
	scanf("%f", &mass);
	printf("Рост в cм: ");
	scanf("%f", &height);
	height /= 100;
	index = mass / (height*height);
	printf("Индекс массы тела = %.2f \n",index);
}

void maxOfFourNumbers() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int max = 0;
	printf("Для поиска максимального введите 4 целых числа через пробел\n");
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
		printf("Не удалось определить наибольшее из чисел. \n");
	else
		printf("Наибольшее число: %d \n", max);
}

void changeValues() {
	int a = 0;
	int b = 0;
	int c = 0;
	printf("Для обмена переменных позначению введите\n");
	printf("а = ");
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
	printf("Введите коэффициенты квадратного уравнения ax2 + bx + c = 0 через пробел\n");
	printf("а = ");
	scanf("%f", &a);
	printf("b = ");
	scanf("%f", &b);
	printf("с = ");
	scanf("%f", &c);

	D = (b * b) - (4 * a * c);
	printf("Дискриминант уравнения = %.2f\n", D);
	if (D > 0)
	{
		D = sqrt(D);
		x1 = (-b + D) / (2 * a);
		x2 = (-b - D) / (2 * a);
		printf("Уравнение имеет два корня:\n");
		printf("x1 = %.2f \n", x1);
		printf("x2 = %.2f \n", x2);
	}
	else if(D < 0)
		printf("Уравнение не имеет корней\n");
	else {
		x1 = (-b) / (2 * a);
		printf("Уравнение имеет один корень:\n");
		printf("x1 = %.2f \n", x1);
	}
}

void getTimeOfTheYear() {
	int month = 0;
	printf("Введите месяц числом, чтобы определить время года\n");
	printf("месяц = ");
	scanf("%d", &month);

	if (month > 2 && month < 6)
		printf("На дворе весна\n");
	else if (month > 5 && month < 9)
		printf("На дворе лето\n");
	else if (month > 8 && month < 12)
		printf("На дворе осень\n");
	else if ((month > 0 && month < 3) || month == 12)
		printf("На дворе зима\n");
	else {
		printf("Месяц введён некорректно\n");
	}
}

void useRightFormOfWord() {
	int age = 0;
	printf("Введите возраст человека от 0 до 150, чтобы узнать правильно склонение\n");
	printf("возраст = ");
	scanf("%d", &age);

	// Год, когда заканчивается на один, кроме 11.
	if (age % 10 == 1 && age != 11) printf("год\n ");
	else
		// Года
		if ((age >= 2 && age <= 4) || (age >= 22 && age <= 24) || (age >= 32 && age <= 34) || (age > 41 && age < 45)) printf("года\n ");
		else
			// Лет
			if ((age == 11) || (age >= 5 && age <= 20) || (age >= 25 && age <= 30) || (age >= 35 && age < 41) || (age > 44 && age < 51)) printf("лет\n ");
}

void checkColorOfCell() {
	int firstEven = 0;
	int secondEven = 0;
	int y2 = 0;
	int y1 = 0;
	int x1 = 0;
	int x2 = 0;
	printf("Введите координаты первой клетки x1 y1: ");
	scanf("%d %d", &x1, &y1);
	printf("Введите координаты второй клетки x2 y2: ");
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
		printf("Клетки одного цвета\n");
	else
		printf("Клетки разных цветов\n");
}

void powerFromAtoB() {
	int a = 0;
	int b = 0;
	int pOfTwo = 0;
	int pOfThree = 0;
	printf("Введите числа a b через пробел: ");
	scanf("%d %d", &a, &b);

	for (int i = a; i <= b; i++)
	{
		pOfTwo = i * i;
		pOfThree = pOfTwo * i;
		printf("квадрат числа %d = %d, ", i, pOfTwo);
		printf("куб = %d\n", pOfThree);
	}
}

void divisionNonK() {
	int N = 0;
	int K = 0;
	int remainder = 0;
	int result = 0;
	int count = 0;
	printf("Введите числа N и K через пробел: ");
	scanf("%d %d", &N, &K);

	while (N >= K)
	{
		N -= K;
		count++;
	}

	printf("N / K = %d и %d в остатке \n", count, N);
}

void isOddNumberHere() {
	int N = 0;
	int checkOdd = 0;
	int remainder = 0;
	printf("Введите число N (> 0): ");
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

	printf("Чтобы посчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8, - вводите числа по одному, для завершения введите 0:\n");
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
	printf("Среднее арифметическое: %.2f\n", average);
}

void maxOfThree() {
	
	int myArr[arrLength] = { 0 };
	int max = 0;

	printf("Введите три целых числа через пробел: ");
	for (int i = 0; i < arrLength; i++)
	{
		scanf("%d", myArr + i);
	}
	for (int i = 0; i < arrLength; i++)
	{
		if (myArr[i] > max)
			max = myArr[i];
	}
	printf("Максимальное значение: %d\n", max);
}

void randNumber() {   
	srand(time(NULL));
	int x, a, b, m;
	m = 100;
	b = 3;
	a = 2;
	x = rand() % 100;
	x = (a * x + b) % m;
	printf("Случайное число %d \n", x);
}

void amorphNumber() {
	int N;
	int checkAmorph = 0;
	int temp = 0;
	int remainder = 0;
	int countOfTens = 0;
	int powTwo = 0;
	int multiplier = 1;
	printf("Введите целое положительное число: ");
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
			printf("Квадрат числа %d равняется %d \n", i, powTwo);
		countOfTens = 0;
		multiplier = 1;
	}
	
}

void menu() {
	printf("\n1 - Рассчёт индекса массы\n");
	printf("2 - Поиск максимального из четырёх чисел\n");
	printf("3 - Обмен значениями\n");
	printf("4 - Поиск корней квадратного уравнения\n");
	printf("5 - Определение времени года по месяцу\n");
	printf("6 - Склонение слова \"лет\" \n");
	printf("7 - Определение цвета клетки на шахматной доске \n");
	printf("8 - Вывод квадратов и кубов чисел от a до b \n");
	printf("9 - Поиск частного от деления N на K, а также остаток, используя только сложение и вычитание. \n");
	printf("10 - Определить, имеются ли в записи числа N нечетные цифры. \n");
	printf("11 - Среднее арифметическое чисел, оканчивающихся на 8. \n");
	printf("12 - Поиск максимального из трех чисел. \n");
	printf("13 - Генерация случайного числа от 0 до 100. \n");
	printf("14 - Вывод на экран всех автоморфных чисел, не превосходящих введённого. \n");
	printf("0 - exit\n");
}