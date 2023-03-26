#include <stdio.h>
#include <stdbool.h>

void sort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (arr[j] >= arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void inv_sort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (arr[j] <= arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void first_fit(int proc_size[], int hole_size[], int proc, int hole, int alloc[]) {
    int k = 0;
    bool allocated[100] = { false };
    for (int i = 0; i < proc; i++) {
        for (int j = 0; j < hole; j++) {
            if (proc_size[i] <= hole_size[j] && allocated[j] == false) {
                alloc[k] = j+1;
                k++;
                allocated[j] = true;
                break;
            } else {
                alloc[k] = -1;
            }
        }
void worst_fit(int proc_size[], int hole_size[], int proc, int hole, int alloc[]) {
    int k = 0;
    bool allocated[100] = { false };
    inv_sort(hole_size, hole);
    for (int i = 0; i < proc; i++) {
        for (int j = 0; j < hole; j++) {
            if (proc_size[i] <= hole_size[j] && allocated[j] == false) {
                alloc[k] = j+1;
                k++;
                allocated[j] = true;
                break;
            } else {
                alloc[k] = -1;
            }
        }
    }
}

void best_fit(int proc_size[], int hole_size[], int proc, int hole, int alloc[]) {
    int k = 0;
    bool allocated[100] = { false };
    sort(hole_size, hole);
    for (int i = 0; i < proc; i++) {
        for (int j = 0; j < hole; j++) {
            if (proc_size[i] <= hole_size[j] && allocated[j] == false) {
                alloc[k] = j+1;
                k++;
                allocated[j] = true;
                break;
            } else {
                alloc[k] = -1;
            }
        }
    }
}

void display(int P, int proc_size[], int alloc[]) {
    printf("P.No.\tSize\tBlock\n");
    for (int i = 0; i < P; i++) {
        if (alloc[i] > 0) {
            printf("%d\t%d\t%d\n", i+1, proc_size[i], alloc[i]);
        } else {
            printf("%d\t%d\t%s\n", i+1, proc_size[i], "Not allocated");
        }
    }
    printf("\n");
}       

int main(){
    int P, H;
    printf("Enter no of processes and no of holes: ");
    scanf("%d%d", &P, &H);
    
    int P_size[P], H_size[H], alloc[P];
    for (int i = 0; i < P; i++) {
        printf("Enter size for process %d: ", i+1);
        scanf("%d", &P_size[i]);
    }
    for (int i = 0; i < H; i++) {
        printf("Enter size for hole %d: ", i+1);
        scanf("%d", &H_size[i]);
    }
    
    int option;
    printf("Enter a choice:\n1. First-fit allocation\n2. Worst-fit allocation\n3. Best-fit allocation\n");
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            first_fit(P_size, H_size, P, H, alloc);
            display(P, P_size, alloc);
            break;
        case 2:
            worst_fit(P_size, H_size, P, H, alloc);
            display(P, P_size, alloc);
            break;
        case 3:
            best_fit(P_size, H_size, P, H, alloc);
            display(P, P_size, alloc);
            break;
    }
}

