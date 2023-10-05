#include <stdio.h>
#include <windows.h>

int main() {
  int table[9][9] = {0};
  int turn = 0;
  int col;
  int mode;
  FILE *tablePtr;
  FILE *turnPtr;
  
  printf("New game or continue (0=New, Else=Continue):");
  scanf("%d", &mode);

  if (mode == 0) {
    turnPtr = fopen("turn.txt", "w");
    fclose(turnPtr);
    tablePtr = fopen("table.txt", "w");
    for (int i = 0; i <= 8; i++) {
      for (int j = 0; j <= 8; j++) {
        fprintf(tablePtr, "%1d ", 0);
      }
      fprintf(tablePtr, "%s", "\n");
    }
    fclose(tablePtr);
  }

  else {
    turnPtr = fopen("turn.txt", "a+");
  }

  tablePtr = fopen("table.txt", "r");
  for (int i = 0; i <= 8; i++) {
    for (int j = 0; j <= 8; j++) {
      fscanf(tablePtr, "%1d", &table[i][j]);
      if (table[i][j] != 0) {
        turn++;
      }
    }
  }
  fclose(tablePtr);

  while (turn <= 80) {
    printf("%d. player %s turn\n", turn % 2 + 1,
           ((turn % 2) ? "(YELLOW)" : "(RED)"));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (table[i][j] == 1) {
          printf("R ");
        } else if (table[i][j] == 2) {
          printf("Y ");
        } else {
          printf("- ");
        }
      }
      printf("\n");
    }
    do {
      printf("Pick the column:");
      scanf("%d", &col);
      if (table[0][col - 1] != 0) {
        printf("The column is full!\n");
      }
    } while (col > 9 || col < 1 || table[0][col - 1] != 0);
    for (int i = 8; i >= 0; i--) {
      if (table[i][col - 1] == 0) {
        turnPtr = fopen("turn.txt", "a");
        if (turn % 2) {
          table[i][col - 1] = turn % 2 + 1;
          fprintf(turnPtr, "P2 %d%d\n", i + 1, col);
        } else {
          table[i][col - 1] = turn % 2 + 1;
          fprintf(turnPtr, "P1 %d%d\n", i + 1, col);
        }
        fclose(turnPtr);
        break;
      }
    }

    tablePtr = fopen("table.txt", "w");
    for (int i = 0; i <= 8; i++) {
      for (int j = 0; j <= 8; j++) {
        fprintf(tablePtr, "%1d ", table[i][j]);
      }
      fprintf(tablePtr, "%s", "\n");
    }
    fclose(tablePtr);

    for (int i = 0; i <= 8; i++) {
      for (int j = 0; j <= 8; j++) {
        if (table[i][j] == table[i][j + 1] && table[i][j] == table[i][j + 2] &&
            table[i][j] == table[i][j + 3] && table[i][j] != 0) {
          system("cls");
          for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
              if (table[i][j] == 1) {
                printf("R ");
              } else if (table[i][j] == 2) {
                printf("Y ");
              } else {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("%d. player %s won! Table is now reset.", table[i][j],
                 ((table[i][j] % 2) ? "(RED)" : "(YELLOW)"));
          tablePtr = fopen("table.txt", "w");
          for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
              fprintf(tablePtr, "%1d ", 0);
            }
            fprintf(tablePtr, "%s", "\n");
          }
          fclose(tablePtr);
          turnPtr = fopen("turn.txt", "w");
          fclose(turnPtr);
          return 0;
        }

        else if (table[i][j] == table[i + 1][j] &&
                 table[i][j] == table[i + 2][j] &&
                 table[i][j] == table[i + 3][j] && table[i][j] != 0) {
          system("cls");
          for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
              if (table[i][j] == 1) {
                printf("R ");
              } else if (table[i][j] == 2) {
                printf("Y ");
              } else {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("%d. player %s won! Table is now reset.", table[i][j],
                 ((table[i][j] % 2) ? "(RED)" : "(YELLOW)"));
          tablePtr = fopen("table.txt", "w");
          for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
              fprintf(tablePtr, "%1d ", 0);
            }
            fprintf(tablePtr, "%s", "\n");
          }
          fclose(tablePtr);
          turnPtr = fopen("turn.txt", "w");
          fclose(turnPtr);
          return 0;
        }

        else if (table[i][j] == table[i + 1][j + 1] &&
                 table[i][j] == table[i + 2][j + 2] &&
                 table[i][j] == table[i + 3][j + 3] && table[i][j] != 0) {
          system("cls");
          for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
              if (table[i][j] == 1) {
                printf("R ");
              } else if (table[i][j] == 2) {
                printf("Y ");
              } else {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("%d. player %s won! Table is now reset.", table[i][j],
                 ((table[i][j] % 2) ? "(RED)" : "(YELLOW)"));
          tablePtr = fopen("table.txt", "w");
          for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
              fprintf(tablePtr, "%1d ", 0);
            }
            fprintf(tablePtr, "%s", "\n");
          }
          fclose(tablePtr);
          turnPtr = fopen("turn.txt", "w");
          fclose(turnPtr);
          return 0;
        } else if (table[i][j] == table[i + 1][j - 1] &&
                   table[i][j] == table[i + 2][j - 2] &&
                   table[i][j] == table[i + 3][j - 3] && table[i][j] != 0) {
          system("cls");
          for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
              if (table[i][j] == 1) {
                printf("R ");
              } else if (table[i][j] == 2) {
                printf("Y ");
              } else {
                printf("- ");
              }
            }
            printf("\n");
          }
          printf("%d. player %s won! Table is now reset.", table[i][j],
                 ((table[i][j] % 2) ? "(RED)" : "(YELLOW)"));
          tablePtr = fopen("table.txt", "w");
          for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
              fprintf(tablePtr, "%1d ", 0);
            }
            fprintf(tablePtr, "%s", "\n");
          }
          fclose(tablePtr);
          turnPtr = fopen("turn.txt", "w");
          fclose(turnPtr);
          return 0;
        }
      }
    }
    system("cls");
    turn++;
  }
  printf("The game ends on a tie. Table is now reset.");
  tablePtr = fopen("table.txt", "w");
  for (int i = 0; i <= 8; i++) {
    for (int j = 0; j <= 8; j++) {
      fprintf(tablePtr, "%1d ", 0);
    }
    fprintf(tablePtr, "%s", "\n");
  }
  fclose(tablePtr);
  turnPtr = fopen("turn.txt", "w");
  fclose(turnPtr);
  return 0;
}