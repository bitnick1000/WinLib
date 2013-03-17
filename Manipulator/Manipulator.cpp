#include "Manipulator.h"
void Manipulator::MouseMove(COORD coord)
{
	MouseMove(coord.X,coord.Y);
}
void Manipulator::MouseMove(int x, int y)
{
	GetCursorPos(&lastPoint);
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
void Manipulator::MouseBack()
{
	MouseMove(lastPoint.x,lastPoint.y);
}
void Manipulator::MouseClick()
{
	MouseLeftDown();
	MouseLeftUp();
}
void Manipulator::MouseLeftDown()
{
	MOUSEINPUT mouse;
	mouse.dx = 0;
	mouse.dy = 0;
	mouse.mouseData = NULL;
	mouse.dwFlags = MOUSEEVENTF_LEFTDOWN;
	mouse.time = 0;
	mouse.dwExtraInfo = NULL;
	INPUT input = {INPUT_MOUSE, mouse};
	SendInput(1,   &input   , sizeof(INPUT));
}
void Manipulator::MouseLeftUp()
{
	MOUSEINPUT mouse;
	mouse.dx = 0;
	mouse.dy = 0;
	mouse.mouseData = NULL;
	mouse.dwFlags = MOUSEEVENTF_LEFTUP;
	mouse.time = 0;
	mouse.dwExtraInfo = NULL;
	INPUT input = {INPUT_MOUSE, mouse};
	SendInput(1,   &input   , sizeof(INPUT));
}