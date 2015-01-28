#include "stdafx.h"
#include "SURFFeatureTracker.h"
#include "Point2D.h"
#include "Rect.h"
#include "Size2D.h"

namespace cvfn {

	/*
// --------------------------------------------------------------------------------------------
SURFFeatureTracker::SURFFeatureTracker( Size2D^ frameSize, Rect^ ROI )	{

	cv::Size frSize( frameSize->Width, frameSize->Height );
	cv::Rect roi( ROI->X, ROI->Y, ROI->Width, ROI->Height );

	mptrUnmanaged = new cvf::SURFFeatureStaticMaskTracker (
		frSize, roi );
}


// --------------------------------------------------------------------------------------------
SURFFeatureTracker::~SURFFeatureTracker(void)	{
}


// --------------------------------------------------------------------------------------------
Point2D^ SURFFeatureTracker::getAnchorPoint() {

	return gcnew Point2D();
}


// --------------------------------------------------------------------------------------------
bool SURFFeatureTracker::AnchorPointOk::get()	{
	return mAnchorPointOk;
}

// --------------------------------------------------------------------------------------------
void SURFFeatureTracker::AnchorPointOk::set( bool value ) {
	mAnchorPointOk = value;
}

// --------------------------------------------------------------------------------------------
cvf::IFrameProcessor *SURFFeatureTracker::ToUnmanaged() {
	return (cvf::IFeatureTracker*)mptrUnmanaged;
}

*/
}