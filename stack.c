/*	Stack, Queue(Chapter 3)
	maker : Choi Jin woo
*/


/* 3.2 ) push �� pop�� �ΰ��� ���� �� �ƴ϶�, 
�ּڰ��� ���� ���Ҹ� ��ȯ�ϴ� min������ ���� ������ ��� ������ �� �ְڴ°�? 
push, pop, �׸��� min�� ���� O(1)�ð��� ó���Ǿ�� �Ѵ�.
*/
//�ذ�
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
			printf("�ٸ� ���� �Է��϶�.\n");
	}
	return 0;
}
*/









/* 3.3) ���ù����⸦ ���÷�����. ���ø� �ʹ� ���� ������, �Ѿ��� ���̴�. 
�׷��Ƿ� ���ǿ����� ������ ���̰� Ư���� ���� �̻����� �������� ���ο� �����⸦ �����. 
�̰��� �䳻���� �ڷᱸ�� SetOfStacks�� �����غ���. 
SetOfStacks�� ���� �������� �����Ǿ�� �ϸ�, ���� ������ ������ �뷮�� �ʰ��ϴ� ��� ���ο� ������ �����ؾ� �Ѵ�.
SetOfStacks.push()�� SetOfStacks.pop()�� ������ �ϳ��� ���� �����ϰ� �����ؾ� �Ѵ�
(�ٽ� ���� pop()�� ��Ȯ�� �ϳ��� ������ ���� ���� ������ ���� ��ȯ�ؾ� �Ѵ�.  */
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



/* 3.4) ������ �ϳ���ž �������� 3���� ž�� N���� ������ �����ϴµ�, 
�� ������ ��� ž���ε� �ű� �� �ִ�. 
�ϳ��� ž ������ �� ���� ž ��� �ϳ��� �� N���� ������ �׾Ƶΰ� �����Ѵ�. 
�� �� ���ǵ��� ������ ���� ������ ���ʿ� ������ �迭�ȴ�. �ϳ��� ž ���񿡴� ������ ���� �������ǵ��� �ִ�.

(1) �ѹ��� �ϳ��� ���Ǹ� �ű� �� �ִ�.
(2) ž�� �� ����⿡ �ִ� ������ ���� �ִ� ž���� �ű� �� �ִ�.
(3) ������ �ڱ⺸�� ������ ū ���� ���θ� �ű� �� �ִ�.

������ ����Ͽ�, ù��° ž�� �ִ� ��� ������ ������ ž���� �ű�� ���α׷��� �ۼ��϶�. */
//Session ���� ��Ȯ��
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
        rehanoi(n - 1, from, to, by);    // 1��  N-1���� ������ ���3�� ���� 2�� �ű��.
        printf("from %d to %d\n", from, to);
        rehanoi(n - 1, by, from, to);    // 3�� ��� 2���� N-1���� ������ ��� 3���� �ű��.
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

















/* 3.5 ) �ΰ��� ������ ����Ͽ� ť�� �����ϴ� MyQueue Ŭ������ �ۼ��غ���. */
//�ذ�
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

	if(top2 < 0) {		//���� ����ִٸ�,
		for(k=0; k<=top+top2+1; k++) {			//�Ʒ� ���꿡�� pop�� �ϸ� top�� �ϳ��� �����ϰ�, push���꿡���� top2�� 1�� �����ϹǷ�, �ᱹ top+top2�� top�� �ȴ�.
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
			printf("�ٸ� ���� �Է��϶�.\n");
	}

	return 0;
}
*/









/* 3.6) ������ ������������ �����ϴ� ���α׷��� �ۼ��϶�. 
������ �����ϱ� ���� ������ ���õ��� �� ����ϴ� ���� ����������, ���� �迭���� �ٸ� �ڷᱸ���� ������ ���� ����. 
������ ������ �װ��� ������ �����Ѵٰ� �����Ѵ�.  push, pop, peek, �׸��� isEmpty */
//�ذ�
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

			while(top2 > -1 && tmp2 > tmp) {			//stack2�� �迭�� �����ϰ�, stack2�� peek�� stack1�� peek���� ũ�ٸ�,
				tmp2 = pop2();				//stack2�� ���� stack1���� �־���.
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






/* 3.7) ���� ���� ������ ���� ������ ���� ���Ͱ� �ִٰ� ����. 
�� ���ʹ� ���� ����̸� ������ �� �ִ�. ������� ������ ������ ��� ���� �� 
���� �����ȵ������� �Ծ��� �� �ִµ�, ���� ����� �� � ������ ������ �� ������ ���� �ִ�. 
Ư���� ������ ������ �������� ���� �����Ǿ� �ִ�. �� �ý����� �ڷᱸ���� �����϶�. 
�ش� �ڷᱸ���� enqueue, dequeueAny, dequeueDog, dequeueCat�� ������� �����ؾ� �Ѵ�. */
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
        if (front1 == - 1)	//���� ť�� ������ִٸ�,
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
        //scanf("%d", &add_item);		//ť������ �� �ޱ�
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