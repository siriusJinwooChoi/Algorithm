/* 1강 C, C++, JAVA 코딩 */

/* (1) 주어진 문장에서 단어의 순서를 반전하는 함수 구현 

입력 : This is a Career Monk String
출력 : String Monk Career a is This

*/

/*
#include <stdio.h>
#include <string.h>

#define MAX 1000

char s[MAX];
char word[MAX];

int main () {
	int i;
	char temp;
	char *dummy = NULL;
	char *ch, *word;
	
	ch = gets(s);
	printf("%s\n", ch);

	while(word != NULL) {
		for(i=0; i<strlen(word); i++) {
			word = strtok_s(ch, " ", &dummy); // word 에 첫 단어 This 가 들어감
		}
	}

	printf("dummy : %s\n", dummy);
	printf("word = %s\n", word);
	
	while (word != NULL) {
		int size = strlen(word);
		for (i = 0; i < size / 2; i++) {
			temp = word[i];
			word[i] = word[(size - 1) - i];
			word[(size - 1) - i] = temp;
		}
		printf("%s ", word);
		word = strtok_s(NULL, " ", &dummy);
	}
  
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
#define MAX 1000

char str[MAX];
char buf[MAX];

int main() {
	char *ch, *pToken = NULL;
	int size, i;
	gets(str);

	size = strlen(str);
    pToken = strtok(str, " ");
    
	printf("%s\n", pToken);
	
	buf[3] = *pToken;

    while ((pToken = strtok(NULL, " ")) != NULL)
    {
		for(i=2; i>=0; i--) {
			//printf("%s\n", pToken);
			buf[i] = *pToken;
		}
    }
	for(i=0; i<4; i++) {
		printf("%s ", buf[i]);
	}
    return 0;
}
*/



/*
#include <stdio.h>
#include <string.h>
int main() {
	int i, size;
	char temp;
	char arr[BUFSIZ];
	char *word;
	char *dummy;

	fgets(arr, sizeof(arr), stdin);
	arr[strlen(arr)-1] = '\0';

	word = strtok_s(arr, " ", &dummy);

	//size = sizeof(word) / sizeof(char *);
	size = strlen(arr);
	
	for (i = 0; i < size / 2; i++) {
		temp = word[i];
		word[i] = word[(size - 1) - i];
		word[(size - 1) - i] = temp;
	}

	for (i = 0; i < size; i++)
		printf("%s ", word[i]);

	return 0;
}
*/





/*
#include <stdio.h>

void reverseString(char* s[], size_t size) {
	int i;
	char *temp;
	
	for (i = 0; i < size / 2; i++) {
    temp = s[i];
    s[i] = s[(size - 1) - i];
    s[(size - 1) - i] = temp;
  }
}
//char s[1000];
char string[1000];
char *str[1000];
int main(void) {
	int i;
	//char string;
	char *ch;
	

	ch = gets(string);

	for(i=0; i<sizeof(string) / sizeof(string[0]); i++) {
		str[i] = ch;
	}
  
	char *s[] = {
    "A", "BB", "CCC", "DDDD", "EEEEE", "가나다라", "마바사하"
               };

  // 문자열 배열 뒤집기
  // sizeof(s) / sizeof(s[0]) 는 배열의 요소 개수
  reverseString(str, sizeof(string) / sizeof(string[0]));

  // 뒤집어진, 문자열 배열 출력
  for (i = 0; i < sizeof(string) / sizeof(string[0]); i++)
    printf("%s ", str[i]);

  return 0;
}
*/






/* (2) 두개의 문자열이 같은지를 검사하는, strcmp() 함수를 구현 같은 문자열이면 0 리턴

abc, cbc -> 음수값
cbc, abc -> 양수값
abcde, abc -> 음수값

*/










