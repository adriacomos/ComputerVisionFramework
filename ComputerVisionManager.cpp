#include "stdafx.h"
#include "ComputerVisionManager.h"
#include "VideoProcessor.h"


#include <msclr\marshal.h>

#include "FeatureTrackerFactory.h"
#include "SingleFeatureTrackerCtrl.h"
#include "IFrameProcessorCtrl.h"

#include <memory>

using namespace cvf;
using namespace System;
using namespace System::Runtime::InteropServices;

namespace cvfn {

ComputerVisionManager::ComputerVisionManager(void)
{
	mptrcvManager = new cvf::ComputerVisionManager();
}


ComputerVisionManager::~ComputerVisionManager(void)
{
}


//-------------------------------------------------------------------------------------------------
void ComputerVisionManager::startVideoProcessorFromFile( System::String^ filename ) 
{
	IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(filename);
	char* outputDisplayNative = static_cast<char*>(ptrToNativeString.ToPointer());

	mptrcvManager->startVideoProcessorFromFile( outputDisplayNative );
}

//-------------------------------------------------------------------------------------------------
void ComputerVisionManager::startVideoProcessorFromDevice( int device ) 
{
	mptrcvManager->startVideoProcessorFromDevice( device );
}


void ComputerVisionManager::setSingleFeatureTrackCtrl( ProcessorTechnology prTech,
			Rect^ areaTracking,
			unsigned int minPoints,
			bool activateSBD,
			double thresholdSBD )
{

	cv::Rect area( areaTracking->X, areaTracking->Y, areaTracking->Width, areaTracking->Height );

	cvf::ProcessorTechnology pt;
	switch (prTech) {
	case ProcessorTechnology::CPU:
		pt = cvf::ProcessorTechnology::CPU; break;
	case ProcessorTechnology::GPU:
		pt = cvf::ProcessorTechnology::GPU; break;
	};
		
	mptrcvManager->setFrameProcessorCtrl( FeatureTrackerFactory::createSingleFeatureFactory( pt,
		area, minPoints, activateSBD, thresholdSBD ) );
}

void ComputerVisionManager::getFrameProcessorCtrl( IFrameProcessorCtrl^ frameProcessor )
{
	if (frameProcessor != nullptr)
		frameProcessor->setUnmanaged( mptrcvManager->getFrameProcessorCtrl() );
}


void ComputerVisionManager::stopVideoProcessor()
{
	mptrcvManager->stopVideoProcessor();
}



};