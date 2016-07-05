/*	LinkedList(Chapter 2)
	maker : Choi Jin woo
*/



/* 1. 다음의 비정렬 연결 리스트에서 중복 문자를 제거하는 코드를 작성하라. 

예) 입력 : 7
      a a b c d d e
    출력 : a b c d e 

*/ 
//미해결
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct mNode {
    char data;
    struct mNode * next;
}Node;

Node *tail, *head, *myNode, *imsiNode;

void InitList() {
       head = NULL;
       tail = NULL;
       myNode = NULL;
	   imsiNode = NULL;
}
char data;
char deleteNode;

int main() {
	int num, i, j, count=0, find;

	InitList();

	scanf("%d", &num);
	
	for(i=0; i<num; i++) {
		Node * myNode = (Node *)malloc(sizeof(Node));

		scanf("%s", &data);
		myNode->data = data;
        myNode->next = NULL;

		if ( head == NULL ) {
             head = myNode;
             tail = myNode;
       }
       tail->next = myNode;
       tail = myNode;
	}

	Node * middle = (Node *)malloc(sizeof(Node));
	Node * imsi = (Node *)malloc(sizeof(Node));
	Node * ptr = (Node *)malloc(sizeof(Node));
	middle = head;
	imsi = middle->next;

	for(i=0; i<num; i++) {		
		for(ptr = head; ptr->next != imsi; ptr = ptr->next) {
			if(ptr->data == imsi->data) {
				middle->next = imsi->next;
				break;
			}
			else {
				middle = middle->next;
			}
		}
		imsi = middle->next;
	}


		if(head->data == middle->data) {
			Node * imsiNode = (Node *)malloc(sizeof(Node));
			imsiNode = middle;
			imsiNode->next = middle->next;
			middle->next = imsiNode->next;
			free(imsiNode);

		while(middle->data != NULL) {
			middle->next = head->next;
		if(middle->next->data == 


		if(head->data == head->next->data) {
			Node * imsiNode = (Node *)malloc(sizeof(Node));
			imsiNode = head;
			imsiNode->next = head->next;
			head = imsiNode->next;
			free(imsiNode);

			}
		else {
			printf("%c ", head->data);
			head = head->next;
		}
	}
	for(i=0; i<num; i++) {
		printf("%c ", head->data);
		head = head->next;
	}
	printf("\n");
	return 0;
}


*/











/*  2. 단방향 연결 리스트에서, 뒤에서K번째 원소를 찾는 알고리즘을 구현하라. 

예) 입력 : 12
           s t u d y s t u d e n t
      5
    출력 : u   
	
*/ 
// 해결
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct mNode {
    char data;
    struct mNode * next;
}Node;

Node *head, *tail, *myNode;

void InitList() {
       head = NULL;
       tail = NULL;
       myNode = NULL;
}

char data;

int main() {
	int cnt, i, find;

	InitList();

	scanf("%d", &cnt);
	
	for(i=0; i<cnt; i++) {
		Node * myNode = (Node *)malloc(sizeof(Node));
		scanf("%s", &data);
		myNode->data = data;
        myNode->next = NULL;

		if ( head == NULL ) {
             head = myNode;
             tail = myNode;
       }
       tail->next = myNode;
       tail = myNode;
	}

	scanf("%d", &find);
	
	for(i=0; i<cnt-find; i++) {
		head = head->next;
	}
	printf("%c\n", head->data);
	return 0;
}
*/











/* 3. 단방향 연결 리스트의 중간에 있는 노드 하나를 삭제하는 알고리즘을 구현하라. 삭제할 노드에 대한 접근만 가능하다는 것에 유의하라. 

예) 입력 : 5
           a b c d e 
           c
           (연결리스트 a->b->c->d->e 의 노드 c)
    결과 : a b d e(연결리스트가 a->b->d->e 되어 있으면 됨)

*/
//미해결
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct mNode {
    char data;
    struct mNode * next;
}Node;

Node *tail, *head, *myNode, *imsiNode;

void InitList() {
       head = NULL;
       tail = NULL;
       myNode = NULL;
	   imsiNode = NULL;
}
char data;
char deleteNode;

int main() {
	int cnt, i, find;

	InitList();

	scanf("%d", &cnt);
	
	for(i=0; i<cnt; i++) {
		Node * myNode = (Node *)malloc(sizeof(Node));
		scanf("%s", &data);
		myNode->data = data;
        myNode->next = NULL;

		if ( head == NULL ) {
             head = myNode;
             tail = myNode;
       }
       tail->next = myNode;
       tail = myNode;
	}
	
	scanf("%s", &deleteNode);
	
	for(i=0; i<cnt; i++) {
		if(head->data == deleteNode) {
			Node * imsiNode = (Node *)malloc(sizeof(Node));
			imsiNode = head;
			imsiNode->next = head->next;
			head = imsiNode->next;
			free(imsiNode);
		}
		else {
			printf("%c ", head->data);
			head = head->next;
		}
	}
	printf("\n");
	return 0;
}
*/








//2번째 모임------------------------------------------------------------------------------------------------






/* (2.4) x값을 갖는 노드를 기준으로 연결 리스트를 나누는 코드를 작성.
x보다 작은 값을 갖는 노드가 x와 같거나 더 큰 값을 갖는 노드들보다 앞쪽에 오도록 하면 된다.

예시) 
입력)
6
5 1 8 4 2 9 
4

출력) 앞 노드 : 1 2 , 뒤 노드: 4 5 8 9
*/
//해결
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct mNode {
    int data;
    struct mNode * next;
}Node;

Node *tail, *tail1, *tail2, *head, *head1, *head2, *frontNode, *endNode, *myNode;

void InitList() {
       head = NULL;
       tail = NULL;
	   head1 = NULL;
       tail1 = NULL;
	   head2 = NULL;
       tail2 = NULL;
       myNode = NULL;
	   frontNode = NULL;
	   endNode = NULL;
}

int main() {
	int num, i, x, data;

	InitList();

	scanf("%d", &num);
	
	for(i=0; i<num; i++) {
		Node * myNode = (Node *)malloc(sizeof(Node));
		scanf("%d", &data);
		myNode->data = data;
        myNode->next = NULL;

		if ( head == NULL ) {
             head = myNode;
             tail = myNode;
       }
       tail->next = myNode;
       tail = myNode;
	}
	
	scanf("%d", &x);
	
	for(i=0; i<num; i++) {
		if(head->data < x) {
			Node * frontNode = (Node *)malloc(sizeof(Node));

			frontNode->data = head->data;
			frontNode->next = NULL;

			if(head1 == NULL) {
				head1 = frontNode;
				tail1 = frontNode;
			}
			tail1->next = frontNode;
			tail1 = frontNode;
		}
		else if(head->data >= x) {
			Node * endNode = (Node *)malloc(sizeof(Node));
			
			endNode->data = head->data;
			endNode->next = NULL;

			if(head2 == NULL) {
				head2 = endNode;
				tail2 = endNode;
			}
			tail2->next = endNode;
			tail2 = endNode;
		}
		head = head->next;
	}
	tail1->next = NULL;
	tail2->next = NULL;

	printf("frontNode = ");
	for(; head1 != NULL; head1 = head1->next) {
		printf("%d ", head1->data);
	}
	printf("\n");
	
	printf("endNode = ");
	for(; head2 != NULL; head2 = head2->next) {
		printf("%d ", head2->data);
	}
	printf("\n");

	return 0;
}
*/











/* (2.5) 연결 리스트로 표현된 두 개의 수가 있다고 하자. 리스트의 각 노드는 해당 수의 갓 자릿수를 표현한다.
이때 자릿수들은 역순으로 배열되는데, 1의 자릿수가 리스트의 맨 앞에 오도록 배열된다는 뜻이다.
이 두수를 더하여 그 합을 연결 리스트로 반환하는 함수를 작성하라.

예)
입력 : 	7 1 6
	5 9 2

출력 : 912

입력: (7->1->6) + (5->9->2) 즉, 617+295
출력: 2->1->9. 즉, 912

*/
//미해결






/* 3.(2.6) 순환 연결 리스트(circular linked list)가 주어졌을 때, 순환되는 부분의 첫 노드를 반환하는 알고리즘 작성.
-정의 : 순환 연결 리스트는 노드의 next 포인트가 앞선 노드를 가운데 어느 하나를 가리키도록 설정되어 있는
연결 리스트다(망가진 연결 리스트라고 볼 수 있다)

예) 
입력: A->B->C->D->E->C(E의 next 노드가 D 앞에 있는 C로 설정 되어 있다)
출력: C

*/
//미해결








/* (2.7) 주어진 연결 리스트가 회문(palindrome)인지 검사하는 함수 작성 (Reverse 사용!)

a b a -> o

b a -> x

c a b -> x

a c b c a -> o

*/
//해결
/*
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

typedef struct mNode {
    char data;
    struct mNode* next;
}Node;

Node *head, *rhead, *tail, *rtail, *myNode, *reverseNode, *tmp, *imsi;

void InitList() {
       head = NULL;
	   rhead = NULL;
       tail = NULL;
	   rtail = NULL;
	   myNode = NULL;
	   reverseNode = NULL;
	   tmp = NULL;
	   imsi = NULL;
}
char str[1000];

int main() {
	int cnt, i, tf=0;

	InitList();
	printf("입력 갯수 : ");
	scanf("%d", &cnt);

	for(i=0; i<cnt; i++) {			//일반과 reverse노드 두개를 만들어줌.
		Node * myNode = (Node *)malloc(sizeof(Node));
		Node * reverseNode = (Node *)malloc(sizeof(Node));
		scanf("%s", &str[i]);
		myNode->data = str[i];		//1번째 만듬
        myNode->next = NULL;
		reverseNode->data = str[i];	//바꿔줄 노드도
        reverseNode->next = NULL;

		if(head == NULL) {
			head = myNode;
            tail = myNode;
		}
		if(rhead == NULL) {
			rhead = reverseNode;
			rtail = reverseNode;
		}
		tail->next = myNode;
		tail = myNode;
		rtail->next = reverseNode;
		rtail = reverseNode;
	}
	tail->next = NULL;
	rtail->next = NULL;

	for(i=0; i<cnt-1; i++) {			//reverseNode는 reverse해줌!(reverse하는 부분)
		tmp = rhead->next;
		if(rtail->next == NULL) {
			rtail->next = rhead;
			rhead->next = NULL;
		}
		else {
			imsi = rtail->next;
			rtail->next = rhead;
			rtail->next->next = imsi;
		}
		rhead = tmp;
	}

	for(i=0; i<cnt; i++) {				//각 노드의 값을 검사하면서 같으면 palindrome이고, 다르면 no palindrome이다.
		if(head->data != rtail->data) {
			tf = 0;
			break;
		}
		else
			tf = 1;
		head = head->next;
		rtail = rtail->next;
	}
	if(tf == 0)
		printf("It is not Palindrome!\n");
	else if(tf == 1)
		printf("It is Palindrome!\n");

	return 0;
}
*/









/* (2.7) 주어진 연결 리스트가 회문(palindrome)인지 검사하는 함수 작성 (재귀 사용!)

a b a -> o

b a -> x

c a b -> x

a c b c a -> o

*/
//해결
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct mNode {
    char data;
    struct mNode* next;
}Node;

Node *head, *tail, *head1, *tail1, *myNode, *myNode2, *nextNode, *tmp;

void InitList() {
       head = NULL;
       tail = NULL;
	   head1 = NULL;
	   tail1 = NULL;
	   myNode = NULL;
	   myNode2 = NULL;
	   nextNode = NULL;
	   tmp = NULL;
}
Node *reverse(Node *head){
    if(!head || !head->next) {
		//printf("%c ", head->data);
        return head;
	}
	nextNode = head->next;
    
	nextNode = reverse(nextNode);
    
	head->next->next = head;
    head->next = NULL;
	//printf("%c ", head->data);
    return head;
}

char str[1000];

int main() {
	int cnt, i, tf=0;

	InitList();
	printf("입력 갯수 : ");
	scanf("%d", &cnt);

	for(i=0; i<cnt; i++) {			//일반과 reverse노드 두개를 만들어줌.
		Node * myNode = (Node *)malloc(sizeof(Node));
		Node * myNode2 = (Node *)malloc(sizeof(Node));
		scanf("%s", &str[i]);

		myNode->data = str[i];
        myNode->next = NULL;

		myNode2->data = str[i];
		myNode2->next = NULL;

		if(head == NULL) {
			head = myNode;
            tail = myNode;
			head1 = myNode2;
			tail1 = myNode2;
		}
		tail->next = myNode;
		tail = myNode;

		tail1->next = myNode2;
		tail1 = myNode2;
	}
	tail->next = NULL;
	tail1->next = NULL;

	tmp = reverse(head);
	for(i=0; i<cnt; i++) {
		printf("%c ", tmp->data);
		tmp = tmp->next;
	}
	
	for(i=0; i<cnt; i++) {				//각 노드의 값을 검사하면서 같으면 palindrome이고, 다르면 no palindrome이다.
		if(head->data != head1->data) {
			tf = 0;
			break;
		}
		else
			tf = 1;
		head = head->next;
		head1 = head1->next;
	}
	if(tf == 0)
		printf("It is not Palindrome!\n");
	else if(tf == 1)
		printf("It is Palindrome!\n");

	return 0;
}

*/







/* 리스트 쌍 뒤집기

예) 입력: 1->2->3->4->5
    출력 : 2->1->4->3->5  
	
*/
//해결
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct mNode {
    int data;
    struct mNode* next;
}Node;

Node *head, *tail, *myNode, *tmp, *tmp2, *imsi;

void InitList() {
       head = NULL;
       tail = NULL;
	   myNode = NULL;
	   tmp = NULL;
	   tmp2 = NULL;
	   imsi = NULL;
}
int data[1000];

int main() {
	int cnt, i;

	InitList();

	printf("입력 갯수 : ");
	scanf("%d", &cnt);

	for(i=0; i<cnt; i++) {								//처음에 노드를 개수만큼 myNode에 입력해줌.
		Node * myNode = (Node *)malloc(sizeof(Node));
		scanf("%d", &data[i]);
		myNode->data = data[i];
        myNode->next = NULL;

		if(head == NULL) {
			head = myNode;
            tail = myNode;
		}
		tail->next = myNode;
		tail = myNode;
	}
	tail->next = NULL;

	tmp = head;							//초기에, 노드들에 대하여 위치를 잡아줌.
	tmp2 = tmp->next;					// "
	head = head->next;					// "
	
	if(cnt % 2 == 1) {					//만약 홀수개를 입력 받았을 때,
		for(i=0; i<cnt/2; i++) {
			tmp->next = tmp2->next;
			tmp2->next = tmp;

			imsi = tmp;

			tmp = tmp->next;
			tmp2 = tmp->next;

			imsi->next = tmp2;
		}

		for(i=0; i<cnt-1; i++) {
			printf("%d ", head->data);
			head = head->next;
		}
		printf("%d\n", tail->data);
	}
	if(cnt % 2 == 0) {					//만약 짝수개를 입력 받았을 때,
		for(i=0; i<cnt/2-1; i++) {
			tmp->next = tmp2->next;
			tmp2->next = tmp;

			imsi = tmp;

			tmp = tmp->next;
			tmp2 = tmp->next;

			imsi->next = tmp2;
		}

		for(i=0; i<cnt-1; i++) {
			printf("%d ", head->data);
			head = head->next;
		}
		printf("%d\n", tmp->data);
	}
	return 0;
}
*/




/*
	삼성 소프트웨어 멤버십 1번 문제->줄 세우기 (swap함수를 이용하여 구현!)
	예시)
	입력)
		5
		0 1 1 3 2
	출력)
		4 2 5 3 1
*/
//해결
/*
#include <stdio.h>
#define MAXSIZE 100
int arr[MAXSIZE];
int main() {
	int num, i, j, cnt, tmp;

	scanf("%d", &num);

	for(i=0; i<num; i++) {
		arr[i] = i+1;
	}

	for(i=0; i<num; i++) {
		scanf("%d", &cnt);
		for(j=i; j>i-cnt; j--) {
			tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
		}
	}

	for(i=0; i<num; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
*/

//다른 풀이 (리스트)
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct mNode {
	int data;
	struct mNode * next;
}Node;

Node *head, *tail, *myNode, *imsi, *tmp;

void initNode() {
	head = NULL;
	tail = NULL;
	myNode = NULL;
	imsi = NULL;
	tmp = NULL;
}

int main() {
	int num, k, i, j, cnt;

	initNode();
	scanf("%d", &num);

	for(i=1; i<=num; i++) {
		Node * myNode = (Node*)malloc(sizeof(Node));
		myNode->data = i;
		myNode->next = NULL;

		if(head == NULL) {
			head = myNode;
			tail = myNode;
		}
		tail->next = myNode;
		tail = myNode;
	}
	tmp = head;
	for(i=0; i<num; i++) {
		scanf("%d", &cnt);
		for(j=0; j>i-1; j++) {
			tmp = tmp->next;
		}
		if(cnt == 0)
			continue;
		else if(cnt != 0) {
			imsi = tmp->next->next;
			tmp->next->next = tmp;
			tmp->next = imsi;
		}
		tmp = head;
	}

	for(i=0; i<num; i++) {
		printf("%d ", tmp->data);
		tmp = tmp->next;

	}
	printf("\n");
	return 0;
}*/

/*
#include <stdio.h>

#define TRUE 1 
#define FALSE 0 

#define VERTICES 7 
#define INF 1000L 

int adj_mat[VERTICES][VERTICES]={ 
{ 0, 29, INF, INF, INF, 10, INF }, 
{ 29,  0, 16, INF, INF, INF, 15 },  
{ INF, 16, 0, 12, INF, INF, INF }, 
{ INF, INF, 12, 0, 22, INF, 18 }, 
{ INF, INF, INF, 22, 0, 27, 25 }, 
{ 10, INF, INF, INF, 27, 0, INF }, 
{ INF, 15, INF, 18, 25, INF, 0 }}; 

int selected[VERTICES]; 
int dist[VERTICES]; 

// 최소 dist[v] 값을 갖는 정점을 반환 
int get_min_vertex(int n) 
{ 
    int v,i; 

    for (i = 0; i <n; i++) 
    { 
        if (!selected[i]) 
        {  
            v = i;  
            break; 
        } 
    } 
    // 선택하지 않은 간선들 중 최소 가중치값을 갖는 정점을 찾는다. 
    for (i = 0; i < n; i++) 
    { 
        if( !selected[i] && (dist[i] < dist[v]))  
            v = i; 
    } 

    return (v); 
} 

//  
void prim(int s, int n) 
{ 
    int i, u, v; 

    for(u=0;u<n;u++) 
        dist[u]=INF; 
     
    dist[s]=0; 
    for(i=0;i<n;i++) 
    { 
        u = get_min_vertex(n); 
        selected[u]=TRUE; // 지나간 경로 체크 
         
        if( dist[u] == INF ) return; 
             
        printf("%d\n", u); 

        for( v=0; v<n; v++) 
        { 
            if( adj_mat[u][v]!= INF) 
            { 
                if( !selected[v] && adj_mat[u][v]< dist[v] )  
                    dist[v] = adj_mat[u][v]; // 간선의 거리를 확정 
            } 
        } 
    } 
} 

// 
void main() 
{ 
    prim(0, VERTICES); 
} */

