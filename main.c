#include<stdio.h>
#include"functions.h"

int main()
{
    char clef;
    char notename[5] = {};
    int notenameNum;

    color(WHITE);//white

    #if DEBUG
    color(YELLOW);//yellow
    printf("[DEBUG]Debug mode.\n");
    color(WHITE);//white
    #endif

    printf("Input a clef. Example:F G\n");
    scanf("%c", &clef);
    printf("Input note. Example:C C# Cb\n");
    getchar(); // 保证下面的scanf正常工作
    scanf("%s", notename);

    #if DEBUG
    color(YELLOW);//yellow
    printf("[DEBUG]notename = %s\n", notename);
    //查找输入的音名
    printf("[DEBUG]findTable() returned:%d\n",findTable(notename));
    color(WHITE);//white
    #endif

    notenameNum = findTable(notename);//return 0~6
    getRealPositon(notenameNum, clef, notename);
    #if WINDOWS    
    system("PAUSE");
    #endif
    return 0;
}

