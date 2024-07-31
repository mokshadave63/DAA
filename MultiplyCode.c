#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
struct Node* add(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    struct Node* current = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int sum = carry;

        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }

        insertNode(&result, sum % 10);
        carry = sum / 10;
    }

    return result;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}
void printListReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }

    printListReverse(head->next);
    printf("%d", head->data);
}
struct Node* multiply(struct Node* num, int multiplier) {
    struct Node* result = NULL;

    for (int i = 0; i < multiplier; ++i) {
        result = add(result, num);
    }

    return result;
}
void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {    
    int num1, num2;
    printf("Niya Patel-22BCP385");
    printf("\nEnter First number: ");
    scanf("%d", &num1);
    printf("Enter Second  number: ");
    scanf("%d", &num2);
    struct Node* list1 = NULL;
    if(num1<=0 || num2<=0) {
	printf("Enter a non negative and non zero number");
    }
    else {
    	while (num1 > 0) {
        	insertNode(&list1, num1 % 10);
        	num1 /= 10;
    	}
    	struct Node* result = multiply(list1, num2);
    	printf("Reversed Result: ");
    	printListReverse(result);
    	freeList(list1);
    	freeList(result);
    }
    return 0;
}


