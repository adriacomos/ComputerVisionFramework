#include "stdafx.h"
#include "SingleFeatureTrackerCtrl.h"

#include "ComputerVisionFrameworkNative.h"

using namespace std;

namespace cvfn {

SingleFeatureTrackerCtrl::SingleFeatureTrackerCtrl(void)
{
	mptrUnmanaged = new std::weak_ptr<cvf::ISingleFeatureTrackerCtrl>();
}


SingleFeatureTrackerCtrl::~SingleFeatureTrackerCtrl(void)
{
	delete mptrUnmanaged;
}


void SingleFeatureTrackerCtrl::setUnmanaged( std::weak_ptr<cvf::IFrameProcessorCtrl> frm )
{
	std::shared_ptr<cvf::IFrameProcessorCtrl> ptrFrm = frm.lock();
	std::shared_ptr<cvf::ISingleFeatureTrackerCtrl> ptrConcrete = dynamic_pointer_cast<cvf::ISingleFeatureTrackerCtrl>(ptrFrm);
	*mptrUnmanaged = std::weak_ptr<cvf::ISingleFeatureTrackerCtrl>(ptrConcrete);
}






Point2D^ SingleFeatureTrackerCtrl::getTrackingPoint() 
{
	std::shared_ptr<cvf::ISingleFeatureTrackerCtrl> sft = mptrUnmanaged->lock();
	cv::Point2f pt = sft->getTrackingPoint();
	return gcnew Point2D( pt.x, pt.y );
}

Point2D^ SingleFeatureTrackerCtrl::getSecondaryAttachedPoint()
{
	std::shared_ptr<cvf::ISingleFeatureTrackerCtrl> sft = mptrUnmanaged->lock();
	cv::Point2f pt = sft->getSecondaryAttachedPoint();
	return gcnew Point2D( pt.x, pt.y );
}

bool	SingleFeatureTrackerCtrl::getTrackingPoint( Point2D% pt )
{
	std::shared_ptr<cvf::ISingleFeatureTrackerCtrl> sft = mptrUnmanaged->lock();
	cv::Point2f p;
	bool ok = sft->getTrackingPoint(p);
	pt.X = p.x;
	pt.Y = p.y;
	return ok;
}

bool	SingleFeatureTrackerCtrl::getSecondaryAttachedPoint( Point2D% pt )
{
	std::shared_ptr<cvf::ISingleFeatureTrackerCtrl> sft = mptrUnmanaged->lock();
	cv::Point2f p;
	bool ok = sft->getSecondaryAttachedPoint(p);
	pt.X = p.x;
	pt.Y = p.y;
	return ok;
}


}