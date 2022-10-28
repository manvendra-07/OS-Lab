#include<stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
  int i, j;
  int allocation[n];

  for (i = 0; i < n; i++) {
    allocation[i] = -1;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (blockSize[j] >= processSize[i]) {
        allocation[i] = j;
        blockSize[j] -= processSize[i];

        break;
      }
    }
  }

  printf("\nProcess No.\tProcess Size\tBlock no.\n");
  for (int i = 0; i < n; i++) {
    printf(" %i\t\t\t", i + 1);
    printf("%i\t\t\t\t", processSize[i]);
    if (allocation[i] != -1)
      printf("%i", allocation[i] + 1);
    else
      printf("Not Allocated");
    printf("\n");
  }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
  int allocation[n];
  for (int i = 0; i < n; i++) {
    int bestIdx = -1;
    for (int j = 0; j < m; j++) {
      if (blockSize[j] >= processSize[i]) {
        if (bestIdx == -1)
          bestIdx = j;
        else if (blockSize[bestIdx] > blockSize[j])
          bestIdx = j;
      }
    }

    if (bestIdx != -1) {
      allocation[i] = bestIdx;
      blockSize[bestIdx] -= processSize[i];
    }
  }

  printf("\nProcess No.\tProcess Size\tBlock no.\n");
  for (int i = 0; i < n; i++) {
    printf("\t%d\t\t%d\t\t", i + 1, processSize[i]);
    if (allocation[i] != -1)
      printf("%d", allocation[i] + 1);
    else
      printf("Not Allocated");
    printf("\n");
  }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
  int allocation[n];
  for (int i = 0; i < n; i++) {

    int wstIdx = -1;
    for (int j = 0; j < m; j++) {
      if (blockSize[j] >= processSize[i]) {
        if (wstIdx == -1)
          wstIdx = j;
        else if (blockSize[wstIdx] < blockSize[j])
          wstIdx = j;
      }
    }

    if (wstIdx != -1) {
      allocation[i] = wstIdx;

      blockSize[wstIdx] -= processSize[i];
    }

  }
  printf("\nProcess No.\tProcess Size\tBlock no.\n");

  for (int i = 0; i < n; i++) {
    printf("\t%d\t\t%d\t\t", i + 1, processSize[i]);
    if (allocation[i] != -1)
      printf("%d", allocation[i] + 1);
    else
      printf("Not Allocated");
    printf("\n");
  }

}

int main() {
  int nb, np, blockSize[100], processSize[100];
  printf("Enter No of blocks : ");
  scanf("%d", & nb);
  printf("Enter No of processes : ");
  scanf("%d", & np);
  printf("Enter size of blocks : ");
  for (int x = 0; x < nb; x++)
    scanf("%d", & blockSize[x]);
  printf("Enter size of processes : ");
  for (int x = 0; x < np; x++)
    scanf("%d", & processSize[x]);

  printf("Menu\n1 - First-Fit\n2 - Best-Fit\n3 - Worst-Fit\nEnter choice of mapping : ");
  int choice;
  scanf("%d", & choice);
  switch (choice) {
  case 1:
    firstFit(blockSize, nb, processSize, np);
    break;
  case 2:
    bestFit(blockSize, nb, processSize, np);
    break;
  case 3:
    worstFit(blockSize, nb, processSize, np);
    break;
  default:
    printf("Invalid Choice of mapping\nTry Again!");
  }
  return 0;
}