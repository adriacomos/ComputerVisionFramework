#include "stdafx.h"

#include <string>

#include "UIAnchorOnClick.h"

#include "IVideoProcessor.h"
#include "IFrameProcessor.h"
#include "IFeatureTracker.h"

#include <msclr\marshal.h>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace cvfn {

	/*
	UIAnchorOnClick::UIAnchorOnClick(IVideoProcessor^ vp )
		:mptrUnmanaged(nullptr)
	{
		IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(vp->getDisplayOutput());
		char* outputDisplay = static_cast<char*>(ptrToNativeString.ToPointer());

		std::string nameOutput = outputDisplay;
		std::string nameInput = outputDisplay;

		IFrameProcessor^ frameProc = vp->getFrameProcessor();
		IFeatureTracker^ featureTracker = safe_cast<IFeatureTracker^>(frameProc);

		if (featureTracker != nullptr )
		{
			// Ha de ser FeatureTrackerWMask
			cvf::IFeatureTrackerWMask  *ft = static_cast<cvf::IFeatureTrackerWMask*>(featureTracker->ToUnmanaged());
			mptrUnmanaged = new cvf::UIAnchorOnClick( nameOutput, nameInput, *ft );
		}
	}


	UIAnchorOnClick::~UIAnchorOnClick(void)
	{
	}
	*/

};