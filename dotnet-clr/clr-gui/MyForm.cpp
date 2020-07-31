#include "AppForm.h"
#include <Windows.h>

using namespace clr;

int WINAPI WinMain(HINSTANCE h, HINSTANCE p, LPSTR l, int i){

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// 创建主窗口并运行它
	Application::Run(gcnew MyForm());

	return 0;
}
