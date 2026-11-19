#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUMS 7      
#define MAXN 69     
#define ROWS 5


void sort(int a[], int len) {
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
}


void make_lotto(int a[]) {
    int used[MAXN + 1] = {0};          
    for (int i = 0; i < NUMS; i++) {
        int x;
        do {
            x = rand() % MAXN + 1;     
        } while (used[x]);             
        used[x] = 1;
        a[i] = x;
    }
    sort(a, NUMS - 1);                 
}

int main(void) {
    int n;
    srand((unsigned)time(NULL));       

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);
    if (n < 1 || n > 5) {
        printf("只能購買 1 ~ 5 組！\n");
        return 1;
    }

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟 lotto.txt\n");
        return 1;
    }

    
    time_t now = time(NULL);
    char date[32];
    strcpy(date, ctime(&now));
    date[strlen(date) - 1] = '\0';

    fprintf(fp, "======== lotto649 ========\n");
    fprintf(fp, "= %s =\n", date);
    for (int i = 0; i < ROWS; i++) {
        fprintf(fp, "[%d]: ", i + 1);
        if (i < n) {
            int a[NUMS];
            make_lotto(a);
            for (int j = 0; j < NUMS; j++)
                fprintf(fp, "%02d ", a[j]);    
        } else {
            for (int j = 0; j < NUMS; j++)
                fprintf(fp, "-- ");
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "======== csie@CGU ========\n");
    fclose(fp);

    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
