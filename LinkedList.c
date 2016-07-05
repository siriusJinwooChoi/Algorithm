/*	LinkedList(Chapter 2)
	maker : Choi Jin woo
*/



/* 1. ������ ������ ���� ����Ʈ���� �ߺ� ���ڸ� �����ϴ� �ڵ带 �ۼ��϶�. 

��) �Է� : 7
      a a b c d d e
    ��� : a b c d e 

*/ 
//���ذ�
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











/*  2. �ܹ��� ���� ����Ʈ����, �ڿ���K��° ���Ҹ� ã�� �˰����� �����϶�. 

��) �Է� : 12
           s t u d y s t u d e n t
      5
    ��� : u   
	
*/ 
// �ذ�
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











/* 3. �ܹ��� ���� ����Ʈ�� �߰��� �ִ� ��� �ϳ��� �����ϴ� �˰����� �����϶�. ������ ��忡 ���� ���ٸ� �����ϴٴ� �Ϳ� �����϶�. 

��) �Է� : 5
           a b c d e 
           c
           (���Ḯ��Ʈ a->b->c->d->e �� ��� c)
    ��� : a b d e(���Ḯ��Ʈ�� a->b->d->e �Ǿ� ������ ��)

*/
//���ذ�
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








//2��° ����------------------------------------------------------------------------------------------------






/* (2.4) x���� ���� ��带 �������� ���� ����Ʈ�� ������ �ڵ带 �ۼ�.
x���� ���� ���� ���� ��尡 x�� ���ų� �� ū ���� ���� ���麸�� ���ʿ� ������ �ϸ� �ȴ�.

����) 
�Է�)
6
5 1 8 4 2 9 
4

���) �� ��� : 1 2 , �� ���: 4 5 8 9
*/
//�ذ�
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











/* (2.5) ���� ����Ʈ�� ǥ���� �� ���� ���� �ִٰ� ����. ����Ʈ�� �� ���� �ش� ���� �� �ڸ����� ǥ���Ѵ�.
�̶� �ڸ������� �������� �迭�Ǵµ�, 1�� �ڸ����� ����Ʈ�� �� �տ� ������ �迭�ȴٴ� ���̴�.
�� �μ��� ���Ͽ� �� ���� ���� ����Ʈ�� ��ȯ�ϴ� �Լ��� �ۼ��϶�.

��)
�Է� : 	7 1 6
	5 9 2

��� : 912

�Է�: (7->1->6) + (5->9->2) ��, 617+295
���: 2->1->9. ��, 912

*/
//���ذ�






/* 3.(2.6) ��ȯ ���� ����Ʈ(circular linked list)�� �־����� ��, ��ȯ�Ǵ� �κ��� ù ��带 ��ȯ�ϴ� �˰��� �ۼ�.
-���� : ��ȯ ���� ����Ʈ�� ����� next ����Ʈ�� �ռ� ��带 ��� ��� �ϳ��� ����Ű���� �����Ǿ� �ִ�
���� ����Ʈ��(������ ���� ����Ʈ��� �� �� �ִ�)

��) 
�Է�: A->B->C->D->E->C(E�� next ��尡 D �տ� �ִ� C�� ���� �Ǿ� �ִ�)
���: C

*/
//���ذ�








/* (2.7) �־��� ���� ����Ʈ�� ȸ��(palindrome)���� �˻��ϴ� �Լ� �ۼ� (Reverse ���!)

a b a -> o

b a -> x

c a b -> x

a c b c a -> o

*/
//�ذ�
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
	printf("�Է� ���� : ");
	scanf("%d", &cnt);

	for(i=0; i<cnt; i++) {			//�Ϲݰ� reverse��� �ΰ��� �������.
		Node * myNode = (Node *)malloc(sizeof(Node));
		Node * reverseNode = (Node *)malloc(sizeof(Node));
		scanf("%s", &str[i]);
		myNode->data = str[i];		//1��° ����
        myNode->next = NULL;
		reverseNode->data = str[i];	//�ٲ��� ��嵵
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

	for(i=0; i<cnt-1; i++) {			//reverseNode�� reverse����!(reverse�ϴ� �κ�)
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

	for(i=0; i<cnt; i++) {				//�� ����� ���� �˻��ϸ鼭 ������ palindrome�̰�, �ٸ��� no palindrome�̴�.
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









/* (2.7) �־��� ���� ����Ʈ�� ȸ��(palindrome)���� �˻��ϴ� �Լ� �ۼ� (��� ���!)

a b a -> o

b a -> x

c a b -> x

a c b c a -> o

*/
//�ذ�
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
	printf("�Է� ���� : ");
	scanf("%d", &cnt);

	for(i=0; i<cnt; i++) {			//�Ϲݰ� reverse��� �ΰ��� �������.
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
	
	for(i=0; i<cnt; i++) {				//�� ����� ���� �˻��ϸ鼭 ������ palindrome�̰�, �ٸ��� no palindrome�̴�.
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







/* ����Ʈ �� ������

��) �Է�: 1->2->3->4->5
    ��� : 2->1->4->3->5  
	
*/
//�ذ�
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

	printf("�Է� ���� : ");
	scanf("%d", &cnt);

	for(i=0; i<cnt; i++) {								//ó���� ��带 ������ŭ myNode�� �Է�����.
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

	tmp = head;							//�ʱ⿡, ���鿡 ���Ͽ� ��ġ�� �����.
	tmp2 = tmp->next;					// "
	head = head->next;					// "
	
	if(cnt % 2 == 1) {					//���� Ȧ������ �Է� �޾��� ��,
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
	if(cnt % 2 == 0) {					//���� ¦������ �Է� �޾��� ��,
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
	�Ｚ ����Ʈ���� ����� 1�� ����->�� ����� (swap�Լ��� �̿��Ͽ� ����!)
	����)
	�Է�)
		5
		0 1 1 3 2
	���)
		4 2 5 3 1
*/
//�ذ�
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

//�ٸ� Ǯ�� (����Ʈ)
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

// �ּ� dist[v] ���� ���� ������ ��ȯ 
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
    // �������� ���� ������ �� �ּ� ����ġ���� ���� ������ ã�´�. 
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
        selected[u]=TRUE; // ������ ��� üũ 
         
        if( dist[u] == INF ) return; 
             
        printf("%d\n", u); 

        for( v=0; v<n; v++) 
        { 
            if( adj_mat[u][v]!= INF) 
            { 
                if( !selected[v] && adj_mat[u][v]< dist[v] )  
                    dist[v] = adj_mat[u][v]; // ������ �Ÿ��� Ȯ�� 
            } 
        } 
    } 
} 

// 
void main() 
{ 
    prim(0, VERTICES); 
} */

