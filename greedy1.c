#include <stdio.h>
#include <stdlib.h>

struct Event {
    char name;
    int start;
    int end;
};

int compare(const void *a, const void *b) {
    struct Event *event1 = (struct Event *)a;
    struct Event *event2 = (struct Event *)b;
    return event1->end - event2->end;
}

void scheduleEvents(struct Event events[], int n) {
    qsort(events, n, sizeof(struct Event), compare);

    int count = 0;
    int lastEnd = 0;

    printf("Scheduled events: ");
    for (int i = 0; i < n; i++) {
        if (events[i].start >= lastEnd) {
            printf("%c ", events[i].name);
            count++;
            lastEnd = events[i].end;
        }
    }

    printf("\nMaximum number of events that can be scheduled: %d\n", count);
}

int main() {
    int n;
    printf("Enter the number of events: ");
    scanf("%d", &n);

    struct Event *events = malloc(n * sizeof(struct Event));

    printf("Enter the events in the format (name start_time end_time):\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d", &events[i].name, &events[i].start, &events[i].end);
    }

    scheduleEvents(events, n);

    free(events);
    return 0;
}
