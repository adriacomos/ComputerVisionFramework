#pragma once

#include "IFeatureTracker.h"
#include "Point2D.h"

namespace cvfn {

	interface class IFrameProcessorCtrl;

	public interface class IComputerVisionManager
	{
	public:

		void startVideoProcessorFromFile( System::String^ filename );
		void startVideoProcessorFromDevice( int device );

		void stopVideoProcessor();

		void setSingleFeatureTrackCtrl( );
		void getFrameProcessorCtrl( IFrameProcessorCtrl^ frameProcessor );


	};

}