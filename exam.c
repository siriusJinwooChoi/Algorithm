/* algorithm 1001번-> A+B */
/*
#include <stdio.h>

int main() {
	int num, num2;
	scanf("%d", &num);
	scanf("%d", &num2);
	num = num+num2;
	printf("%d\n", num);

	return 0;
}
*/






/* Algorithm 1003번 -> 피보나치수열 */
/*
#include <stdio.h>

int fibo(int n);
int cnt0=0, cnt1=0;
 
int main() {
	int count, i, num;
	
	scanf("%d", &count);

	for(i = 0; i < count; i++) {
		scanf("%d", &num);
		fibo(num);
		printf("%d %d\n", cnt0, cnt1);
		cnt0=0, cnt1=0;
	}
	return 0;
}

int fibo(int n) {
	if(n == 0)
		cnt0++;
	else if(n == 1)
		cnt1++;
	else
		return fibo(n-1) + fibo(n-2);
}
*/




/* 1009번 분산처리 */
/*
#include <stdio.h>
int main() {
	int arr[10000];
	int i, j, test, data, jegop, sum;
	scanf("%d", &test);

	for(i=0; i<test; i++) {
		sum = 1;
		scanf("%d %d", &data, &jegop);
		for(j=0; j<jegop; j++) {
			sum = (sum * data) % 10;
			if(sum == 0)
				arr[i] = 10;
			else
				arr[i] = sum;
		}
	}

	for(i=0; i<test; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
*/




/* Algorithm 1015번. -> 수열 */
/*
#include <stdio.h>
int main() {
	int i, j, num;
	int arr[51];
	int tmp[51] = {0, };
	scanf("%d", &num);

	for(i=0; i<num; i++) {
		scanf("%d", &arr[i]);
		for(j = 0; j<i; j++) {
			if(arr[j] > arr[i]) {
				tmp[j]++;
			}
			else if(arr[j] <= arr[i]) {
				tmp[i]++;
			}
		}
	}
	for(i = 0; i<num; i++) {
		printf("%d ", tmp[i]);
	}
	return 0;
}
*/

/*
#include <stdio.h>
 
int main(){
    int i, j, n;
    int arr[51], ans[51] = {0, };
 
    scanf("%d", &n);
 
    for(i = 0; i < n; i++){
        scanf("%d", arr+i);
 
        for(j = 0; j < i; j++){
            if(arr[j] > arr[i])
                ans[j] += 1;
            else
                ans[i] += 1;
        }
    }
 
    for(i = 0; i < n; i++)
        printf("%d ", ans[i]);
 
    return 0;
}
*/

/* Algorithm 1026번. -> 보물 */
//A와 B를 정렬 후, 최소/최대 값을 서로 곱해줄것!!
/*
#include <stdio.h>

int main() {
	int i, j, num, temp, S=0;
	int arr_A[101];
	int arr_B[101];

	scanf("%d", &num);
	for(i=0; i<num; i++) {
		scanf("%d", &arr_A[i]);
	}
	
	for(i=0; i<num; i++) {
		scanf("%d", &arr_B[i]);
	}

	for(i=0; i<num; i++) {
		for(j=0; j<i; j++) {
			if(arr_A[j] < arr_A[i]) {
				temp = arr_A[i];
				arr_A[i] = arr_A[j];
				arr_A[j] = temp;
			}
		}
	}

	for(i=0; i<num; i++) {
		for(j=0; j<i; j++) {
			if(arr_B[j] > arr_B[i]) {
				temp = arr_B[i];
				arr_B[i] = arr_B[j];
				arr_B[j] = temp;
			}
		}
	}

	for(i=0; i<num; i++)
		S += arr_A[i] * arr_B[i];
	
	printf("%d\n", S);
	
	return 0;
}
*/









