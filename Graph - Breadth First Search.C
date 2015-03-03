/* Program to perform breadth first traversal on a graph */

#include <stdio.h>

#define QUEUESIZE 10
#define ERROR (-1)
#define OK      0


struct queue
{
    int  front , rear ;
    int  items[QUEUESIZE] ;
};

/* Assuming maximum 9 vertices.*/
int  v , adj[10][10] , visited[10] ;

void bfs(int k);

int main()
{
    int  i , j ;


    /* Creating graph of v vertices */
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &v);

    for(i = 1 ; i <= v ; i++)
        for(j = 1 ; j <= v ; j++)
        {
            printf("Is vertex %d adjacent to vertex %d ? ", j, i);
            printf("Enter 1 if yes and 0 if no. ");
            scanf("%d", &adj[i][j]);
        }

    /* Making all the vertices as unvisited */
    for(i = 1 ; i <= v ; i++)
        visited[i] = 0;

    printf("Breadth first Search of the graph is as shown:\n");
    for(i = 1 ; i <= v ; i++)
        if(visited[i] == 0)
            bfs(i);
    /* Initiating bfs from vertex i if it is not visited */

    return 0;
}

int empty(struct  queue  *pq)
{
    if(pq->rear < pq->front)
        return 1;
    else
        return 0;
}

int removes(struct  queue  *pq)
{
    return (pq->items[(pq->front)++]);
}

int insert(struct queue *pq , int x)
{
    if(pq->rear == QUEUESIZE - 1)
    {
        printf("Queue Overflow. Cannot insert. \n");
        return ERROR;
    }
    pq->items[++(pq->rear)] = x;
    return OK;
}

int sequential(struct queue q , int key)
{
    int i = 0;
    while(i < QUEUESIZE)
        if(key == q.items[i])
            return i;
        else
            i++;
    return -1;
}


void bfs(int k)
{
    int  j ;

    struct queue q ;
    q.rear = -1;
    q.front = 0;

    insert(&q, k);
    while(!empty(&q))
    {
        k = removes(&q);
        visited[k] = 1;
        printf("%d ", k);
        for(j = 1 ; j <= v ; j++)
            if(adj[k][j] == 1)
                if(visited[j] == 0 && (sequential(q, j)) == -1)
                    insert(&q, j);
    }
}


