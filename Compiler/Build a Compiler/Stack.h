#include <stdlib.h>

#define MAX 100000
int itemCount = 0;

// Creating a stack
struct stack {
  int items[MAX];
  int top;
};
typedef struct stack _stack;

void createEmptyStack(_stack *s) {
  s->top = -1;
}

// Check if the stack is full
int isStackFull(_stack *s) {
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

// Check if the stack is empty
int isempty(_stack *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

// Add elements into stack
void push(_stack *s, int newitem) {
  if (isStackFull(s)) {
    printf("STACK FULL");
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  itemCount++;
}

// Remove element from stack
int pop(_stack *s) {
  if (isempty(s)) {
    return -1;
  } else {
    //printf("Item popped= %d", s->items[s->top]);
    s->top--;
  }
  itemCount--;
}

// Print elements of stack
void printStack(_stack *s) {
  int i;
  for (i = 0; i < itemCount; i++) {
    printf("%d, ", s->items[i]);
  }
}
