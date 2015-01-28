#pragma once

#include "IVideoProcessor.h"
#include "ComputerVisionFrameworkNative.h"

namespace cvfn {

	/* clase anulada (al menos temporalmente)
	ref class Size2D;
	interface class IFrameProcessor;

ref class VideoProcessor : public IVideoProcessor
{
	cvfn::IFrameProcessor^  mFrameProcessor;
	cvf::IVideoProcessor  *mptrUnmanaged;

public:
	VideoProcessor( cvf::IVideoProcessor *ptrUnmanaged );
	virtual ~VideoProcessor(void);

	virtual	Size2D^ getFrameSize();
	virtual IFrameProcessor^ getFrameProcessor();
	virtual void setFrameProcessor( IFrameProcessor^ fp );

	virtual	System::String^ getDisplayOutput();


};

*/

}