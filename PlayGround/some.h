//
// Created by Pavel on 2019-03-14.
//

typedef struct message_format {
    char header[10];
    int number;
    void (*function)(int);
} message;