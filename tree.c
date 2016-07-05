/* Tree, Graph Algorithm(Chapter 4)
	made by Choi Jin woo
*/
//�⺻ ����Ʈ�� ���� (����(preorder)/����(inorder)/����(postorder) ��ȸ)
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	int data;
	struct treeNode* leftPtr;
	struct treeNode* rightPtr;
} TreeNode;

typedef TreeNode *TreeNodePtr;  // TreeNode*�� ���Ǿ�

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main() { 
	int i, item, num;
	TreeNode* rootPtr = NULL;
	//TreeNodePtr rootPtr = NULL;						// Ʈ���� NULL�� �ʱ�ȭ

	printf("������ Ʈ���� ������ �Է��Ͻÿ� : ");
	scanf("%d", &num);

	printf("Ʈ���� ���ڸ� �Է��Ͻÿ� : \n");
	for(i=0; i<num; i++) {
		scanf("%d", &item);
		insertNode(&rootPtr, item);
	}
	
	printf("\n����ǥ���� : ");
	preOrder(rootPtr);

	printf("\n\n����ǥ���� : ");
	inOrder(rootPtr);

	printf("\n\n����ǥ���� : ");
	postOrder(rootPtr);
	
	printf("\n");
	
	return 0;
}

void insertNode(TreeNodePtr* treePtr, int value) {
	if(*treePtr == NULL) {									//Ʈ���� ����ִٸ�,
		*treePtr = (TreeNode*)malloc(sizeof(TreeNode));		// �޸𸮸� �Ҵ��ϸ� ������ ����
		if(*treePtr != NULL) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else
			printf("%d ���� �߸��Ǿ��ų�, �����Դϴ�.\n", value);
	}
	else {										//Ʈ���� ������� ������
		if(value < (*treePtr)->data)				// �� ���� ����� �����ͺ��� ������ �����Ͱ� ���� ���
			insertNode(&((*treePtr)->leftPtr), value);
		else if(value > (*treePtr)->data)		// �� ���� ����� �����ͺ��� ������ �����Ͱ� �� Ŭ ���
			insertNode(&((*treePtr)->rightPtr), value);
		else									// �ߺ��� ���� ����
			printf("�ߺ�");
	}
}

// Ʈ���� ������ ��ȸ(��->��->��)
void inOrder(TreeNode* treePtr) {
	if(treePtr != NULL) {				// ���� Ʈ���� ������� ������ ��ȸ
		inOrder(treePtr->leftPtr);
		printf("%d ", treePtr->data);
		inOrder(treePtr->rightPtr);	
	}
}	// inOrder ���� �Լ� ��

