#include "AppForm.h"
#include <Windows.h>

using namespace clr;

int WINAPI WinMain(HINSTANCE h, HINSTANCE p, LPSTR l, int i){

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Application::Run(gcnew MyForm());

	return 0;
}
