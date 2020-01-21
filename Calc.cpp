// Calc.cpp : main project file.

#include "stdafx.h"
#include "FFirst.h"

using namespace Calc;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
