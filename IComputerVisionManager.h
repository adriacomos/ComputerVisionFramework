#pragma once

#include "IFeatureTracker.h"
#include "Point2D.h"
#include "Rect.h"
#include "Size2D.h"

namespace cvfn {

	interface class IFrameProcessor;



	public enum class ProcessorTechnology {
		CPU,
		GPU
	};


	public interface class IComputerVisionManager
	{
	public:

		void startVideoProcessorFromFile( System::String^ filename, bool resizeFrame, Size2D^ resizeFrameSize   );
		void startVideoProcessorFromDevice( int device, Size2D^ captureSize, double frameRate, bool resizeFrame, Size2D^ resizeFrameSize   );

		void stopVideoProcessor();

		void setSingleFeatureTracker( ProcessorTechnology prTch,
										Rect^ areaTracking,
										unsigned int minPoints,
										bool activateSBD,
										double thresholdSBD );
		void getFrameProcessor( IFrameProcessor^ frameProcessor );

		long getPotentialFrameRate();
		double getAverageFrameTime();
		double getRelativeVideoProgression();  // s�lo para reproducci�n desde ficheros
		void setRelativeVideoProgression( double relpos );// s�lo para reproducci�n desde ficheros


		System::Collections::Generic::Dictionary< System::String^, System::String^>^ getDebugInfo();

	};

}