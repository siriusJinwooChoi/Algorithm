/* Tree, Graph Algorithm(Chapter 4)
	made by Choi Jin woo
*/
//기본 이진트리 구현 (전위(preorder)/중위(inorder)/후위(postorder) 순회)
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	int data;
	struct treeNode* leftPtr;
	struct treeNode* rightPtr;
} TreeNode;

typedef TreeNode *TreeNodePtr;  // TreeNode*와 동의어

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main() { 
	int i, item, num;
	TreeNode* rootPtr = NULL;
	//TreeNodePtr rootPtr = NULL;						// 트리를 NULL로 초기화

	printf("구성할 트리의 개수를 입력하시오 : ");
	scanf("%d", &num);

	printf("트리에 숫자를 입력하시오 : \n");
	for(i=0; i<num; i++) {
		scanf("%d", &item);
		insertNode(&rootPtr, item);
	}
	
	printf("\n전위표현식 : ");
	preOrder(rootPtr);

	printf("\n\n중위표현식 : ");
	inOrder(rootPtr);

	printf("\n\n후위표현식 : ");
	postOrder(rootPtr);
	
	printf("\n");
	
	return 0;
}

void insertNode(TreeNodePtr* treePtr, int value) {
	if(*treePtr == NULL) {									//트리가 비어있다면,
		*treePtr = (TreeNode*)malloc(sizeof(TreeNode));		// 메모리를 할당하면 데이터 대입
		if(*treePtr != NULL) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else
			printf("%d 값이 잘못되었거나, 에러입니다.\n", value);
	}
	else {										//트리가 비어있지 않으면
		if(value < (*treePtr)->data)				// ① 현재 노드의 데이터보다 삽입할 데이터가 작을 경우
			insertNode(&((*treePtr)->leftPtr), value);
		else if(value > (*treePtr)->data)		// ② 현재 노드의 데이터보다 삽입할 데이터가 더 클 경우
			insertNode(&((*treePtr)->rightPtr), value);
		else									// 중복된 값은 무시
			printf("중복");
	}
}

// 트리를 중위로 순회(왼->중->오)
void inOrder(TreeNode* treePtr) {
	if(treePtr != NULL) {				// 만약 트리가 비어있지 않으면 순회
		inOrder(treePtr->leftPtr);
		printf("%d ", treePtr->data);
		inOrder(treePtr->rightPtr);	
	}
}	// inOrder 중위 함수 끝

