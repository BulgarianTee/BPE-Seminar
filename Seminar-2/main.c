#include "menu.h"
#include <stdio.h>

int returnMin(int a, int b) {

    if(a<b) return a;
    else return b;

}

int returnMax(int a, int b) {

    if(a>b) return a;
    else return b;

}

void zadacha1() {

    int n = 1;
    int min;
    int max;

    printf("Enter a number: ");
    scanf("%d", &min);
    while(n != 0 && min != 0) {
        printf("Enter a number: ");
        scanf("%d", &n);
        min = returnMin(n, min);
    }
    printf("\nSmallest was %d\n\n", min);
    n = 1;

    printf("Enter a number: ");
    scanf("%d", &max);
    while(n != 0 && max != 0) {
        printf("Enter a number: ");
        scanf("%d", &n);
        max = returnMax(n, max);
    }
    printf("\nLargest was %d", max);


    pause_and_wait();

}

void zadacha2() {

    int hour, min;
    printf("Enter hours: ");
    scanf("%d", &hour);
    printf("Enter minutes: ");
    scanf("%d", &min);
    printf("\nTime was %.2d:%.2d", hour, min);
    min+=15;
    hour+=0;
    if(min >= 60) {min-=60; hour+=1;}
    if(hour >= 24) {hour-=24;}
    printf("\nTime now is %.2d:%.2d", hour, min);
    pause_and_wait();

}

void zadacha3() {

    double a,b,c;
    printf("A: ");
    scanf("%lf", &a);
    printf("B: ");
    scanf("%lf", &b);
    printf("C: ");
    scanf("%lf", &c);
    if(a==b && b==c) printf("yes");
    else printf("no");
    pause_and_wait();

}

void zadacha4() {

    int points;
    double total;
    double bonus=0;
    printf("Enter points: ");
    scanf("%d", &points);
    total = points;

    if(points<=100) bonus+=5;
    else if(points<=1000) bonus+=((total*20)/100);
    else bonus+=((total*10)/100);

    if(points%2==0) bonus+=1;
    if(points%10==5) bonus+=2;

    total=points+bonus;

    printf("Bonus: %.1lf\nTotal points: %.1lf", bonus, total);

    pause_and_wait();

}

void zadacha5() {

    int a,b,c;
    int min=0, sec=0;

    printf("Enter time (1 to 50) #1: ");
    scanf("%d", &a);
    printf("Enter time (1 to 50) #2: ");
    scanf("%d", &b);
    printf("Enter time (1 to 50) #3: ");
    scanf("%d", &c);

    sec += (a+b+c);
    while(sec >= 60) {sec-=60;min+=1;}

    printf("Total time: %d:%.2d", min, sec);

    pause_and_wait();

}

void zadacha6() {

    int x1,x2,x;
    int y1,y2,y;

    printf("Enter x1: ");
    scanf("%d", &x1);

    printf("Enter y1: ");
    scanf("%d", &y1);

    do {
        printf("Enter x2: ");
        scanf("%d", &x2);
    } while(x2 <= x1);

    do {
        printf("Enter y2: ");
        scanf("%d", &y2);
    } while(y2 <= y1);

    printf("A(?;?): ");
    scanf("%d", &x);
    printf("A(%d;?): ", x);
    scanf("%d", &y);

    if(y <= y2 && y >= y1 && x <= x2 && x >= x1) {
        printf("\nA(%d;%d) is INSIDE the rectangle", x, y);
    }
    else {
        printf("\nA(%d;%d) is OUTSIDE the rectangle", x, y);
    }

    pause_and_wait();

}

void zadacha7() {

    int n;
    char time, enter;
    double taxi=0.7,bus=0,train=0;
    printf("Enter kilometers n: ");
    scanf("%d", &n);
    printf("Enter time of day: ");
    scanf("%c", &enter); // eat the enter
    scanf("%c", &time);
    scanf("%c", &enter); // eat the enter

    if(time == 'N') taxi+=(0.9*n);
    else taxi+=(0.79*n);

    if(n < 20) {
        printf("Only taxi is available. Taxi: %.2f", taxi);
    }
    else {
        bus+=(0.09*n);
        if(n < 100) {
            printf("Bus and taxi available. Taxi: %.2f. Bus: %.2f",taxi,bus);
            if(taxi>bus) printf("\nBus is cheaper!");
            else printf("\nTaxi is cheaper!");
        }
        else {
            train+=(0.06*n);
            printf("All transports available. Taxi: %.2f. Bus: %.2f. Train: %.2f",taxi,bus,train);
            if(taxi>bus) {
                if(bus>train) printf("\nTrain is cheapest!");
                else printf("\nBus is cheapest!");
            }
            else {
                if(taxi>train) printf("\nTrain is cheapest!");
                else printf("\nTaxi is cheapest!");
            }
        }
    }

    pause_and_wait();

}

