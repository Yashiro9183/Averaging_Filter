#include<opencv2/opencv.hpp>
#include<iostream>


int main(int argc,char* argv[]) {
	cv::Mat src_img = cv::imread("./data/lena.jpg");
	if (!src_img.data) {
		std::cout << "ファイルが開けません" << std::endl;
		return 1;
	}

	int k;
	std::cout << "フィルタサイズ入力:k=" << std::endl;
	std::cin >> k;

	cv::Mat dst_img = cv::Mat::zeros(cv::Size(src_img.rows,src_img.cols),CV_8UC3);

	for (int BGR = 0; BGR < 3; BGR++) {
		for (int x = 0; x < src_img.rows; x++) {
			for (int y = 0; y < src_img.cols; y++) {
				int tem = 0;
				int num = 0;
				for (int i = -(k-1)/2; i < (k-1)/2; i++) {
					for (int j = -(k-1)/2; j < (k-1)/2; j++) {
						if ((y + i < 0) || (x + j < 0)||(src_img.rows<y+i)||(src_img.cols<x+j)) break;
						else {
							tem += src_img.at<cv::Vec3b>(y + i, x + j)[BGR];
							num++;
						}

					}
				}
				tem = tem / num;
				if (tem > 255)tem = 255;
				dst_img.at<cv::Vec3b>(y, x)[BGR] = tem;
			}
		}
	}

		cv::imshow("Averaging_Filter", dst_img);
		cv::imshow("View", src_img);
		cv::imwrite("AveragingFilter.jpg", dst_img);
		cv::waitKey();
		system("pause");
		
}
	

