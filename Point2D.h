#pragma once

namespace cvfn {

	public ref class Point2D
	{
	public:

		double X;
		double Y;

		Point2D(void);
		Point2D( double x, double y );
		virtual ~Point2D(void);


		virtual System::String^ ToString() override { 
			return ((int)X).ToString() + "," + ((int)Y).ToString(); 
		}

		virtual System::String^ ToString( System::String^ format)  {   
			return X.ToString(format) + "," + Y.ToString(format); 
		}

	};

};