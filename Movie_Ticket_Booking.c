#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char code[20];
    char name[20];
    int cost;
};

void viewAll();
void insert_details();
void book_ticket();
void old_record();
void delete_files();

int main()
{
    int ch;
    
    do {
        printf("\n\t\t\t\t===============================================");
        printf("\n");
        printf("\t\t\t\t\tMovie Ticket Booking System");
        printf("\n");
        printf("\n\t\t\t\t===============================================");
        printf("\nPress <1> View All Movies");
        printf("\nPress <2> Insert Movie");
        printf("\nPress <3> Book Ticket");
        printf("\nPress <4> View All Transactions");
        printf("\nPress <5> Delete Files");
        printf("\nPress <0> Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                viewAll();
                break;
            case 2:
                insert_details();
                break;
            case 3:
                book_ticket();
                break;
            case 4:
                old_record();
                break;
            case 5:
                delete_files();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("\n\nWrong choice!");
                break;
        }
    } while (ch != 0);

    return 0;
}

void viewAll()
{
    char ch;
    FILE *fp;
    
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("\nFile does not found!");
        exit(1);
    } else {
        system("clear");
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
    }
    
    fclose(fp);
}

void insert_details()
{
    FILE *fp;
    struct book b;
    
    printf("\nEnter movie code: ");
    scanf("%s", b.code);
    printf("Enter name: ");
    scanf("%s", b.name);
    printf("Enter ticket price: ");
    scanf("%d", &b.cost);
    
    fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("\nFile not Found");
    } else {
        fprintf(fp, "%s %s %d\n", b.code, b.name, b.cost);
        printf("\nRecord inserted successfully into the file");
    }
    
    fclose(fp);
}

void book_ticket()
{
    struct book b;
    FILE *fp;
    FILE *ufp;
    int total_seat, total_amount;
    char name[20];
    char mobile[40];
    char ch;
    char movie_code[20];
    
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("\nFile does not found!");
        exit(1);
    } else {
        system("clear");
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
    }
    
    fclose(fp);
    
    printf("\nFor booking ticket, enter the movie code (first letter of the movie): ");
    scanf("%s", movie_code);
    system("clear");
    
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File does not found!");
        exit(1);
    } else {
        while (fscanf(fp, "%s %s %d", b.code, b.name, &b.cost) != EOF) {
            if (strcmp(b.code, movie_code) == 0) {
                printf("%s / %s / %d\n", b.code, b.name, b.cost);
                printf("\nRecord Found\n");
                printf("\n\t\tCode: %s", b.code);
                printf("\n\t\tMovie name: %s", b.name);
                printf("\n\t\tPrice of ticket: %d", b.cost);
            }
        }
    }
    
    printf("\n\n* Fill Details *");
    printf("\nYour name: ");
    scanf("%s", name);
    printf("Mobile number (10 digits only): ");
    scanf("%s", mobile);
    printf("Total number of tickets: ");
    scanf("%d", &total_seat);
    
    total_amount = b.cost * total_seat;
    
    printf("\n* ENJOY THE MOVIE **\n");
    printf("\n\t\tName: %s", name);
    printf("\n\t\tMobile Number: %s", mobile);
    printf("\n\t\tMovie Name: %s", b.name);
    printf("\n\t\tTotal Seats: %d", total_seat);
    printf("\n\t\tCost per Ticket: %d", b.cost);
    printf("\n\t\tTotal Amount: %d", total_amount);
    
    ufp = fopen("oldTransaction.txt", "a");
    if (ufp == NULL) {
        printf("\nFile not Found");
    } else {
        fprintf(ufp, "%s %s %d %d %s %d\n", name, mobile, total_seat, total_amount, b.name, b.cost);
        printf("\nRecord inserted successfully into the old record file");
    }
    
    fclose(ufp);
    fclose(fp);
}

void old_record()
{
    char ch;
    FILE *fp;
    
    system("clear");
    
    fp = fopen("oldTransaction.txt", "r");
    if (fp == NULL) {
        printf("\nFile does not found!");
        exit(1);
    } else {
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
    }
    
    fclose(fp);
}

void delete_files()
{
    if (remove("data.txt") == 0) {
        printf("\nThe Movie file is deleted successfully.");
    } else {
        printf("\nThe Movie file is not deleted.");
    }
    
    if (remove("transaction.txt") == 0) {
        printf("\nThe Transaction file is deleted successfully.");
    } else {
        printf("\nThe Transaction file is not deleted.");
    }
}
