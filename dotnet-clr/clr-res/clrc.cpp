// clrc.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "MyForm.h"

using namespace clrc;

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");

	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Application::Run(gcnew MyForm());

	
    return 0;
}
