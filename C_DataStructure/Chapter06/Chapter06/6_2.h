#pragma once
#define cQ_SIZE 4

typedef char element;
typedef struct {
	element queue[cQ_SIZE];
	int front, rear;
}QueueType;

QueueType *createQueue();

int isEmpty(QueueType *cQ);

int isFull(QueueType *cQ);

void enQueue(QueueType *cQ, element item);

element deQueue(QueueType *cQ);

element peek(QueueType *cQ);

void printQ(QueueType *cQ);