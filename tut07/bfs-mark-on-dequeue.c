/*

Incorrect BFS implementation for cyclic graph

This implementation demonstrates how BFS can go wrong if
you reuse the characteristics of the DFS implementation,
namely marking a node as visited when dequeuing instead of
when enqueuing. When you mark visited on dequeue, you are adding duplicates of
nodes to the queue (assuming the graph has cycles) which messes up the
predecessor array.

If you don't care about getting the correct predecessor array (array that tracks
the predecessor node of each node on the path back towards the source) then this
BFS implementation is actually perfectly valid.

void breadthFirst(Graph g, int src) {
        bool *visited = calloc(g->nV, sizeof(bool));
        int *pred = calloc(g->nV, sizeof(int));
        Queue q = QueueNew();

        QueueEnqueue(q, src);
        while (!QueueIsEmpty(q)) {
                int v = QueueDequeue(q);

                if (visited[v]) continue;
                visited[v] = true;

                printf("%d\n", v);
                for (int w = 0; w < g->nV; w++) {
                        if (g->edges[v][w] && !visited[w]) {
                                pred[w] = v;
                                QueueEnqueue(q, w);
                        }
                }
        }

        free(visited);
        free(pred);
        QueueFree(q);
}

*/
