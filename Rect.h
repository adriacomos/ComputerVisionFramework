#pragma once

namespace cvfn {

public ref class Rect
{
public:
	int X, Y, Width, Height;

	Rect( int x, int y, int width, int height );
	virtual ~Rect(void);
};

};