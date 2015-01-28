#include "stdafx.h"
#include "Point2D.h"

namespace cvfn {

Point2D::Point2D(void)
	:X(0), Y(0)
{
}

Point2D::Point2D( double x, double y )
	:X(x), Y(y)
{
}

Point2D::~Point2D(void)
{
}

};