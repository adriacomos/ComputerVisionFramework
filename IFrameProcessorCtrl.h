#pragma once

#include <memory>

namespace cvf {
	class IFrameProcessorCtrl;
};


namespace cvfn
{



	public interface class IFrameProcessorCtrl
	{
	public:
		void setUnmanaged( std::weak_ptr<cvf::IFrameProcessorCtrl> frm );
	};

}