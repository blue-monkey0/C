#pragma once
#define Q_SIZE 4

typedef char element;			
typedef struct {
	element queue[Q_SIZE];
	int front, rear;
}QueueType;

QueueType *createQueue();
int isEmpty(QueueType *Q);
int isFull(QueueType *Q);
void enQueue(QueueType *Q, element item);
element deQueue(QueueType *Q);
element peek(QueueType *Q);
void printQ(QueueType *Q);
