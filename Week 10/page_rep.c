#include<stdio.h>

void fifo(int string[20], int n, int size) {
  int frames[n];

  for (int i = 0; i < n; i++)
    frames[i] = -1;

  int index = -1;

  int page_miss = 0;
  int page_hits = 0;

  for (int i = 0; i < size; i++) {
    int symbol = string[i];
    int flag = 0;

    for (int j = 0; j < n; j++) {
      if (symbol == frames[j]) {
        flag = 1;
        break;
      }
    }

    if (flag == 1) {
      printf("\nSymbol: %d  Frame: ", symbol);
      for (int j = 0; j < n; j++)
        printf("%d ", frames[j]);
      page_hits += 1;
    } else {
      index = (index + 1) % n;
      frames[index] = symbol;
      page_miss += 1;
      printf("\nSymbol: %d  Frame: ", symbol);
      for (int j = 0; j < n; j++)
        printf("%d ", frames[j]);
    }
  }
  printf("\nPage hits: %d", page_hits);
  printf("\nPage misses: %d", page_miss);
}

void optimal(int string[20], int n, int size) {
  int frames[n];

  for (int i = 0; i < n; i++)
    frames[i] = -1;

  int index = -1;

  int page_miss = 0;
  int page_hits = 0;

  int full = 0;

  for (int i = 0; i < size; i++) {
    int symbol = string[i];
    int flag = 0;
    for (int j = 0; j < n; j++) {
      if (symbol == frames[j]) {
        flag = 1;
        break;
      }
    }

    if (flag == 1) {
      printf("\nSymbol: %d  Frame: ", symbol);
      for (int j = 0; j < n; j++)
        printf("%d ", frames[j]);
      page_hits += 1;
    } else {

      if (full == 0) {
        index = (index + 1) % n;
        frames[index] = symbol;
        page_miss += 1;
        printf("\nSymbol: %d  Frame: ", symbol);
        for (int j = 0; j < n; j++)
          printf("%d ", frames[j]);

        if (i == n - 1)
          full = 1;
      } else {

        int pos = -1;
        int index = -1;

        for (int j = 0; j < n; j++) {

          int found = 0;
          for (int k = i + 1; k < size; k++) {

            if (frames[j] == string[k]) {
              found = 1;
              if (pos < k) {
                pos = k;
                index = j;
              }
              break;
            }
          }

          if (found == 0) {
            pos = size;
            index = j;
          }
        }
        frames[index] = symbol;

        printf("\nSymbol: %d  Frame: ", symbol);
        for (int j = 0; j < n; j++)
          printf("%d ", frames[j]);
      }
    }
  }
  printf("\nPage hits: %d", page_hits);
  printf("\nPage misses: %d", page_miss);
}

void lru(int string[20], int n, int size) {

  int frames[n];

  for (int i = 0; i < n; i++)
    frames[i] = -1;

  int index = -1;

  int page_miss = 0;
  int page_hits = 0;
  for (int i = 0; i < size; i++) {
    int symbol = string[i];
    int flag = 0;

    int full = 0;

    for (int j = 0; j < n; j++) {
      if (symbol == frames[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      printf("\nSymbol: %d  Frame: ", symbol);
      for (int j = 0; j < n; j++)
        printf("%d ", frames[j]);
      page_hits += 1;
    } else {
      if (full == 0) {
        index = (index + 1) % n;
        frames[index] = symbol;
        page_miss += 1;
        printf("\nSymbol: %d  Frame: ", symbol);
        for (int j = 0; j < n; j++)
          printf("%d ", frames[j]);
      } else {
        int pos = 999;
        int index = -1;
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < size; k++) {
            if (frames[j] == string[k]) {
              if (pos > k) {
                pos = k;
                index = j;
                break;
              }
            }
          }
        }

        frames[index] = symbol;
      }
    }
  }
  printf("\nPage hits: %d", page_hits);
  printf("\nPage misses: %d", page_miss);
}

int main() {
  int n, frames;
  printf("Enter the number of pages:\n");
  scanf("%d", & n);
  int string[n];
  printf("Enter the reference string: \n");
  for (int i = 0; i < n; i++)
    scanf("%d", & string[i]);
  printf("Enter the number of frames:\n ");
  scanf("%d", & frames);
  printf("Menu\n1 - FIFO\n2 - Optimal\n3 - LRU\nEnter Choice of Page Replacement : ");
  int choice;
  switch (choice) {
  case 1:
    fifo(string, frames, n);
    break;
  case 2:
    optimal(string, frames, n);
    break;
  case 3:
    lru(string, frames, n);
    break;
  default:
    printf("Invalid Choice\nTry Again!");
  }
  return 0;
}