#pragma once

#include "IComputerVisionManager.h"
#include "IVideoProcessor.h"

#include "ComputerVisionFrameworkNative.h"
#include "IFrameProcessorCtrl.h"

using namespace System::Collections::Generic;

namespace cvfn {

	ref class Point2D;
	interface class IVideoProcessor;


	public ref class ComputerVisionManager : public IComputerVisionManager
	{
		//Dictionary< System::String^, IFrameProcessor^>^  mList;

		cvf::IComputerVisionManager  *mptrcvManager;
		//IVideoProcessor ^mVideoProcessor;

	public:
		ComputerVisionManager(void);
		virtual ~ComputerVisionManager(void);

		virtual void startVideoProcessor(); 
		virtual void stopVideoProcessor();

		void setFrameProcessorCtrl( IFrameProcessorCtrl^ frm );


		virtual Point2D^ getTrackingPoint();
		virtual Point2D^ getSecondaryAttachedPoint();
		virtual bool	getTrackingPoint( Point2D% pt );
		virtual bool	getSecondaryAttachedPoint( Point2D% pt );


		/*
		virtual void setFrameProcessor(IFrameProcessor^ frameProcessor);
		virtual IVideoProcessor^  getVideoProcessor();
		*/

	};
}

