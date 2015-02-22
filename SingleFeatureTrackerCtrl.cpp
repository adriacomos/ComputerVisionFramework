#include "stdafx.h"
#include "SingleFeatureTrackerCtrl.h"

#include "ComputerVisionFrameworkNative.h"

using namespace std;

namespace cvfn {

SingleFeatureTrackerCtrl::SingleFeatureTrackerCtrl(void)
{
	mptrUnmanaged = new std::weak_ptr<cvf::ISingleFeatureTrackerWSecondaryPt>();
}


SingleFeatureTrackerCtrl::~SingleFeatureTrackerCtrl(void)
{
	delete mptrUnmanaged;
}


void SingleFeatureTrackerCtrl::setUnmanaged( std::weak_ptr<cvf::IFrameProcessor> frm )
{
	std::shared_ptr<cvf::IFrameProcessor> ptrFrm = frm.lock();
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> ptrConcrete = dynamic_pointer_cast<cvf::ISingleFeatureTrackerWSecondaryPt>(ptrFrm);
	*mptrUnmanaged = std::weak_ptr<cvf::ISingleFeatureTrackerWSecondaryPt>(ptrConcrete);
}




Point2D^ SingleFeatureTrackerCtrl::getTrackingPoint() 
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f pt = sft->getTrackingPoint();
	return gcnew Point2D( pt.x, pt.y );
}

Point2D^ SingleFeatureTrackerCtrl::getSecondaryAttachedPoint()
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f pt = sft->getSecondaryPoint();
	return gcnew Point2D( pt.x, pt.y );
}

Point2D^ SingleFeatureTrackerCtrl::getNormalizedTrackingPoint() 
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f pt;
	sft->getNormalizedTrackingPoint(pt);
	return gcnew Point2D( pt.x, pt.y );
}

Point2D^ SingleFeatureTrackerCtrl::getNormalizedSecondaryAttachedPoint()
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f pt;
	sft->getNormalizedDeltaSecondaryPoint(pt);
	return gcnew Point2D( pt.x, pt.y );
}


bool	SingleFeatureTrackerCtrl::getTrackingPoint( Point2D% pt )
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f p;
	bool ok = sft->getTrackingPoint(p);
	pt.X = p.x;
	pt.Y = p.y;
	return ok;
}

bool	SingleFeatureTrackerCtrl::getSecondaryAttachedPoint( Point2D% pt )
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f p;
	bool ok = sft->getSecondaryPoint(p);
	pt.X = p.x;
	pt.Y = p.y;
	return ok;
}


}