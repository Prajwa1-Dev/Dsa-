#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a day
typedef struct {
    char *dayName;
    int date;
    char *activity;
} Day;

// Function to create the calendar dynamically
Day* create(int size) {
    Day *calendar = (Day *)malloc(size * sizeof(Day));
    if (calendar == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return calendar;
}

// Function to read data into the calendar

void read(Day *calendar, int size) {
    char choice;
    int validentry=0;
    for (int i = 0; i < size; i++) {
        printf("Enter details for Day %d [y/n]", i + 1);
        scanf("%c",&choice);
        
        if(choice=='y'|| choice=='Y'){
        validentry=1;
        char tempDay[50], tempActivity[100];
        
        // Read day name
        printf("  Enter day name: ");
        scanf(" %49s", tempDay);
        calendar[i].dayName = (char *)malloc(strlen(tempDay) + 1);
        if (calendar[i].dayName == NULL) {
            printf("Memory allocation failed for day name!\n");
            exit(1);
        }
        strcpy(calendar[i].dayName, tempDay);

        // Read date
        printf("  Enter date (as an integer): ");
        scanf("%d", &calendar[i].date);

        // Read activity description
        printf("  Enter activity description: ");
        getchar(); // Consume newline left by previous input
        fgets(tempActivity, 100, stdin);
        tempActivity[strcspn(tempActivity, "\n")] = 0; // Remove trailing newline
        calendar[i].activity = (char *)malloc(strlen(tempActivity) + 1);
        if (calendar[i].activity == NULL) {
            printf("Memory allocation failed for activity!\n");
            exit(1);
        }
        strcpy(calendar[i].activity, tempActivity);
        }
        else{
            printf("Invalid: please enter valid input\n");
            exit(0);
        }
    }
}

// Function to display the calendar
void display(Day *calendar, int size) {
    printf("\nWeekly Activity Report:\n");
    printf("========================\n");
    for (int i = 0; i < size; i++) {
        printf("Day: %s\n", calendar[i].dayName);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].activity);
        printf("------------------------\n");
    }
}

// Free dynamically allocated memory
void freeCalendar(Day *calendar, int size) {
    for (int i = 0; i < size; i++) {
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
    free(calendar);
}

int main() {
    int size = 7; // Size of the calendar for 7 days

    // Create the calendar
    Day *calendar = create(size);

    // Read data for the calendar
    read(calendar, size);

    // Display the calendar
    display(calendar, size);

    // Free allocated memory
    freeCalendar(calendar, size);

    return 0;
}
