#pragma once

#include "IComputerVisionManager.h"
#include "IVideoProcessor.h"

#include "ComputerVisionFrameworkNative.h"
#include "IFrameProcessorCtrl.h"

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

		virtual void startVideoProcessorFromFile( System::String^ filename );
		virtual void startVideoProcessorFromDevice( int device );

		virtual void stopVideoProcessor();

		virtual void setSingleFeatureTrackCtrl( );
		virtual void getFrameProcessorCtrl( IFrameProcessorCtrl^ frameProcessor );




	};
}

