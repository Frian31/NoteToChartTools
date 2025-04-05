# NoteToChartTools
## 概述
一个输入音符名，输出五线谱位置信息的自用学习小工具。跨平台支持。
## 使用方法：
按照提示输入谱号，音符即可生成结果。

## 关于编译与跨平台
本项目使用**gcc**编译，提供源代码，因此可以跨平台编译属于自己的版本。  
编译方式：使用**gcc**编译**functions.c**文件和**main.c**文件：  
> gcc -o findNotePosition_Debug main.c functions.c

**compile_and_run.ps1**是一个十分简陋的Windows PowerShell脚本。运行可以在Windows平台上自动执行编译并运行。可供参考。  

## 宏
在functions.h中的**DEBUG**宏用于区分调试模式和正常使用模式。调试模式不会执行清屏，并且输出一些调试打印信息。后续所有的调试代码均应该由这个宏进行启用与禁用。  
在Windows平台编译，可以将**WINDOWS**宏设置为1，为控制台提供更好的显示效果，例如颜色突出显示。  
在其他平台编译，请将WINDOWS宏设置为0，防止库的缺失导致的编译失败。 

## 其他
这个readme写得太丑了。见谅。

## 更行
我在尝试用git管理本项目。
