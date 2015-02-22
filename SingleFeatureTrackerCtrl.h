#pragma once

#include "iframeprocessor.h"
#include <memory>
#include "Point2D.h"

namespace cvf
{
	class IFrameProcessor;
	class ISingleFeatureTrackerWSecondaryPt;
};

namespace cvfn {



public ref class SingleFeatureTrackerCtrl : public IFrameProcessor
{

	std::weak_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> *mptrUnmanaged;

public:
	SingleFeatureTrackerCtrl(void);
	virtual ~SingleFeatureTrackerCtrl(void);

	virtual void setUnmanaged( std::weak_ptr<cvf::IFrameProcessor> frm );

	virtual Point2D^ getTrackingPoint();
	virtual Point2D^ getNormalizedTrackingPoint();
	virtual Point2D^ getSecondaryAttachedPoint();
	virtual Point2D^ getNormalizedSecondaryAttachedPoint();
	virtual bool	getTrackingPoint( Point2D% pt );
	virtual bool	getSecondaryAttachedPoint( Point2D% pt );


};



}