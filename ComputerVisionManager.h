#pragma once

#include "IComputerVisionManager.h"
#include "IVideoProcessor.h"

#include "ComputerVisionFrameworkNative.h"
#include "IFrameProcessorCtrl.h"

#include "Size2D.h"

using namespace System::Collections::Generic;

namespace cvfn {

	ref class Point2D;
	interface class IFrameProcessorCtrl;
	interface class IVideoProcessor;



	public ref class ComputerVisionManager : public IComputerVisionManager
	{
		cvf::IComputerVisionManager  *mptrcvManager;

	public:
		ComputerVisionManager(void);
		virtual ~ComputerVisionManager(void);

		virtual void startVideoProcessorFromFile( System::String^ filename, bool resizeFrame, Size2D^ resizeFrameSize  );
		virtual void startVideoProcessorFromDevice( int device, bool resizeFrame, Size2D^ resizeFrameSize   );

		virtual void stopVideoProcessor();

		virtual void setSingleFeatureTrackCtrl( ProcessorTechnology prTch,
			Rect^ areaTracking,
			unsigned int minPoints,
			bool activateSBD,
			double thresholdSBD );

		virtual void getFrameProcessorCtrl( IFrameProcessorCtrl^ frameProcessor );

		virtual	long getPotentialFrameRate();
		virtual	double getAverageFrameTime();
		virtual double getRelativeVideoProgression();  // sólo para reproducción desde ficheros
		virtual void setRelativeVideoProgression( double relpos );




	};
}

