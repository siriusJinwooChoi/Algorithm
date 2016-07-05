/*	Stack, Queue(Chapter 3)
	maker : Choi Jin woo
*/


/* 3.2 ) push 와 pop의 두가지 연산 뿐 아니라, 
최솟값을 갖는 원소를 반환하는 min연산을 갖춘 스택은 어떻게 구현할 수 있겠는가? 
push, pop, 그리고 min은 공히 O(1)시간에 처리되어야 한다.
*/
//해결
/*
#include <stdio.h>

int arr[1000];
int main() {
	int cnt, j, caseN, ptr, i=0;

	while(1) {
		printf("Push : 1\t Pop : 2 \t min : 3 \t print : 4 \t Exit : 5\n");
		scanf("%d", &caseN);

		if(caseN == 1) {
			scanf("%d", &arr[i]);
			if(i==0)
				ptr = arr[i];
			else if(i!=0) {
				if(ptr > arr[i])
					ptr = arr[i];
			}
			i++;
		}
		else if(caseN == 2) {
			if(i != 0) {
				i--;
				ptr = arr[0];
				for(j=0; j<i; j++)
					if(ptr > arr[j])
						ptr = arr[j];
			}
			else if(i == 0)
				printf("no stack data!\n");
		}
		else if(caseN == 3)
			printf("min Value : %d\n", ptr);
		else if(caseN == 4) {
			printf("Stack Architecture\n");
			for(j=i-1; j>=0; j--)
				printf("%d\n", arr[j]);
		}
		else if(caseN == 5)
			break;
		else
			printf("다른 값을 입력하라.\n");
	}
	return 0;
}
*/









/* 3.3) 접시무더기를 떠올려보자. 접시를 너무 높이 쌓으면, 넘어질 것이다. 
그러므로 현실에서는 무더기 높이가 특정한 수준 이상으로 높아지면 새로운 무더기를 만든다. 
이것을 흉내내는 자료구조 SetOfStacks를 구현해보라. 
SetOfStacks는 여러 스택으로 구성되어야 하며, 이전 스택이 지정된 용량을 초과하는 경우 새로운 스택을 생성해야 한다.
SetOfStacks.push()와 SetOfStacks.pop()은 스택이 하나인 경우와 동일하게 동작해야 한다
(다시 말해 pop()은 정확히 하나의 스택이 있을 때와 동일한 값을 반환해야 한다.  */
/*
#include <stdio.h>
#define MAX 1000

int setOfStack_push(int t);
int setOfStack_pop();

int top = -1;
int stack[MAX];

int main() {
	int i, num;
	scanf("%d", &num);


	for(i=0; i<num; i++) {
		printf("%d", stack[i]);
	}

	return 0;
}

int setOfStack_push(int t) {
	if(top >= MAX - 1) {
		printf("\n Stack Overflow");
		return -1;
	}
	stack[++top] = t;
	return t;
}

int setOfStack_pop() {
	if(top < 0) {
		printf("\n Stack Underflow");
		return -1;
	}
	return stack[top--];
}
*/



