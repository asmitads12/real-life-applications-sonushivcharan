#include <stdio.h>
#include "Queue.h"

// Function to take vehicle type input (supports multi-word input)
char* inputVehicleType() {
    static char vehicleType[50];  // Adjust the size as needed
    printf("Enter vehicle Type: ");
    getchar();  // To clear the newline left in buffer from previous input
    fgets(vehicleType, sizeof(vehicleType), stdin);

    // Remove the trailing newline character if present
    size_t len = strlen(vehicleType);
    if (len > 0 && vehicleType[len - 1] == '\n') {
        vehicleType[len - 1] = '\0';
    }

    return vehicleType;
}


// Main function to simulate the emergency vehicle management system
int main() {
    Queue normalQueue;
    PriorityQueue priorityQueue;
    EmergencyRequest dispatched;
    initQueue(&normalQueue);
    initPriorityQueue(&priorityQueue);
    int ch;

    do {
        printf("\n--------------Menu--------------\n");
        printf("1. Enqueue in Normal Queue\n");
        printf("2. Enqueue in Priority Queue\n");
        printf("3. Dispatch vehicle\n");
        printf("4. Exit System\n");
        printf("\nChoose the operation on queue: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                enqueue(&normalQueue, inputVehicleType());
                break;
            case 2:
                enqueuePriority(&priorityQueue, inputVehicleType());
                break;
            case 3:
                dispatched = dispatchVehicle(&priorityQueue, &normalQueue);
                printf("Dispatched: %s (Priority: %d)\n", dispatched.vehicleType, dispatched.priority);
                break;
            case 4:
                printf("Exiting System.\n");
                break;
            default:
                printf("Invalid Choice. Please choose again.\n");
        }
    } while (ch != 4);

    return 0;
}
