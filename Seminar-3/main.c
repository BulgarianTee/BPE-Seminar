#include <stdio.h>
#include "menu.h"

void zadacha1() {

    int array[64];
    int n;

    int maxlen = 0;
    int currentlen = 0;
    int maxvalue;
    int currentvalue;

    printf("Input N between 1 and 64: "); scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Input element[%d]: ", i); scanf("%d", &array[i]);
    }

    maxvalue = array[0];
    currentvalue = array[0];

    for(int i = 0; i < n; i++) {

        if(array[i] == currentvalue) {
            currentlen++;
            if(currentlen >= maxlen) {
                maxlen = currentlen;
                maxvalue = currentvalue;
            }
        }
        else {
            currentvalue = array[i];
            currentlen = 1;
        }

    }

    printf("\nBiggest field is at %d with length %d", maxvalue, maxlen);

    pause_and_wait();

}

void zadacha2() {

    int array[64];
    int n;

    printf("Input N between 1 and 64: "); scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Input element[%d]: ", i); scanf("%d", &array[i]);
    }

    int shouldbeless = 0;
    int relations = 1;

    for(int i = 1; i < n; i++) {
        if(shouldbeless) {
            if(array[i] > array[i-1]) {relations = 0; break;}
        }
        else {
            if(array[i] < array[i-1]) {relations = 0; break;}
        }

        shouldbeless = !shouldbeless;
    }

    if(relations) printf("Relations are true!"); else printf("Relations are NOT true!");

    pause_and_wait();

}

void zadacha3() {

    int array[64];
    int n;

    printf("Input N between 1 and 64: "); scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Input element[%d]: ", i); scanf("%d", &array[i]);
    }

    int newarray[64];

    for(int i = 0; i < n; i++) newarray[i] = array[n-i-1];

    for(int i = 0; i < n; i++) printf("New array element[%d] = %d\n", i, newarray[i]);

    pause_and_wait();

}

void zadacha4() {

    int array[64];
    int n;

    printf("Input N between 1 and 64: "); scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Input element[%d]: ", i); scanf("%d", &array[i]);
    }

    int k;
    int newarray[64];

    printf("Input K: "); scanf("%d", &k);

    int truek = k;
    while(truek > n) truek-=n;

    for(int i = 0; i < n; i++) {
        int movement = truek;
        if(movement+i >= n) {
            newarray[i] = array[-(n - (movement+i))];
        }
        else {
            newarray[i] = array[i+movement];
        }
    }

    for(int i = 0; i < n; i++) printf("New array element[%d] = %d\n", i, newarray[i]);

    pause_and_wait();

}

void zadacha5() {

    int array[64];
    int n;

    printf("Input N between 1 and 64: "); scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Input element[%d]: ", i); scanf("%d", &array[i]);
    }

    int k;

    printf("Input K above 1: "); scanf("%d", &k);

    int currentmax;
    int limit = array[0];

    for(int i = 0; i < n; i++) if(array[i] > limit) limit = array[i];

    for(int i = 1; i < k; i++) {
        currentmax = array[0];
        for(int j = 0; j < n; j++) {
            if(array[j] > currentmax && array[j] < limit) {
                currentmax = array[j];
            }
        }
        limit = currentmax;
    }

    printf("#%d largest number is %d", k, limit);

    pause_and_wait();

}

void zadacha6() {

    int array[64];
    int n;

    printf("Input N between 1 and 64: "); scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Input element[%d]: ", i); scanf("%d", &array[i]);
    }

    int max = 0;
    int currentrise = 0;
    int currentfall = 0;
    int atindex = 0;

    for(int i = 1; i < n; i++) {
        if(array[i] > array[i-1]) {
            currentfall = 0;
            currentrise++;
        }
        else if(array[i] < array[i-1]) {
            currentrise = 0;
            currentfall++;
        }
        else {
            currentrise++;
            currentfall++;
        }

        if(currentrise > max) {
            max = currentrise;
            atindex = i-max;
        }
        else if(currentfall > max) {
            max = currentfall;
            atindex = i-max;
        }
    }

    printf("\n");
    for(int i = atindex; i <= atindex+max; i++) printf("%d ", array[i]);

    pause_and_wait();

}

void zadacha7() {

    int array[64];
    int n;

    printf("Input N between 1 and 64: "); scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Input element[%d]: ", i); scanf("%d", &array[i]);
    }

    int currentsum;
    int sum;

    printf("Input sum: "); scanf("%d", &sum);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            currentsum = 0;
            for(int k = 0; k <= i; k++) currentsum += array[j+k];
            if(currentsum == sum) {
                printf("%d is the sum of ", sum);
                for(int k = 0; k <= i; k++) printf("%d ",array[j+k]);
                printf("\n");
            }
        }
    }

    pause_and_wait();

}

void zadacha8() {

    int array[64];
    int count = 10;
    int n;
    int index;

    for(int i = 0; i < 10; i++) {
        printf("Input element[%d]: ", i); scanf("%d", &array[i]);
    }

    for(int i = 0; i < 10; i++) {
        printf("Enter number to push into the array or 0 to exit: ");
        scanf("%d", &n);

        if(n == 0) break;
        else {
            count++;
            printf("Enter index: ");
            scanf("%d", &index);
            for(int j = count; j > index; j--) {
                array[j] = array[j-1];
            }
            array[index] = n;
        }
    }

    for(int i = 0; i < count; i++) printf("Array[%d]: %d\n", i, array[i]);

    pause_and_wait();

}

void zadacha9() {

    int array[64];
    int n;

    printf("Input N between 1 and 64: "); scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Input element[%d]: ", i); scanf("%d", &array[i]);
    }

    int max = 0;
    int current = 0;
    int atindex = 0;

    for(int i = 1; i < n; i++) {
        if(array[i] == array[i-1]) current++;
        else current = 0;

        if(current > max) {
            max = current;
            atindex = i-max;
        }
    }

    printf("\n");
    for(int i = atindex; i <= atindex+max; i++) printf("%d ", array[i]);

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
        {"Zadacha 9", zadacha9},
        {"Exit", exit_program}
    };

    run_menu("Zadachi Menu", options, 10);

    return 0;

}