/* 3.4) 유명한 하노이탑 문제에는 3개의 탑과 N개의 원판이 등장하는데, 
각 원판은 어느 탑으로도 옮길 수 있다. 
하노이 탑 퍼즐은 세 개의 탑 가운데 하나에 이 N개의 원판을 쌓아두고 시작한다. 
이 때 원판들은 지름이 작은 원판이 위쪽에 오도록 배열된다. 하노이 탑 퍼즐에는 다음과 같은 제약조건들이 있다.

(1) 한번에 하나의 원판만 옮길 수 있다.
(2) 탑의 맨 꼭대기에 있는 원판은 옆에 있는 탑으로 옮길 수 있다.
(3) 원판은 자기보다 지름이 큰 원판 위로만 옮길 수 있다.

스택을 사용하여, 첫번째 탑에 있는 모든 원판을 마지막 탑으로 옮기는 프로그램을 작성하라. */
//Session 과정 미확실
/*
#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top;

int push(int t) {
	if(top >= MAX - 1) {
		printf("\n Stack Overflow");
		return -1;
	}
	stack[++top] = t;
	return t;
}

int pop() {
	if(top < 0) {
		printf("\n Stack Underflow");
		return -1;
	}
	return stack[top--];
}

int is_stack_empty() {
	if(top > -1)
		return 0;
	else
		return 1;
}

void rehanoi(int n, int from, int by, int to) {
    if (n == 1)
        printf("from %d to %d\n", from, to);
    else{
        rehanoi(n - 1, from, to, by);    // 1번  N-1개의 원반을 기둥3을 거쳐 2로 옮긴다.
        printf("from %d to %d\n", from, to);
        rehanoi(n - 1, by, from, to);    // 3번 기둥 2에서 N-1개의 원반을 기둥 3으로 옮긴다.
    }
}

void hanoi(int n, int from, int by, int to) {
	top = -1;

	while(1) {
		while(n > 1) {
			push(to);
			push(by);
			push(from);
			push(n);
			n--;

			push(to);
			to = by;
			by = pop();
		}

		printf("from %d to %d\n", from, to);

		if(!is_stack_empty()) {
			n = pop();
			from = pop();
			by = pop();
			to = pop();

			printf("from %d to %d\n", from, to);

			n--;
			push(from);
			from = by;
			by = pop();
		}

		else {
			break;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);

	rehanoi(N, 1,2,3);

	return 0;
}
*/

















/* 3.5 ) 두개의 스택을 사용하여 큐를 구현하는 MyQueue 클래스를 작성해보라. */
//해결
/*
#include <stdio.h>
#include <string.h>
#define MAX 1000

int stack1[MAX];
int stack2[MAX];

int top=-1;
int top2=-1;

void push1(int t) {
	if(top >= MAX - 1) {
		printf("\n Stack Overflow \n");
	}
	stack1[++top] = t;
}

int pop1() {
	if(top < 0) {
		printf("\n Stack Underflow \n");
		return -1;
	}
	return stack1[top--];
}

void push2(int pop1data) {
	if(top2 >= MAX - 1) {
		printf("\n Stack Overflow \n");
	}
	stack2[++top2] = pop1data;
}

void pop2() {
	int k;
	if((top < 0) && (top2 < 0)) {
		printf("\n Stack Underflow \n");
	}

	if(top2 < 0) {		//만약 비어있다면,
		for(k=0; k<=top+top2+1; k++) {			//아래 연산에서 pop을 하면 top이 하나씩 감소하고, push연산에서는 top2가 1씩 증가하므로, 결국 top+top2는 top이 된다.
			push2(pop1());
		}
	}
	printf("%d\n", stack2[top2--]);
}

int main() {
	int caseN, num, i, res,data;

	printf("Input data\n");

	while(1) {
		printf("Enqueue : 1\t Dequeue : 2 \t print : 3 \t Exit : 4\n");
		scanf("%d", &caseN);

		if(caseN == 1) {
			scanf("%d", &data);
			push1(data);
		}
		else if(caseN == 2) {
			//res = pop2();
			pop2();
			//printf("%d\n", res);
		}
		else if(caseN == 3) {
			printf("Queue Architecture\n");
			
			for(i=0; i<=top; i++) {
				printf("%d ", stack1[i]);
			}
		}
		else if(caseN == 4) {
			break;
		}
		else
			printf("다른 값을 입력하라.\n");
	}

	return 0;
}
*/









