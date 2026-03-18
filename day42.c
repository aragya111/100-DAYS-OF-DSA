#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *data;
    int head;
    int tail;
    int size;
    int capacity;
} Queue;

static Queue *queue_create(int capacity) {
    Queue *q = malloc(sizeof(Queue));
    if (!q) return NULL;
    q->data = malloc(sizeof(int) * capacity);
    if (!q->data) {
        free(q);
        return NULL;
    }
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

static void queue_destroy(Queue *q) {
    if (!q) return;
    free(q->data);
    free(q);
}

static int queue_is_empty(const Queue *q) {
    return q->size == 0;
}

static int queue_is_full(const Queue *q) {
    return q->size == q->capacity;
}

static int queue_enqueue(Queue *q, int value) {
    if (queue_is_full(q)) return 0;
    q->data[q->tail] = value;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
    return 1;
}

static int queue_dequeue(Queue *q, int *out) {
    if (queue_is_empty(q)) return 0;
    *out = q->data[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return 1;
}


static void reverse_queue(Queue *q) {
    if (!q || q->size <= 1) return;

    int n = q->size;
    int *stack = malloc(sizeof(int) * n);
    if (!stack) return;

   
    for (int i = 0; i < n; ++i) {
        int x;
        queue_dequeue(q, &x);
        stack[i] = x;
    }

    
    for (int i = n - 1; i >= 0; --i) {
        queue_enqueue(q, stack[i]);
    }

    free(stack);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        return 0;
    }

    Queue *q = queue_create(n > 0 ? n : 1);
    if (!q) return 0;

    for (int i = 0; i < n; ++i) {
        int x;
        if (scanf("%d", &x) != 1) break;
        queue_enqueue(q, x);
    }

    reverse_queue(q);

    
    while (!queue_is_empty(q)) {
        int x;
        queue_dequeue(q, &x);
        printf("%d", x);
        if (!queue_is_empty(q)) printf(" ");
    }
    printf("\n");

    queue_destroy(q);
    return 0;
}
