#include "stdafx.h"
#include "SingleFeatureTrackerCtrl.h"


#include "ComputerVisionFrameworkNative.h"



namespace cvfn {

SingleFeatureTrackerCtrl::SingleFeatureTrackerCtrl(void)
{
}


SingleFeatureTrackerCtrl::~SingleFeatureTrackerCtrl(void)
{
}


cvf::IFrameProcessorCtrl *SingleFeatureTrackerCtrl::ToUnmanaged() 
{
	return mptrUnmanaged;
}

}