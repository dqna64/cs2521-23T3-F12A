/*

Correct DFS implementation for cyclic graph

void depthFirst(Graph g, int src) {
        bool *visited = calloc(g->nV, sizeof(bool));
        int *pred = calloc(g->nV, sizeof(int));
        Stack s = StackNew();

        StackPush(s, src);
        while (!StackIsEmpty(s)) {
                int v = StackPop(s);

                if (visited[v]) continue;
                visited[v] = true;

                printf("%d\n", v);
                for (int w = g->nV - 1; w >= 0; w--) {
                        if (g->edges[v][w] && !visited[w]) {
                                pred[w] = v;
                                StackPush(s, w);
                        }
                }
        }

        free(visited);
        free(pred);
        StackFree(s);
}

*/
