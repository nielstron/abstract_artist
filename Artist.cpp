#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

Scalar randomColor(RNG rng) {
	int max_color = 255;
	return Scalar(rng.uniform(0, max_color), rng.uniform(0, max_color), rng.uniform(0, max_color));
}

int main(int argc, char* argv[])
{
	RNG rng(0xFFFFFFFF);

	cout << "Enter a size for your drawing." << endl;
	int w;
	cin >> w;
	cout << "How many strokes should be done?" << endl;
	int strokes;
	cin >> strokes;

	Mat img = Mat(Size(w, w), CV_8UC3, Scalar(255, 255, 255));

	namedWindow("window");


	for (int i = 0; i < strokes; i++) {
		Point start, end;
		start.x = rng.uniform(0, w);
		start.y = rng.uniform(0, w);
		end.x = rng.uniform(0, w);
		end.y = rng.uniform(0, w);

		int pos = rng.uniform(0, 4);
		
		switch (pos) {
		case 0:
			line(img, start, end, randomColor(rng), rng.uniform(1, 20), 8);
			break;
		default:
		case 1:
			Size axes;
			axes.width = rng.uniform(0, 200);
			axes.height = rng.uniform(0, 200);
			int start_angle = rng.uniform(0, 360);
			ellipse(img, start, axes, rng.uniform(0, 360), start_angle, rng.uniform(start_angle, 360), randomColor(rng), rng.uniform(1, 20), 8);
			break;
		}

		waitKey(1);
		imshow("window", img);


	}
	cout << "Enter a filename for your drawing." << endl;
	string name;
	cin >> name;

	imwrite(name, img);
	waitKey(0);
}
