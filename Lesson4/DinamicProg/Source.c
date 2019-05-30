/*
1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
  > Например, карта:
  > 3 3
  > 1 1 1
  > 0 1 0
  > 0 1 0
2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.

3. *Требуется обойти конем шахматную доску размером NxM, пройдя через все поля доски по одному разу. 
Здесь алгоритм решения такой же, как в задаче о 8 ферзях. Разница только в проверке положения коня. 
(не выполнено) 

Сергей Ткачёв
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define firstWord 10
#define secondWord 10
#define N 3
#define M 3

void Print1(int n, int m, int a[N][M]);
void Print2(int n, int m, int a[firstWord][secondWord]);
void roadWithBarrier();
void LCS();
void menu();

int main() {
	int sel = 0;
	char * locale = setlocale(LC_ALL, "");
	do {
		menu();
		scanf("%d", &sel);
		switch (sel) {
		case 1:
			roadWithBarrier();
			break;
		case 2:
			LCS();
			break;
		default:
			if (sel != 0)
				printf("Неверный ввод. Повторите\n");
		}
	} while (sel != 0);
	return 0;
}

//функция вывода матрицы для обхода с преградами
void Print1(int n, int m, int a[N][M]) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}

//функция вывода матрицы для подпоследоватлеьности
void Print2(int n, int m, int a[firstWord][secondWord]) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}

//функция обхода карты с преградами
void roadWithBarrier() {
	int A[N][M];
	int i, j;
	//Карта запретных клеток, где 0 - запрет, 1 - можно ходить
	int Map[][M] = { 
		{1,1,1},
		{0,1,1},
		{0,1,0} 
	};

	printf("Для заданной карты:\n");
	Print2(N, M, Map);
	printf("Количество маршрутов будет следующим:\n");

	for (j = 0; j < M; j++)
		if(Map[0][j] == 1)
			A[0][j] = 1;
		else
			A[0][j] = 0;
	for (i = 1; i < N; i++)
	{
		if (Map[i][0] == 1)
			A[i][0] = 1;
		else
			A[i][0] = 0;
		for (j = 1; j < M; j++) {
			if (Map[i][j] == 1)
				A[i][j] = A[i][j - 1] + A[i - 1][j];
			else
				A[i][j] = 0;
		}
	}
	Print1(N, M, A);
}

//функция добавления символа к строке
void append(char* s, char c) {
	int len = strlen(s);
	s[len] = c;
	s[len + 1] = '\0';
}

//функция поиска наибольшей общей подпоследовательности
void LCS() {
	char str1[firstWord] =  { 'g','e','e','k','b','r','a','i','n','s' };
	char str2[secondWord] = { 'o', 'g','e','e','k','m','i','n','d','s' };
	int i, j, c;
	int delta = 1;
	int matrix[firstWord][secondWord] = { 0 };
	int maxlen = 0;
	char result[firstWord] = { 0 };

	for (j = 0; j < firstWord; j++)
		if (str2[0] == str1[j]) {
			for (c = 0; c < secondWord; c++)
				matrix[c][j] = 1;
			for (c = j; c < firstWord; c++)
				matrix[j][c] = 1;
		}

	for (i = 1; i < firstWord; i++)
		for (j = 0; j < secondWord; j++)
		{
			if (matrix[i][j] != 0)
				continue;
			if (str2[i] == str1[j]) {
				append(result, str2[i]);
				if (j == 0)
					matrix[i][j] = matrix[i - 1][j] + 1;
				else
					matrix[i][j] = matrix[i - 1][j - 1] + 1;
				for (c = i+1; c < secondWord; c++)
					matrix[c][j] = matrix[i][j];
				for (c = j+1; c < firstWord; c++)
					matrix[i][c] = matrix[i][j];
				while (matrix[i+1][j-delta] == 0)
				{
					for (c = i + 1; c < secondWord; c++)
						matrix[c][j - delta] = matrix[i][j] - 1;
					delta++;
				}
				delta = 1;
				break;
			}
			else {
				matrix[i][j] = matrix[i-1][j-1];
			}
		}
	printf("Для слов 'geekbrains' и 'ogeekminds' вычислена общая подпоследовательность по матрице: \n\n");
	Print2(firstWord, secondWord, matrix);
	printf("Ответ %s\n", result);
}

void menu() {
	printf("\nВы находитесь в основном меню.\n");
	printf("1 - Количество маршрутов с препятствиями\n");
	printf("2 - Наибольшая общая подпоследовательность\n");
	printf("0 - exit\n");
}