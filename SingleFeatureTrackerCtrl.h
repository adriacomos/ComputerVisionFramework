#pragma once
#include "iframeprocessorctrl.h"

namespace cvf
{
	class SingleFeatureTrackerCtrl;
	class IFrameProcessorCtrl;
};

namespace cvfn {

ref class SingleFeatureTrackerCtrl : public IFrameProcessorCtrl
{

	cvf::SingleFeatureTrackerCtrl *mptrUnmanaged;

public:
	SingleFeatureTrackerCtrl(void);
	virtual ~SingleFeatureTrackerCtrl(void);


	cvf::IFrameProcessorCtrl *ToUnmanaged();
};



}