#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
typedef struct record {
    char *cityName;
    int x;
    int y;
} record;
 
typedef struct database {
    int size;
    record *records;
} database;
 
void printDatabase(database *db) {
    for(int i = 0; i < db->size; i++) {
        printf("%s %d %d\n", db->records[i].cityName, db->records[i].x , db->records[i].y);
    }
}
 
void insertRecord(database *db) {
    db->records = (record*)realloc(db->records, (db->size+1)*sizeof(record));
    if(!db) {
        printf("Memory allocation failed...Exiting");
        return;
    }
    else {
        db->records[db->size].cityName = (char*)malloc(25*sizeof(char));
 
        printf("Enter city name: ");
        scanf("%s", db->records[db->size].cityName);
        printf("Enter x-coordinate: ");
        scanf("%d", &db->records[db->size].x);
        printf("Enter y-coordinate: ");
        scanf("%d", &db->records[db->size].y);
 
        db->size++;
 
        printf("Record inserted\n");
    }
}
 
void deleteRecord(database *db) {
    char ch;
    printf("Delete by (n)ame or (c)oordinate? n/c ");
    scanf(" %c", &ch);
 
    if(ch == 'n') {
        char cityName[25];
        printf("Enter city name to delete: ");
        scanf("%s", cityName);
 
        for(int i = 0; i < db->size; i++) {
            if(strcmp(db->records[i].cityName, cityName) == 0) {
                free(db->records[i].cityName);
                // deallocate the char array
 
                for(int j = i; j < db->size - 1; j++) {
                    db->records[j] = db->records[j + 1];
                }
 
                db->records = realloc(db->records, (db->size-1)*sizeof(record));
                db->size--;
                printf("Record deleted\n");
                return;
            }
        }
        printf("City not found.\n");
    }
    else if(ch == 'c') {
        int deleteX, deleteY;
        printf("Enter x coordinate to delete: ");
        scanf("%d", &deleteX);
        printf("Enter y coordinate to delete: ");
        scanf("%d", &deleteY);
 
        for(int i = 0; i < db->size; i++) {
            if(db->records[i].x == deleteX && db->records[i].y == deleteY) {
                free(db->records[i].cityName);
 
                for(int j = i; j < db->size - 1; j++) {
                    db->records[j] = db->records[j + 1];
                }
 
                db->records = realloc(db->records, (db->size-1)*sizeof(record));
                db->size--;
                printf("Record deleted\n");
                return;
            }
        }
        printf("Coordinate not found.\n");
    }
    else {
        printf("Invalid option...Exiting\n");
    }
}
 
void searchRecord(database *db) {
    char ch;
    printf("Search by (n)ame or (c)oordinate? n/c ");
    scanf(" %c", &ch);
 
    if(ch == 'n') {
        char cityName[25];
        printf("Enter city name to search: ");
        scanf("%s", cityName);
 
        for(int i = 0; i < db->size; i++) {
            if(strcmp(db->records[i].cityName, cityName) == 0) {
                printf("%s %d %d\n", db->records[i].cityName, db->records[i].x , db->records[i].y);
            }
        }
    }
    else if(ch == 'c') {
        int searchX, searchY;
        printf("Enter x coordinate to search: ");
        scanf("%d", &searchX);
        printf("Enter y coordinate to search: ");
        scanf("%d", &searchY);
 
        for(int i = 0; i < db->size; i++) {
            if(db->records[i].x == searchX && db->records[i].y == searchY) {
                printf("%s %d %d\n", db->records[i].cityName, db->records[i].x , db->records[i].y);
            }
        }
    }
    else {
        printf("Invalid option...Exiting\n");
    }
} 
void main() {
    database db = {0, NULL};
 printf("Moksha Dave 22BCP366");
    int ch;
 
    do {
        printf("\nCity Database Menu:\n");
        printf("1) Insert Record\n");
        printf("2) Delete Record\n");
        printf("3) Search Record\n");
        printf("4) Print Database\n");
        printf("0) Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");
 
        switch(ch) {
            case 1:
                insertRecord(&db);
                break;
            case 2:
                deleteRecord(&db);
                break;
            case 3:
                searchRecord(&db);
                break;
            case 4:
                printDatabase(&db);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
 
    } while (ch != 0);
}
