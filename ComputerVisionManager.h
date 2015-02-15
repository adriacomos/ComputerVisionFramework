#pragma once

#include "IComputerVisionManager.h"
#include "IVideoProcessor.h"

#include "ComputerVisionFrameworkNative.h"


#include "Size2D.h"

using namespace System::Collections::Generic;

namespace cvfn {

	ref class Point2D;
	interface class IVideoProcessor;



	public ref class ComputerVisionManager : public IComputerVisionManager
	{
		cvf::IComputerVisionManager  *mptrcvManager;

	public:
		ComputerVisionManager(void);
		virtual ~ComputerVisionManager(void);

		virtual void startVideoProcessorFromFile( System::String^ filename, bool resizeFrame, Size2D^ resizeFrameSize  );
		virtual void startVideoProcessorFromDevice( int device, Size2D^ captureSize, double frameRate, bool resizeFrame, Size2D^ resizeFrameSize   );

		virtual void stopVideoProcessor();

		virtual void setSingleFeatureTracker( ProcessorTechnology prTch,
			Rect^ areaTracking,
			unsigned int minPoints,
			bool activateSBD,
			double thresholdSBD );

		virtual void getFrameProcessor( IFrameProcessor^ frameProcessor );

		virtual	long getPotentialFrameRate();
		virtual	double getAverageFrameTime();
		virtual double getRelativeVideoProgression();  // sólo para reproducción desde ficheros
		virtual void setRelativeVideoProgression( double relpos );

		virtual	System::Collections::Generic::Dictionary< System::String^, System::String^>^ getDebugInfo();





	};
}

