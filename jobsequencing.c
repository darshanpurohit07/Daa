#include <stdio.h>

// Job structure
struct Job {
    int deadline;
    int profit;
};

// Function to swap two jobs
void swap(struct Job* a, struct Job* b) {
    struct Job temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort to sort jobs by profit in descending order
void bubbleSort(struct Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                swap(&jobs[j], &jobs[j + 1]);
            }
        }
    }
}

// Function to find maximum deadline
int findMaxDeadline(struct Job jobs[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    }
    return max;
}

void jobSequencing(struct Job jobs[], int n) {
    bubbleSort(jobs, n);

    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[maxDeadline];   // Tracks if a slot is occupied
    int result[maxDeadline]; // Store index of scheduled jobs
    int totalProfit = 0;

    // Initialize slots as free
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = 0;

    // Greedy scheduling
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                result[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print result
    printf("Scheduled Jobs (by index): ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i])
            printf("%d ", result[i] + 1); // +1 to show 1-based job number
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    struct Job jobs[] = {
        {2, 60},
        {1, 100},
        {3, 20},
        {2, 40},
        {1, 20}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobSequencing(jobs, n);

    return 0;
}
