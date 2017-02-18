/*
 * main.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: me
 */


#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv )

{

	Mat image;

	image = imread( argv[1], 1 );

	if( argc != 2 || !image.data )

	{

		printf( "No image data \n" );

		return -1;

	}

	int numcols = image.cols;
	int numrows = image.rows;

	line(image,Point(0,0),Point(numcols - 1, numrows - 1),Scalar(255,0,0),3,LINE_8);

	namedWindow( "Display Image", WINDOW_AUTOSIZE );

	imshow( "Display Image", image );

	waitKey(0);

	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	try{
		imwrite("output.png", image, compression_params);
	}catch (cv::Exception& ex){
		fprintf(stderr, "exception saving image: %s\n", ex.what());
	}

	return 0;

}

