#pragma once

namespace cvfn {


public ref class Size2D
{
public:
	int Width;
	int Height;

	Size2D( int width, int height );
	virtual ~Size2D(void);
};

}