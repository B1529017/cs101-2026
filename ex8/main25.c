#include <stdio.h>

int main() {
    int var = 20;
    int* ip;

    ip = &var;   /* 取得 var 的位址，存進 ip */

    printf("Address of var: %p\n", &var);
    printf("Value of ip: %p\n", ip);
    printf("Address of ip: %p\n", &ip);
    printf("Value of *ip: %d\n", *ip);   /* 取出 ip 指到的值 */
    return 0;
}
