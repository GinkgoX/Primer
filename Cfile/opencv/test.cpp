#include "cv.h"
#include "highgui.h"
#include <iostream>
using namespace std;

#define	PICTURE	"./lena.jpg"

int main(void)

{

    IplImage* img = cvLoadImage(PICTURE, 0);

    cvNamedWindow( "test", 0 );

    cvShowImage("test", img);

    cvWaitKey(0);

    cvReleaseImage( &img );

    cvDestroyWindow( "test" );

    return 0;

}
