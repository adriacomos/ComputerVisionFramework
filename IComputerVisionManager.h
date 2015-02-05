#pragma once

#include "IFeatureTracker.h"
#include "Point2D.h"
#include "Rect.h"

namespace cvfn {

	interface class IFrameProcessorCtrl;

	public enum class ProcessorTechnology {
		CPU,
		GPU
	};


	public interface class IComputerVisionManager
	{
	public:

		void startVideoProcessorFromFile( System::String^ filename );
		void startVideoProcessorFromDevice( int device );

		void stopVideoProcessor();

		void setSingleFeatureTrackCtrl( ProcessorTechnology prTch,
										Rect^ areaTracking,
										unsigned int minPoints,
										bool activateSBD,
										double thresholdSBD );
		void getFrameProcessorCtrl( IFrameProcessorCtrl^ frameProcessor );


	};

}