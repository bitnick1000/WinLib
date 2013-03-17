#include <Windows.h>
class Manipulator
{
public:
	void MouseMove(COORD coord);
	void MouseMove(int x,int y);
	void MouseBack();
	void MouseClick();
	void MouseLeftDown();
	void MouseLeftUp();
private:
	POINT lastPoint;
};