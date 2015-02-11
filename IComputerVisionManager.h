#pragma once

#include "IFeatureTracker.h"
#include "Point2D.h"
#include "Rect.h"
#include "Size2D.h"

namespace cvfn {

	interface class IFrameProcessorCtrl;



	public enum class ProcessorTechnology {
		CPU,
		GPU
	};


	public interface class IComputerVisionManager
	{
	public:

		void startVideoProcessorFromFile( System::String^ filename, bool resizeFrame, Size2D^ resizeFrameSize   );
		void startVideoProcessorFromDevice( int device, bool resizeFrame, Size2D^ resizeFrameSize   );

		void stopVideoProcessor();

		void setSingleFeatureTrackCtrl( ProcessorTechnology prTch,
										Rect^ areaTracking,
										unsigned int minPoints,
										bool activateSBD,
										double thresholdSBD );
		void getFrameProcessorCtrl( IFrameProcessorCtrl^ frameProcessor );

		long getPotentialFrameRate();
		double getAverageFrameTime();
		double getRelativeVideoProgression();  // sólo para reproducción desde ficheros
		void setRelativeVideoProgression( double relpos );// sólo para reproducción desde ficheros


	};

}