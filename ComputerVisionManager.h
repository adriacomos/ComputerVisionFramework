#pragma once

#include "IComputerVisionManager.h"
#include "IVideoProcessor.h"

#include "ComputerVisionFrameworkNative.h"

#include "Size2D.h"

#include <vcclr.h>

using namespace System::Collections::Generic;

namespace cvfn {

	ref class Point2D;
	interface class IVideoProcessor;

	class ListenerKeyboard;
	class ListenerMouse;
	class CVMListeners;


	public ref class ComputerVisionManager : public IComputerVisionManager
	{

		cvf::IComputerVisionManager  *mptrcvManager;
		CVMListeners *mptrCVMListeners;

	public:



		virtual event System::EventHandler<MouseEvtArgs^>^  OnMouseEvent;
		virtual event System::EventHandler<KeyboardEvtArgs^>^  OnKeyboardEvent;


		ComputerVisionManager(void);
		virtual ~ComputerVisionManager(void);

		virtual void startVideoProcessorFromFile( System::String^ filename, bool resizeFrame, Size2D^ resizeFrameSize  );
		virtual void startVideoProcessorFromDevice( int device, Size2D^ captureSize, double frameRate, bool resizeFrame, Size2D^ resizeFrameSize );

		virtual void stopVideoProcessor();

		// Funciones provisionales de creación de FeatureTrackers ---------------->
		// TODO: si esta versión .NET tira adelante, habría que publicar clases equivalentes a C++ nativo en el que la creación
		// de los FrameProcessors es externa, y en este interface simplemente se registran
		virtual void setSingleFeatureTracker( ProcessorTechnology prTch,
												Rect^ areaTracking,
												unsigned int minPoints,
												bool activateSBD,
												double thresholdSBD);

		virtual void setSCIMFeatureTracker( Rect^ areaTracking,
											unsigned int minPoints,
											bool activateSBD,
											double thresholdSBD,
											unsigned int maxDistanceAnchorInterFrame );

		virtual void setSCIMPathTracer( Rect^ areaTracking,
										unsigned int minPoints,
										bool activateSBD,
										double thresholdSBD,
										unsigned int maxDistanceAnchorInterFrame );
		// <-------------------------------------------------------------------------


		virtual void getFrameProcessor( IFrameProcessor^ frameProcessor );

		virtual	long getPotentialFrameRate();
		virtual	double getAverageFrameTime();
		virtual double getRelativeVideoProgression();  // sólo para reproducción desde ficheros
		virtual void setRelativeVideoProgression( double relpos );

		virtual	System::Collections::Generic::Dictionary< System::String^, System::String^>^ getDebugInfo();

		virtual void pause( bool pause );

		void raiseMouseEvent( MouseEvtArgs^ args );
		void raiseKeyboardEvent( KeyboardEvtArgs^ args );

	};

	// ----------------------------------------------------------------------------------------------------
	// ----------------------------------------------------------------------------------------------------
	class ListenerKeyboard : public cvf::IListenerKeyboardEvents
	{
		gcroot< ComputerVisionManager^ > mCVManager;
	public:
		ListenerKeyboard( gcroot< ComputerVisionManager^> cvManager )
			:mCVManager(cvManager)
		{}

		virtual void onEvent( const cvf::UserKeyboardEvtArgs &args ) override 
		{
			KeyboardEvtArgs^ manArgs = gcnew KeyboardEvtArgs( args.Evt, args.KbCode );
			mCVManager->raiseKeyboardEvent( manArgs);
		}
	};



	// ----------------------------------------------------------------------------------------------------
	// ----------------------------------------------------------------------------------------------------
	class ListenerMouse : public cvf::IListenerMouseEvents
	{
		gcroot< ComputerVisionManager^ > mCVManager;
	public:
		ListenerMouse( gcroot< ComputerVisionManager^> cvManager )
			:mCVManager(cvManager)
		{}

		virtual void onEvent( const cvf::UserMouseEvtArgs &args ) override 
		{
			MouseEvtArgs^ manArgs = gcnew MouseEvtArgs( args.Evt, args.X, args.Y );
			mCVManager->raiseMouseEvent( manArgs);
		}
	};


}

