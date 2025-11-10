#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    printf("Enter the element to insert: ");
    scanf("%d", &item);

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("\nQueue Overflow! Cannot insert more elements.\n");
        return;
    }

    if (front == -1) {  
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;  
    } else {
        rear++;
    }

    queue[rear] = item;
    printf("%d inserted into the circular queue.\n", item);
}

void delete() {
    if (front == -1) {
        printf("\nQueue Underflow! No elements to delete.\n");
        return;
    }

    printf("%d deleted from the circular queue.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;  
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nCircular Queue elements are: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
