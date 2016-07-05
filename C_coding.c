/* 1�� C, C++, JAVA �ڵ� */

/* (1) �־��� ���忡�� �ܾ��� ������ �����ϴ� �Լ� ���� 

�Է� : This is a Career Monk String
��� : String Monk Career a is This

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
			word = strtok_s(ch, " ", &dummy); // word �� ù �ܾ� This �� ��
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
    "A", "BB", "CCC", "DDDD", "EEEEE", "�����ٶ�", "���ٻ���"
               };

  // ���ڿ� �迭 ������
  // sizeof(s) / sizeof(s[0]) �� �迭�� ��� ����
  reverseString(str, sizeof(string) / sizeof(string[0]));

  // ��������, ���ڿ� �迭 ���
  for (i = 0; i < sizeof(string) / sizeof(string[0]); i++)
    printf("%s ", str[i]);

  return 0;
}
*/






/* (2) �ΰ��� ���ڿ��� �������� �˻��ϴ�, strcmp() �Լ��� ���� ���� ���ڿ��̸� 0 ����

abc, cbc -> ������
cbc, abc -> �����
abcde, abc -> ������

*/










/* (3) ���ڿ����� �ݺ����� �ʴ� ù��° ���ڸ� ã�Ƴ��� ȿ������ �Լ� ���� 

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




//2��° ����------------------------------------------------------------------------------------------


/*   4. ���� ���ڰ� �������� �ݺ��� ���, �� Ƚ���� ����� ���ڿ��� �����ϴ� �޼��带 �����϶�.
���� �����ؾ� �� ���ڿ��� aabccccccccaaa��� a2b1c8a3�� ���� ����Ǿ�� �Ѵ�.
���� ����� ��������� ���ڿ��� ���� ���ڿ� ���� ª������ �ʴ� ���, �� �޼���� ���� 
���ڿ��� �״�� ��ȯ�ؾ��Ѵ�. */
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







/* 5. �̹����� ǥ���ϴ� NxN ����� �ִ�. �̹����� �� �ȼ��� 4����Ʈ�� ǥ���ȴ�.
�̶�, �̹����� 90�� ȸ����Ű�� �޼��带 �ۼ��϶�. �ΰ����� ����� ������� �ʰ���
�� �� �ִ°�? */

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

	//90�� �ٲٱ�.
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











/* 6. �� �ܾ �ٸ� �ܾ ���Ե� ���ڿ����� �Ǻ��ϴ� isSubstring �̶�� �޼��尡 �ִٰ� ����.
s1�� s2�� �� ���ڿ��� �־����� ��, s2�� s1�� ȸ����Ų ������� �Ǻ��ϴ� �ڵ带
isSubstring�� �� ���� ȣ���ϵ��� �Ͽ� �ۼ��϶�.(���� 'waterbottle'�� 'erbottlewat'�� ȸ������
���� �� �ִ� ���ڿ��̴�. */

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










