/* Algorithm 대회 (백준 알고리즘) */

/* A번 문제. */
/*
#include <stdio.h>

int main() {
	int num, i, findNum, cnt=0;
	int arr[BUFSIZ];

	scanf("%d", &num);

	for(i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &findNum);
	for(i = 0; i < num; i++) {
		if(arr[i] == findNum) {
			cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}
*/



/* B번문제 */
/*
#include <stdio.h>
#include <string.h>

int main() {
	char arr[BUFSIZ];
	int tmp[BUFSIZ], cnt[BUFSIZ]={0,};
	int i, j;

	scanf("%s", arr);

	//gets(arr);

	for(i = 0; i < strlen(arr); i++)
		tmp[i] = arr[i] - 97;
		
	for(i = 0; i < strlen(arr); i++)
		for(j = 0; j < 26; j++)
			if(tmp[i] == j)
				cnt[j]++;
	for(i=0; i < 26; i++)
		printf("%d ", cnt[i]);
	printf("\n");
	
	return 0;
}
*/






/* 10809번 : 알파벳 찾기 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, num;
	int alpha[26]={-1,};
	char str[BUFSIZ], tmp[BUFSIZ];

	gets(str);

	for(i = 0; i < strlen(str); i++)
		tmp[i] = str[i]-97;



	for(i = 0; i < 26; i++) {
		printf("%d ", alpha[i]);

}
*/



/* 10815번 : 숫자 카드 */
/*
#include <stdio.h>
int main() {
	int i, j, n1, n2;
	int card1[BUFSIZ], card2[BUFSIZ], tmp[BUFSIZ]={0,};
	
	scanf("%d", &n1);
	for(i=0; i<n1; i++) {
		scanf("%d", &card1[i]);
	}
	scanf("%d", &n2);
	for(i=0; i<n2; i++) {
		scanf("%d", &card2[i]);
	}

	for(i=0; i<n2; i++) {
		for(j=0; j<n1; j++) {
			if(card1[j] == card2[i]) {
				tmp[i] = 1;
			}
		}
	}
	for(i=0; i<n2; i++)
		printf("%d ", tmp[i]);

	printf("\n");

	return 0;
}
*/








/* 10816번 : 숫자 카드2 */
/*
#include <stdio.h>
int main() {
	int i, j, n1, n2;
	int card1[BUFSIZ], card2[BUFSIZ], tmp[BUFSIZ]={0,};
	
	scanf("%d", &n1);
	for(i=0; i<n1; i++) {
		scanf("%d", &card1[i]);
	}
	scanf("%d", &n2);
	for(i=0; i<n2; i++) {
		scanf("%d", &card2[i]);
	}

	for(i=0; i<n2; i++) {
		for(j=0; j<n1; j++) {
			if(card1[j] == card2[i]) {
				tmp[i]++;
			}
		}
	}
	for(i=0; i<n2; i++)
		printf("%d ", tmp[i]);

	printf("\n");

	return 0;
}
*/












/* M번 : 10817번 -> 세 수 */
/*
#include <stdio.h>

int main() {
	int arr[3], i, j, tmp;
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

	for(i=0; i<3; i++)
		for(j=0; j<2; j++)
			if(arr[j] >= arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}

	printf("%d\n", arr[1]);
	return 0;
}
*/





/* N번 문제 : 10818번 */
/*
#include <stdio.h>

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}

int main() {
	int i, cnt, mini, maxi=0;
	int arr[BUFSIZ];

	scanf("%d", &cnt);

	for(i=0; i<cnt; i++)
		scanf("%d", &arr[i]);

	mini = arr[0];

	if(cnt == 1)
		maxi = arr[0];

	else {
		for(i=0; i<cnt-1; i++) {
			mini = min(min(arr[i], arr[i+1]), mini);
			maxi = max(max(arr[i], arr[i+1]), maxi);
		}
	}
	printf("%d %d\n", mini, maxi);

	return 0;
}
*/




