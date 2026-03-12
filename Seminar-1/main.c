#include "menu.h"
#include <stdio.h>
#include <math.h>

/* ---------------- ZADACHA 1 ---------------- */
void zadacha1() {
    printf("-----------------| Zadacha 1.: |-----------------\n\n");

    for(int i = 0; i < 10; i++) {
        printf("%d\n", i+1);
    }

    pause_and_wait();
}

/* ---------------- ZADACHA 2 ---------------- */
void zadacha2() {
    printf("-----------------| Zadacha 2.: |-----------------\n\n");

    for(int i = 1; i <= 10; i++) {
        for(int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    pause_and_wait();
}

/* ---------------- ZADACHA 3 + 4 ---------------- */
void zadacha3_4() {

    char myChar;
    char emptyChar;

    printf("-----------------| Zadacha 3 & 4.: |-----------------\n\n");

    printf("Input char: ");
    scanf("%c", &myChar);
    scanf("%c", &emptyChar);

    for(int i = 0; i < 10; i++) printf("%c", myChar);
    printf("\n");

    for(int i = 0; i < 3; i++)
        printf("%c        %c\n", myChar, myChar);

    for(int i = 0; i < 10; i++) printf("%c", myChar);

    printf("\n");

    printf("    %c    \n   %c %c\n  %c   %c\n %c%c%c%c%c%c%c",
           myChar,myChar,myChar,myChar,myChar,myChar,myChar,myChar,myChar,myChar,myChar,myChar);

    printf("\n\n %c%c%c%c%c%c%c \n  %c   %c\n   %c %c\n    %c    \n",
           myChar,myChar,myChar,myChar,myChar,myChar,myChar,
           myChar,myChar,myChar,myChar,myChar);

    pause_and_wait();
}

/* ---------------- ZADACHA 5 ---------------- */
void zadacha5() {
    int myInt;
    double myFloat;

    printf("-----------------| Zadacha 5.: |-----------------\n\n");

    printf("Input amount of inches: ");
    scanf("%d", &myInt);

    myFloat = myInt * 0.0254;

    printf("\nMeters: %lf\nDecimeters: %lf\nCentimeters: %lf\nMillimeters: %lf\n",
           myFloat, myFloat*10, myFloat*100, myFloat*1000);

    pause_and_wait();
}

/* ---------------- ZADACHA 6 ---------------- */
void zadacha6() {
    double myFloat;

    printf("-----------------| Zadacha 6.: |-----------------\n\n");

    printf("Input amount of degrees in Celsius: ");
    scanf("%lf", &myFloat);

    printf("\nDegrees in Farenheit: %lf", (myFloat*1.8)+32);

    pause_and_wait();
}

/* ---------------- ZADACHA 7 ---------------- */
void zadacha7() {
    int myInt;
    double myFloat;

    printf("-----------------| Zadacha 7.: |-----------------\n\n");

    printf("Input angle in degrees: ");
    scanf("%d", &myInt);

    myFloat = myInt/180.0;
    printf("\nRadians: %lfPi\n", myFloat);

    pause_and_wait();
}

/* ---------------- ZADACHA 8 ---------------- */
void zadacha8() {
    double myFloat;

    printf("-----------------| Zadacha 8.: |-----------------\n\n");

    printf("Input lev: ");
    scanf("%lf", &myFloat);

    printf("\nEuro: %lf\nDollar: %lf\nPound: %lf\n",
           myFloat*0.51, myFloat*0.61, myFloat*0.45);

    pause_and_wait();
}

/* ---------------- ZADACHA 9 ---------------- */
void zadacha9() {
    double a,b,h;

    printf("-----------------| Zadacha 9.: |-----------------\n\n");

    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("h: ");
    scanf("%lf", &h);

    printf("\nArea: %lf\n", ((a+b)/2)*h);

    pause_and_wait();
}

/* ---------------- ZADACHA 10 ---------------- */
void zadacha10() {
    int myInt;
    double myFloat;

    printf("-----------------| Zadacha 10.: |-----------------\n\n");

    printf("Input angle in degrees: ");
    scanf("%d", &myInt); myFloat = (myInt/180.0) * 3.14; // radians
    printf("sin(%d) = %.2lf\n", myInt, sin(myFloat));
    printf("cos(%d) = %.2lf\n", myInt, cos(myFloat));
    printf("tg(%d) = %.2lf\n", myInt, tan(myFloat));
    printf("cotg(%d) = %.2lf\n", myInt, 1/tan(myFloat));

    pause_and_wait();
}

/* ---------------- ZADACHA 11 ---------------- */
void zadacha11() {
    int coords[4];

    printf("-----------------| Zadacha 11.: |-----------------\n\n");

    printf("A(?;?) B(?;?): "); scanf("%d", &coords[0]);
    printf("A(%d;?) B(?;?): ", coords[0]);
    scanf("%d", &coords[1]);
    printf("A(%d;%d) B(?;?): ", coords[0], coords[1]);
    scanf("%d", &coords[2]);
    printf("A(%d;%d) B(%d;?): ", coords[0], coords[1], coords[2]);
    scanf("%d", &coords[3]);
    printf("A(%d;%d) B(%d;%d): Area of rectangle is ", coords[0], coords[1], coords[2], coords[3]);
    int xdiff = coords[0] - coords[2];
    if(xdiff < 0) {
        xdiff*=-1;
    }
    int ydiff = coords[1] - coords[3];
    if(ydiff < 0) {
        ydiff*=-1;
    }
    printf("%d\n", xdiff * ydiff);

    pause_and_wait();
}

/* ---------------- ZADACHA 12 ---------------- */
void zadacha12() {
    int coords[6];

    printf("-----------------| Zadacha 12.: |-----------------\n\n");

    printf("A(?;?) B(?;?) C(?;?): ");
    scanf("%d", &coords[0]);
    printf("A(%d;?) B(?;?) C(?;?): ", coords[0]);
    scanf("%d", &coords[1]);
    printf("A(%d;%d) B(?;?) C(?;?): ", coords[0], coords[1]);
    scanf("%d", &coords[2]);
    printf("A(%d;%d) B(%d;?) C(?;?): ", coords[0], coords[1], coords[2]);
    scanf("%d", &coords[3]);
    printf("A(%d;%d) B(%d;%d) C(?;?): ", coords[0], coords[1], coords[2], coords[3]);
    scanf("%d", &coords[4]);
    printf("A(%d;%d) B(%d;%d) C(%d;?): ", coords[0], coords[1], coords[2], coords[3], coords[4]);
    scanf("%d", &coords[5]);
    printf("A(%d;%d) B(%d;%d) C(%d;%d)\n", coords[0], coords[1], coords[2], coords[3], coords[4], coords[5]);
    double area = (coords[0] * (coords[3] - coords[5])) + (coords[2] * (coords[5] - coords[1])) + (coords[4] * (coords[1] - coords[3]));
    area/=2;
    printf("\nArea of triangle: %lf", area);

    pause_and_wait();
}

/* ---------------- ZADACHA 13 ---------------- */
void zadacha13() {

    double H, W;

    printf("-----------------| Zadacha 13.: |-----------------\n\n");

    printf("Input hall width (m): "); scanf("%lf", &W);
    printf("Input hall height (m): "); scanf("%lf", &H);

    W *= 100;
    H *= 100;

    int rows = (int)(H / 120);
    int cols = (int)((W - 100) / 70);

    int total = rows * cols - 3;

    printf("Workplaces: %d\n", total);

    pause_and_wait();
}

/* ---------------- ZADACHA 14 ---------------- */
void zadacha14() {
    int kgN, kgM;
    double N, M;

    printf("-----------------| Zadacha 14.: |-----------------\n\n");

    printf("Price of a kilogram of vegetables (lv): ");
    scanf("%lf", &N);
    printf("Price of a kilogram of fruits (lv): ");
    scanf("%lf", &M);
    printf("Kilograms of vegetables: ");
    scanf("%d", &kgN);
    printf("Kilograms of fruits: ");
    scanf("%d", &kgM);
    N*=0.51; M*=0.51;
    printf("\nProfit from vegetables (eur): %.2lf\nProfit from fruits (eur): %.2lf\n", N*kgN, M*kgM);

    pause_and_wait();
}

/* ---------------- ZADACHA 15 ---------------- */
void zadacha15() {
    double N, W, L, O, M;

    printf("-----------------| Zadacha 15.: |-----------------\n\n");

    printf("Input N in meters: "); scanf("%lf", &N);
    printf("Input W in meters: "); scanf("%lf", &W);
    printf("Input L in meters: "); scanf("%lf", &L);

    double area = N * N;
    double tileArea = W * L;

    printf("Input O in meters: "); scanf("%lf", &O);
    printf("Input M in meters: "); scanf("%lf", &M);

    double benchArea = O * M;
    double coverArea = area - benchArea;

    printf("Area of %.2lf square meters requires %.2lf tiles which are each %.2lf square meters\n", coverArea, coverArea/tileArea, tileArea);
    printf("It will take %.2lf minutes to place them\n", (coverArea/tileArea)*0.2);

    pause_and_wait();
}

/* ---------------- ZADACHA 16 ---------------- */
void zadacha16() {
    int days;
    double M, conversion;

    printf("-----------------| Zadacha 16.: |-----------------\n\n");

    printf("How many days per month does Ivan work: ");
    scanf("%d", &days);
    printf("How much does he earn per day work (dollars): ");
    scanf("%lf", &M); printf("Convert 1 dollar to X lev: ");
    scanf("%lf", &conversion);
    double monthly = days*M;
    double total = monthly * 14.5; total = (total * 3) / 4;
    total *= conversion;
    printf("\nPer day (lev): %.2lf", total/365);

    pause_and_wait();
}

/* ---------------- MAIN ---------------- */
int main() {

    MenuOption options[] = {
        {"Zadacha 1", zadacha1},
        {"Zadacha 2", zadacha2},
        {"Zadacha 3 & 4", zadacha3_4},
        {"Zadacha 5", zadacha5},
        {"Zadacha 6", zadacha6},
        {"Zadacha 7", zadacha7},
        {"Zadacha 8", zadacha8},
        {"Zadacha 9", zadacha9},
        {"Zadacha 10", zadacha10},
        {"Zadacha 11", zadacha11},
        {"Zadacha 12", zadacha12},
        {"Zadacha 13", zadacha13},
        {"Zadacha 14", zadacha14},
        {"Zadacha 15", zadacha15},
        {"Zadacha 16", zadacha16},
        {"Exit", exit_program}
    };

    run_menu("Zadachi Menu", options, 16);

    return 0;
}
