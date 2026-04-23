#include <stdio.h>
#include <string.h>
#include "menu.h"

void zadacha1() {

    int guests = 0;
    int chair = 0;
    int table = 0;
    int cups = 0;
    int dishes = 0;
    printf("Input guests: "); scanf("%d", &guests);
    printf("Input text:\n");

    char input[64];
    while(1) {
        scanf(" %s", input);
        if(strcmp(input, "PARTY!") == 0) break;
        else if(strcmp(input, "Chair") == 0) chair++;
        else if(strcmp(input, "Dishes") == 0) dishes++;
        else if(strcmp(input, "Table") == 0) table++;
        else if(strcmp(input, "Cups") == 0) cups++;
    }

    double total = 0;
    total += (13.99 * chair);
    total += (42.0 * table);
    total += (5.98 * cups);
    total += (21.02 * dishes);

    table*=8; cups*=6; dishes*=6;

    printf("\nTotal spent so far: %.2lf\n", total);
    chair = guests - chair; if(chair<0) chair = 0;
    printf("Needed %d more chairs\n", chair);
    table = guests - table; if(table <= 0) table = 0; else table = table/9 + 1;
    printf("Needed %d more tables\n", table);
    cups = guests - cups; if(cups <= 0) cups = 0; else cups = cups/7 + 1;
    printf("Needed %d more cups\n", cups);
    dishes = guests - dishes; if(dishes <= 0) dishes = 0; else dishes = dishes/7 + 1;
    printf("Needed %d more dishes\n", dishes);

    pause_and_wait();

}

void zadacha2() {

    struct Product {
        int id;
        char name[64];
        double price;
    };

    struct Order {
        int idbought;
        char address[64];
    };

    struct Product productlist[64];
    struct Order orderlist[64];
    int productcount = 0;
    int ordercount = 0;

    char input[64];
    while(1) {
        scanf(" %s", input);
        if(strcmp(input, "END") == 0) break;
        else if(strcmp(input, "Product") == 0) {
            printf("Name: "); scanf(" %s", productlist[productcount].name);
            printf("Price: "); scanf(" %lf", &productlist[productcount].price);
            printf("ID: "); scanf(" %d", &productlist[productcount].id);
            productcount++;
        }
        else if(strcmp(input, "Order") == 0) {
            printf("Address: "); scanf(" %s", orderlist[ordercount].address);
            printf("ID to buy: "); scanf(" %d", &orderlist[ordercount].idbought);
            for(int i = 0; i < productcount; i++) {
                if(productlist[i].id == orderlist[ordercount].idbought) {
                    printf(" |----| Client %s bought %s!\n", orderlist[ordercount].address, productlist[i].name);
                    break;
                }
            }
            ordercount++;
        }
    }

    pause_and_wait();

}

void zadacha3() {

    FILE *fptr;
    fptr = fopen("words.txt", "r");
    if(fptr == NULL) {
        printf("Error opening file words.txt!");
        exit(1);
    }

    char words[64][64];
    char word[64];
    char lastchar;
    int i = 0;
    int filesize;
    fseek(fptr, 0, SEEK_END);
    filesize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    while(ftell(fptr) < filesize) {
        fscanf(fptr, " %s", word);
        if(i == 0) {
            strcpy(words[i], word);
            lastchar = words[i][strlen(words[i]) - 1];
            i++;
        }
        else {
            if(lastchar == word[0]) {
                strcpy(words[i], word);
                lastchar = words[i][strlen(words[i]) - 1];
                i++;
            }
        }
    }

    fclose(fptr);

    fptr = fopen("words-binary.bin", "wb");
    if(fptr == NULL) {
        printf("Error creating file words-binary.bin!");
        exit(1);
    }

    fwrite(words, sizeof(words), 1, fptr);

    fclose(fptr);

    fptr = fopen("words-binary.bin", "rb");
    if(fptr == NULL) {
        printf("Error opening file words-binary.bin!");
        exit(1);
    }

    char binarywords[64][64];

    fread(binarywords, sizeof(binarywords), 1, fptr);

    for(int j = 0; j < i; j++) {
        printf("%s ", binarywords[j]);
    }

    fclose(fptr);

    pause_and_wait();

}

