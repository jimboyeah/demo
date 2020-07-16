
    // Funciton：    
    // 拷贝数据到剪切板   
    // 从剪切板粘贴数据    
    // Data：2011/4/8    
    #include <windows.h>   
    #include <stdio.h>   
    void SetDataToClip(void)    
    {   
        // 打开剪贴板   
        if (!OpenClipboard(NULL)|| !EmptyClipboard())    
        {   
            printf("打开或清空剪切板出错！/n");   
            return;   
        }   
           
        HGLOBAL hMen;   
        TCHAR strText[256] = "我被拷贝到剪切板！/n";   
           
        // 分配全局内存    
        hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(strText)+1)*sizeof(TCHAR)));    
           
        if (!hMen)   
        {   
            printf("分配全局内存出错！/n");    
            // 关闭剪切板    
            CloseClipboard();   
            return;         
        }   
           
        // 把数据拷贝考全局内存中   
        // 锁住内存区    
        LPSTR lpStr = (LPSTR)GlobalLock(hMen);    
           
        // 内存复制   
        memcpy(lpStr, strText, ((strlen(strText))*sizeof(TCHAR)));    
        // 字符结束符    
        lpStr[strlen(strText)] = (TCHAR)0;   
        // 释放锁    
        GlobalUnlock(hMen);   
           
        // 把内存中的数据放到剪切板上   
        SetClipboardData(CF_TEXT, hMen);   
        CloseClipboard();   
           
        return;   
    }   
    void GetDataFromClip()   
    {   
        // 判断数据格式    
        if (!IsClipboardFormatAvailable(CF_TEXT) )   
        {   
            printf("剪切板数据格式不是CF_TEXT/n");   
            return;   
        }   
           
        if (!OpenClipboard(NULL))    
        {   
            printf("打开剪切板出错！/n");   
            return;   
        }   
        // 从剪切板获取数据    
        HGLOBAL hMem = GetClipboardData(CF_TEXT);   
        if (hMem)   
        {    
            //  获取字符串    
            LPSTR lpStr = (LPSTR)GlobalLock(hMem);     
            if (lpStr)   
            {   
                printf(lpStr);   
                // 释放内存锁    
                GlobalUnlock(hMem);    
            }   
        }    
        // 关闭剪切板    
        CloseClipboard();    
    }   
    int main(void)   
    {   
        //SetDataToClip();   
        GetDataFromClip();    
        return 0;   
    }  
