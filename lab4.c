#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>   
#include <math.h>

/*Задание 3*/
void task3(void) {
    printf("Task3\n");
        int n, i, j, sum;

        printf("Enter a natural number n:");
        scanf("%d", &n);
        if ( n <= 1) {
            printf("Error\n");
            return;
        }

        printf("Complete numbers, less for %d:\n", n);
        for (i = 2; i < n; i++) {
            sum = 0;
            for (j = 1; j <= i / 2; j++) {
                if (i % j == 0) {
                    sum += j;
                }
            }
            if (sum == i) {
                printf("%d ", i);
            }
        }
        printf("\n");
}
/*Задание 10*/
void task10(void) {
        int pounds;
        printf("Pounds\tKilograms\n");
        printf("-------------------\n");
        for (pounds = 1; pounds <= 10; pounds++) {
            double kg = pounds * 0.453;
            printf("%d\t%.3f\n", pounds, kg);
        }
}
/*Задание 29*/
void task29(void) {
    double a, P = 1.0;
    int n, i;

    printf("Enter the real number a and natural number n: ");
    scanf("%lf %d", &a, &n);
    if ( n <= 0) {
        printf("Error in input.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        P *= (a + i);
    }

    printf("Result P = %.4lf\n", P);
}
/*Задание:65.*/
void task65(void) {
	int n, i;
	unsigned long long factorial = 1;
	printf("Enter a natural number n: ");
	scanf("%d", &n);
	if (n <= 0) {
		printf("Error: Enter a natural number n.\n");
		return;
	}
	for (i = 1; i <= n; i++) {
		factorial *= i;
	}
	printf("Factorial of %d = %llu\n", n, factorial);
}
/*Задание 66*/
void task66(void) {
	double a, result = 1.0;
	int n, i;
	printf("Enter a real number a and a natural number n: ");
	scanf("%lf %d", &a, &n);
	if (n <= 0) {
		printf("Error: Exponent must be a natural number.\n");
		return;
	}
	for (i = 0; i < n; i++) {
		result *= a;
	}
	printf("%.4lf ^ %d = %.4lf\n", a, n, result);
}
/*Задание 127*/
void task127(void) {
    int a, b;
    printf("Task127\n");
    for (a = 1; a < 10; a++) {
        b = 10 - a;
        if (a * a + b * b == 58) {
            printf("The numbers are: %d and %d\n", a, b);
            return;
        }
    }
}
         
/*Задание 162*/
void task162(void) {
    printf("Task 162\n");
    long long n, temp;
    int digit;
    int sign = 1;
    long long sumA = 0;
    long long sumB = 0;

    printf("Enter a natural number: ");
    scanf("%lld", &n);

    temp = n;
    while (temp > 0) {
        digit = temp % 10;
        sumA += sign * digit;
        sign = -sign;
        temp /= 10;
    }

    int start_sign = -sign;
    temp = n;
    while (temp > 0) {
        digit = temp % 10;
        sumB += start_sign * digit;
        start_sign = -start_sign;
        temp /= 10;
    }

    printf("a) Signed sum of younger digits (a0 - a1 + ...): %lld\n", sumA);
    printf("b) Signed sum of older digits (ak - ak-1 + ...): %lld\n\n", sumB);
} 
/*Задание 171*/
void task171(void) {
        double height, new_s;
		double short_s = 0.0, tall_s = 0.0;
        int rank = 1;
        int i;
        int equal = 0;

        printf("Enter the height of the new student (in cm):");
        scanf("%lf", &new_s);

        printf("Enter the heights of 15 students in descending order (in cm):\n");
        for (i = 0; i < 15; i++) {
            scanf("%lf", &height);
			tall_s = (i == 0) * height + (i != 0) * tall_s;
			short_s = (i == 14) * height + (i != 14) * short_s;
            rank += (new_s < height);
            equal += (new_s == height);
        }
        int check = (new_s < tall_s) * (new_s > short_s) * (equal == 0);
        int final = rank * check;

        printf("The new student will occupy position %d in the list. If position = 0, then conditions are incorrect\n", final);
}
/*Задание 218*/
void task218(void) {
	double eps;
    double a_prev = 0.0;
    double a_curr;
    int n = 1;

    printf("Enter the precision eps (e.g., 0.001): ");
    scanf("%lf", &eps);
    if (eps <= 0) {
        printf("Input error.\n");
        return;
    }

    printf("n = %d: a_%d = %.6lf\n", n, n, a_prev);

    do {
        n++;
        a_curr = exp(-a_prev);
        printf("n = %d: a_%d = %.6lf\n", n, n, a_curr);

        double diff = fabs(a_curr - a_prev);
        a_prev = a_curr;
    } while (diff >= eps);

    printf("\nThe smallest index n = %d\n", n);
}
/*Задание 234*/
void task234(void) {
	double a, b, x, fx;
	printf("Enter the interval [a, b]\n");
    scanf("%lf %lf", &a, &b);
    if (a > b || a < 0) {
		printf("Input error.\n");
		return;
	}
	printf("x\tF(x)\n");
	printf("-------------------\n");
	for (x = a; x <= b; x += 4) {
		fx = sqrt(x)*pow(cos(x), 2);
		printf("%.4lf\t%.4lf\n", x, fx);
	}
}
int main(void) {
    task3();
    task10();
    task29();
    task65();
    task66();
    task127();
    task162();
    task171();
    task218();
    task234();

    return 0;
}