// 트리를 전위로 순회(중->왼->오)
void preOrder(TreeNode* treePtr) {
	if (treePtr != NULL) {				// 만약 트리가 비어있지 않으면 순회
		printf("%d ", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}	// preOrder 전위 함수 끝

// 트리를 후위로 순회(왼->오->중)
void postOrder(TreeNode* treePtr) { 
	if (treePtr != NULL) {				// 만약 트리가 비어있지 않으면 순회
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%d ", treePtr->data);
	}
}	// postOrder 후위 함수 끝
*/

//DFS C알고리즘
/*
#include<stdio.h>
#define MAX 100

int arr[MAX][MAX], reach[MAX], n;

void dfs(int vertex) {
	int i;
	reach[vertex] = 1;				//방문한 vertex는 reach배열에 1로 저장해줌.
	for(i=1; i<=n; i++)
		if(arr[vertex][i] && !reach[i]) {
			printf("\n%d->%d", vertex, i);
			dfs(i);				//재귀적으로 함으로써, 길에 따라서 차례대로 길을 printf 하게 됨.
		}
}

int main() {
	int i, j, count=0;
	printf("\nEnter number of vertices:");
	scanf("%d", &n);
	for(i=1; i<=n; i++) {		//reach와 arr배열 0으로 초기화
		reach[i]=0;
		for(j=1; j<=n; j++)
			arr[i][j]=0;
	}
	printf("\nEnter the adjacency matrix: \n");		//인접행렬에 대하여 입력받음
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d", &arr[i][j]);
	
	dfs(1);		//루트노드(시작노드)는 1로 설정해줌. (임의로)
	printf("\n");

	for(i=1; i<=n; i++) {
		if(reach[i])				//reach에는 방문한 vertex들이 1로 바뀌어 저장되게 되는데, 1로 바뀐값들을 count 해준다.
			count++;
	}

	
	if(count == n)					//만약 방문한 vertex들의 count수가, 전체 vertex수(n)과 다르면, 그래프는 연결되어 있지 않다는 것을 알 수 있다.
		printf("\nGraph is connected");
	else
		printf("\nGraph is not connected");
	
	return 0;
}
*/

//BFS C알고리즘
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

/* 4.1) 주어진 이진 트리가 균형 이진 트리인지 판별하는함수를 구현하라. 
이 문제에서 이진트리는 어떤 노드의 두 자식 두 자식 트리 깊이가 하나 이상 차이나지 않는
트리다. */






/* 4.2) 주어진 유향그래프(directed Graph)에서 특정한 두 노드간에 경로(route)가 존재
하는지를 판별하는 알고리즘을 구현하라. */






/* 4.3) 오름차순으로 정렬된 배열로부터 그 높이가 가장 낮은 이진 탐색 트리를 생성하는
알고리즘을 작성하라. 배열 내 모든 원소는 배열 내에서 유일한 값을 갖는다. */






/* 4.4) 주어진 이진 트리에서 깊이별로 연결 리스트를 만들어 내는 알고리즘을 작성하라.
(트리의 깊이가 D라면, 알고리즘 수행 결과로 D개의 연결리스트가 만들어져야 한다.) */






/* 4.5) 어떤 이진 트리가 이진 탐색 트리인지 판별하는 함수를 구현하라. */





/* 4.6) 정순회 기준으로, 이진 탐색 트리 내의 한 노드가 주어지면, 그 노드의 '다음'노드를
찾아내는 알고리즘을 작성하라. 각 노드에는 부모 노드를 가리키는 링크가 존재한다고 가정한다. */




/* 4.7) 이진 트리 내의 두 노드의 공통 선조(ancestor) 노드를 찾는 알고리즘을 설계하고 구현하라.
자료구조 내에 부가적인 노드를 저장해 두는 일은 금한다. 
주의 : 이진탐색트리가 아닐 수도 있다. */





/* 4.8) 두개의 큰 이진트리 T1, T2가 있다고 하자. T1에는 수백만 개의 노드가 있고,
T2에는 수백 개 정도의 노드가 있다. T2가 T1의 하위 트리인지 판별하는 알고리즘을 만들라.
 T1안에 노드 n이 있어 그 노드의 하위 트리가 T2와 동일하면, T2는 T1의 하위 트리다.
 다시 말해, T1에서 n부터 시작하여 그 아래쪽을 끊어내면, 그 결과가 T2와 동일해야 한다. */





/* 4.9) 각 노드에 어떤 값이 저장되어 있는 이진 트리 하나와 값 n이 주어졌을 때,
n과 같은 값을 갖는 모든 경로를 찾아라. 어떤 경로의 값은 그 경로에 포함된 모든 노드의 값의
합이며, 경로는 트리 내의 아무 위치에서나 시작하고 끝날 수 있다. */








//Prim, Kruskal Algorithm!
/*
#include <stdio.h>

#define MAX 7		//Vertex의 개수
#define INF 100		//간선의 가중치가 없는 경우 무한대로 둠.

void prim();
void kruskal();

int weight[MAX][MAX] = {		//가중치 행렬. 각 행은 각 정점에서 인접정점으로 가는 가중치를 나타냄
	{0, 5, 8, INF, INF, 3, INF},
	{5, 0, INF, 4, 2, INF, INF},
	{8, INF, 0, 10, 5, INF, INF},
	{INF, 4, 10, 0, INF, INF, 7},
	{INF, 2, 5, INF, 0, INF, 2},
	{3, INF, INF, INF, INF, 0, 3},
	{INF, INF, INF, 7, 2, 3, 0}
};

char alph[MAX] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};		//정점의 이름들

int main() {
	//prim();
	kruskal();
	printf("\n");

	return 0;
}
//프림 알고리즘
void prim() {
	int n, lnum, i, j, min, idx, tmp, sum=0;
	int dist[MAX], visit[MAX], start[MAX], finish[MAX-1];

	n = MAX;
	lnum = n-1;

	for(i=0; i<n; i++) {
		dist[i] = weight[1][i];				//weight[1][n] 은 루트노드를 B로 시작하겠다는 것임. 즉, B와 연결된 가중치 값들을 dist에 저장해줌.
		visit[i] = -1;						//B와 연결된 부분은 전부 -1로 저장해서 visit했다고 침.
	}
	dist[1] = -1;		//B는 루트이므로 가중치를 -1로 저장.
	idx = 1;
	start[0] = 1;		//시작배열은 1로.

	for(i=0; i<n-1; i++) {
		min = INF;
		for(tmp = 0; tmp < n; tmp++) {					//dist값을 비교하며 가장 최소의 값을 찾아낸다.
			if(dist[tmp] != 0 && dist[tmp] != -1 && dist[tmp] != INF) {		//만약 dist의 거리가 0, -1, 무한대가 아니라면,
				if(tmp == 0)			//tmp는 항상 0부터 시작한다. 즉 처음의 dist값을 최소값으로 설정.
					min = dist[tmp];
				else					//다음의 dist[1~]부터는 최소값을 비교하여 더 작은 값을 min으로 설정해 준다.
					if(min > dist[tmp])
						min = dist[tmp];
			}
		}

		for(j=0; j<n; j++)
			for(tmp = 0; tmp<n; tmp++)						
				if(dist[j] == -1 && weight[j][tmp] == min)		//위에서 구한 min값을 알아내기 위해, 가중치배열을 전부 탐색해서, 거리값이 -1이고, 가중치가 min값과 같다면
					start[i+1] = j;		//j값을 start배열에 넣는다.

		for(j=0; j<n; j++) {
			if(dist[j] != -1 && min >= dist[j]) {			//만약 dist값이 -1이고, min값이 dist값보다 크다면, dist에 저장 된 값이 더 최소임을 감안.
				min = dist[j];				//min값을 dist의 값으로 바꿔주고,
				finish[i] = j;				//그에 대한 j의 값을 finish배열에 저장해 준다.
				visit[idx] = j;				//그리고 j는 visit배열(방문한 배열)에 저장해줌.
				idx = j;					//j의 값은 idx를 가리킴.
			}
		}
		sum = sum + min;			//기존의 sum 값에 위에서 구한 최소값을 더해줌.
		dist[idx] = -1;		//거리는 -1로 설정해줌.
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




//크루스칼 알고리즘
void kruskal() {
	int min, i, j, n, a, b, tmp, tmp2, cycle, sum;
	int v[MAX];
	n = MAX;
	sum = 0;
	printf("result of kruskal algorithm : ");
	for(i=0; i<n; i++) //v를 1로 초기화 해줌.
		v[i] = 1;

	for(tmp = 0; tmp < n-1;) {		//cycle은 항상 0으로 초기화해주고, min 은 무한대값으로 초기화.
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


//다익스트라 알고리즘

// input 값 sample
// 첫번째 라인에는 정점의 개수, 그리고 시작 정점, 도착 정점이 입력
// 두번째 라인에는 정점별 간선의 입력받을 가중치의 개수(m)가 입력된다.
// 세번째 라인부터는 정점별 간선의 입력받을 가중치가 m번이 들어온다.
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
 
        // 각 정점으로 가는 간선의 가중치를 무한대로 초기화한다.(최소값을 구하기위해)
        for (i=1; i <= n; i++)
                for (j=1; j <= n; j++)
                        if (i != j)					//시작점과 도착점이 같은부분은 전부 0으로 초기화 되고, 나머지 부분은 무한대로 초기화된다.
                                InputArray[i][j] = INF;

        for (i=1; i <= m; i++) {			// 정점에서 정점으로 가는 간선의 가중치가 사용자로부터 입력된다.
                scanf("%d %d %d",&from, &to, &weight);
                InputArray[from][to] = weight;
        }
        for (i=1; i <= n; i++)			//처음에 dist(최단거리 정보를 가진 배열) 은 전부 무한대로 초기화된다.
                dist[i] = INF;
}

void dijkstra() {
        int i,j, min, vertex;

        dist[start] = 0;        // 시작점의 거리 0 (원래는 전부 무한대로 초기화되어있음)

        for (i=1; i <= n; i++) {
                min = INF;
                for (j=1; j <= n; j++) {
                        if (visit[j] == 0 && min > dist[j]) {   // 갈수 있는 정점중에 가장 가까운 정점 선택
                                min = dist[j];
                                vertex = j;
                        }
                }
                visit[vertex] = 1;   // 가장 가까운 정점으로 방문, i정점에서 가장 가까운 최단경로 v
                for ( j = 1;j <= n; j++) {
                        if (dist[j] > (dist[vertex] + InputArray[vertex][j]))       // 방문한 정점을 통해 다른 정점까지의 거리가 짧아지는지 계산하여 누적된값 저장
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
				if(randNum == 0) {		//우측
					j++;
					arr1[i][j] = str[0];
					visit[i][j] = ON;
				}
				else if(randNum == 1) {	//아래
					i++;
					arr1[i][j] = str[0];
					visit[i][j] = ON;
				}
				else if(randNum == 2) {	//왼쪽
					j--;
					arr1[i][j] = str[0];
					visit[i][j] = ON;
				}
				else if(randNum == 3) {	//위
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