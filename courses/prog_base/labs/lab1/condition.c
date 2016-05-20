#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int satisfies(int, int, int);

int main() {
    int a = 0, b = 0, c = 0; 
    int result;
    result = satisfies(a, b, c);
    printf("%i", result);
    return 0;
}


int satisfies(int a, int b, int c) {
	int result;

	int modmin = 0, sum2 = 0, max = 0, min = 0;
	
	//Якщо всі числа (a, b, c) від’ємні то:
	if (a < 0 && b < 0 && c < 0) {
		//Знайти найменше число modmin
		if (a < b && a < c) {
			//Знайти модуль найменшого числа (modmin)
			modmin = abs(a);
			//Знайти суму двох інших чисел (sum2);
			sum2 = b + c;
		}
		else if (b < a && b < c) {
			modmin = abs(b);
			sum2 = a + c;
		}
		else if (c < a && c < b) {
			modmin = abs(c);
			sum2 = a + b;
		}
		else {
			result = 0;
		}
		//Якщо sum2 менше -256, а modmin є степенню двійки і modmin менше 256 то результат буде True
		if (sum2 < -256 && (log2(modmin)-(int)log2(modmin))==0 && modmin < 256) {
			result = 1;
		}
		//Результат: True якщо модуль sum2 більше 16 або modmin більше 8;
		if (abs(sum2) > 16 || abs(modmin) > 8 ) {
				result = 1;
			} 
		else {
				result = 0;
			}
	}
	//Якщо не всі числа додатні (0 вважати додатнім) то:
	else if (a < 0 || b < 0 || c < 0) {
		//Якщо тільки одне з них від’ємне то:
		if (a < 0 && b > 0 && c > 0) {
			//Результат - чи це від’ємне число більше -256
			// замінити тернарним оператором
			return a>-256; 
		//	 {
		//		result = 1;
		//	}
		//	else {
		//		result = 0;
		//	}
		}
		else if (a > 0 && b < 0 && c > 0) {
			if (b > -256) {
				result = 1;
			}
			else {
				result = 0;
			}
		}
		else if (a > 0 && b > 0 && c < 0) {
			if (c > -256) {
				result = 1;
			}
			else {
				result = 0;
			}
		}
		//Якщо два від’ємних числа то:
		else if (a < 0 && b < 0 && c > 0) {
			//Результат - чи сума цих двох від’ємних чисел помножена на суму n0 i n1 більша за -256
			if (((a + b)*(3 + 2))>-256) {
				result = 1;
			}
		}
		else if (a < 0 && b > 0 && c < 0) {
			if (((a + c)*(3 + 2))>-256) {
				result = 1;
			}
		}
		else if (a > 0 && b < 0 && c < 0) {
			if (((b + c)*(3 + 2))>-256) {
				result = 1;
			}
		}
		else {
			result = 0;
		}
	}

	//Якщо всі числа додатні (0 вважати додатнім) то:
	else if (a >= 0 && b >= 0 && c >= 0) {
		//Знайти максимальне (max) з цих чисел
		if (a > b && a > c) {
			max = a;
		}
		else if (b > a && b > c) {
			max = b;
		}
		else if (c > a && c > b) {
			max = c;
		}
		else {
			result = 0;
		}
		//Знайти мінімальне (min) з цих чисел
		if (a < b && a < c) {
			min = a;
		}
		else if (b < a && b < c) {
			min = b;
		}
		else if (c < a && c < b) {
			min = c;
		}
		else {
			result = 0;
		}
		//Результат: чи max - min більше 32;
		if ((max - min) > 32) {
			result = 1;
		}
		else {
			result = 0;
		}
	}
	//just else
	else {
		result = 0;
	}

	return result;
}