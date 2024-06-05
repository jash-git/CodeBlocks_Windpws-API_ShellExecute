#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
    Copilot: C++ shellexecute api Set work directory
*/
/*
Code::Blocks執行 C/C++輸出時，若發現 「命令模式(console)」 輸出的中文為亂碼時的處理

資料來源: https://jiannrong.blogspot.com/2015/02/codeblockscc.html

修改I.

    步驟01.點選「Settings」功能表內的「Editor」

    步驟02.左邊請點選「General settings」，再請點選右邊的「Other settings」，於「Encoding」的下拉式選單內挑選「UTF-8」

    步驟03.按下「OK」後離開

修改II.

    步驟01.點選「Settings」功能表內的「Compiler」

    步驟02.左邊請點選「Global compiler settings」，再請點選右邊的「Compiler settings」，再請點選「Other options」

    步驟03.請輸入指令，指令內容為
-fexec-charset=BIG-5

    步驟04.按下「OK」後離開
*/
void pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}

int main()
{
    char programPath[512]={'\0'};
    char workingDirectory[512]={'\0'};
    int len=0;

    printf("請輸入執行檔路徑: ");
    scanf("%s", programPath);//LPCSTR programPath = "C:\\Program Files\\MyProgram\\MyApp.exe";
    len=strlen(programPath);
    if(len<=0)
    {
        strcpy(programPath, "C:\\VTEAM\\VTEAM-POS\\MAUI\\MAUI_VPOS.exe");// C:\VTEAM\VTEAM-POS\MAUI\MAUI_VPOS.exe
    }

    printf("請輸入工作目錄路徑: ");
    scanf("%s", workingDirectory);//LPCSTR workingDirectory = "C:\\MyWorkDirectory";
    len=strlen(programPath);
    if(len<=0)
    {
        strcpy(programPath, "C:\\VTEAM\\VTEAM-POS\\MAUI");// C:\VTEAM\VTEAM-POS\MAUI
    }

    printf("輸入的執行檔路徑: %s\n",programPath);
    printf("輸入的工作目錄路徑: %s\n",workingDirectory);

    // 使用 ShellExecute 启动程序
    ShellExecute(NULL, "open", programPath, NULL, workingDirectory, SW_SHOWDEFAULT);
    pause();
    return 0;
}