/* Algorithm 1037번. -> 약수 */
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
	int cnt, i, j, result;
	int *num = (int *)malloc(sizeof(int) * 1000000);
	int *temp = (int *)malloc(sizeof(int) * 1000000);

	scanf("%d", &cnt);

	for(i = 0; i < cnt; i++) {
		scanf("%d", &num[i]);
	}
	
	if(cnt == 1)
		result = num[0]*num[0];
	else {
		for(i = 0; i < cnt; i++) {
			for(j = 0; j < cnt-1; j++) {
				if(num[j] < num[j+1]) {
					temp[j] = num[j];
					num[j] = num[j+1];
					num[j+1] = temp[j];
				}
			}
		}
		result = num[0] * num[cnt-1];
	}
	printf("%d\n", result);

	return 0;
}


//다른 풀이방법(1037)
#include <stdio.h>
 
int main (void)
{
    int n, i, ans, max=0, min=1000000;
    int arr[10000]={0,};
     
    scanf("%d", &n);
     
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);    
        if(max<arr[i]) max=arr[i];
        if(min>arr[i]) min=arr[i];
    }
    ans = max * min;
    printf("%d\n", ans);

    return 0;
}
*/


/* Algorithm 1057번 토너먼트 */
/*
#include <stdio.h>
int main() {
	int n, J, H, temp, cnt=0;
	scanf("%d %d %d", &n, &J, &H);

	if(J>H) {		//항상 H가 J보다 크다고 가정!
		temp = J;
		J = H;
		H = temp;
	}

	for(; n>0; n/2) {
		cnt++;
		if(((H-J) == 1) && ((((H+1)/2) - ((J+1)/2)) == 0))
			break;
		J = (J+1) / 2;
		H = (H+1) / 2;
	}
	printf("%d\n", cnt);

	return 0;
}
*/




/* Algorithm 1083번 소트 */
/*
#include <stdio.h>
int arr[51];
int main() {
	int i, j, numcnt, S, tmp, cnt=0;
	scanf("%d", &numcnt);

	for(i=0; i<numcnt; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &S);
	for(j=0; cnt != S; j++) {
		for(i=0; i<numcnt-1; i++) {
			if(arr[i] < arr[i+1]) {
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				cnt++;
				break;
			}
			if(cnt == S)
				break;
		}
	}
	for(i=0; i<numcnt; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
*/



/* Algorithm 1085번. -> 직사각형에서 탈출 */
/* method1 */
/*
#include <stdio.h>
int main() {
	int x, y, w, h, i, min;
	int arr[4];

	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	arr[0] = x;
	arr[1] = w-x;
	arr[2] = y;
	arr[3] = h-y;

	for(i=0; i<3; i++) {
		if(arr[i] <= arr[i+1]) {
			min = arr[i];
			arr[i+1] = min;
		}
	}

	printf("%d\n", min);
	return 0;
}
*/

/* method2 */
/*
#include <stdio.h>
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int x, y, w, h;
 
    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d\n", min(min(x, y), min(w - x, h - y)));
 
    return 0;
} 
*/





/* Algorithm 1100번 : 하얀 칸 */
/*
#include <stdio.h>

char arr[8][8];

int main() {
	int i, j, cnt=0;
	int k, l;
	
	for(i = 0; i < 8; i++) {
		gets(arr[i]);
	}
	for(i=0; i<8; i+=2)
		for(j=0; j<8; j+=2)
			if(arr[i][j] == 'F')
				cnt++;

	for(k=1; k<8; k+=2)
		for(l = 1; l<8; l+=2)
			if(arr[k][l] == 'F')
				cnt++;

	printf("%d\n", cnt);
	return 0;
}
*/




/* Algorithm 1110번. -> 더하기 사이클 */
/*
#include <stdio.h>
int main() {
    int buf[2];
 
    int a, first, second, sum;
    int cnt = 0;
 
    scanf("%d", &a);
    if(a >= 10) {
        first = a / 10;
        second = a % 10;
    }
    else {
        first = 0;
        second = a;
    }
    buf[0] = first;
    buf[1] = second;
 
    do {
        sum = 0;
        sum = first + second;
 
        first = second;
        if(sum >= 10) {
            second = sum % 10;
        }
        else {
            second = sum;
        }
        cnt++;
    }while(buf[0] != first || buf[1] != second);
 
    printf("%d\n", cnt);
 
    return 0;
}
*/








