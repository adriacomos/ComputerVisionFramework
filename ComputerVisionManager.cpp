#include "stdafx.h"
#include "ComputerVisionManager.h"
#include "VideoProcessor.h"


#include <msclr\marshal.h>

#include "FeatureTrackerFactory.h"
#include "SingleFeatureTrackerCtrl.h"
#include "IFrameProcessorCtrl.h"

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
void ComputerVisionManager::startVideoProcessorFromDevice( int device, bool resizeFrame, Size2D^ resizeFrameSize   ) 
{
	cv::Size size(0,0);
	if (resizeFrame)
	{
		size = cv::Size( resizeFrameSize->Width, resizeFrameSize->Height );
	}
	mptrcvManager->startVideoProcessorFromDevice( device, resizeFrame, size  );
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
		
	mptrcvManager->setFrameProcessorCtrl( FeatureTrackerFactory::createSingleFeatureTracker( pt,
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


long ComputerVisionManager::getPotentialFrameRate()
{
	return mptrcvManager->getPotentialFrameRate();
}

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