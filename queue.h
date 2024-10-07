#include <stdio.h>
#include <string.h>
#define MAX 5
// Structure to represent an emergency vehicle request
typedef struct {
    char vehicleType[20];
    int priority;  // 1 for high priority, 2 for normal priority
} EmergencyRequest;

// Queue structure for normal requests
typedef struct {
    EmergencyRequest requests[MAX];
    int front, rear;
} Queue;

// Priority Queue for high-priority requests
typedef struct {
    EmergencyRequest requests[MAX];
    int count;
} PriorityQueue;


// Function to initialize a normal queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if normal queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Function to check if normal queue is empty
int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Enqueue function for normal queue
void enqueue(Queue *q, char *vehicleType) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add more vehicles.\n");
        return;
    }
    if (q->front == -1) q->front = 0;  // First element
    q->rear++;
    strcpy(q->requests[q->rear].vehicleType, vehicleType);
    q->requests[q->rear].priority = 2;  // Normal priority
    printf("Added %s to normal queue.\n", vehicleType);
}

// Dequeue function for normal queue
EmergencyRequest dequeue(Queue *q) {
    EmergencyRequest req;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        strcpy(req.vehicleType, "No vehicle");
        req.priority = -1;
        return req;
    }
    req = q->requests[q->front];
    q->front++;
    return req;
}

// Function to initialize the priority queue
void initPriorityQueue(PriorityQueue *pq) {
    pq->count = 0;
}

// Function to check if priority queue is full
int isPriorityFull(PriorityQueue *pq) {
    return pq->count == MAX;
}

int isEmptyPriorityQueue(PriorityQueue* pq){
    return pq->count == 0;
}

// Enqueue function for priority queue
void enqueuePriority(PriorityQueue *pq, char *vehicleType) {
    if (isPriorityFull(pq)) {
        printf("Priority queue is full! Cannot add more vehicles.\n");
        return;
    }
    strcpy(pq->requests[pq->count].vehicleType, vehicleType);
    pq->requests[pq->count].priority = 1;  // High priority
    pq->count++;
    printf("Added %s to priority queue.\n", vehicleType);
}

// Dequeue function for priority queue (highest priority first)
EmergencyRequest dequeuePriority(PriorityQueue *pq) {
    EmergencyRequest req;
    if (isEmptyPriorityQueue(pq)) {
        printf("Priority queue is empty!\n");
        strcpy(req.vehicleType, "No vehicle");
        req.priority = -1;
        return req;
    }
    req = pq->requests[0];  // Highest priority (index 0)
    for (int i = 0; i < pq->count - 1; i++) {
        pq->requests[i] = pq->requests[i + 1];  // Shift remaining elements
    }
    pq->count--;
    return req;
}

// Function to dispatch a vehicle based on priority
EmergencyRequest dispatchVehicle(PriorityQueue *pq, Queue *q) {
    EmergencyRequest req;
    if (!isEmptyPriorityQueue(pq)) {
        req = dequeuePriority(pq);  // Priority queue gets dispatched first
    } else if (!isEmpty(q)) {
        req = dequeue(q);  // Dispatch from normal queue
    } else {
        strcpy(req.vehicleType, "No vehicles available");
        req.priority = -1;
    }
    return req;
}