/* Algorithm 2501번. -> 약수구하기 */

/*
#include <stdio.h>

int main() {
	int p, q, i, count=0;

	scanf("%d %d", &p, &q);
	for(i = 1; i <= p; i++) {
		if((p % i) == 0) {
			count++;
			if(count == q)
				break;
		}
	}
	if(count < q)
		printf("0\n");
	else
		printf("%d\n", i);
	
	return 0;
}
*/








/* Algorithm 2506 -> 점수계산 */
/*
#include <stdio.h>

int main() {
	int arr[BUFSIZ];
	int num, i, panel=0, sum=0;

	scanf("%d", &num);
	for(i=0; i < num; i++) {
		scanf("%d", &arr[i]);
		if(arr[i] == 1) {
			panel++;
			sum += panel;
		}
		else
			panel = 0;
	}
	printf("%d\n", sum);
	return 0;
}
*/








/* algorithm 2525 -> 오븐시계 */
/*
#include <stdio.h>

int main() {
	int hour, min, time;

	scanf("%d %d", &hour, &min);
	scanf("%d", &time);

	hour += time / 60;
	min += time % 60;

	if(min >= 60) {
		hour++;
		min %= 60;
	}
	if(hour >= 24) {
		hour %= 24;
	}
	printf("%d %d\n", hour, min);

	return 0;
}
*/













/* Algorithm 2557번. -> Hello World 출력 */
/*
#include <stdio.h>
 
int main() {
    printf("Hello World!");
    return 0;
}
*/







/* Algorithm 2558번. -> A+B를 출력 */
/*
#include <stdio.h>
 
int main() {
    int num, num2;
    scanf("%d", &num);
    scanf("%d", &num2);
    num = num+num2;
    printf("%d\n", num);
 
    return 0;
}
*/









/* Algorithm 2563번. -> 색종이 */
/*
#include <stdio.h>
 
int arr[100][100];
 
void put_rect(int i, int j)
{
   int k, p;
   int tmp = j;
 
   for (k = 0; k < 10; k++) {
      j = tmp;
      for(p = 0; p < 10; p++) {
         arr[i][j] = 1;
         j++;
      }
      i++;
   }
}
 
int calc_rect_size()
{
   int i, j, cnt = 0;
   for(i = 0; i < 100; i++)
      for(j = 0; j < 100; j++)
         if( arr[i][j] )
            cnt++;
   return cnt;
}
 
int main(int argc, char* argv[])
{
   int i, num, tmp1, tmp2;
    
   scanf("%d", &num);
 
   for(i = 0; i < num; i++) 
   {
      scanf("%d %d", &tmp1, &tmp2);
      put_rect(tmp1, tmp2);
   }
    
   printf("%d\n", calc_rect_size());
}
*/










/* Algorithm 2577번. -> 숫자의 개수 */
/*
#include <stdio.h>

int main() {
    int i, a, j, c=1;
    int buf[10];
    for(i = 0; i < 10; i++) {
        buf[i] = 0;
    }
    for(i = 0; i < 3; i++) {
        scanf("%d", &a);
        c *= a;
    }
    for(i = 0; c > 0; i++) {
        a = c % 10;
        c /= 10;
        for(j = 0; j < 10; j++) {
            if(a == j)
                buf[j] += 1;
        }
    }
 
    for(i = 0; i < 10; i++) {
        printf("%d\n", buf[i]);
    }
}
*/


/*
#include <stdio.h>

int main() {
	char str[BUFSIZ];
	int i;

	//gets(str);
	scanf("%s", str);
	for(i = 0; i < 4; i++) {
		printf("%s ", &str[i]);
	}
	printf("\n");
	printf("%s\n", &str[1]);
	
	return 0;
}*/

