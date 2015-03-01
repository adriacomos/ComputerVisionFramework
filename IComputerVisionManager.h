#pragma once

#include "IFeatureTracker.h"
#include "Point2D.h"
#include "Rect.h"
#include "Size2D.h"
#include "MouseEvtArgs.h"
#include "KeyboardEvtArgs.h"

namespace cvfn {

	interface class IFrameProcessor;



	public enum class ProcessorTechnology {
		CPU,
		GPU
	};


	public interface class IComputerVisionManager
	{


	public:

		event System::EventHandler<MouseEvtArgs^>^  OnMouseEvent;
		event System::EventHandler<KeyboardEvtArgs^>^  OnKeyboardEvent;

		void startVideoProcessorFromFile( System::String^ filename, bool resizeFrame, Size2D^ resizeFrameSize   );
		void startVideoProcessorFromDevice( int device, Size2D^ captureSize, double frameRate, bool resizeFrame, Size2D^ resizeFrameSize   );

		void stopVideoProcessor();

		// Funciones provisionales de creación de FeatureTrackers ---------------->
		// TODO: si esta versión .NET tira adelante, habría que publicar clases equivalentes a C++ nativo en el que la creación
		// de los FrameProcessors es externa, y en este interface simplemente se registran
		void setSingleFeatureTracker( ProcessorTechnology prTch,
										Rect^ areaTracking,
										unsigned int minPoints,
										bool activateSBD,
										double thresholdSBD);

		void setSCIMFeatureTracker( Rect^ areaTracking,
									unsigned int minPoints,
									bool activateSBD,
									double thresholdSBD,
									unsigned int maxDistanceAnchorInterFrame );

		void setSCIMPathTracer( Rect^ areaTracking,
								unsigned int minPoints,
								bool activateSBD,
								double thresholdSBD,
								unsigned int maxDistanceAnchorInterFrame );

		void setSCIMDualFeatureTracker( Rect^ areaTracking,
										unsigned int minPoints,
										bool activateSBD,
										double thresholdSBD,
										unsigned int maxDistanceAnchorInterFrame );

		void setCCFeatureTracker( Rect^ areaTracking,
								unsigned int minPoints,
								bool activateSBD );
		// <-------------------------------------------------------------------------


		void getFrameProcessor( IFrameProcessor^ frameProcessor );

		long getPotentialFrameRate();
		double getAverageFrameTime();
		double getRelativeVideoProgression();  // sólo para reproducción desde ficheros
		void setRelativeVideoProgression( double relpos );// sólo para reproducción desde ficheros


		System::Collections::Generic::Dictionary< System::String^, System::String^>^ getDebugInfo();

		void pause( bool pause );

	};

}