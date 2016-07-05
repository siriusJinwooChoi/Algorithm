/* 30계단 다익스트라2 알고리즘
	made by Choi Jin woo
*/
/*
#include <stdio.h>
#define MAX 1000

int matrix[MAX][MAX]

//int arr[NUM+1][NUM+1], visit[NUM+1], vertex[NUM+1], seq[NUM+1], tmp[NUM+1];

int main () {
	//int N, M, S, i, j, from, to, cost, min, v, cnt=0;
	int i, j, mat, row;

	scanf("%d %d", &mat, &row);

	for(i=0; i<mat; i++) {
		for(j=0; j<row; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	scanf("%d %d", &startmat, &startrow);
	scanf("%d %d", &destimat, &mestirow);

	for(i=1; i<=N; i++) {
		visit[i] = 0;
		vertex[i] = INF;
		for(j=1; j<NUM+1; j++) {
			if(i != j)
				arr[i][j] = INF;
		}
	}
	
	for(i=0; i<M; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		arr[from][to] = cost;
	}

	vertex[S] = 0;

	for (i=1; i <= N; i++) {
		min = 999999;
        for (j=1; j <= N; j++) {
			if (visit[j] == 0 && min > vertex[j]) {   // 갈수 있는 정점중에 가장 가까운 정점 선택
				min = vertex[j];
                v = j;
			}
		}
        visit[v] = 1;   // 가장 가까운 정점으로 방문, i정점에서 가장 가까운 최단경로 v
		seq[S] = S;
        for (j = 1; j <= N; j++) {
			if (vertex[j] > (vertex[v] + arr[v][j])) {      // 방문한 정점을 통해 다른 정점까지의 거리가 짧아지는지 계산하여 누적된값 저장
				vertex[j] = vertex[v] + arr[v][j];
				seq[j] = v;
			}
		}
	}
	
	for(i=1; i<=N; i++) {
		j = i;
		if(S != i) {
			tmp[cnt++] = i;
		}
		while(1) {
			if(seq[j] == S) {
				tmp[cnt++] = seq[j];
				break;
			}
			else {
				tmp[cnt++] = seq[j];
				j = seq[j];
			}
		}
		
		for(j=N-1; j>=0; j--)
			if(tmp[j] != 0)
				printf("%d ", tmp[j]);
			printf("\n");
		cnt = 0;
		for(j=0; j<N; j++)
			tmp[j] = 0;
	}
	return 0;
}*/