// Ʈ���� ������ ��ȸ(��->��->��)
void preOrder(TreeNode* treePtr) {
	if (treePtr != NULL) {				// ���� Ʈ���� ������� ������ ��ȸ
		printf("%d ", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}	// preOrder ���� �Լ� ��

// Ʈ���� ������ ��ȸ(��->��->��)
void postOrder(TreeNode* treePtr) { 
	if (treePtr != NULL) {				// ���� Ʈ���� ������� ������ ��ȸ
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%d ", treePtr->data);
	}
}	// postOrder ���� �Լ� ��
*/

//DFS C�˰���
/*
#include<stdio.h>
#define MAX 100

int arr[MAX][MAX], reach[MAX], n;

void dfs(int vertex) {
	int i;
	reach[vertex] = 1;				//�湮�� vertex�� reach�迭�� 1�� ��������.
	for(i=1; i<=n; i++)
		if(arr[vertex][i] && !reach[i]) {
			printf("\n%d->%d", vertex, i);
			dfs(i);				//��������� �����ν�, �濡 ���� ���ʴ�� ���� printf �ϰ� ��.
		}
}

int main() {
	int i, j, count=0;
	printf("\nEnter number of vertices:");
	scanf("%d", &n);
	for(i=1; i<=n; i++) {		//reach�� arr�迭 0���� �ʱ�ȭ
		reach[i]=0;
		for(j=1; j<=n; j++)
			arr[i][j]=0;
	}
	printf("\nEnter the adjacency matrix: \n");		//������Ŀ� ���Ͽ� �Է¹���
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d", &arr[i][j]);
	
	dfs(1);		//��Ʈ���(���۳��)�� 1�� ��������. (���Ƿ�)
	printf("\n");

	for(i=1; i<=n; i++) {
		if(reach[i])				//reach���� �湮�� vertex���� 1�� �ٲ�� ����ǰ� �Ǵµ�, 1�� �ٲﰪ���� count ���ش�.
			count++;
	}

	
	if(count == n)					//���� �湮�� vertex���� count����, ��ü vertex��(n)�� �ٸ���, �׷����� ����Ǿ� ���� �ʴٴ� ���� �� �� �ִ�.
		printf("\nGraph is connected");
	else
		printf("\nGraph is not connected");
	
	return 0;
}
*/

//BFS C�˰���
/*
#include<stdio.h>
#define MAX 100
int arr[MAX][MAX], queue[MAX], visited[MAX], n, front=0, rear=-1;

void bfs(int vertex) {
	int i;

	for(i=1; i<=n; i++)
		if(arr[vertex][i] && !visited[i])
			queue[++rear] = i;

	if(front <= rear) {
		visited[queue[front]] = 1;
		bfs(queue[front++]);
	}
}
int main() {
	int vertex, i, j;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	
	for(i=1; i<=n; i++) {
		queue[i]=0;
		visited[i]=0;
	}
	printf("\nEnter graph data in matrix form:\n");
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++)
			scanf("%d", &arr[i][j]);
	}

	printf("\nEnter the starting vertex: ");
	scanf("%d", &vertex);
	
	bfs(vertex);

	printf("\nThe node which are reachable are:\n");
	for(i=1; i<=n; i++) {
		if(visited[i])
			printf("%d ", i);
		else
			printf("\nBfs is not possible");
	}

	return 0;
}
*/

/* 4.1) �־��� ���� Ʈ���� ���� ���� Ʈ������ �Ǻ��ϴ��Լ��� �����϶�. 
�� �������� ����Ʈ���� � ����� �� �ڽ� �� �ڽ� Ʈ�� ���̰� �ϳ� �̻� ���̳��� �ʴ�
Ʈ����. */






/* 4.2) �־��� ����׷���(directed Graph)���� Ư���� �� ��尣�� ���(route)�� ����
�ϴ����� �Ǻ��ϴ� �˰����� �����϶�. */






/* 4.3) ������������ ���ĵ� �迭�κ��� �� ���̰� ���� ���� ���� Ž�� Ʈ���� �����ϴ�
�˰����� �ۼ��϶�. �迭 �� ��� ���Ҵ� �迭 ������ ������ ���� ���´�. */






/* 4.4) �־��� ���� Ʈ������ ���̺��� ���� ����Ʈ�� ����� ���� �˰����� �ۼ��϶�.
(Ʈ���� ���̰� D���, �˰��� ���� ����� D���� ���Ḯ��Ʈ�� ��������� �Ѵ�.) */






/* 4.5) � ���� Ʈ���� ���� Ž�� Ʈ������ �Ǻ��ϴ� �Լ��� �����϶�. */





/* 4.6) ����ȸ ��������, ���� Ž�� Ʈ�� ���� �� ��尡 �־�����, �� ����� '����'��带
ã�Ƴ��� �˰����� �ۼ��϶�. �� ��忡�� �θ� ��带 ����Ű�� ��ũ�� �����Ѵٰ� �����Ѵ�. */




/* 4.7) ���� Ʈ�� ���� �� ����� ���� ����(ancestor) ��带 ã�� �˰����� �����ϰ� �����϶�.
�ڷᱸ�� ���� �ΰ����� ��带 ������ �δ� ���� ���Ѵ�. 
���� : ����Ž��Ʈ���� �ƴ� ���� �ִ�. */





/* 4.8) �ΰ��� ū ����Ʈ�� T1, T2�� �ִٰ� ����. T1���� ���鸸 ���� ��尡 �ְ�,
T2���� ���� �� ������ ��尡 �ִ�. T2�� T1�� ���� Ʈ������ �Ǻ��ϴ� �˰����� �����.
 T1�ȿ� ��� n�� �־� �� ����� ���� Ʈ���� T2�� �����ϸ�, T2�� T1�� ���� Ʈ����.
 �ٽ� ����, T1���� n���� �����Ͽ� �� �Ʒ����� �����, �� ����� T2�� �����ؾ� �Ѵ�. */





/* 4.9) �� ��忡 � ���� ����Ǿ� �ִ� ���� Ʈ�� �ϳ��� �� n�� �־����� ��,
n�� ���� ���� ���� ��� ��θ� ã�ƶ�. � ����� ���� �� ��ο� ���Ե� ��� ����� ����
���̸�, ��δ� Ʈ�� ���� �ƹ� ��ġ������ �����ϰ� ���� �� �ִ�. */








//Prim, Kruskal Algorithm!
/*
#include <stdio.h>

#define MAX 7		//Vertex�� ����
#define INF 100		//������ ����ġ�� ���� ��� ���Ѵ�� ��.

void prim();
void kruskal();

int weight[MAX][MAX] = {		//����ġ ���. �� ���� �� �������� ������������ ���� ����ġ�� ��Ÿ��
	{0, 5, 8, INF, INF, 3, INF},
	{5, 0, INF, 4, 2, INF, INF},
	{8, INF, 0, 10, 5, INF, INF},
	{INF, 4, 10, 0, INF, INF, 7},
	{INF, 2, 5, INF, 0, INF, 2},
	{3, INF, INF, INF, INF, 0, 3},
	{INF, INF, INF, 7, 2, 3, 0}
};

char alph[MAX] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};		//������ �̸���

int main() {
	//prim();
	kruskal();
	printf("\n");

	return 0;
}
//���� �˰���
void prim() {
	int n, lnum, i, j, min, idx, tmp, sum=0;
	int dist[MAX], visit[MAX], start[MAX], finish[MAX-1];

	n = MAX;
	lnum = n-1;

	for(i=0; i<n; i++) {
		dist[i] = weight[1][i];				//weight[1][n] �� ��Ʈ��带 B�� �����ϰڴٴ� ����. ��, B�� ����� ����ġ ������ dist�� ��������.
		visit[i] = -1;						//B�� ����� �κ��� ���� -1�� �����ؼ� visit�ߴٰ� ħ.
	}
	dist[1] = -1;		//B�� ��Ʈ�̹Ƿ� ����ġ�� -1�� ����.
	idx = 1;
	start[0] = 1;		//���۹迭�� 1��.

	for(i=0; i<n-1; i++) {
		min = INF;
		for(tmp = 0; tmp < n; tmp++) {					//dist���� ���ϸ� ���� �ּ��� ���� ã�Ƴ���.
			if(dist[tmp] != 0 && dist[tmp] != -1 && dist[tmp] != INF) {		//���� dist�� �Ÿ��� 0, -1, ���Ѵ밡 �ƴ϶��,
				if(tmp == 0)			//tmp�� �׻� 0���� �����Ѵ�. �� ó���� dist���� �ּҰ����� ����.
					min = dist[tmp];
				else					//������ dist[1~]���ʹ� �ּҰ��� ���Ͽ� �� ���� ���� min���� ������ �ش�.
					if(min > dist[tmp])
						min = dist[tmp];
			}
		}

		for(j=0; j<n; j++)
			for(tmp = 0; tmp<n; tmp++)						
				if(dist[j] == -1 && weight[j][tmp] == min)		//������ ���� min���� �˾Ƴ��� ����, ����ġ�迭�� ���� Ž���ؼ�, �Ÿ����� -1�̰�, ����ġ�� min���� ���ٸ�
					start[i+1] = j;		//j���� start�迭�� �ִ´�.

		for(j=0; j<n; j++) {
			if(dist[j] != -1 && min >= dist[j]) {			//���� dist���� -1�̰�, min���� dist������ ũ�ٸ�, dist�� ���� �� ���� �� �ּ����� ����.
				min = dist[j];				//min���� dist�� ������ �ٲ��ְ�,
				finish[i] = j;				//�׿� ���� j�� ���� finish�迭�� ������ �ش�.
				visit[idx] = j;				//�׸��� j�� visit�迭(�湮�� �迭)�� ��������.
				idx = j;					//j�� ���� idx�� ����Ŵ.
			}
		}
		sum = sum + min;			//������ sum ���� ������ ���� �ּҰ��� ������.
		dist[idx] = -1;		//�Ÿ��� -1�� ��������.
		visit[i] = idx;		//visit

		if(i == n-2)
			break;
		for(j=0; j<n; j++) {
			if(dist[j] > weight[idx][j]) {
				dist[j] = weight[idx][j];
				if(i+1 != n-1)
					start[i+1] = idx;
			}
		}
	}

	printf("Result of prim algorithm : ");

	for(i=0; i<n-1; i++)
		printf("(%c, %c) ", alph[start[i]], alph[finish[i]]);

	printf("\nSum = %d", sum);
}




//ũ�罺Į �˰���
void kruskal() {
	int min, i, j, n, a, b, tmp, tmp2, cycle, sum;
	int v[MAX];
	n = MAX;
	sum = 0;
	printf("result of kruskal algorithm : ");
	for(i=0; i<n; i++) //v�� 1�� �ʱ�ȭ ����.
		v[i] = 1;

	for(tmp = 0; tmp < n-1;) {		//cycle�� �׻� 0���� �ʱ�ȭ���ְ�, min �� ���Ѵ밪���� �ʱ�ȭ.
		min = INF;
		cycle = 0;

		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				if(weight[i][j] != 0 && weight[i][j] != -1 && weight[i][j] != INF) {
					if(min > weight[i][j]) {
						min = weight[i][j];
						a = i;
						b = j;
					}
				}
			}
		}
		for(i=0; i<n; i++) {
			if(weight[a][i] == -1 && weight[i][b] == -1) {
				weight[a][b] = -1;
				weight[b][a] = -1;
			}
		}

		if(v[a] == -1 && v[b] == -1)
			for(i=0; i<n; i++) {
				if(weight[a][i] == -1 && weight[i][b] == -1) {
					cycle = 1;
					break;
				}
			}

		if(cycle == 0) {
			printf("(%c, %c) ", alph[a], alph[b]);
			v[a] = -1;
			v[b] = -1;
			weight[a][b] = -1;
			weight[b][a] = -1;
			sum += min;
			tmp++;
		}

		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				for(tmp2= 0; tmp2 < n; tmp2++) {
					if(weight[i][tmp2] == -1 && weight[tmp2][j] == -1) {
						weight[i][j] = -1;
						weight[j][i] = -1;
					}
				}
			}
		}
	}
	printf(", Sum = %d", sum);
}	
*/


//���ͽ�Ʈ�� �˰���

// input �� sample
// ù��° ���ο��� ������ ����, �׸��� ���� ����, ���� ������ �Է�
// �ι�° ���ο��� ������ ������ �Է¹��� ����ġ�� ����(m)�� �Էµȴ�.
// ����° ���κ��ʹ� ������ ������ �Է¹��� ����ġ�� m���� ���´�.
/*
7 1 7
9
1 2 4
1 3 2
2 4 1
2 5 2
3 4 7
3 6 3
4 7 3
5 7 1
6 7 5 
*/
 
/*
#include <stdio.h> 
#define N 100
#define INF 100000

int InputArray[N+1][N+1], visit[N+1], dist[N+1];
int start, end, n, m;

void input() {
        int i,j, from, to, weight;

        scanf("%d %d %d",&n, &start, &end);
        scanf("%d",&m);
 
        // �� �������� ���� ������ ����ġ�� ���Ѵ�� �ʱ�ȭ�Ѵ�.(�ּҰ��� ���ϱ�����)
        for (i=1; i <= n; i++)
                for (j=1; j <= n; j++)
                        if (i != j)					//�������� �������� �����κ��� ���� 0���� �ʱ�ȭ �ǰ�, ������ �κ��� ���Ѵ�� �ʱ�ȭ�ȴ�.
                                InputArray[i][j] = INF;

        for (i=1; i <= m; i++) {			// �������� �������� ���� ������ ����ġ�� ����ڷκ��� �Էµȴ�.
                scanf("%d %d %d",&from, &to, &weight);
                InputArray[from][to] = weight;
        }
        for (i=1; i <= n; i++)			//ó���� dist(�ִܰŸ� ������ ���� �迭) �� ���� ���Ѵ�� �ʱ�ȭ�ȴ�.
                dist[i] = INF;
}

void dijkstra() {
        int i,j, min, vertex;

        dist[start] = 0;        // �������� �Ÿ� 0 (������ ���� ���Ѵ�� �ʱ�ȭ�Ǿ�����)

        for (i=1; i <= n; i++) {
                min = INF;
                for (j=1; j <= n; j++) {
                        if (visit[j] == 0 && min > dist[j]) {   // ���� �ִ� �����߿� ���� ����� ���� ����
                                min = dist[j];
                                vertex = j;
                        }
                }
                visit[vertex] = 1;   // ���� ����� �������� �湮, i�������� ���� ����� �ִܰ�� v
                for ( j = 1;j <= n; j++) {
                        if (dist[j] > (dist[vertex] + InputArray[vertex][j]))       // �湮�� ������ ���� �ٸ� ���������� �Ÿ��� ª�������� ����Ͽ� �����Ȱ� ����
                                dist[j] = dist[vertex] + InputArray[vertex][j];
                }
        }
}

int main(void) {
        input();
        dijkstra();
        printf("%d \n",dist[end]);
        return 0;
}*/














/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4
#define ON 1
#define OFF 0

char arr1[MAX][MAX];
int carr[MAX][MAX];
int visit[MAX][MAX];

int main() {
	int i, j, randNum;
	char str[] = "apple";

	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			arr1[i][j] = rand()%26 + 65;
			carr[i][j] = strlen(str);
			visit[i][j] = 0;
		}
	}

	arr1[0][0] = str[0];
	visit[0][0] = ON;

	while(strlen(str) != 0) {
		for(i=0; i<1; i++) {
			for(j=0; j<1; j++) {
				carr[++i][j]--;
				carr[i][j++]--;
				carr[--i][j]--;
				carr[i][--j]--;
	
				randNum = rand()%4;
				if(randNum == 0) {		//����
					j++;
					arr1[i][j] = str[0];
					visit[i][j] = ON;
				}
				else if(randNum == 1) {	//�Ʒ�
					i++;
					arr1[i][j] = str[0];
					visit[i][j] = ON;
				}
				else if(randNum == 2) {	//����
					j--;
					arr1[i][j] = str[0];
					visit[i][j] = ON;
				}
				else if(randNum == 3) {	//��
					i--;
					arr1[i][j] = str[0];
					visit[i][j] = ON;
				}
			}
		}

		for(i=0; i<strlen(str); i++) {
			str[i] = str[i+1];
		}
		str[strlen(str)] = '\0';
	}

	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			printf("%c ", arr1[i][j]);
		}
		printf("\n");
	}

	
	for(i=0; i<strlen(str); i++) {
		str[i] = str[i+1];
	}
	str[strlen(str)] = '\0';
	
	return 0;
}

*/