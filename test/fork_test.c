//
// Created by 李延 on 2021/7/14.
//


#include <zconf.h>
#include <printf.h>

int test() {



    int aaa = (1<<0) & (1<<0);

    int son;

    if ((son = fork()) == 0) {
        printf("%s\n", "00000");
        _exit(son);
    } else {
        printf("%s\n", "22222");
        return son;
    }
}

int main() {
    int son = test();
    printf("%s\n", "111111");

    return 1;

}