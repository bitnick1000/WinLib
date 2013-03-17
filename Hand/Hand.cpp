#include "Hand.h"
void Hand::MouseMove(COORD coord)
{
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	MOUSEINPUT mouse;
	mouse.dx = coord.X * (65536 / width	);
	mouse.dy = coord.Y * (65536 / height );
	mouse.mouseData = NULL;
	mouse.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
	mouse.time = 0;
	mouse.dwExtraInfo = NULL;
	INPUT input = {INPUT_MOUSE, mouse};
	SendInput(1,   &input   , sizeof(INPUT));
}
void Hand::MouseMove(int x,int y)
{
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	MOUSEINPUT mouse;
	mouse.dx = x * (65536 / width	);
	mouse.dy = y * (65536 / height );
	mouse.mouseData = NULL;
	mouse.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
	mouse.time = 0;
	mouse.dwExtraInfo = NULL;
	INPUT input = {INPUT_MOUSE, mouse};
	SendInput(1,   &input   , sizeof(INPUT));
}