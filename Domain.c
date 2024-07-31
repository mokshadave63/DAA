#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node Node;
struct LinkedList {
    Node* head;
};
typedef struct LinkedList LinkedList;
void addDigit(LinkedList* list, int digit) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = digit;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}
void addNumbers(LinkedList* result, LinkedList* num1, LinkedList* num2) {
    int carry = 0;
    Node* current1 = num1->head;
    Node* current2 = num2->head;
    while (current1 != NULL || current2 != NULL || carry != 0) {
        int digit1 = (current1 != NULL) ? current1->data : 0;
        int digit2 = (current2 != NULL) ? current2->data : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        addDigit(result, sum % 10);
        if (current1 != NULL) {
            current1 = current1->next;
        }
        if (current2 != NULL) {
            current2 = current2->next;
        }
    }
}
int compareLists(LinkedList* num1, LinkedList* num2) {
  Node* current1 = num1->head;
  Node* current2 = num2->head;
  while (current1 != NULL && current2 != NULL) {
    if (current1->data != current2->data) {
      return current1->data > current2->data ? 1 : -1; 
    }
    current1 = current1->next;
    current2 = current2->next;
  }
  if (current1 == NULL && current2 != NULL) {
    return -1; 
  } else if (current2 == NULL && current1 != NULL) {
    return 1; 
  } else {
    return 0; 
  }
}
void subtractNumbers(LinkedList* result, LinkedList* num1, LinkedList* num2) {
  int borrow = 0;
  Node* current1 = num1->head;
  Node* current2 = num2->head;
  int isNum1Larger = compareLists(num1, num2);
  while (current1 != NULL || current2 != NULL || borrow != 0) {
    int digit1 = (current1 != NULL) ? current1->data : 0;
    int digit2 = (current2 != NULL) ? current2->data : 0;
    int difference = digit1 - digit2 - borrow;
    borrow = 0;
    if (difference < 0) {
      borrow = 1;
      difference += 10;
    }
    if (isNum1Larger < 0 && difference < 0) {
      printf("Error: Cannot subtract larger number from smaller number.\n");
      return;
    }
    addDigit(result, difference);
    if (current1 != NULL) {
      current1 = current1->next;
    }
    if (current2 != NULL) {
      current2 = current2->next;
    }
  }
}
void printListReverse(LinkedList* list) {
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%d", current->data);
        current = current->prev;
    }
    printf("\n");
}
void extractDigits(LinkedList* list, int number) {
    while (number > 0) {
        addDigit(list, number % 10);
        number /= 10;
    }
}
int main() {
    LinkedList num1 = {NULL};
    LinkedList num2 = {NULL};
    LinkedList result = {NULL};
    int input_num1, input_num2;
    printf("Enter the first number: ");
    scanf("%d", &input_num1);
    printf("Enter the second number: ");
    scanf("%d", &input_num2);
    int choice;
    printf("\n1 for addition and 2 for subtraction");
    scanf("%d",&choice);
    if(choice==1)
{
    
    	extractDigits(&num1, input_num1);
    	extractDigits(&num2, input_num2);
    	addNumbers(&result, &num1, &num2);
    	printf("Result of addition: ");
    	printListReverse(&result);
    	Node* current = num1.head;
    	Node* next;
    	while (current != NULL) {
        	next = current->next;
        	free(current);
        	current = next;
    	}
    	current = num2.head;
    	while (current != NULL) {
        	next = current->next;
        	free(current);
        	current = next;
    	}
    	current = result.head;
    	while (current != NULL) {
        	next = current->next;
        	free(current);
        	current = next;
    	}
}
    else if(choice==2)
{
    	if(input_num1>input_num2)
	{
    		extractDigits(&num1, input_num1);
    		extractDigits(&num2, input_num2);

    		subtractNumbers(&result, &num1, &num2);
	}
	else{
   		extractDigits(&num2,input_num2);
    		extractDigits(&num1,input_num1);
    		subtractNumbers(&result,&num2,&num1);
	}
    	printf("Result of sub: ");
    	printListReverse(&result);
	Node* current = num1.head;
	Node* next;
    	while (current != NULL) {
       		next = current->next;
        	free(current);
        	current = next;
    	}
    	current = num2.head;
    	while (current != NULL) {
        	next = current->next;
        	free(current);
        	current = next;
    	}
    	current = result.head;
    	while (current!= NULL) {
        	next = current->next;
        	free(current);
        	current = next;
    	}
}
    	return 0;
}