/* (3) 문자열에서 반복되지 않는 첫번째 문자를 찾아내는 효율적인 함수 구현 

 total -> o
 teeter -> r

*/
/*
#include <stdio.h>

int main() {
	int i, j, len;
	char temp;
	char str[BUFSIZ];
	char result[28]={0,};
	
	//scanf("%s", str);
	*str = fgetc(stdin);

	len = sizeof(str)/sizeof(str[0]);

	for(i=0; i<len; i++) {
		temp = str[i];
		result[temp-'a']++;
	}

	for(j=0; j<28; j++) {
		if(result[j] == 1)
			printf("%c", result[j+'a']);
	}

	return 0;
}
*/




//2번째 모임------------------------------------------------------------------------------------------


/*   4. 같은 문자가 연속으로 반복될 경우, 그 횟수를 사용해 문자열을 압축하는 메서드를 구현하라.
가령 압축해야 할 문자열이 aabccccccccaaa라면 a2b1c8a3과 같이 압축되어야 한다.
압축 결과로 만들어지는 문자열이 원래 문자열 보다 짧아지지 않는 경우, 이 메서드는 원래 
문자열을 그대로 반환해야한다. */
/*
#include <stdio.h>
#include <string.h>
char str[1000];
char str2[1000];

int main() {
	int i=0, j=0, cnt=1;
	char alpha, ch;

	while((str[i++] = getc(stdin)) != '\n');
	alpha = str[0];
	
	for(i = 1; i < strlen(str); i++) {
		if(str[i] == alpha)
			cnt++;
		else {
			str2[j++] = alpha;
			str2[j++] = cnt;
			alpha = str[i];
			cnt = 1;
		}
	}

	if(strlen(str) > strlen(str2))
		for(i=0; i < strlen(str2); i+=2)
			printf("%c%d", str2[i], str2[i+1]);

	else if(strlen(str) < strlen(str2))
		for(i=0; i < strlen(str); i++)
			printf("%c", str[i]);
	else
		printf("What Problem?");

	printf("\n");
	return 0;
}
*/







/* 5. 이미지를 표현하는 NxN 행렬이 있다. 이미지의 각 픽셀은 4바이트로 표현된다.
이때, 이미지를 90도 회전시키는 메서드를 작성하라. 부가적인 행렬을 사용하지 않고서도
할 수 있는가? */

/*
#include <stdio.h>

int main() {
	int i, j;
	int arr[3][3]= {{1,2,3}, {4,5,6}, {7,8,9}};
	//int tmp, tmp2, imsi;

	int tmp[3];
	
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	//90도 바꾸기.
	for(j=0; j<3; j++) {
		for(i=-2; i<=0; i++) {
			tmp[i+2] = arr[j][i+2];
			tmp2[
			arr[j][i+2] = arr[-i][j];			
		}
		printf("\n");
	}

	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}
*/
/*
#include <stdio.h>
#define N 5

int main(void){
    int arr1[N][N], arr2[N][N];
    int i,j;
 
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &arr1[i][j]);
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            arr2[j][N-1-i]=arr1[i][j];
        }
    }
 
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/











/* 6. 한 단어가 다른 단어에 포함된 문자열인지 판별하는 isSubstring 이라는 메서드가 있다고 하자.
s1과 s2의 두 문자열이 주어졌을 때, s2가 s1을 회전시킨 결과인지 판별하는 코드를
isSubstring을 한 번만 호출하도록 하여 작성하라.(가령 'waterbottle'은 'erbottlewat'을 회전시켜
얻을 수 있는 문자열이다. */

/*
#include <stdio.h>

int main() {
	int j, i=0;
	char ch1, ch2;
	char str1[BUFSIZ], str2[BUFSIZ];
	
	while((ch1 = getc(stdin)) != '\n') {
		str1[i++] = ch1;
	}
	
	i=0;
	while((ch2 = getc(stdin)) != '\n') {
		str2[i++] = ch2;
	}

	for(i=0; i < sizeof(str1) / sizeof(str1[0]); i++) {
		for(j=0; j < sizeof(str1) / sizeof(str1[0]); j++) {
			if(str1[i] == str2[j]) {
			}
			else{

			}
		}
	}

	return 0;
}*/