/*
#include <stdio.h>
#define MAX_STR_SIZE 100
int main() {
	int i, cnt = 0;
	//char *arr[100];

    char str_read[MAX_STR_SIZE];

	//for(i=0; i<3; i++) {
	//fgets(str_read, MAX_STR_SIZE, stdin);
	gets(str_read);
	//}
	printf("읽어들인 문자열 : %s \n", &str_read);

    return 0;
}*/
	
	/*
	while(cnt < 100) {
		gets(arr);
		printf("%s\n", arr);
		cnt++;
	}*/
	/*
	for(i=0; i<5; i++) {
		//scanf("%s", &arr[i]);
		gets(&arr[i]);
		cnt++;
	}
	printf("%s\n", &arr[0]);
	printf("%s\n", &arr[1]);
	printf("%s\n", &arr[2]);
	printf("%s\n", &arr[3]);
	printf("%s\n", &arr[4]);
	*/
	/*
	printf("%s\n", &arr[0]);
	printf("%s\n", &arr[1]);
	printf("%s\n", &arr[2]);
	printf("%s\n", &arr[3]);
	printf("%s\n", &arr[4]);
	*/

	/*
	while(cnt < 100) {
		scanf("%s ", arr);
		cnt++;
	}*/
	/*
	if(arr[0] == *arr2) {
		for(i=0; i<100; i++) {
			printf("%s\n", &arr[i]);
		}
	}*/
/*
	return 0;
}*/

/*
#include <stdio.h>
#define MAX_SIZE 15
char str_read[5][MAX_SIZE];
int main() {
	int i, j;
	
	for(i=0; i<5; i++) {
		scanf("%s", str_read[i]);
	}

	for(i=0; i<MAX_SIZE; i++) {
		for(j=0; j<5; j++) {
			if(str_read[j][i] == NULL) {
				continue;
			}
			else
				printf("%c", str_read[j][i]);
		}
	}
	printf("\n");
	return 0;
}*/


/*
#include <stdio.h>
int arr[1000000];
int temp[1000000];
int temp2[1000000];
int main() {
	int N, i;
	scanf("%d", &N);

	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}

	for(i=0; i<N; i++) {
		temp[i] = arr[i+1] - arr[i];
		temp2[i] = arr[i+1] / arr[i];
	}
	for(i=0; i<N; i++) {
		if(temp[i] == temp[i+1]) {		//등차
			printf("%d\n", arr[N-1]+temp[0]);
			break;
		}
		if(temp2[i] == temp2[i+1]) {		//등비
			printf("%d\n", arr[N-1]*temp2[0]);
			break;
		}
	}
	return 0;
}
*/

/* 1789 수들의 합 */
/*
#include <stdio.h>
int main() {
	long long int S, i, n=0;
	int cnt=0;
	scanf("%lld", &S);

	for(i=1; ; i++) {
		n += i;
		cnt++;
		if(n > S) {
			break;
		}
	}
	printf("%d\n", --cnt);

	return 0;
}
*/



/* Algorithm 5347 LCM */
/*
#include <stdio.h>
int gcd(int x, int y) {
	int n;
	while(1) {
		n = x % y;
		if(n == 0) return y;
		x = y;
		y = n;
	}
}
int main() {
	int num1, num2, cnt, i, maxi;
	int lcm[1000];
	long long int tmp;

	scanf("%d", &cnt);

	for(i = 0; i < cnt; i++) {
		scanf("%d", &num1);
		scanf("%d", &num2);
		maxi = gcd(num1, num2);
		tmp = num1 * num2;
		lcm[i] = tmp / maxi;
	}
	for(i = 0; i < cnt; i++)
		printf("%d\n", lcm[i]);
	return 0;
}
*/



/* 9012 . 괄호 */
/*
#include <stdio.h>
#define MAXSIZE 100
int main ()
{
	int i, j, n, cnt=0;
	char su[MAXSIZE][MAXSIZE];
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		scanf("%s", su[i]);
		for(j=0; j<MAXSIZE; j++) {
			if(su[i][j] == '(')
				++cnt;
			if(su[i][j] == ')')
				--cnt;
			if(su[i][j] == NULL)
				continue;
			if(cnt <= -1)
				break;
		}
		if(cnt == 0) printf("YES\n");
		if(cnt != 0) printf("NO\n");
		cnt = 0;
	}
	return 0;
}
*/


