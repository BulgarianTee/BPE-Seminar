#include <stdio.h>
#include "menu.h"

# define ROWS 5
# define COLUMNS 6
# define CURRENT_SUM matrix_of_sums[i][j]


void zadacha1() {

    int matrix[ROWS][COLUMNS] = {
        {6, 7, 8, 9, 10, 11},
        {5, 6, 7, 8, 9, 10},
        {4, 5, 6, 7, 8, 9},
        {3, 4, 5, 6, 7, 8},
        {2, 3, 4, 5, 6, 7}
    };

    // check rows
    for(int i = 0; i < ROWS; i++) {
        int prev = matrix[i][0];
        for(int j = 1; j < COLUMNS; j++) {
            if(matrix[i][j] <= prev) {
                printf("Matrix is incorrect!");
                pause_and_wait();
                return;
            }
            else {
                prev = matrix[i][j];
            }
        }
    }

    // check columns
    for(int j = 0; j < COLUMNS; j++) {
        int prev = matrix[0][j];
        for(int i = 1; i < ROWS; i++) {
            if(matrix[i][j] >= prev) {
                printf("Matrix is incorrect!");
                pause_and_wait();
                return;
            }
            else {
                prev = matrix[i][j];
            }
        }
    }

    printf("Matrix is correct!");

    pause_and_wait();

}

void zadacha2() {

    int matrix[ROWS][COLUMNS] = {
        {3, 7, 1, 9, 0, 5},
        {8, 2, 6, 4, 7, 1},
        {0, 9, 3, 5, 2, 8},
        {6, 1, 4, 7, 9, 3},
        {5, 8, 2, 0, 6, 4}
    };

    int matrix_of_sums[ROWS][COLUMNS] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {

            if(i-1 >= 0) CURRENT_SUM += matrix[i-1][j];
            if(i+1 < ROWS) CURRENT_SUM += matrix[i+1][j];
            if(j-1 >= 0) CURRENT_SUM += matrix[i][j-1];
            if(j+1 < COLUMNS) CURRENT_SUM += matrix[i][j+1];

            if(i-1 >= 0 && j-1 >= 0) CURRENT_SUM += matrix[i-1][j-1];
            if(i-1 >= 0 && j+1 < COLUMNS) CURRENT_SUM += matrix [i-1][j+1];
            if(i+1 < ROWS && j-1 >= 0) CURRENT_SUM += matrix[i+1][j-1];
            if(i+1 < ROWS && j+1 < COLUMNS) CURRENT_SUM += matrix[i+1][j+1];

        }
    }

    int max = matrix_of_sums[0][0];

    for(int i = 0; i < ROWS; i++) for(int j = 0; j < COLUMNS; j++) {
        if(CURRENT_SUM > max) max = CURRENT_SUM;
    }

    for(int i = 0; i < ROWS; i++) for(int j = 0; j < COLUMNS; j++) {
        if(CURRENT_SUM == max) {
            printf("Element %d at [%d;%d] with sum %d!", matrix[i][j], i, j, max);
            i = ROWS;
            j = COLUMNS;
            break;
        }
    }

    pause_and_wait();

}

void zadacha3() {

    int matrix[ROWS][COLUMNS] = {
        {3, 7, 1, 9, 0, 5},
        {8, 2, 6, 4, 7, 1},
        {-1, 9, 3, 5, 2, 8},
        {6, 1, 4, 7, 9, 3},
        {5, 8, 2, 0, 6, 10}
    };

    int result[ROWS][COLUMNS] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0} 
    };

    int min = matrix[0][0];
    int minrow = 0;
    int max = matrix[0][0];
    int maxrow = 0;

    for(int i = 0; i < ROWS; i++) for(int j = 0; j < COLUMNS; j++) {
        if(matrix[i][j] > max) {max = matrix[i][j]; maxrow = i;}
        if(matrix[i][j] < min) {min = matrix[i][j]; minrow = i;}
    }

    for(int i = 0; i < ROWS; i++) {
        int change = i;
        if(change == minrow) change = maxrow;
        else if(change == maxrow) change = minrow;
        for(int j = 0; j < COLUMNS; j++) {
            result[i][j] = matrix[change][j];
        }
    }

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    pause_and_wait();

}

void zadacha4() {

    int friendCount[512];

    int N;
    int M;
    printf("Enter N <= 100k: ");
    scanf("%d", &N);
    printf("Enter M <= 1M: ");
    scanf("%d", &M);

    for(int i = 0; i < N; i++) friendCount[i] = 0;

    int a;
    int b;

    for (int i = 0; i < M; i++) {

        printf("Person #1 ID: ");
        scanf("%d", &a);

        printf("Person #2 ID: ");
        scanf("%d", &b);

        printf("Person[%d] and Person[%d] are now friends!\n", a, b);

        friendCount[a]++;
        friendCount[b]++;
    }

    int n = 0;

    while(1) {
        printf("Person ID (-1 to exit): ");
        scanf("%d", &n);
        if(n < 0) break;
        printf("Person[%d] has %d amount of connections!\n", n, friendCount[n]);
    }

    pause_and_wait();

}

