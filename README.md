# Hệ thống quản lí ví điểm thưởng
## 1. Giới thiệu về dự án 
Dự án nhầm mục đích hỗ trợ người tiêu dùng quản lí điểm thường, cho phép người dùng đăng kí, đăng nhập và bảo mật thông qua OTP. 

Dự án được xây dựng thông qua ngôn ngữ C++, đồng thời là sự kết hợp của QT Creator.

## 2. Thành viên tham gia 
| Họ và tên            | MSSV         | Vai trò                       |
|---------------------|--------------|-------------------------------|
| Nguyễn Khắc An       | N24DECE053   | Phụ trách giao diện frontend |
| Đỗ Vương Bảo Anh     | N24DECE054   | Xây dựng menu giao dịch      |
| Lâm Minh Chiến       | N24DECE057   | Xử lý OTP và mật khẩu        |
| Lê Nguyễn Quốc Hùng  | N24DECE070   | Đăng ký/đăng nhập, tester    |

## 3. Phân tích và đặc tả chức năng 
### 1. Đăng ký người dùng
- Tạo tài khoản với tên đăng nhập, mật khẩu, thông tin cá nhân.
- Có thể được nhập bởi người quản lý nếu người dùng không tự nhập.

### 2. Lưu trữ dữ liệu
- Lưu toàn bộ người dùng vào 1 file duy nhất, thuận tiện tra cứu.
- Có bản sao lưu file người dùng.

### 3. Đăng nhập và bảo mật
- Kiểm tra thông tin người dùng đã đăng ký.
- Cho phép thay đổi mật khẩu.
- OTP dùng xác thực thay đổi thông tin.

### 4. Giao dịch ví điểm thưởng
- Mỗi người dùng có 1 ví điểm với ID duy nhất.
- Giao dịch chuyển điểm giữa hai ví có kiểm tra số dư và hiển thị số dư
## 4. Cách chạy chương trình
- Đăng kí tài khoản
- Đăng nhập
- Thực hiện giao dịch chuyển điểm
- Thay đổi mật khẩu
- Xem thông tin cá nhân
- Thoát chương trình
  
