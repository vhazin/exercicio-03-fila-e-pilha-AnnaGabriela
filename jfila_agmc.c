#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int id;
    struct Element *next;
} Element;

typedef struct Queue {
    struct Element *first, *last, *new, *pointer;
} Queue;

Queue* createQueue(int);
int enqueue(Queue*, int);
void getRemain(Queue*, Queue*);

int main() {
    int initial_amount, exit_amount;

    scanf("%d", &initial_amount);
    Queue *original_queue = createQueue(initial_amount);

    scanf("%d", &exit_amount);
    Queue *exit_queue = createQueue(exit_amount);

    getRemain(original_queue, exit_queue);
    
    free(original_queue);
    free(exit_queue);

    return 0;
}

Queue* createQueue(int size) {
    Queue *queue = malloc(sizeof(Queue));
    queue->first = queue->last = NULL;

    while(size--) {
        int id;
        scanf("%d", &id);
        enqueue(queue, id);
    }

    return queue;
}

int enqueue(Queue *queue, int id) {
    Element *new_element = queue->new;
    new_element = malloc(sizeof(struct Element));
    
    new_element->id = id;
    new_element->next = NULL;

    if ((queue->first == NULL) && (queue->last == NULL)) {
        queue->first = new_element;
        queue->last = new_element;
        return 1;
    }

    queue->last->next = new_element;
    queue->last = new_element;

    return 0;
}

void getRemain(Queue *original_queue, Queue *exit_queue) {
    original_queue->pointer = original_queue->first;

    while(original_queue->pointer != NULL) {
        exit_queue->pointer = exit_queue->first;
        int has_left = 0;

        while(exit_queue->pointer != NULL) {
            if (original_queue->pointer->id == exit_queue->pointer->id) {
                has_left = 1;
                break;
            }
            exit_queue->pointer = exit_queue->pointer->next;
        }
        if (!has_left) printf("%d ", original_queue->pointer->id);
        original_queue->pointer = original_queue->pointer->next;
    }
    putchar('\n');
}
