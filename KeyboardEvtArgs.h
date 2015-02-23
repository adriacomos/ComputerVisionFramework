#pragma once

namespace cvfn {

public ref class KeyboardEvtArgs : public System::EventArgs
{
public:

	int KbCode;
	int Evt;

	KeyboardEvtArgs( int evt, int kbCode) : Evt(evt), KbCode(kbCode) {}
	virtual ~KeyboardEvtArgs(void) {}
};

}