/*10828 스택 */
/*
#include <stdio.h>
#include <string.h>

int stack[200000];

int main() {
	int N, i, j, num, top=0;
	scanf("%d", &N);

	for(i=0; i<N; i++) {
		char cmd[2000];
		scanf("%s", cmd);
		if(strcmp(cmd, "push") == 0) {
			scanf("%d", &num);
			stack[top] = num;
			top++;
		}
		if(strcmp(cmd, "pop") == 0) {
			if(top <= 0)
				printf("-1\n");
			else {
				printf("%d\n", stack[top-1]);
				top--;
			}
		}
		if(strcmp(cmd, "size") == 0) {
			printf("%d\n", top);
		}
		if(strcmp(cmd, "empty") == 0) {
			if(top <= 0)
				printf("1\n");
			else
				printf("0\n");
		}
		if(strcmp(cmd, "top") == 0) {
			if(top <= 0)
				printf("-1\n");
			else 
				printf("%d\n", stack[top-1]);
		}
	}
	return 0;
}*/


/* 11728 배열 합치기 */
/*
#include <stdio.h>
int A[1000000];
int main() {
	int N, M, i, j, tmp;
	
	scanf("%d %d", &N, &M);

	for(i=0; i<N+M; i++)
		scanf("%d", &A[i]);

	for(i=0; i<N+M; i++) {
		for(j=i+1; j<N+M; j++) {
			if(A[i] >= A[j]) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
	for(i=0; i<N+M; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
*/

/*
#include <stdio.h>
int A[100000];
void swap(int* a, int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
 
void quick_sort(int* A, int start, int end){
	int mid, pivot, p, q;
	
    if(start>=end) return;
 
    mid = (start + end) / 2;
	pivot = A[mid];
 
    swap(&A[start],&A[mid]);
 
    p = start+1;
	q = end;
 
    while(1){
        while(A[p]<=pivot){ p++; }
        while(A[q]>pivot){ q--; }
 
        if(p>q) break;
 
        swap(&A[p],&A[q]);
    }
 
    swap(&A[start],&A[q]);
 
    quick_sort(A,start,q-1);
    quick_sort(A,q+1,end);
}

int main(void){
    int i, N, M;

	scanf("%d %d", &N, &M);
	
	for(i=0; i<N+M; i++) {
		scanf("%d", &A[i]);
	} 
	quick_sort(A, 0, N+M);

	for(i=0; i<N+M; i++) {
		printf("%d ", A[i+1]);
	}
	printf("\n");
 
    return 0;
}*/


/*
#include <stdio.h>
int main() {
	int i, j, N, cnt=0;
	scanf("%d", &N);

	for(i=1; i<=N; i++) {
		int arr[1000];
		for(j=0; j<N; j++) {
			arr[j] = i;
		}
		if((arr[i+1] - arr[i]) == (arr[i+2] - arr[i+1])) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}*/


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str[1000];
	int len;
	char tmp;
	int i;

	while(1) {
		scanf("%s", &str);
		len = strlen(str);
      
		for(i=0;i<len/2;i++) {
			tmp = str[i];
			str[i] = str[len-i-1];
			str[len-i-1] = tmp;
		}
		printf("%s\n", str);
	}
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[26] = {0,};

int main() {
   char s[100];
   int i,j,len,n,min;
   while(1){
   scanf("%s",&s);
   len = strlen(s);

   for(i=0; i<len; i++) {
      n = s[i] - 'a';
      if( arr[n] == 0 )
         arr[n] = i + 1;

      else if( arr[n] != 0 && arr[n] != -1 )
         arr[n] = -1;
   }
   min = 30;
   for(i=0; i<26; i++) {
      if( min > arr[i] && arr[i] > 0 )
         min = arr[i];
   }
   printf("%c",s[min-1]);
   }
   return 0;
}*/
/*
#include <stdio.h>
#include <string.h>

char str[10000];
int arr[30]={0,};
int main() {
	int i, n, k=0;
	char ch;
	scanf("%s", &str);

	for(i=0; i< strlen(str); i++) {
		n = str[i] - 'a';
		arr[n]++;
	}

	for(i=0; i<30; i++) {
		if(arr[i] == 0) {
			ch = arr[n]+'a';
			printf("%c\n", ch);
			break;
		}
	}

	return 0;
}*/


