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

	
	for (int BGR = 0; BGR < 3; BGR++) {
		for (int x = (k-1)/2; x < src_img.rows-(k-1)/2; x++) {
			for (int y = (k-1)/2; y < src_img.cols-(k-1)/2; y++) {
				int tem = 0;
				for (int i = -(k-1)/2; i < (k-1)/2; i++) {
					for (int j = -(k-1)/2; j < (k-1)/2; j++) {
						if ((y + i < 0) || (x + j < 0)) {
							src_img.at<cv::Vec3b>(y + i, x + j)[BGR] = 0;
						}
						tem += src_img.at<cv::Vec3b>(y + i, x + j)[BGR];
					}
				}
				tem = tem / (k*k);
				if (tem > 255)tem = 255;
				src_img.at<cv::Vec3b>(y, x)[BGR] = tem;
			}
		}
	}

		cv::imshow("Averaging_Filter", src_img);
		cv::imwrite("AveragingFilter.jpg", src_img);
		cv::waitKey();
		system("pause");
		
}
	

