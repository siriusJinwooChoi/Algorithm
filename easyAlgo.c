/* 기타문제...(if)
#include <stdio.h>
int main() {
	int grade;
	scanf("%d", &grade);

	if(grade >= 90 && grade <= 100)
		printf("A\n");
	else if(grade >= 80 && grade < 90)
		printf("B\n");
	else if(grade >= 70 && grade < 80)
		printf("C\n");
	else if(grade >= 60 && grade < 70)
		printf("D\n");
	else
		printf("F\n");
	return 0;
}
*/

/* 기타문제2 (if...)
#include <stdio.h>
int main() {
	int n, x, i;
	int arr[10000];
	
	scanf("%d %d", &n, &x);

	for(i=0; i<n; i++) {
		scanf("%d", &arr[i]);
		if(arr[i] < x)
			printf("%d ", arr[i]);
	}
	return 0;
}
*/

/* 기타문제-사칙연산 
#include <stdio.h>
int main() {
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	printf("%d\n", num1+num2);
	printf("%d\n", num1-num2);
	printf("%d\n", num1*num2);
	printf("%d\n", num1/num2);
	printf("%d\n", num1%num2);

	return 0;
}
*/

/* 기타문제-사칙연산 
#include <stdio.h>
int main() {
	double A,B;
	scanf("%lf %lf", &A, &B);
	printf("%.20lf\n", A/B);

	return 0;
}
*/




/* 기타문제-사칙연산 
#include <stdio.h>
int main() {
	int A,B,C;
	scanf("%d %d %d", &A, &B, &C);

	printf("%d\n", (A+B)%C);
	printf("%d\n", (A%C+B%C)%C);
	printf("%d\n", (A*B)%C);
	printf("%d\n", (A%C*B%C)%C);

	return 0;
}
*/

/* 기타문제-for문  
#include <stdio.h>
int main() {
	int n, i, sum=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		sum += i;
	printf("%d\n", sum);

	return 0;
}*/

/* 기타문제- for문
#include <stdio.h>
int main() {
	int i, N;
	scanf("%d", &N);

	for(i=1; i<=9; i++) {
		printf("%d * %d = %d\n", N, i, N * i);
	}
	return 0;
}*/

/* 기타문제- for문 
#include <stdio.h>
int main() {
	int i, j, N;
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		for(j=0; j<=i; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
*/

/* 기타문제- for문
#include <stdio.h>
int main() {
	int i, j, N;
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		for(j=N-1; j>i; j--)
			printf(" ");
		for(j=0; j<=i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
*/

/* 기타문제- for문 
#include <stdio.h>
int main() {
	int i, j, N;
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		for(j=N; j>i; j--)
			printf("*");
		printf("\n");
	}
	return 0;
}
*/

/* 기타문제- for문 
#include <stdio.h>
int main() {
	int i, j, N;
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		for(j=0; j<i; j++)
			printf(" ");
		for(j=N; j>i; j--)
			printf("*");
		printf("\n");
	}
	return 0;
}
*/


/* 기타문제 - for문 */
/*
#include <stdio.h>
int main() {
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	print
}*/