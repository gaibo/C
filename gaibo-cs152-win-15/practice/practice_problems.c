#include <stdio.h>
#include <stdlib.h>


// Linked Lists

typedef struct int_list int_list;
struct int_list {
    int val;
    int_list* next;
};

void list_show(int_list* list) {
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
    return;
}

void list_free(int_list* list) {
    if (list != NULL) {
        list_free(list->next);
        free(list);
    }
    return;
}

// NOTE: DESTRUCTIVE MEANS THE INPUT IS REARRANGED
// YOU WON'T GET A MEMORY LEAK FROM USING THIS IT'LL JUST RETURN YOU
// THE NEW HEAD WITH EVERYTHING ELSE FIXED ACCORDINGLY
int_list* il_rev(int_list* ns) {
    int_list *prev, *next;
    prev = NULL;
    while (ns != NULL) {
        next = ns->next;
        ns->next = prev;
        prev = ns;
        ns = next;
    }
    return prev;
}

void il_rev_d(int_list** ns) {
    int_list* reversed = il_rev(*ns);
    *ns = reversed;
    return;
}

int_list* cons(int val, int_list* list) {
    int_list* new_head = malloc(sizeof(int_list));
    new_head->val = val;
    new_head->next = list;
    return new_head;
}

void evidence_il_rev(void) {
    int_list* list_1 = cons(1, cons(2, cons(3, cons(4, NULL))));
    int_list* list_2 = cons(1, cons(2, cons(3, cons(4, NULL))));
    list_show(list_1);
    list_show(list_2);
    int_list* reversed_list_1 = il_rev(list_1);
    list_show(reversed_list_1);
    il_rev_d(&list_2);
    list_show(list_2);
    list_free(list_1);
    list_free(list_2);
    return;
}


// Trees and Bit Operations


// Two-Dimensional Arrays

typedef struct matrix matrix;
struct matrix {
    unsigned int n_rows;
    unsigned int n_cols;
    float **entries;
};

matrix* matrix_transpose(matrix* m) {
    matrix* mat_out = matrix_zero(m->n_cols, m->n_rows);
    int i_row, i_col;
    for (i_row = 0; i_row < m->n_rows; i_row++) {
        for (i_col = 0; i_col < m->n_cols; i_col++) {
            matrix_write(mat_out, i_col, i_row, matrix_read(m, i_row, i_col));
        }
    }
    return mat_out;
}


// Graphs and Queues

// okay just make a bfs and then add in like an extra counter
// that counts number of things added to list and then short circuit
il* limited_bfs(graph *g, unsigned int start_key, unsigned int max_steps) {
    // check for errors
    if (start_key>=g->n_vertices) {
        fprintf(stderr,"bfs: no such vertex (%u)\n",start_key);
        exit(1);
    }
    
    il *prev_reached, *reached;
    reached = NULL;
    iq *q = iq_new();
    int curr;
    int list_elements = 0;
    enqueue(q, start_key);
    
    while (q->n > 0) {
        curr = dequeue(q);
        if (g->vs[curr]->done)
            continue;
        g->vs[curr]->done = 1;
        prev_reached = reached;
        reached = il_append(prev_reached,il_singleton(curr));
        il_free(prev_reached);
        list_elements++;
        if (list_elements >= max_steps) {
            iq_free(q);
            return reached;
        }
        il *neighbors = g->es[curr];
        while (neighbors != NULL) {
            int n = neighbors->n;
            enqueue(q,n);
            neighbors = neighbors->next;
        }
    }
    iq_free(q);
    return reached;
}


// Trees and Stacks

typedef struct tree tree;
struct tree {
    char* label;
    tree *lsub, *rsub;
};


/*****************************************************************************/

int main() {
    evidence_il_rev();
    return 0;
}