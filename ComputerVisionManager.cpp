#include "stdafx.h"
#include "ComputerVisionManager.h"
#include "VideoProcessor.h"


#include <msclr\marshal.h>

#include "FeatureTrackerFactory.h"
#include "SingleFeatureTrackerCtrl.h"


#include <memory>
#include <map>
#include <string>

using namespace cvf;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;
using namespace std;

namespace cvfn {

ComputerVisionManager::ComputerVisionManager(void)
{
	mptrcvManager = new cvf::ComputerVisionManager();
}


ComputerVisionManager::~ComputerVisionManager(void)
{
}


//-------------------------------------------------------------------------------------------------
void ComputerVisionManager::startVideoProcessorFromFile( System::String^ filename, bool resizeFrame, Size2D^ resizeFrameSize    ) 
{
	IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(filename);
	char* outputDisplayNative = static_cast<char*>(ptrToNativeString.ToPointer());

	cv::Size size(0,0);
	if (resizeFrame)
	{
		size = cv::Size( resizeFrameSize->Width, resizeFrameSize->Height );
	}

	mptrcvManager->startVideoProcessorFromFile( outputDisplayNative, resizeFrame, size );
}

//-------------------------------------------------------------------------------------------------
void ComputerVisionManager::startVideoProcessorFromDevice( int device, Size2D^ captureSize, double frameRate, bool resizeFrame, Size2D^ resizeFrameSize   ) 
{
	cv::Size size(0,0);
	if (resizeFrame)
	{
		size = cv::Size( resizeFrameSize->Width, resizeFrameSize->Height );
	}

	cvf::ProcessorFromDeviceParams params;
	params.Device = device;
	params.Resize = resizeFrame;
	params.CaptureFrameSize = cv::Size(captureSize->Width, captureSize->Height);
	params.CaptureFrameRate = frameRate;
	params.WorkingFrameSize = size;

	mptrcvManager->startVideoProcessorFromDevice( params );
}


//-------------------------------------------------------------------------------------------------
void ComputerVisionManager::setSingleFeatureTracker( ProcessorTechnology prTech,
			Rect^ areaTracking,
			unsigned int minPoints,
			bool activateSBD,
			double thresholdSBD)
{

	cv::Rect area( areaTracking->X, areaTracking->Y, areaTracking->Width, areaTracking->Height );

	cvf::ProcessorTechnology pt;
	switch (prTech) {
	case ProcessorTechnology::CPU:
		pt = cvf::ProcessorTechnology::CPU; break;
	case ProcessorTechnology::GPU:
		pt = cvf::ProcessorTechnology::GPU; break;
	};


	mptrcvManager->setFrameProcessor( FeatureTrackerFactory::createSingleFeatureTracker( 
		pt,	area, minPoints, activateSBD, thresholdSBD  ) );
}


//-------------------------------------------------------------------------------------------------
void ComputerVisionManager::setSCIMFeatureTracker( Rect^ areaTracking,
			unsigned int minPoints,
			bool activateSBD,
			double thresholdSBD,
			unsigned int maxDistanceAnchorInterFrame )
{
	cv::Rect area( areaTracking->X, areaTracking->Y, areaTracking->Width, areaTracking->Height );

	mptrcvManager->setFrameProcessor( FeatureTrackerFactory::createSCIMFeatureTracker( 
					area, minPoints, activateSBD, thresholdSBD, maxDistanceAnchorInterFrame  ) );
}

//-------------------------------------------------------------------------------------------------
void ComputerVisionManager::getFrameProcessor( IFrameProcessor^ frameProcessor )
{
	if (frameProcessor != nullptr)
		frameProcessor->setUnmanaged( mptrcvManager->getFrameProcessor() );
}

//-------------------------------------------------------------------------------------------------
void ComputerVisionManager::stopVideoProcessor()
{
	mptrcvManager->stopVideoProcessor();
}

//-------------------------------------------------------------------------------------------------
long ComputerVisionManager::getPotentialFrameRate()
{
	return mptrcvManager->getPotentialFrameRate();
}

//-------------------------------------------------------------------------------------------------
double ComputerVisionManager::getAverageFrameTime()
{
	return mptrcvManager->getAverageFrameTime();
}

double ComputerVisionManager::getRelativeVideoProgression()  // sólo para reproducción desde ficheros
{
	return mptrcvManager->getRelativeVideoProgression();
}

void ComputerVisionManager::setRelativeVideoProgression( double relpos )
{
	mptrcvManager->setRelativeVideoProgression( relpos );
}

void ComputerVisionManager::pause( bool pause )
{
	mptrcvManager->pause( pause );
}


Dictionary< String^, String^>^ ComputerVisionManager::getDebugInfo() 
{
	Dictionary< String^, String^>^ ret = gcnew Dictionary< String^, String^ >();

	map<string,string> debugInfo = mptrcvManager->getDebugInfo();

	for (auto kv : debugInfo)
	{
		System::String^ name = gcnew System::String( kv.first.c_str());
		System::String^ value = gcnew System::String( kv.second.c_str());

		ret->Add( name, value );

	}

	return ret;

}


};