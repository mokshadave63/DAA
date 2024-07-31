#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CITIES 1000

// Structure for city record
typedef struct {
    char name[100];
    int x;
    int y;
} CityRecord;

// Structure for array-based list
typedef struct {
    CityRecord cities[MAX_CITIES];
    int size;
} CityDatabaseArray;

// Function to initialize the city database
void initCityDatabaseArray(CityDatabaseArray *db) {
    db->size = 0;
}

// Function to insert a record into the city database
void insertRecordArray(CityDatabaseArray *db, const char *name, int x, int y) {
    if (db->size < MAX_CITIES) {
        strcpy(db->cities[db->size].name, name);
        db->cities[db->size].x = x;
        db->cities[db->size].y = y;
        db->size++;
    } else {
        printf("City database is full.\n");
    }
}

// Function to delete a record by name from the city database
void deleteRecordByNameArray(CityDatabaseArray *db, const char *name) {
    int i, found = 0;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->cities[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < db->size - 1; j++) {
            db->cities[j] = db->cities[j + 1];
        }
        db->size--;
    } else {
        printf("City not found.\n");
    }
}

// Function to delete a record by coordinate from the city database
void deleteRecordByCoordinateArray(CityDatabaseArray *db, int x, int y) {
    int i, found = 0;
    for (i = 0; i < db->size; i++) {
        if (db->cities[i].x == x && db->cities[i].y == y) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < db->size - 1; j++) {
            db->cities[j] = db->cities[j + 1];
        }
        db->size--;
    } else {
        printf("City not found.\n");
    }
}

// Function to search a record by name in the city database
void searchRecordByNameArray(CityDatabaseArray *db, const char *name) {
    int i, found = 0;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->cities[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("City found: %s (%d, %d)\n", db->cities[i].name, db->cities[i].x, db->cities[i].y);
    } else {
        printf("City not found.\n");
    }
}

// Function to search a record by coordinate in the city database
void searchRecordByCoordinateArray(CityDatabaseArray *db, int x, int y) {
    int i, found = 0;
    for (i = 0; i < db->size; i++) {
        if (db->cities[i].x == x && db->cities[i].y == y) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("City found: %s (%d, %d)\n", db->cities[i].name, db->cities[i].x, db->cities[i].y);
    } else {
        printf("City not found.\n");
    }
}

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to print all records within a given distance of a specified point
void printRecordsWithinDistanceArray(CityDatabaseArray *db, int x, int y, double dist) {
    printf("Cities within distance %.2f of (%d, %d):\n", dist, x, y);
    for (int i = 0; i < db->size; i++) {
        double d = distance(x, y, db->cities[i].x, db->cities[i].y);
        if (d <= dist) {
            printf("%s (%d, %d) - Distance: %.2f\n", db->cities[i].name, db->cities[i].x, db->cities[i].y, d);
        }
    }
}

int main() {
    CityDatabaseArray db;
    initCityDatabaseArray(&db);

    int choice;
    do {
        printf("\n1. Insert a city\n");
        printf("2. Delete a city\n");
        printf("3. Search for a city\n");
        printf("4. Print cities within a distance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[100];
                int x, y;
                printf("Enter city name: ");
                scanf("%s", name);
                printf("Enter x coordinate: ");
                scanf("%d", &x);
                printf("Enter y coordinate: ");
                scanf("%d", &y);
                insertRecordArray(&db, name, x, y);
                break;
            }
            case 2: {
                int subChoice;
                printf("1. Delete by name\n");
                printf("2. Delete by coordinate\n");
                printf("Enter sub-choice: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    char name[100];
                    printf("Enter city name to delete: ");
                    scanf("%s", name);
                    deleteRecordByNameArray(&db, name);
                } else if (subChoice == 2) {
                    int x, y;
                    printf("Enter x coordinate to delete: ");
                    scanf("%d", &x);
                    printf("Enter y coordinate to delete: ");
                    scanf("%d", &y);
                    deleteRecordByCoordinateArray(&db, x, y);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            }
            case 3: {
                int subChoice;
                printf("1. Search by name\n");
                printf("2. Search by coordinate\n");
                printf("Enter sub-choice: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    char name[100];
                    printf("Enter city name to search: ");
                    scanf("%s", name);
                    searchRecordByNameArray(&db, name);
                } else if (subChoice == 2) {
                    int x, y;
                    printf("Enter x coordinate to search: ");
                    scanf("%d", &x);
                    printf("Enter y coordinate to search: ");
                    scanf("%d", &y);
                    searchRecordByCoordinateArray(&db, x, y);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            }
            case 4: {
                int x, y;
                double dist;
                printf("Enter x coordinate: ");
                scanf("%d", &x);
                printf("Enter y coordinate: ");
                scanf("%d", &y);
                printf("Enter distance: ");
                scanf("%lf", &dist);
                printRecordsWithinDistanceArray(&db, x, y, dist);
                break;
            }
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