void zadacha4() {

    char text[64];
    int key = 0;

    while(key < 2 || key > 10) {
        printf("Enter key[2; 10]: ");
        scanf("%d", &key);
    }

    printf("\nEnter filename: ");
    scanf(" %s", text);

    FILE *fptr;
    fptr = fopen(text, "r");
    if(fptr == NULL) {
        printf("Error opening file to be encrypted!");
        exit(1);
    }

    fgets(text, sizeof(text), fptr);

    fclose(fptr);

    for(int i = 0; i < strlen(text); i++) {
        text[i] += key;
    }

    fptr = fopen("encrypted.txt", "w");
    if(fptr == NULL) {
        printf("Error opening encrypted.txt!");
        exit(1);
    }

    fputs(text, fptr);

    fclose(fptr);

    pause_and_wait();

}

void zadacha5() {

    char word[64] = "ecology\0";
    int attempts = strlen(word) + 2;
    char display[64];
    char guess;

    for(int i = 0; i < strlen(word); i++) display[i] = '-';
    display[strlen(display)] = '\0';

    while(attempts > 0) {
        printf("Word: %s\nAttempts left: %d\n\nGuess: ", display, attempts);
        guess = getchar(); getchar();
        attempts--;
        for(int i = 0; i < strlen(word); i++) {
            if(guess == word[i]) display[i] = word[i];
        }

        if(strcmp(display, word) == 0) {printf("You win!"); attempts = 1; break;}
    }

    if(attempts == 0) printf("You lose!");

    pause_and_wait();

}

int is_anagram(char *str1, char *str2) {
    if(strlen(str1) != strlen(str2)) return 0;
    char string1[64]; strcpy(string1, str1);
    char string2[64]; strcpy(string2, str2);
    for(int i = 0; i < strlen(string1); i++) {
        for(int j = 0; j < strlen(string2); j++) {
            if(string1[i] == string2[j]) {
                string1[i] = '-';
                string2[j] = '-';
                break;
            }
        }
    }
    for(int i = 0; i < strlen(string1); i++) {
        if(string1[i] != '-') return 0;
        if(string2[i] != '-') return 0;
    }

    return 1;
}

void zadacha6() {

    printf("%d\n", is_anagram("dog\0", "spot\0"));
    printf("%d\n", is_anagram("dog\0", "dod\0"));
    printf("%d\n", is_anagram("dog\0", "god\0"));
    printf("%d\n", is_anagram("peach\0", "cheap\0"));
    printf("%d\n", is_anagram("players\0", "prayers\0"));

    pause_and_wait();

}

struct Worker {
    int id;
    double rate;
    int hours;
    double payment;
};

void zadacha7() {

    int max = 30;
    int current = 0;
    struct Worker workerslist[64];

    FILE *fptr;
    fptr = fopen("database.bin", "r");
    if(fptr == NULL) {
        printf("Error opening workers database!");
        exit(1);
    }

    fread(&current, sizeof(int), 1, fptr);

    for(int i = 0; i < current; i++) {
        fread(&workerslist[i], sizeof(struct Worker), 1, fptr);
    }

    int option;
    while(1) {
        printf("Current workers list: %d/%d\n1. Add a worker\n2. Display workers payment\n3. Save and Exit\n\nOption: ", current, max);
        scanf("%d", &option);
        if(option == 3) break;
        else if(option == 1) if(current >= max) printf("Exceeds limit!\n"); else {
            int id, hours;
            double rate, payment;
            printf("Enter worker's ID: "); scanf("%d", &id);
            printf("Enter worker's $/h: "); scanf("%lf", &rate);
            printf("Enter worker's h/w: "); scanf("%d", &hours);
            if(hours <= 40) payment = hours*rate;
            else payment = 40*rate + (hours-40)*rate*1.5;
            workerslist[current].hours = hours;
            workerslist[current].rate = rate;
            workerslist[current].id = id;
            workerslist[current].payment = payment;
            current++;
        }
        else if(option == 2) {
            printf("\n\nWorkers List:\n\n");
            for(int i = 0; i < current; i++) {
                printf("Worker #%d:\n", workerslist[i].id);
                printf("Works %d hours per week with payment of $%.2lf/h\n", workerslist[i].hours, workerslist[i].rate);
                printf("Calculated weekly salary: $%.2lf\n\n", workerslist[i].payment);
            }
            printf("\n\n");
        }
    }

    fclose(fptr);

    fptr = fopen("database.bin", "w");
    if(fptr == NULL) {
        printf("Error saving workers database!");
        exit(1);
    }

    fwrite(&current, sizeof(int), 1, fptr);
    for(int i = 0; i < current; i++) fwrite(&workerslist[i], sizeof(struct Worker), 1, fptr);

    fclose(fptr);

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
        {"Exit", exit_program}
    };

    run_menu("Zadachi Menu", options, 8);

    return 0;

}