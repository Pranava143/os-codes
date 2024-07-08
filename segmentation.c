#include <stdio.h>
#include <stdlib.h>

struct Segment {
    int seg;
    int base;
    int limit;
    struct Segment *next;
};

struct Segment *head = NULL;

void insertSegment(int seg, int base, int limit) {
    struct Segment *newSegment = (struct Segment *)malloc(sizeof(struct Segment));
    newSegment->seg = seg;
    newSegment->base = base;
    newSegment->limit = limit;
    newSegment->next = NULL;

    if (head == NULL) {
        head = newSegment;
    } else {
        struct Segment *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSegment;
    }
}

struct Segment* findSegment(int seg) {
    struct Segment *temp = head;
    while (temp != NULL && temp->seg != seg) {
        temp = temp->next;
    }
    return temp;
}

int main() {
    int seg, base, limit, offset;
    printf("Enter segment table\n");
    printf("Enter -1 as segment number to stop input\n");

    while (1) {
        printf("Enter segment number: ");
        scanf("%d", &seg);
        if (seg == -1) {
            break;
        }
        printf("Enter base value: ");
        scanf("%d", &base);
        printf("Enter limit value: ");
        scanf("%d", &limit);
        insertSegment(seg, base, limit);
    }

    printf("Enter segment number for address translation: ");
    scanf("%d", &seg);
    printf("Enter offset: ");
    scanf("%d", &offset);

    struct Segment *segment = findSegment(seg);
    if (segment != NULL) {
        if (offset < segment->limit) {
            int physicalAddress = segment->base + offset;
            printf("Physical address is: %d\n", physicalAddress);
        } else {
            printf("Error: Offset exceeds segment limit\n");
        }
    } else {
        printf("Error: Segment not found\n");
    }

    return 0;
}
