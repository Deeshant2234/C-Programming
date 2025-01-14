#include <stdio.h>
#include <stdlib.h>

int x[10]= {0};

// Define the hash table entry structure
struct HashEntry {
    int value; // Value stored
    int index; // Index in the original nums array
};

// Hash function to calculate the index
int hash(int value, int size) {
    return (value % size + size) % size;  // Ensures positive indices
}

// Function to initialize the hash table
void initializeHashTable(struct HashEntry *H, int size) {
    for (int i = 0; i < size; i++) {
        H[i].value = -1; // Use -1 to indicate an empty slot
        H[i].index = -1; // No index stored for an empty slot
    }
}

// Function to search for a value in the hash table
int search(struct HashEntry *H, int size, int value) {
    int index = hash(value, size);
    int i = 0;

    while (H[(index + i) % size].value != -1) { // Check until an empty slot
        if (H[(index + i) % size].value == value) {
            return H[(index + i) % size].index;  // Return the index if found
        }
        i++;
        if (i == size) // Avoid infinite loop if the table is full
            break;
    }
    return -1; // Not found
}

// Function to insert a value and its index into the hash table
void insert(struct HashEntry *H, int size, int value, int index) {
    int hashIndex = hash(value, size);
    int i = 0;

    while (H[(hashIndex + i) % size].value != -1) { // Find the next empty slot
        i++;
    }
    int finalIndex = (hashIndex + i) % size;
    H[finalIndex].value = value;
    H[finalIndex].index = index;
}

// Two Sum function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int sizeHT = numsSize * 2;  // Larger table to reduce collisions
    struct HashEntry *HT = (struct HashEntry*)malloc(sizeHT * sizeof(struct HashEntry));
    initializeHashTable(HT, sizeHT); // Initialize the hash table

    int *result = NULL;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int y = target - x;

        int idx = search(HT, sizeHT, y);  // Search for the complement
        if (idx != -1) {  // Complement found
            result = (int*)malloc(2 * sizeof(int));
            result[0] = idx;
            result[1] = i;
            *returnSize = 2;
            free(HT);  // Free the hash table
            return result;
        }

        insert(HT, sizeHT, x, i);  // Insert the current value and its index
    }

    *returnSize = 0;
    free(HT);
    return NULL;
}

int main() {
    int nums[] = {-10, -1, -18, -19};
    int target = -19;
    int returnSize;

    int *result = twoSum(nums, 4, target, &returnSize);

    if (result != NULL) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
