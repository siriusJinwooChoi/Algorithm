/*
#include <stdio.h>

int main() {
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	printf("%d\n", num1 * num2);
	return 0;
}

*/

/* m2s */
/*
#include <stdio.h>
int main() {
	int min;
	scanf("%d", &min);
	printf("%d minutes is %d seconds.\n", min, min*60);

	return 0;
}
*/


/* swap */
/*
#include <stdio.h>
void swap(int *n1, int *n2) {
	int tmp;
	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

int main() {
	int num1, num2;
	scanf_s("%d %d", &num1, &num2);

	printf("num1:%d, num2:%d\n", num1, num2);
	swap(&num1, &num2);
	printf("After swap\n=> num1:%d, num2:%d\n", num1, num2);

	return 0;
}
*/
/* op */
/*
#include <stdio.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d+%d=%d\n",a,b,a+b);
	printf("%d-%d=%d\n",a,b,a-b);
	printf("%d*%d=%d\n",a,b,a*b);
	printf("%d/%d=%d\n",a,b,a/b);
	printf("%d%%%d=%d\n",a,b,a%b);

	return 0;
}
*/


/* triangle */
/*
#include <stdio.h>
int main() {
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	printf("%.2f\n", (float)(num1*num2)/2);

	return 0;
}
*/


/* average */
/*
#include <stdio.h>
int main() {
	int n1, n2, n3, n4;

	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

	printf("%.2f\n", (float)(n1+n2+n3+n4)/4);

	return 0;
}
*/


/* CtoF */
/*
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	printf("%.1f\n", ((float)9/5)*n+32);

	return 0;
}
*/
 
/* q/r */
/*
#include <stdio.h>
int main() {
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	printf("%d %d\n", n1/n2, n1%n2);

	return 0;
}
*/

/* change */ // 해결! 50의 자리가 0이 안나오는 문제 해결! 해당부분 주석처리함 .ex)580
/*
#include <stdio.h>
int money[] = {100, 50, 10};

void coin_change(int change) {
	int i=0;
	while(change) {
		//if(change >= money[i]) {
		if (change >= 0) {
			int count = change / money[i];
			change %= money[i];

			if (i == 0)				//100won
				printf("%d ", count);
			else if (i == 1)		//50won
				printf("%d ", count);
			else if (i == 2)		//10won
				printf("%d ", count);
		}
		i++;
	}
	printf("\n");
}
int main() {
	int n, repay;
	scanf_s("%d", &n);
	repay = 1000-n;

	coin_change(repay);

	return 0;
}
*/


/*
#include <stdio.h>
int main() {
	int p, q, i, count=0;
	while(scanf("%d %d", &p, &q) != EOF) {
		for(i = 1; i <= p; i++) {
			if((p % i) == 0) {
				count++;
				if(count == q)
					break;
			}
		}
	}
	if(count < q)
		printf("0\n");
	else
		printf("%d\n", i);
	
	return 0;
	
	int a, b, c;
	while(scanf("%d %d", &a, &b) != EOF) {
		
		printf("%d", c);
	}
}
*/



/* rprint */ 
//reverse print out!! (Using Array)
/*
#include <stdio.h>

int main() {
	int i, N;
	int arr[1000];
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}

	for(i=N-1; i>=0; i--) {
		printf("%d ", arr[i]);
	}
	return 0;
}*/

/* bubble sort */
/*
#include <stdio.h>
int num[1000];
int main() {
	int i, j, cnt, step, temp;
	
	scanf("%d %d", &cnt, &step);

	for(i=0; i<cnt; i++) {
		scanf("%d", &num[i]);
	}

	for(j=0; j<step; j++) {
		for(i=0; i<cnt-1; i++) {
			if(num[i] > num[i+1]) {
				temp = num[i];
				num[i] = num[i+1];
				num[i+1] = temp;
			}
		}
	}
	for(i=0; i<cnt; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");

	return 0;
}*/
