#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h> 

#define MAX_STAGE 10

int main() {

    srand(time(NULL));

    const int maxStage = 10;
    int stage = 0;
    int number = 0;
    int answer = rand() %1000;
    int min = 0;
    int max = 1000;
    int numHistory[MAX_STAGE];
    int status;
    int c;
    printf("answer:%d\n",answer);
    do {
        printf("---------\n残り%d回です!\n---------\n",MAX_STAGE - stage);
        printf("%d から %d の間で整数を入力してください: ", min, max);
        status = scanf("%d", &number);
        if(status != 1) {printf("\nエラー:整数ではありません\n") ; while ((c = getchar()) != '\n' && c != EOF); continue; }
        if(number < min || number > max) {printf("エラー:範囲外の数値です\n"); while ((c = getchar()) != '\n' && c != EOF); continue; }
        
        numHistory[stage++] =number;
        
        if(number < answer) {
            printf("もっと大きい数字です！ \a\n"); 
        } else if (number > answer) {
            printf("もっと小さい数字です！ \a\n");
        } 
        
        

    } while (answer != number && stage < MAX_STAGE);

        if(answer == number){
            printf("正解です！ \n");
            printf("%d回で正解しました！",MAX_STAGE - stage);

        } else {
            printf("残念！ 正解は%dでした！ \n",answer);
        
    }


    printf("-----入力履歴-----\n");
    for(int i = 0; i < stage; i++){
        printf("%2d : %4d %+4d\n",i +1 , numHistory[i], numHistory[i] - answer);
    }
    

    return 0;
}