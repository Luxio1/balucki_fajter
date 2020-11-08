#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 1080, 480, 32 ), "Kurs SFML - http://cpp0x.pl" );

    sf::Texture tekstura;
    tekstura.loadFromFile( "rekawica_lewa.png" );
    sf::Sprite obrazek;
    obrazek.setTexture( tekstura );

    using namespace sf;

    float changeX = 0;
    float changeY = 0;

    while( oknoAplikacji.isOpen() )
    {
        sf::Event zdarzenie;
        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
                oknoAplikacji.close();

        }
        oknoAplikacji.clear( sf::Color::Black );

        //obrazek.setOrigin( 20, 20 ); //INFO: dopisane w tym rozdziale
        obrazek.setPosition( changeX, changeY ); //INFO: dopisane w tym rozdziale
        //obrazek.setRotation( 30 ); //INFO: dopisane w tym rozdziale
        //obrazek.setScale( 1.2, 0.8 ); //INFO: dopisane w tym rozdziale

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            changeX += -2;
        } else if (sf::Keyboard::isKeyPressed(Keyboard::D)) {
            changeX += 2;
        } else {
            //changeX = 0;
        } if (sf::Keyboard::isKeyPressed(Keyboard::W)) {
            changeY += -2;
        } else if (sf::Keyboard::isKeyPressed(Keyboard::S)) {
            changeY += 2;
        } else {
            //changeY = 0;
        }
        //sf::Sprite::move(changeX, changeY);

        oknoAplikacji.draw( obrazek );
        oknoAplikacji.display();
    }
    return 0;
}

/*#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {
    VideoCapture cap(0); //capture the video from webcam

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the web cam" << endl;
        return -1;
    }

    int iLowH = 170;
    int iHighH = 179;

    int iLowS = 150;
    int iHighS = 255;

    int iLowV = 60;
    int iHighV = 255;

    int iLastX = -1;
    int iLastY = -1;

    //Capture a temporary image from the camera
    Mat imgTmp;
    cap.read(imgTmp);

    //Create a black image with the size as the camera output
    Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);;


    while (true) {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video



        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        Mat imgHSV;

        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

        Mat imgThresholded;

        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV),
                imgThresholded); //Threshold the image

        //morphological opening (removes small objects from the foreground)
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
        dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

        //morphological closing (removes small holes from the foreground)
        dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

        //Calculate the moments of the thresholded image
        Moments oMoments = moments(imgThresholded);

        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;

        // if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero
        if (dArea > 10000) {
            //calculate the position of the ball
            int posX = dM10 / dArea;
            int posY = dM01 / dArea;

            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0) {
                //Draw a red line from the previous point to the current point
                line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0, 0, 255), 2);
            }

            iLastX = posX;
            iLastY = posY;
        }

        vector<Mat> channels;
        split(imgThresholded,channels);

        Mat red;
        inRange(channels[0], Scalar(0), Scalar(10), red); // red
// ... do the same for blue, green, etc only changing the Scalar values and the Mat

        double image_size = imgThresholded.cols*imgThresholded.rows;
        double red_percent = (1 - ((double) cv::countNonZero(red))/image_size) * 100;

        //cout << "Red percent: " << red_percent << "%" << endl;
        if(red_percent>20) cout << "BANG!!" << endl;

        //to ma dodac aktualna ilosc w % czerwonego na zarejestrowanym obrazie ale trzeba naprawic
        putText(imgThresholded, to_string(red_percent), Point2f(100,100), FONT_HERSHEY_PLAIN, 2,  Scalar(0,0,255,255));

        Mat flipHorizontal, flipOriginalHorizontal;
        flip(imgThresholded, flipHorizontal, 1);
        imshow("Thresholded Image", flipHorizontal); //show the thresholded image

        imgOriginal = imgOriginal + imgLines;

        flip(imgOriginal, flipOriginalHorizontal, 1);
        imshow("Original", flipOriginalHorizontal); //show the original image

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }

    return 0;
}*/