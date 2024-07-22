#include"functions.h"
#include<stdlib.h>
#include<stdio.h>

#if WINDOWS
    #include <Windows.h>
#endif

const char noteNameTable[21][5] = {  "G","A","B","C","D","E","F",
                                "G#","A#","B#","C#","D#","E#","F#",
                                "Gb","Ab","Bb","Cb","Db","Eb","Fb",};

const char FClef_Normal_Position1[7][10] = {"[Space]-3", "[Line]-2", "[Space]-2", "[Line]-1", "[Space]-1", "[Line]1", "[Space]1", };
const char FClef_Normal_Position2[7][10] = {"[Line]2", "[Space]2", "[Line]3", "[Space]3", "[Line]4", "[Space]4", "[Line]5", };
const char FClef_Normal_Position3[7][10] = {"[Space]+1", "[Line]+1", "[Space]+2", "[Line]+2", "[Space]+3", "[Line]+3", "[Space]+4", };

//函数findTable，输入字符串，在二维数组中查找，返回序号。找不到返回-1
int findTable(char * string)
{
    int i = 0;
    //int j = 0;
    int flag;
    for(i = 0; i <= 25; i ++)
    {
        flag = compareStrings(string, noteNameTable[i]);
        if(flag)
        {
            return i % 7;
        }
    }
    return -1;
}
//函数compareStrings，输入两字符串，内容相同返回1，否则返回0
//本函数由“文心一言”创建
int compareStrings(char *str1, char *str2) {  
    // 确保两个字符串都不是NULL  
    if (str1 == NULL || str2 == NULL) {  
        return 0; // 如果任一字符串为NULL，则视为不相同  
    }  
  
    // 逐个字符比较直到遇到'\0'  
    while (*str1 != '\0' && *str2 != '\0') {  
        if (*str1 != *str2) {  
            return 0; // 字符不同，返回0  
        }  
        str1++;  
        str2++;  
    }  
  
    // 检查是否两个字符串都在同一位置遇到了'\0'  
    return *str1 == *str2; // 如果同时到达字符串末尾，则为1（相同）；否则为0（不相同）  
}  

//函数getRealPositon，输入0~6序号，谱号，曾输入的音名查询表格输出文字，指明音符位置
int getRealPositon(int number, char clef, char* noteName)
{
    #if !DEBUG
	#if WINDOWS
    	system("cls");
    	#endif
    #endif

    printf("================================================\n");
    switch (clef)
    {
    case 'G':
        // printf("In clef [%c], for note [%s] have found these positions:\n", clef, noteName);
        // printf("Position 1:%s\t%s\n", FClef_Normal_Position1[number], getNoteStatus(noteName));
        // printf("Position 2:%s\t%s\n", FClef_Normal_Position2[number], getNoteStatus(noteName));
        // printf("Position 3:%s\t%s\n", FClef_Normal_Position3[number], getNoteStatus(noteName));
        printf("In clef [");
        color(YELLOW);
        printf("%c", clef);
        color(WHITE);
        printf("], for note [");
        color(BLUE);
        printf("%s", noteName);
        color(WHITE);
        printf("] have found these positions:\n");
        printf("Position 1:%s\t%s\n", FClef_Normal_Position1[number], getNoteStatus(noteName));
        printf("Position 2:%s\t%s\n", FClef_Normal_Position2[number], getNoteStatus(noteName));
        printf("Position 3:%s\t%s\n", FClef_Normal_Position3[number], getNoteStatus(noteName));
        printf("================================================\n");
        break;
    case 'F':
        // printf("In clef [%c], for note [%s] have found these positions:\n", clef, noteName);
        // printf("Position [1]:%s\n", FClef_Normal_Position1[number]);
        // printf("Position [2]:%s\n", FClef_Normal_Position2[number]);
        // printf("Position [3]:%s\n", FClef_Normal_Position3[number]);
        printf("In clef [");
        color(YELLOW);
        printf("%c", clef);
        color(WHITE);
        printf("], for note [");
        color(BLUE);
        printf("%s", noteName);
        color(WHITE);
        printf("] have found these positions:\n");

        color(BLUE);//blue
        printf("No data.\n");
        color(WHITE);//white

        printf("================================================\n");
        break;

    default:
        color(RED);
        printf("[ERR]Unknown clef.\n");
        color(WHITE);
        printf("================================================\n");
        return -1;
        break;
    }
    return 0;
}
//根据音名输入，返回升降提示信息。
char* getNoteStatus(char* notename)
{
    switch (notename[1])
    {
    case '#':
        return "Sharp position.";
        break;
    case 'b':
        return "Flat position.";
        break;
    case '\0':
        return "Normal position.";
        break;
    default:
        return "UNKNOWN POSITION.";
        break;
    }
}
int color(int c)//更改字体颜色
{
    #if WINDOWS
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    #endif

	return 0;
}
