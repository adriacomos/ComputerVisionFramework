#include "stdafx.h"
#include "ComputerVisionManager.h"
#include "VideoProcessor.h"

#include "Point2D.h"

namespace cvfn {

ComputerVisionManager::ComputerVisionManager(void)
{
	mptrcvManager = new cvf::ComputerVisionManager();
}


ComputerVisionManager::~ComputerVisionManager(void)
{
}


void ComputerVisionManager::startVideoProcessor() 
{
	mptrcvManager->startVideoProcessor();
}


void ComputerVisionManager::setFrameProcessorCtrl( IFrameProcessorCtrl^ frm )
{
	mptrcvManager->setFrameProcessorCtrl( frm->ToUnmanaged()); 
}


void ComputerVisionManager::stopVideoProcessor()
{
	mptrcvManager->stopVideoProcessor();
}


Point2D^ ComputerVisionManager::getTrackingPoint() 
{
	cv::Point2f pt = mptrcvManager->getTrackingPoint();
	return gcnew Point2D( pt.x, pt.y );
}

Point2D^ ComputerVisionManager::getSecondaryAttachedPoint()
{
	cv::Point2f pt = mptrcvManager->getSecondaryAttachedPoint();
	return gcnew Point2D( pt.x, pt.y );
}

bool	ComputerVisionManager::getTrackingPoint( Point2D% pt )
{
	cv::Point2f p;
	bool ok = mptrcvManager->getTrackingPoint(p);
	pt.X = p.x;
	pt.Y = p.y;
	return ok;
}

bool	ComputerVisionManager::getSecondaryAttachedPoint( Point2D% pt )
{
	cv::Point2f p;
	bool ok = mptrcvManager->getSecondaryAttachedPoint(p);
	pt.X = p.x;
	pt.Y = p.y;
	return ok;
}

/*
IVideoProcessor^  ComputerVisionManager::getVideoProcessor() 
{
	throw gcnew System::NotImplementedException();
	//return mVideoProcessor;
}

void ComputerVisionManager::setFrameProcessor(IFrameProcessor^ frameProcessor)
{
	throw gcnew System::NotImplementedException();
	//mVideoProcessor->setFrameProcessor( frameProcessor );
}
*/


};