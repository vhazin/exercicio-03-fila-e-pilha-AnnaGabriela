#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int id;
    struct Element *next;
} Element;

typedef struct Queue {
    struct Element *first, *last, *new;
} Queue;

Queue* createQueue(int);
int enqueue(Queue*, int);
void dequeue(Queue*, int);
void printQueue(Queue*);

int main() {
    int initial_amount, exit_amount;

    scanf("%d", &initial_amount);
    Queue *original_queue = createQueue(initial_amount);

    scanf("%d", &exit_amount);
    while(exit_amount--) {
        int id;
        scanf("%d", &id);
        dequeue(original_queue, id);
    }

    printQueue(original_queue);

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

void dequeue(Queue *queue, int id) {
    Element *pointer = queue->first;
    Element *previous = NULL;

    while(pointer != NULL) {
        if (id == pointer->id) {
            if (previous == NULL) {
                queue->first = pointer->next;
                free(pointer);
                return;
            }
            previous->next = pointer->next;
            free(pointer);
            pointer = pointer->next;
            return;
        }
        previous = pointer;
        pointer = pointer->next;
    }
}

void printQueue(Queue *queue) {
    Element *pointer = queue->first;
    for(int i = 1; pointer != NULL; i++) {
        printf("%d ", pointer->id);
        pointer = pointer->next;
    }
    printf("\n");
}
