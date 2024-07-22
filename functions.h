#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
//调试宏
#define DEBUG 0 //1:debug mode; 0:normal mode
#define WINDOWS 1 //目前给字符上颜色的功能仅限Windows的控制台可用 跨平台编译请将此宏改为0

//控制台颜色宏
#if WINDOWS
    #define BLACK       0
    #define BLUE        1
    #define GREEN       2
    #define LIGHT_GREEN 3
    #define RED         4
    #define PURPLE      5
    #define YELLOW      6
    #define WHITE       7
    #define GRAY        8
    #define LIGHT_BLUE  9
#else
    #define BLACK       0
    #define BLUE        0
    #define GREEN       0
    #define LIGHT_GREEN 0
    #define RED         0
    #define PURPLE      0
    #define YELLOW      0
    #define WHITE       0
    #define GRAY        0
    #define LIGHT_BLUE  0
#endif

int findTable(char * string);//输入字符串，在二维数组中查找，返回序号。找不到返回-1
int compareStrings(char* str1, char* str2);//输入两字符串，内容相同返回1，否则返回0
int getRealPositon(int number, char clef, char* noteName);//输入0~6序号，谱号，曾输入的音名查询表格输出文字，指明音符位置
char* getNoteStatus(char* notename);//根据音名输入，返回升降提示信息。
int color(int c);//更改字体颜色

#endif /*_FUNCTIONS_H*/