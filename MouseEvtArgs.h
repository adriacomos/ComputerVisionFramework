#pragma once

namespace cvfn {

public ref class MouseEvtArgs : public System::EventArgs
{
public:

	int Evt;
	int X;
	int Y;

	MouseEvtArgs( int evt, int x, int y) : Evt(evt), X(x), Y(y) {}
	virtual ~MouseEvtArgs(void) {}
};

}