#include <iostream>
#include <iomanip> // Để sử dụng std::setw

using namespace std;

int main() {
    // Tiêu đề của bảng
    cout << setw(15) << left << "Tên" 
         << setw(15) << left << "Tuổi" 
         << setw(15) << left << "Địa chỉ" << endl;

    // Dữ liệu của bảng
    cout << setw(15) << left << "Nguyễn Văn A" 
         << setw(15) << left << 25 
         << setw(15) << left << "Hà Nội" << endl;

    cout << setw(15) << left << "Trần Thị B" 
         << setw(15) << left << 30 
         << setw(15) << left << "Đà Nẵng" << endl;

    cout << setw(15) << left << "Lê Văn C" 
         << setw(15) << left << 22 
         << setw(15) << left << "TP HCM" << endl;

    return 0;
}
