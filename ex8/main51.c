#include <stdio.h>

int main() {
    int var[5] = {1, 10, 100, 1000, 10000};
    int* ip = NULL;
    ip = var;    /* 陣列名稱就是第一個元素的位址 */
    printf("%p\n", var);
    printf("%p\n", &var[0]);
    printf("%p\n", &var);
    printf("%p\n", ip);
    return 0;
}
