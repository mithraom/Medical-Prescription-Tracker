#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Prescription {
    char medName[50];
    char dosage[30];
    char startDate[20];
    char endDate[20];
    char intakeTime[20];
    struct Prescription* next;
} Prescription;

Prescription* head = NULL;

// Create a new prescription node
Prescription* createNode() {
    Prescription* newNode = (Prescription*)malloc(sizeof(Prescription));
    printf("Enter medicine name: ");
    scanf(" %[^\n]", newNode->medName);
    printf("Enter dosage: ");
    scanf(" %[^\n]", newNode->dosage);
    printf("Enter start date (dd-mm-yyyy): ");
    scanf(" %[^\n]", newNode->startDate);
    printf("Enter end date (dd-mm-yyyy): ");
    scanf(" %[^\n]", newNode->endDate);
    printf("Enter time of intake (Morning/Night/etc): ");
    scanf(" %[^\n]", newNode->intakeTime);
    newNode->next = NULL;
    return newNode;
}

// Add Prescription
void addPrescription() {
    Prescription* newNode = createNode();
    if (head == NULL) {
        head = newNode;
    } else {
        Prescription* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Prescription added successfully!\n");
}

// Display Prescriptions
void displayPrescriptions() {
    if (head == NULL) {
        printf("No prescriptions found.\n");
        return;
    }
    Prescription* temp = head;
    printf("\n--- Prescription List ---\n");
    while (temp) {
        printf("\nMedicine: %s\nDosage: %s\nStart Date: %s\nEnd Date: %s\nIntake Time: %s\n",
               temp->medName, temp->dosage, temp->startDate, temp->endDate, temp->intakeTime);
        temp = temp->next;
    }
}

// Linear Search
void searchPrescriptionLinear() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]", name);
    Prescription* temp = head;
    while (temp) {
        if (strcmp(temp->medName, name) == 0) {
            printf("\nFound Prescription:\nDosage: %s\nStart Date: %s\nEnd Date: %s\nIntake Time: %s\n",
                   temp->dosage, temp->startDate, temp->endDate, temp->intakeTime);
            return;
        }
        temp = temp->next;
    }
    printf("Prescription not found.\n");
}

// Bubble Sort by Medicine Name
void bubbleSort() {
    if (!head) return;

    Prescription *i, *j;
    char tempMed[50], tempDosage[30], tempStart[20], tempEnd[20], tempTime[20];

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->medName, j->medName) > 0) {
                // Swap fields
                strcpy(tempMed, i->medName);
                strcpy(i->medName, j->medName);
                strcpy(j->medName, tempMed);

                strcpy(tempDosage, i->dosage);
                strcpy(i->dosage, j->dosage);
                strcpy(j->dosage, tempDosage);

                strcpy(tempStart, i->startDate);
                strcpy(i->startDate, j->startDate);
                strcpy(j->startDate, tempStart);

                strcpy(tempEnd, i->endDate);
                strcpy(i->endDate, j->endDate);
                strcpy(j->endDate, tempEnd);

                strcpy(tempTime, i->intakeTime);
                strcpy(i->intakeTime, j->intakeTime);
                strcpy(j->intakeTime, tempTime);
            }
        }
    }

    printf("Prescriptions sorted successfully by Bubble Sort.\n");
}

// Selection Sort by Medicine Name
void selectionSort() {
    if (!head) return;

    Prescription *i, *j, *min;
    char tempMed[50], tempDosage[30], tempStart[20], tempEnd[20], tempTime[20];

    for (i = head; i != NULL; i = i->next) {
        min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(j->medName, min->medName) < 0) {
                min = j;
            }
        }
        if (min != i) {
            // Swap fields
            strcpy(tempMed, i->medName);
            strcpy(i->medName, min->medName);
            strcpy(min->medName, tempMed);

            strcpy(tempDosage, i->dosage);
            strcpy(i->dosage, min->dosage);
            strcpy(min->dosage, tempDosage);

            strcpy(tempStart, i->startDate);
            strcpy(i->startDate, min->startDate);
            strcpy(min->startDate, tempStart);

            strcpy(tempEnd, i->endDate);
            strcpy(i->endDate, min->endDate);
            strcpy(min->endDate, tempEnd);

            strcpy(tempTime, i->intakeTime);
            strcpy(i->intakeTime, min->intakeTime);
            strcpy(min->intakeTime, tempTime);
        }
    }

    printf("Prescriptions sorted successfully by Selection Sort.\n");
}

