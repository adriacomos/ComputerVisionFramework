#pragma once

#include "iframeprocessorctrl.h"
#include <memory>
#include "Point2D.h"

namespace cvf
{
	class IFrameProcessorCtrl;
	class ISingleFeatureTrackerCtrl;
};

namespace cvfn {



public ref class SingleFeatureTrackerCtrl : public IFrameProcessorCtrl
{

	std::weak_ptr<cvf::ISingleFeatureTrackerCtrl> *mptrUnmanaged;

public:
	SingleFeatureTrackerCtrl(void);
	virtual ~SingleFeatureTrackerCtrl(void);

	virtual void setUnmanaged( std::weak_ptr<cvf::IFrameProcessorCtrl> frm );

	virtual Point2D^ getTrackingPoint();
	virtual Point2D^ getSecondaryAttachedPoint();
	virtual bool	getTrackingPoint( Point2D% pt );
	virtual bool	getSecondaryAttachedPoint( Point2D% pt );


};



}