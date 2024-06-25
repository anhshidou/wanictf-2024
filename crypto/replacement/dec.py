import hashlib

# Đọc nội dung từ file
with open('E:\dev\ctf\wanictf\cry-replacement\my_diary_11_8_Wednesday.txt', 'r') as f:
    content = f.read().strip()
    enc = eval(content)  # Đọc nội dung và chuyển về list các số nguyên

# Tạo bảng ánh xạ MD5 từ ký tự về giá trị băm
md5_map = {}
for i in range(256):  # Tất cả các ký tự ASCII
    char = chr(i)
    md5_hash = hashlib.md5(str(ord(char)).encode()).hexdigest()
    md5_map[int(md5_hash, 16)] = char

# Giải mã từng giá trị trong enc
decrypted_cal = []
for x in enc:
    if x in md5_map:
        decrypted_cal.append(md5_map[x])
    else:
        decrypted_cal.append('?')  # Dùng '?' cho các giá trị không xác định

# Ghép các ký tự giải mã lại thành chuỗi
decrypted_cal_str = ''.join(decrypted_cal)
print("Decrypted calendar:")
print(decrypted_cal_str)