#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int jobId;
    char fileName[100];
    int pages;
} PrintJob;

int main(void) {
    int n, i;
    int front = 0, rear = -1;

    printf("Enter the maximum number of print jobs: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of jobs!\n");
        return 1;
    }

    // Dynamically allocate memory
    PrintJob *queue = malloc((size_t)n * sizeof(PrintJob));

    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;

    do {
        printf("\n--- PRINTER JOB MANAGEMENT ---\n");
        printf("1. Add print job\n");
        printf("2. Process next job\n");
        printf("3. Display pending jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            free(queue);
            return 1;
        }

        switch (choice) {
            case 1:
                if (rear == n - 1) {
                    printf("Queue is full!\n");
                    break;
                }

                rear++;

                queue[rear].jobId = rear + 1;

                printf("Enter file name (without spaces): ");
                if (scanf("%99s", queue[rear].fileName) != 1) {
                    printf("Invalid file name!\n");
                    rear--;
                    break;
                }

                printf("Enter number of pages: ");
                if (scanf("%d", &queue[rear].pages) != 1 ||
                    queue[rear].pages <= 0) {
                    printf("Invalid page count!\n");
                    rear--;
                    break;
                }

                printf("Print job added successfully!\n");
                break;

            case 2:
                if (front > rear) {
                    printf("No pending print jobs!\n");
                } else {
                    printf("\nProcessing Job ID: %d\n",
                           queue[front].jobId);
                    printf("File: %s\n",
                           queue[front].fileName);
                    printf("Pages: %d\n",
                           queue[front].pages);

                    printf("Print job completed!\n");
                    front++;
                }
                break;

            case 3:
                if (front > rear) {
                    printf("Queue is empty!\n");
                } else {
                    printf("\nPending print jobs:\n");

                    for (i = front; i <= rear; i++) {
                        printf("Job ID: %d | File: %s | Pages: %d\n",
                               queue[i].jobId,
                               queue[i].fileName,
                               queue[i].pages);
                    }
                }
                break;

            case 4:
                printf("Exiting the system...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    // Release allocated memory
    free(queue);

    return 0;
}
