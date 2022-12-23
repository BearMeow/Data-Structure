#include <stdio.h>
#include <stdbool.h>

void BFS(int *G, int n, int begin);

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

  printf("BFS = ");
  BFS(&G[0][0], 10, 1);
  printf("\n");

  return 0;
}

void BFS(int *G, int n, int begin)
{
  const int CAPACITY = 16;
  int q[CAPACITY], front = 0, back = 0;
  bool visited[n];

  for(int i=0; i<n; i++)
  {
    visited[i] = false;
  }

  back = (back+1) % CAPACITY;
  q[back] = begin;
  visited[begin] = true;

  while(front != back)
  {
    front = (front+1) % CAPACITY;
    int tmp = q[front];

    printf("%d ", tmp);
    
    for(int i=0; i<n; i++)
    {
      if(G[tmp*n + i] == 1 && visited[i] == false)
      {
        /* Add all adjacent that not push int queue yet. */
        back = (back+1) % CAPACITY;
        q[back] = i;
        visited[i] = true;
      }
    }
  }
}
