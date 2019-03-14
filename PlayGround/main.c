//
// Created by Pavel on 2019-03-14.
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "some.h"

void print(int a){
    printf("you passed %d\n", a);
}

int main(){
    message first;

    first.function = print;
    first.number = 3;
    strcpy(first.header, "dsdf");

    first.function(11);



}