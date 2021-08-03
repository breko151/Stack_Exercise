#include "stack.h"

void procedure();

int main(int argc, char **argv) {
    procedure();
    return 0;
}

void procedure() {
    Stack *numberRegister = createStack();
    Stack *auxStack = createStack();
    Stack *minusStack = createStack();
    char ans = 'n';
    int opt = 0;
    int value = 0;
    printf("Welcome...");
    while(ans == 'n' || ans == 'N') {
        printf("\nThese are your options:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Top");
        printf("\nWhat do you want? ");
        scanf("%d", &opt);
        fflush(stdout);
        switch(opt) {
            case 1:
                printf("Write a value: ");
                scanf("%d", &value);
                push(numberRegister, value);
                break;
            case 2:
                printf("The delete value was: %d", pop(numberRegister)); 
                break;
            case 3:
                printf("The last-in value is:  %d", top(numberRegister));
                break;
            default:
                printf("You have to choose a right option");
                break;
        }
        fflush(stdin);
        printf("\nDou you want to exit? [y/n]: ");
        scanf("%c", &ans);
    }
    while(numberRegister->top != 0) {
        push(minusStack, top(numberRegister));
        pop(numberRegister);
        while (numberRegister->top != 0)
        {
            if(top(numberRegister) >= top(minusStack)) {
                push(auxStack, top(numberRegister));
                pop(numberRegister);
            } else {
                push(minusStack, top(numberRegister));
                pop(numberRegister);
            }
        }
        
    }
    printf("The minus value is: %d", top(minusStack));
}