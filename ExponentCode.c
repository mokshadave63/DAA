#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
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
struct Node* multiply(struct Node* num, int multiplier) {
    struct Node* result = NULL;
    for (int i = 0; i < multiplier; ++i) {
        result = add(result, num);
    }
    return result;
}
struct Node* extractNumber(int num) {
    struct Node* head = NULL;
    while (num > 0) {
        insertNode(&head, num % 10);
        num /= 10;
    }
    return head;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}
struct Node* power(int x, int y) {
    struct Node* result = extractNumber(1);  
    struct Node* xList = extractNumber(x);
    for (int i = 0; i < y; ++i) {
        result = multiply(result, x);
    }
    return result;
}
int main() {
    int x, y;
    printf("Niya Patel-22BCP385");
    printf("\nEnter the base (x): ");
    scanf("%d", &x);
    printf("Enter the exponent (y): ");
    scanf("%d", &y);
    struct Node* result = power(x, y);
    printf("%d raised to the power %d is: ", x, y);
    printList(result);
    return 0;
}