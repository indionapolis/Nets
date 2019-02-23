#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// use "push [int]" to push number onto stack

struct Node
{
    int value;
    struct Node *next_node;
};

struct Node* head = NULL;
int count;


int peek(){
    if (head == NULL) {
        printf("use \"create\" function to set up new stack\n");
        exit(EXIT_FAILURE);
    }

    if (count == 0) {
        printf("stack is empty\n");
        return -1;
    }

    printf("%d\n", head->value);
    return head->value;
}

void push(int value){
    if (head == NULL) {
        printf("use \"create\" function to set up new stack\n");
        exit(EXIT_FAILURE);
    }

    if (count == 0) {
        head->value = value;
    }
    else {
        struct Node *next_node = malloc(sizeof(struct Node));
        next_node->value = value;
        next_node->next_node = head;
        head = next_node;
    }

    count++;
}

void pop(){
    if (head == NULL) {
        printf("use \"create\" function to set up new stack\n");
        exit(EXIT_FAILURE);
    }
//    printf("%d\n", count);

    if (count == 0) {
        printf("stack is empty\n");
        return;
    }


    int value = head->value;

    if (count != 1){
        struct Node* head_pointer = head;
        head = head->next_node;

        free(head_pointer);
    }

    count--;

    printf("%d\n", value);
}

int empty(){
    if (head == NULL) {
        printf("use \"create\" function to set up new stack\n");
        exit(EXIT_FAILURE);
    }

    return count;
}

void display(){
    if (head == NULL) {
        printf("use \"create\" function to set up new stack\n");
        exit(EXIT_FAILURE);
    }

    if (count == 0) {
        printf("stack is empty\n");
        return;
    }

    struct Node* current_node = head;

    while (current_node != NULL)
    {
        printf("%d\n", current_node->value);
        current_node = current_node->next_node;
    }

}

void create(){
    head = malloc(sizeof(struct Node));
    head->next_node = NULL;
    count = 0;

    printf("stack has been created!\n");
}

void stack_size(){
    if (head == NULL) {
        printf("use \"create\" function to set up new stack\n");
        exit(EXIT_FAILURE);
    }
    printf("size: %d\n", count);
}



int main() {
    char* buf = malloc(128* sizeof(char));
    int fds[2];
    pipe(fds);

    int pid = fork();
    if (pid > 0){
        close(fds[0]);
        char* string = malloc(128*sizeof(char*));

        while (1){
            // read string from console
            gets(string);
            // send string to server
            write(fds[1], string, 128);
        }

    } else {

        while (1){
            read(fds[0], buf, 128);
            printf("server got massage: %s\n", buf);

            if (strstr(buf, "peek")) {
                peek();
            } else if (strstr(buf, "push")) {
                push(atoi(buf + 5));
            } else if (strstr(buf, "pop")) {
                pop();
            } else if (strstr(buf, "empty")) {
                empty();
            } else if (strstr(buf, "display")) {
                display();
            } else if (strstr(buf, "create")) {
                create();
            } else if (strstr(buf, "stack_size")) {
                stack_size();
            };
        }

    }
}

