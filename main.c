#include <stdio.h>
#include "queue.h"


// Main function to simulate the emergency vehicle management system
int main() {
    Queue normalQueue;
    PriorityQueue priorityQueue;
    EmergencyRequest dispatched;

    initQueue(&normalQueue);
    initPriorityQueue(&priorityQueue);

    // Simulating emergency vehicle requests
    enqueue(&normalQueue, "Ambulance");
    enqueue(&normalQueue, "Fire Truck");
    enqueuePriority(&priorityQueue, "Police Car");
    enqueuePriority(&priorityQueue, "Rescue Helicopter");

    // Dispatching vehicles based on priority
    printf("Dispatching vehicles...\n");
    dispatched = dispatchVehicle(&priorityQueue, &normalQueue);
    printf("Dispatched: %s (Priority: %d)\n", dispatched.vehicleType, dispatched.priority);

    dispatched = dispatchVehicle(&priorityQueue, &normalQueue);
    printf("Dispatched: %s (Priority: %d)\n", dispatched.vehicleType, dispatched.priority);

    dispatched = dispatchVehicle(&priorityQueue, &normalQueue);
    printf("Dispatched: %s (Priority: %d)\n", dispatched.vehicleType, dispatched.priority);

    dispatched = dispatchVehicle(&priorityQueue, &normalQueue);
    printf("Dispatched: %s (Priority: %d)\n", dispatched.vehicleType, dispatched.priority);

    return 0;
}
