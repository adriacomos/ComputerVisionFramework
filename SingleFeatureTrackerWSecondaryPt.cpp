#include "stdafx.h"
#include "SingleFeatureTrackerWSecondaryPt.h"

#include "ComputerVisionFrameworkNative.h"

using namespace std;

namespace cvfn {

SingleFeatureTrackerWSecondaryPt::SingleFeatureTrackerWSecondaryPt(void)
{
	mptrUnmanaged = new std::weak_ptr<cvf::ISingleFeatureTrackerWSecondaryPt>();
}


SingleFeatureTrackerWSecondaryPt::~SingleFeatureTrackerWSecondaryPt(void)
{
	delete mptrUnmanaged;
}


void SingleFeatureTrackerWSecondaryPt::setUnmanaged( std::weak_ptr<cvf::IFrameProcessor> frm )
{
	std::shared_ptr<cvf::IFrameProcessor> ptrFrm = frm.lock();
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> ptrConcrete = dynamic_pointer_cast<cvf::ISingleFeatureTrackerWSecondaryPt>(ptrFrm);
	*mptrUnmanaged = std::weak_ptr<cvf::ISingleFeatureTrackerWSecondaryPt>(ptrConcrete);
}




Point2D^ SingleFeatureTrackerWSecondaryPt::getTrackingPoint() 
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f pt = sft->getTrackingPoint();
	return gcnew Point2D( pt.x, pt.y );
}

Point2D^ SingleFeatureTrackerWSecondaryPt::getDeltaSecondaryPoint()
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f pt;
	sft->getDeltaSecondaryPoint(pt);
	return gcnew Point2D( pt.x, pt.y );
}

Point2D^ SingleFeatureTrackerWSecondaryPt::getNormalizedTrackingPoint() 
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f pt;
	sft->getNormalizedTrackingPoint(pt);
	return gcnew Point2D( pt.x, pt.y );
}

Point2D^ SingleFeatureTrackerWSecondaryPt::getNormalizedDeltaSecondaryPoint()
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f pt;
	sft->getNormalizedDeltaSecondaryPoint(pt);
	return gcnew Point2D( pt.x, pt.y );
}


bool	SingleFeatureTrackerWSecondaryPt::getTrackingPoint( Point2D% pt )
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f p;
	bool ok = sft->getTrackingPoint(p);
	pt.X = p.x;
	pt.Y = p.y;
	return ok;
}

bool	SingleFeatureTrackerWSecondaryPt::getDeltaSecondaryPoint( Point2D% pt )
{
	std::shared_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> sft = mptrUnmanaged->lock();
	cv::Point2f p;
	bool ok = sft->getDeltaSecondaryPoint(p);
	pt.X = p.x;
	pt.Y = p.y;
	return ok;
}


}