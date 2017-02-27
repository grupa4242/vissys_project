/*
 * main.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: me
 */


#include <opencv2/opencv.hpp>
#include <unistd.h>

using namespace cv;
using namespace std;

int main( int argc, char** argv )

{
	/*
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
*/

	VideoCapture cap(0); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;

	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(0);



	Mat edges;
	namedWindow("edges",CV_WINDOW_AUTOSIZE);
	int i = 0;
	for(;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera

		if (frame.empty()) break;
		imshow("edges", frame);
		char name[20];
		sprintf(name,"img%d.png",i);
		try{
			imwrite(name, frame, compression_params);
		}catch (cv::Exception& ex){
			fprintf(stderr, "exception saving image: %s\n", ex.what());
		}
		i++;
		if(waitKey(10) == 27) break;
		//if (i>50) break;
	}
	//cap.release();

	i = 0;
	namedWindow("edges2",CV_WINDOW_AUTOSIZE);
	for (;;)
	{
		Mat frame2;

		char name[20];
		sprintf(name,"img%d.png",i);
		frame2 = imread(name,1);
		i++;
		if (frame2.data == NULL)
			break;
		imshow("edges2", frame2);
		if(waitKey(10) == 27) break;
		usleep(30000);
	}
	return 0;

}

