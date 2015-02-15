#pragma once


#include "ComputerVisionFrameworkNative.h"

namespace cvfn {

	
	public interface class IFrameProcessor
	{
	public:
		//cvf::IFrameProcessor *ToUnmanaged();
		void setUnmanaged( std::weak_ptr<cvf::IFrameProcessor> frm );

	};
	
};