//반복되지 않는 첫번째 문자 찾기
/*
#include <stdio.h>

char str[10000];
char arr[30];

int main() {
	int i;
	char ch;
	scanf("%s", &str);

	for(i=0; i<sizeof(str)/sizeof(str[0]); i++) {
		ch = str[i];
		arr[ch]++;
	}

	for(i=0; i<sizeof(str)/sizeof(str[0]); i++) {
		ch = str[i];
		if(arr[ch] == 1) {
			printf("%c\n", ch);
			break;
		}
	}

	return 0;
}*/

/*
#include <stdio.h>

int main() {
	int num, binary, sum, i=0;

	scanf("%d", &num);
	while(num > 0) {
        binary = num % 2;
        sum += binary * i;
        num = num / 2;
        i *= 10;
    }
	printf("%d", sum);
	return 0;
}*/


//10진수를 2진수로 변환하는 프로그램
/*
#include <stdio.h>

int main() {
	int i, j, num;
	int result[20];
	
	scanf("%d", &num);

	for(i=0; num > 0; i++) {
		result[i] = num%2;
		num = num/2;
	}

	for(j=i-1; j>=0; j--)
		printf("%d ", result[j]);

	printf("\n");
	return 0;
}*/


//10진수를 8진수로 변환하는 프로그램
//10진수를 16진수로 "
/*
#include <stdio.h>

#define MAXSIZE 500
int main() {
	int i, num, j;
	int result[MAXSIZE];

	scanf("%d", &num);

	for(i=0; num > 0; i++) {
		result[i] = num%8;
		//result[i] = num%16;
		num /= 8;
		//num /= 16;
	}

	for(j=i-1; j>=0; j--) {
		printf("%d ", result[j]);
	}

	return 0;
}
*/

//2진수에서 10진수로 변환하기
/*
#include<stdio.h>

void main() {
	char arr[100];
	int i, sum=0, k=1, len=0;
	
	scanf("%s", arr);
 
	while(arr[len] != NULL)
		len++;

	for(i=len-1; i>=0; i--) {
		if(arr[i] % 2 == 0) //0은 아스키코드로 48 , 1은 49라는 점을 이용
			sum += 0;
		else{
			sum += k;
		}
		k *= 2;
	}
	printf("10진수로는 => %d\n", sum);
}
*/




//8진수에서 10진수로 변환하기
//16진수에서 10진수로 변환하기
/*
#include<stdio.h>

void main() {
	char arr[100];
	int i, num, sum=0, k=1, len=0;

	scanf("%s", &arr);
 
	while(arr[len] != NULL)
		len++;

	for(i=len-1; i>=0; i--) {
		num = arr[i] - 48;		//아스키코드 변환
		num *= k;
		sum += num;
		//k *= 16;
		k *= 8;
	}
	printf("10진수로는 => %d\n", sum);
}
*/



//약수 구하기
/*
#include <stdio.h>

int main() {
	int n,i;
	
	scanf("%d", &n);

	for(i = 1; i*i<n; i++) {
		if(n % i == 0)
			printf("%d %d ", i, n/i);
	}
	return 0;
}*/

//팩토리얼 함수
/*
#include <stdio.h>

int fact(int num) {
	if(num == 1)
		return num;
	else
		return num * fact(num-1);
}

int main() {
	int n;

	scanf("%d", &n);

	printf("%d", fact(n));
	printf("\n");

	return 0;
}
*/

//피보나치 수열
/*
#include <stdio.h>

int fibo(int n) {
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fibo(n-1) + fibo(n-2);
}

int main() {
	int num, i;

	scanf("%d", &num);

	for(i=1; i<=num; i++) {
		printf("%d ", fibo(i));
	}
	printf("\n");

	return 0;
}
*/