void zadacha8() {

    int v,n,t1,t2;
    printf("Enter v in m3: ");
    scanf("%d", &v);
    v*=1000;
    printf("Enter n in h: ");
    scanf("%d", &n);
    printf("Enter liters/hour for first tube: ");
    scanf("%d", &t1);
    printf("Enter liters/hour for second tube: ");
    scanf("%d", &t2);

    if(v-(t1+t2)*n <= 0) printf("Pool is filled");
    else printf("Pool is still filling");

    pause_and_wait();

}

void zadacha9() {

    int x,y,z;
    printf("Enter x in m2: ");
    scanf("%d", &x);
    printf("Enter y in kg per m2: ");
    scanf("%d", &y);
    printf("Enter z in liters: ");
    scanf("%d", &z);

    double grapes = x*y; // total grapes
    grapes*=40;
    grapes/=100; // only 40% is kept

    grapes/=2.5; // 2.5 kg -> 1 liter
    if(grapes >= z) {
        printf("%.2lf liters produced, enough to meet the %d liters requirement", grapes, z);
        printf("\n%.2lf liters for the workers", grapes-z);
    }
    else printf("%.2lf liters is not enough to meet the %d liters requirement", grapes, z);

    pause_and_wait();

}

void zadacha10() {

    int n;
    double p1=0,p2=0,p3=0,p4=0,p5=0;

    printf("Enter n: ");
    scanf("%d", &n);

    int array[n];

    for(int i = 0; i < n; i++) {
        printf("Enter number %d/%d: ", i+1, n);
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < n; i++) {
        if(array[i]<200) p1++;
        else if(array[i]>=200&&array[i]<=399) p2++;
        else if(array[i]>=400&&array[i]<=599) p3++;
        else if(array[i]>=600&&array[i]<=799) p4++;
        else p5++;
    }

    p1*=(100/n); p2*=(100/n); p3*=(100/n); p4*=(100/n); p5*=(100/n);

    printf("P1: %.2lf\n", p1);
    printf("P2: %.2lf\n", p2);
    printf("P3: %.2lf\n", p3);
    printf("P4: %.2lf\n", p4);
    printf("P5: %.2lf\n", p5);

    pause_and_wait();

}

void zadacha11() {

    int n;
    printf("Enter n>3: ");
    scanf("%d", &n);
    int m=n/2;

    // first line
    printf(" /");
    for(int i = 0; i < m; i++) printf("^");
    printf("\\");
    if(n-4>0) for(int i = 0; i < n-4; i++) printf("_");
    printf("/");
    for(int i = 0; i < m; i++) printf("^");
    printf("\\");

    // next lines
    printf("\n");
    for(int i = 0; i < n-2; i++) {
        printf("|");
        if(n%2==1) for(int j = 0; j < n*2-1; j++) printf(" ");
        else for(int j = 0; j < n*2; j++) printf(" ");
        if(n==3) printf(" ");
        printf("|\n");
    }

    // last line
    printf(" \\");
    for(int i = 0; i < m; i++) printf("_");
    printf("/");
    if(n-4>0) for(int i = 0; i < n-4; i++) printf("-");
    printf("\\");
    for(int i = 0; i < m; i++) printf("_");
    printf("/");

    pause_and_wait();

}

void zadacha12() {

    int n;
    printf("Enter n>3: ");
    scanf("%d", &n);



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
        {"Zadacha 10", zadacha10},
        {"Zadacha 11", zadacha11},
        {"Zadacha 12", zadacha12},
        {"Exit", exit_program}
    };

    run_menu("Zadachi Menu", options, 13);

    return 0;

}
