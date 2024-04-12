#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Đọc ảnh đầu vào
    Mat image = imread("input_image.jpg", IMREAD_GRAYSCALE); //Chèn đường dẫn của ảnh cần Input vào input_image.jpg
    
    if (image.empty()) {
        cout << "Không thể đọc được ảnh!\n";
        return -1;
    }
    
    // Tính histogram
    int histSize = 256; // Số lượng bin của histogram
    float range[] = {0, 256}; // Phạm vi giá trị pixel
    const float* histRange = {range};
    Mat hist;
    calcHist(&image, 1, 0, Mat(), hist, 1, &histSize, &histRange, true, false);
    
    // Tính histogram tích lũy
    Mat cumulative_hist = hist.clone();
    for (int i = 1; i < histSize; ++i) {
        cumulative_hist.at<float>(i) += cumulative_hist.at<float>(i - 1);
    }
    
    // Chuẩn hóa histogram tích lũy
    cumulative_hist /= cumulative_hist.at<float>(histSize - 1);
    cumulative_hist *= 255;
    
    // Ánh xạ lại các giá trị pixel ban đầu bằng histogram cân bằng
    Mat equalized_image = image.clone();
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            equalized_image.at<uchar>(y, x) = saturate_cast<uchar>(cumulative_hist.at<float>(image.at<uchar>(y, x)));
        }
    }
    
    // Hiển thị ảnh gốc và ảnh đã được cân bằng histogram
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", image);
    
    namedWindow("Equalized Image", WINDOW_AUTOSIZE);
    imshow("Equalized Image", equalized_image);
    
    waitKey(0);
    destroyAllWindows();
    
    return 0;
}