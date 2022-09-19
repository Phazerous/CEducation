#include <stdio.h>

int removeDublicates(int num);

int main()
{
    int num;

    printf("Input a number: \n> ");

    if (scanf("%d", &num) != 1) {
        printf("Something went wrong");
        return -1;
    }

    printf("%d", removeDublicates(num));

    return 0;
}

int removeDublicates(int num) {
    int digits[10]; // цифры числа
    int used[10]; // использованные цифры

    int isNegative = 0;
    int result = 0;

    int i = 0;

    for (int i = 0; i < 10; i++) {
        used[i] = 0;
        digits[i] = 0;
    }

    if (num < 0) { // Проверка, если число является отрицательным
        isNegative = 1; // Ставим флаг отрицательности
        num *= -1;
    }

    while (num) { // Заполнить массив цифрами в том же самом порядке, в котором они поступили на ввод
        digits[9 - i] = num % 10;
        i++;
        num /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (digits[i] == 0 && result == 0) continue; // Если есть ведущие нули, то мы их не считаем

        if (!used[digits[i]]) { // Проверяем, если число еще не использовано
            result = 10 * result + digits[i]; // Делаем сдвиг налево и прибавляем справа текущее число
            used[digits[i]] = 1; // Отмечаем, что число было использовано
        }
    }

    if (isNegative) { // Если изначально было отрицательное число, то мы и возвращаем отрицательное
        result *= -1;
    }

    return result;
}
