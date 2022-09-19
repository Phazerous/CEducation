#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int nums[10]; // массив для проверки использованности цифр

void initialize();
int removeRepeatingDigits(int num);

int main(void) {
	initialize();

	printf("Input a number: ");

	int num;

	if (scanf("%d", &num) != 1) {
		printf("Invalid input");
		return -1;
	}

	printf("%d", removeRepeatingDigits(num));

	return 0;
}

void initialize() {
	for (int i = 0; i < 10; i++) {
		nums[i] = 0;
	}
}

int removeRepeatingDigits(int num) {
	int i = 0; // разряд числа
	int digit; // текущая цифра
	int result = 0; // конечное число

	while (num) {
		digit = num % 10;

		if (!nums[digit]) { // проверка, если число уже использовано
			result += digit * pow(10, i); //добавляем цифру в нужном разряде к конечному числу
			nums[digit] = 1; // теперь цифра будет являться использованной
			i++; //увеличиваем разряд числа
		}

		num /= 10;
	}

	return result;
}