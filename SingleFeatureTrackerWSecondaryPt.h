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

ref class SingleFeatureTrackerWSecondaryPt
{
	std::weak_ptr<cvf::ISingleFeatureTrackerWSecondaryPt> *mptrUnmanaged;

public:
	SingleFeatureTrackerWSecondaryPt(void);
	virtual ~SingleFeatureTrackerWSecondaryPt(void);

	virtual void setUnmanaged( std::weak_ptr<cvf::IFrameProcessor> frm );

	virtual Point2D^ getTrackingPoint();
	virtual Point2D^ getNormalizedTrackingPoint();
	virtual Point2D^ getDeltaSecondaryPoint();
	virtual Point2D^ getNormalizedDeltaSecondaryPoint();
	virtual bool	getTrackingPoint( Point2D% pt );
	virtual bool	getDeltaSecondaryPoint( Point2D% pt );

};

}