/* 3.6) 스택을 오름차순으로 정렬하는 프로그램을 작성하라. 
값들을 보관하기 위해 여벌의 스택들을 더 사용하는 것은 가능하지만, 값을 배열등의 다른 자료구조로 복사할 수는 없다. 
스택은 다음의 네가지 연산을 지원한다고 가정한다.  push, pop, peek, 그리고 isEmpty */
//해결
/*
#include <stdio.h>

#define MAX 1000

int stack1[MAX];
int stack2[MAX];

int top=-1;
int top2=-1;

void push1(int t) {
	if(top >= MAX - 1) {
		printf("\n Stack Overflow \n");
	}
	stack1[++top] = t;
}

int pop1() {
	if(top < 0) {
		printf("\n Stack Underflow \n");
		return -1;
	}
	return stack1[top--];
}

void push2(int pop1data) {
	if(top2 >= MAX - 1) {
		printf("\n Stack Overflow \n");
	}
	stack2[++top2] = pop1data;
}

int pop2() {
	if(top2 < 0) {
		printf("\n Stack Underflow \n");
		return -1;
	}
	return stack2[top2--];
}

int main() {
	int i, cnt, num, tmp, tmp2;

	scanf("%d", &cnt);

	for(i=0; i<cnt; i++) {
		scanf("%d", &num);
		push1(num);
	}

	while(top > -1) {
		tmp = pop1();

		if(top2 == -1) {
			push2(tmp);
		}
		else if(top2 > -1) {
			tmp2 = stack2[top2];

			while(top2 > -1 && tmp2 > tmp) {			//stack2의 배열이 존재하고, stack2에 peek가 stack1의 peek보다 크다면,
				tmp2 = pop2();				//stack2의 값을 stack1으로 넣어줌.
				push1(tmp2);
			}
			push2(tmp);
		}
	}

	for(i=0; i<=top2; i++) {
		printf("%d ", stack2[i]);
	}

	return 0;
}
*/






/* 3.7) 먼저 들어온 동물이 먼저 나가는 동물 쉼터가 있다고 하자. 
이 쉼터는 개와 고양이만 수용할 수 있다. 사람들은 쉼터의 동물들 가운데 들어온 지 
가장 오래된동물부터 입양할 수 있는데, 개와 고양이 중 어떤 동물을 데려갈 지 선택할 수도 있다. 
특정한 동물을 지정해 데려가는 것은 금지되어 있다. 이 시스템을 자료구조로 구현하라. 
해당 자료구조는 enqueue, dequeueAny, dequeueDog, dequeueCat의 연산들을 제공해야 한다. */
/*
#include <stdio.h>
#include <string.h>

#define MAX 1000

int rear1 = - 1;
int rear2 = -1;
int front1 = - 1;
int front2 = - 1;

int num=0;
int queue_array[MAX];
int dog_array[MAX];
int cat_array[MAX];

char str[MAX];

void display();
int dequeueAny();
int dequeueDog();
int dequeueCat();
void enqueue();

int main() {
    int choice;
    while (1) {
        printf("1.enqueue \n");
        printf("2.DequeueAny \n");
		printf("3.DequeueDog \n");
		printf("4.DequeueCat \n");
        printf("5.Display \n");
        printf("6.Exit \n");
        scanf("%d", &choice);

		if(choice == 1)
			enqueue();
		else if(choice == 2)
			dequeueAny();
		else if(choice == 3)
			dequeueDog();
		else if(choice == 4)
			dequeueCat();
		else if(choice == 5)
			display();
		else if(choice == 6)
			break;
		else
			printf("Wrong choice \n");
    }
}

void enqueue() {
    int add_item;
    if ((rear1 == MAX - 1) || (rear2 == MAX - 1))
		printf("Queue Overflow \n");
    else {
        if (front1 == - 1)	//만약 큐가 비어져있다면,
			front1 = 0;
		if (front2 == - 1)
			front2 = 0;

		scanf("%s %d", str, num);
		if(strcmp(str, "dog") == 0) {
			dog_array[rear1]++;
		}
		else if(strcmp(str, "cat") == 0) {
			cat_array[rear2]++;
		}
        //scanf("%d", &add_item);		//큐에넣을 값 받기
        rear += 1;
        queue_array[rear] = add_item;
    }
}

int dequeueAny() {
	int i;
	for(i=0; i<rear1+rear2; i++) {
		//queue_array[i] = ;
	}
}

int dequeueDog() {
    if (front1 == - 1 || front1 > rear1) {
        printf("Queue Underflow \n");
        return -1;
    }
    else {
        printf("Dequeue : %d\n", queue_array[front1]);
        front1 = front1 + 1;
    }
}

int dequeueCat() {
    if (front2 == - 1 || front2 > rear2) {
        printf("Queue Underflow \n");
        return -1;
    }
    else {
        printf("Dequeue : %d\n", queue_array[front2]);
        front2 = front2 + 1;
    }
}
*/
/*
void display() {
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}*/