void zadacha5() {

    int array[64];
    int elementcount = 0;

    int choice;

    while(1) {
        printf("Current array: [ ");
        for(int i = 0; i < elementcount; i++) printf("%d ", array[i]);
        printf("]\n\n1. add(x)\n2. delete(x)\n3. smallest(x)\n4. exit\n\n");
        scanf("%d", &choice);
        if(choice == 4) break;
        if(choice == 1) {
            int x;
            printf("X = ");
            scanf("%d", &x);
            array[elementcount] = x;
            elementcount++;
        }
        if(choice == 2) {
            int x;
            printf("X = ");
            scanf("%d", &x);
            for(int i = 0; i < elementcount; i++) {
                if(array[i] == x) {
                    for(int j = i; j < elementcount-1; j++) array[j] = array[j+1];
                    elementcount--;
                    i--;
                }
            }
        }
        if(choice == 3) {

            int temp[64];
            int x;
            printf("X = ");
            scanf("%d", &x);

            for (int i = 0; i < elementcount; i++) {
                temp[i] = array[i];
            }

            for (int i = 0; i < elementcount - 1; i++) {
                for (int j = i + 1; j < elementcount; j++) {
                    if (temp[i] > temp[j]) {
                        int t = temp[i];
                        temp[i] = temp[j];
                        temp[j] = t;
                    }
                }
            }

            printf("#%d smallest element in the list is %d\n", x, temp[x-1]);

        }
    }

    pause_and_wait();

}

int isPrime(int num) {
    if (num < 2) return 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void zadacha6() {

    int array[64];
    int primes[64];
    int n;
    int primesN = 0;

    printf("N: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < n; i++) {
        if(isPrime(array[i])) {
            primes[primesN] = array[i];
            primesN++;
            for(int j = i; j < n-1; j++) array[j] = array[j+1];
            n--;
            i--;
        }
    }

    for(int i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");
    for(int i = 0; i < primesN; i++) printf("%d ", primes[i]);

    pause_and_wait();

}

void zadacha7() {

    int matrix[64][64];
    int matrix_of_sums[64][64];
    int n;
    int m;

    printf("N: ");
    scanf("%d", &n);
    printf("M: ");
    scanf("%d", &m);

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        printf("Matrix[%d][%d]: ", i, j);
        scanf("%d", &matrix[i][j]);
        matrix_of_sums[i][j] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            CURRENT_SUM += matrix[i][j];

            if(i-1 >= 0) CURRENT_SUM += matrix[i-1][j];
            if(i+1 < n) CURRENT_SUM += matrix[i+1][j];
            if(j-1 >= 0) CURRENT_SUM += matrix[i][j-1];
            if(j+1 < m) CURRENT_SUM += matrix[i][j+1];

            if(i-1 >= 0 && j-1 >= 0) CURRENT_SUM += matrix[i-1][j-1];
            if(i-1 >= 0 && j+1 < m) CURRENT_SUM += matrix [i-1][j+1];
            if(i+1 < n && j-1 >= 0) CURRENT_SUM += matrix[i+1][j-1];
            if(i+1 < n && j+1 < m) CURRENT_SUM += matrix[i+1][j+1];

        }
    }

    int max = matrix_of_sums[0][0];

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(CURRENT_SUM > max) max = CURRENT_SUM;
    }

    printf("Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(CURRENT_SUM == max) {
            printf("3x3 at [%d;%d] with sum %d!", i, j, max);
            i = n;
            j = m;
            break;
        }
    }

    pause_and_wait();

}

void zadacha8() {
    
    int array[64];
    int count = 10;

    for(int i = 0; i < count; i++) {
        printf("Array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    int n;
    int index;
    while(1) {

        printf("Current array: [ ");
        for(int i = 0; i < count; i++) printf("%d ", array[i]);
        printf("]\n\n");

        printf("Enter value or 0 to exit: ");
        scanf("%d", &n);
        if(n == 0) break;
        printf("Enter index: ");
        scanf("%d", &index);

        for(int i = count; i > index; i--) array[i] = array[i-1];
        count++;
        array[index] = n;
    }
    
    pause_and_wait();

}

int main() {

    MenuOption options[] = {
        {"Zadacha 1", zadacha1},
        {"Zadacha 2", zadacha2},
        {"Zadacha 3", zadacha3},
        {"Zadacha 4", zadacha4},
        {"Zadacha 5", zadacha5},
        {"Zadacha 6", zadacha6},
        {"Zadacha 7", zadacha7},
        {"Zadacha 8", zadacha8},
        {"Exit", exit_program}
    };

    run_menu("Zadachi Menu", options, 9);

    return 0;

}