// Convert Linked List to Array
int listToArray(Prescription* arr[]) {
    int count = 0;
    Prescription* temp = head;
    while (temp) {
        arr[count++] = temp;
        temp = temp->next;
    }
    return count;
}

// Binary Search
void binarySearch() {
    Prescription* arr[100];
    int n = listToArray(arr);

    // First, Selection Sort on array
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (strcmp(arr[j]->medName, arr[min]->medName) < 0)
                min = j;
        }
        if (min != i) {
            Prescription* temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    char name[50];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]", name);

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high)/2;
        int cmp = strcmp(arr[mid]->medName, name);
        if (cmp == 0) {
            printf("\nFound Prescription:\nDosage: %s\nStart Date: %s\nEnd Date: %s\nIntake Time: %s\n",
                   arr[mid]->dosage, arr[mid]->startDate, arr[mid]->endDate, arr[mid]->intakeTime);
            return;
        } else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Prescription not found.\n");
}

// Update Prescription
void updatePrescription() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf(" %[^\n]", name);

    Prescription* temp = head;
    while (temp) {
        if (strcmp(temp->medName, name) == 0) {
            printf("Enter new dosage: ");
            scanf(" %[^\n]", temp->dosage);
            printf("Enter new start date (dd-mm-yyyy): ");
            scanf(" %[^\n]", temp->startDate);
            printf("Enter new end date (dd-mm-yyyy): ");
            scanf(" %[^\n]", temp->endDate);
            printf("Enter new intake time: ");
            scanf(" %[^\n]", temp->intakeTime);
            printf("Prescription updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Prescription not found.\n");
}

// Delete Prescription
void deletePrescription() {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf(" %[^\n]", name);

    Prescription *temp = head, *prev = NULL;
    while (temp) {
        if (strcmp(temp->medName, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Prescription deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Prescription not found.\n");
}

// Free memory
void freeList() {
    Prescription* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main Menu
int main() {
    int choice;
    clock_t start, end;

    do {
        printf("\n===== Medical Prescription Tracker =====\n");
        printf("1. Add Prescription\n");
        printf("2. Display Prescriptions\n");
        printf("3. Linear Search (Medicine Name)\n");
        printf("4. Binary Search (Medicine Name)\n");
        printf("5. Bubble Sort (by Medicine Name)\n");
        printf("6. Selection Sort (by Medicine Name)\n");
        printf("7. Update Prescription\n");
        printf("8. Delete Prescription\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPrescription(); break;
            case 2: displayPrescriptions(); break;
            case 3:
                start = clock();
                searchPrescriptionLinear();
                end = clock();
                printf("Time taken: %.6f sec\n", (double)(end - start)/CLOCKS_PER_SEC);
                break;
            case 4:
                start = clock();
                binarySearch();
                end = clock();
                printf("Time taken: %.6f sec\n", (double)(end - start)/CLOCKS_PER_SEC);
                break;
            case 5:
                start = clock();
                bubbleSort();
                end = clock();
                printf("Time taken: %.6f sec\n", (double)(end - start)/CLOCKS_PER_SEC);
                break;
            case 6:
                start = clock();
                selectionSort();
                end = clock();
                printf("Time taken: %.6f sec\n", (double)(end - start)/CLOCKS_PER_SEC);
                break;
            case 7: updatePrescription(); break;
            case 8: deletePrescription(); break;
            case 0:
                freeList();
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
