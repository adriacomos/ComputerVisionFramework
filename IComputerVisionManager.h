#pragma once

#include "IFeatureTracker.h"
#include "Point2D.h"

namespace cvfn {

	interface class IVideoProcessor;

	public interface class IComputerVisionManager
	{
	public:

		void startVideoProcessor();
		void stopVideoProcessor();

		Point2D^ getTrackingPoint();
		Point2D^ getSecondaryAttachedPoint();
		bool	getTrackingPoint( Point2D% pt );
		bool	getSecondaryAttachedPoint( Point2D% pt );


		//void setFrameProcessor(IFrameProcessor^ frameProcessor);

		//IVideoProcessor^ getVideoProcessor();
	};

}