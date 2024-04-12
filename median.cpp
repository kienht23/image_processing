#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// Hàm thực hiện lọc trung vị trên ảnh grayscale
Mat medianFilter(const Mat& inputImage, int kernelSize) {
    Mat outputImage;
    // Áp dụng lọc trung vị
    medianBlur(inputImage, outputImage, kernelSize);
    return outputImage;
}

int main() {
    // Đọc ảnh đầu vào
    Mat inputImage = imread("input.jpg", IMREAD_GRAYSCALE);

    if (inputImage.empty()) {
        cout << "Không thể đọc ảnh đầu vào\n";
        return -1;
    }

    // Hiển thị ảnh gốc
    imshow("Input Image", inputImage);

    // Kích thước của kernel (phải là số lẻ và lớn hơn 1)
    int kernelSize = 3;  // Kích thước kernel 3x3

    // Lọc trung vị
    Mat outputImage = medianFilter(inputImage, kernelSize);

    // Hiển thị ảnh sau khi được lọc trung vị
    imshow("Median Filtered Image", outputImage);

    // Chờ người dùng nhấn phím bất kỳ để thoát
    waitKey(0);

    return 0;
}