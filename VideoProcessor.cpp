#include "stdafx.h"
#include "VideoProcessor.h"
#include "Size2D.h"

#include "IFrameProcessor.h"

using namespace System;

namespace cvfn {

	/*
VideoProcessor::VideoProcessor( cvf::IVideoProcessor *ptrUnmanaged )	{
	mptrUnmanaged = ptrUnmanaged;
}

VideoProcessor::~VideoProcessor(void)	{
}


Size2D^ VideoProcessor::getFrameSize() {
	cv::Size sz = mptrUnmanaged->getFrameSize();

	return gcnew Size2D( sz.width, sz.height );
}


String^ VideoProcessor::getDisplayOutput()
{
	return gcnew String( mptrUnmanaged->getDisplayOutput().c_str() );
}


IFrameProcessor^ VideoProcessor::getFrameProcessor()
{
	return mFrameProcessor;
}

void VideoProcessor::setFrameProcessor( IFrameProcessor^ fp )
{

	mFrameProcessor = fp;  // Nos guardamos una referencia al objeto net
	mptrUnmanaged->setFrameProcessor( fp->ToUnmanaged() );

}
*/


}