#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h> 

int main() {

    srand(time(NULL));

    int number = 0;
    int answer = rand() %1000;
    int min = 0;
    int max = 1000;
    int status;
    
    do {
        printf("%d から %d の間で整数を入力してください: ", min, max);
        status = scanf("%d", &number);
        if(status != 1) {printf("\nエラー:整数ではありません\n") ; while(getchar() != '\n'); continue; }
        if(number < min || number > max) {printf("エラー:範囲外の数値です\n"); while(getchar() != '\n'); continue; }
        if(number < answer) {
            printf("もっと大きい数字です！ \a\n");
        } else if (number > answer) {
            printf("もっと小さい数字です！ \a\n");
        } 
    } while (answer != number);


    printf("正解です！ \n");
    

    return 0;
}