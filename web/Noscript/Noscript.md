# Đề bài:

![Screenshot (633)](https://github.com/anhshidou/wanictf-2024/assets/152991010/266a4459-3fc8-4904-bd61-f4f8a0d73193)

# Giao diện:
- Khi vào web thì ta có 1 giao diện login, đây là giao diện để submit cho admin

![Screenshot (634)](https://github.com/anhshidou/wanictf-2024/assets/152991010/9f75392b-d477-4610-857a-e9ad30a7c3ef)

- Bấm sign in thì ta có:

![Screenshot (635)](https://github.com/anhshidou/wanictf-2024/assets/152991010/19c57616-fec5-476c-83c2-f256c1eacdf0)

# Khai thác:
## Tổng quát
- Trước tiên thì endpoint user đã xài CSP, CSP hay Content Security Policy, là 1 tiêu chuẩn bảo mật được thiết kế để ngăn chặn các kiểu tấn công, ví dụ như xss bằng cách xác định các nguồn được cho phép cho từng loại nội dung
-  Ở đây thì ta có `default-src 'self', script-src 'none'`
- `default-src 'self' tức là chỉ có các tài nguyên từ cùng 1 website được tải và sử dụng
-  script-src 'none' không cho phép bất cứ câu lệnh javascript nào được thực hiện
-  Điều đó có nghĩa là ta sẽ phải xss mà ko được xài câu lệnh javascript
## Suộc:
- Sau khi xem xong source, ta thấy có 4 endpoint là /report, /user/, /username/, /signin
- /signin sẽ tạo ra 1 endpoint có dạng ^/user/[a-fA-F0-9]{8}-[a-fA-F0-9]{4}-4[a-fA-F0-9]{3}-[8|9|aA|bB][a-fA-F0-9]{3}-[a-fA-F0-9]{12}$
- /report sẽ là gửi cho admin 1 cái link mà định dạng bắt buộc phải là ^/user/[a-fA-F0-9]{8}-[a-fA-F0-9]{4}-4[a-fA-F0-9]{3}-[8|9|aA|bB][a-fA-F0-9]{3}-[a-fA-F0-9]{12}$
- Điều đó tức là ta sẽ bắt buộc phải gửi endpoint user cho admin
## Hướng làm:
- Trước tiên hãy thử xss bằng ```<img src=0 onerror=alert(1)>```

![Screenshot (636)](https://github.com/anhshidou/wanictf-2024/assets/152991010/ac3928d6-9082-4790-b1e0-4e80b956e86a)

- Web vẫn thực thi code html tạo ra ảnh, nhưng ko thể hiện pop up do csp đã chặn toàn bộ câu lệnh js được thực thi
- Nếu bạn truy cập vào endpoint username, điều này sẽ xảy ra

![Screenshot (637)](https://github.com/anhshidou/wanictf-2024/assets/152991010/6f85e2c3-6e3d-44a8-9fa9-c8d64c161c1a)

- Vậy thì endpoint username ko hề có gì để bảo vệ khỏi xss, và ta có thể thoải mái để execute lệnh js

=> Hướng làm: dùng các tag html để chuyển hướng endpoint user sang username, xong đó execute lệnh js ở bên username

## Exploit:
- Để dùng tag html chuyển hướng 1 endpoint, ta có tag meta
- Tag meta là 1 tag định nghĩa metadata của web, và trong tag đó có 1 cách để chuyển hướng web, đó là ```<meta http-equiv="refresh" content="0;url=your-url-here">```
- Do không có bất cứ 1 code js nào, do đó csp sẽ không thể chặn chuyển hướng
### Payload:

![Screenshot (616)](https://github.com/anhshidou/wanictf-2024/assets/152991010/b8ff4e42-9d79-4b1c-9783-a0e3711453f1)

# Flag:

![Screenshot (617)](https://github.com/anhshidou/wanictf-2024/assets/152991010/69a398d4-8657-44dd-82cb-b4163895a536)

