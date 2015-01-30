#pragma once
#include "iframeprocessorctrl.h"

namespace cvf
{
	class IFrameProcessorCtrl;
};

namespace cvfn {



ref class SingleFeatureTrackerCtrl : public IFrameProcessorCtrl
{

	cvf::IFrameProcessorCtrl *mptrUnmanaged;

public:
	SingleFeatureTrackerCtrl(void);
	virtual ~SingleFeatureTrackerCtrl(void);


	cvf::IFrameProcessorCtrl *ToUnmanaged();
};



}