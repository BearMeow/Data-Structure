#include <stdio.h>
#include <stdbool.h>

#define RECURSIVE 0
#define ITERATIVE 1
#define MODE ITERATIVE

bool visited[10];

void DFS(int *G, int n, int begin);

int main(void)
{
  /* node 0~9 undirected graph */
  int G[10][10] = {0};

  /*    9--4---8
   *   /|     /
   *  1 |    /
   *   \|   /
   *    6--0
   */
  G[1][9] = G[9][1] = 1;
  G[1][6] = G[6][1] = 1;
  G[6][9] = G[9][6] = 1;
  G[4][9] = G[9][4] = 1;
  G[4][8] = G[8][4] = 1;
  G[0][6] = G[6][0] = 1;
  G[0][8] = G[8][0] = 1;

  for(int i=0; i<10; i++)
  {
    visited[i] = false;
  }

  printf("DFS = ");
  DFS(&G[0][0], 10, 1);
  printf("\n");

  return 0;
}

void DFS(int *G, int n, int begin)
{
#if (MODE == RECURSIVE)
  printf("%d ", begin);
  visited[begin] = true;

  for(int i=0; i<n; i++)
  {
    if(G[begin*n+i] == 1 && visited[i] == false)
    {
      DFS(G, n, i);
    }
  }
#elif (MODE == ITERATIVE)
  const int CAPACITY = 16;
  int stack[CAPACITY], top = -1;

  stack[++top] = begin;

  while(top >= 0)
  {
    int tmp = stack[top--];
    
    if(visited[tmp] == false)
    {
      printf("%d ", tmp);
      visited[tmp] = true;
    }

    for(int i=0; i<n; i++)
    {
      if(G[tmp*n+i] == 1 && visited[i] == false)
      {
        stack[++top] = i;
      }
    }
  }
#endif
}
