
    // Funciton��    
    // �������ݵ����а�   
    // �Ӽ��а�ճ������    
    // Data��2011/4/8    
    #include <windows.h>   
    #include <stdio.h>   
    void SetDataToClip(void)    
    {   
        // �򿪼�����   
        if (!OpenClipboard(NULL)|| !EmptyClipboard())    
        {   
            printf("�򿪻���ռ��а����/n");   
            return;   
        }   
           
        HGLOBAL hMen;   
        TCHAR strText[256] = "�ұ����������а壡/n";   
           
        // ����ȫ���ڴ�    
        hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(strText)+1)*sizeof(TCHAR)));    
           
        if (!hMen)   
        {   
            printf("����ȫ���ڴ����/n");    
            // �رռ��а�    
            CloseClipboard();   
            return;         
        }   
           
        // �����ݿ�����ȫ���ڴ���   
        // ��ס�ڴ���    
        LPSTR lpStr = (LPSTR)GlobalLock(hMen);    
           
        // �ڴ渴��   
        memcpy(lpStr, strText, ((strlen(strText))*sizeof(TCHAR)));    
        // �ַ�������    
        lpStr[strlen(strText)] = (TCHAR)0;   
        // �ͷ���    
        GlobalUnlock(hMen);   
           
        // ���ڴ��е����ݷŵ����а���   
        SetClipboardData(CF_TEXT, hMen);   
        CloseClipboard();   
           
        return;   
    }   
    void GetDataFromClip()   
    {   
        // �ж����ݸ�ʽ    
        if (!IsClipboardFormatAvailable(CF_TEXT) )   
        {   
            printf("���а����ݸ�ʽ����CF_TEXT/n");   
            return;   
        }   
           
        if (!OpenClipboard(NULL))    
        {   
            printf("�򿪼��а����/n");   
            return;   
        }   
        // �Ӽ��а��ȡ����    
        HGLOBAL hMem = GetClipboardData(CF_TEXT);   
        if (hMem)   
        {    
            //  ��ȡ�ַ���    
            LPSTR lpStr = (LPSTR)GlobalLock(hMem);     
            if (lpStr)   
            {   
                printf(lpStr);   
                // �ͷ��ڴ���    
                GlobalUnlock(hMem);    
            }   
        }    
        // �رռ��а�    
        CloseClipboard();    
    }   
    int main(void)   
    {   
        //SetDataToClip();   
        GetDataFromClip();    
        return 0;   
    }  
