#ifndef QUEUE_H
    #define QUEUE_H

    typedef struct queue_ QUEUE;

    #include<stdbool.h>
    
    typedef struct carta_{
        char *naipe;
        char *valor;
    }CARTA;

    QUEUE *queue_generate();
    void queue_push(QUEUE *queue, CARTA carta);
    CARTA queue_pop(QUEUE *queue);
    bool queue_empty(QUEUE *queue);
    void queue_erase(QUEUE **queue);
    int queue_size(QUEUE *queue);
    bool queue_full(QUEUE *queue);
    void queue_print(QUEUE *queue);

#endif
    