#include "MyFunction.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

Mat src, src_gray, dst;
//const char* window_name = "Threshold Demo";

const char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* trackbar_value = "Value";

/// Function headers
void Threshold_Demo( int, void* );

/**
 * @function main
 */
//int Threshold( int, char** argv )
int Threshold(char * srcImage)
{
    /// Load an image
    //src = imread( "lena.png", 1 );
    src = imread(srcImage, 1 );

    /// Convert the image to Gray
    //cvtColor( src, src_gray, COLOR_RGB2GRAY );
    if (src.empty()) {
    }
    else if (src.channels() > 1)
        cvtColor(src, src_gray, CV_BGR2GRAY);
    else src_gray = src;

    /// Create a window to display results
    namedWindow( window_name, WINDOW_NORMAL );

    /// Create Trackbar to choose type of Threshold
    createTrackbar( trackbar_type,
                    window_name, &threshold_type,
                    max_type, Threshold_Demo );

    createTrackbar( trackbar_value,
                    window_name, &threshold_value,
                    max_value, Threshold_Demo );

    /// Call the function to initialize
    Threshold_Demo( 0, 0 );

    /// Wait until user finishes program
    for (;;)
    {
        int c;
        c = waitKey( 33 );
        if ( (char)c == 27 )
        {            break;        }
    }

    return 0;
}


/**
 * @function Threshold_Demo
 */
void Threshold_Demo( int, void* )
{
    /* 0: Binary
       1: Binary Inverted
       2: Threshold Truncated
       3: Threshold to Zero
       4: Threshold to Zero Inverted
     */

    threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );
    imshow( window_name, dst );
}