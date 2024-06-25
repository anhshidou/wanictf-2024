# Đề bài

```
from secret import cal
import hashlib

enc = []
for char in cal:
    x = ord(char)
    x = hashlib.md5(str(x).encode()).hexdigest()
    enc.append(int(x, 16))
        
with open('my_diary_11_8_Wednesday.txt', 'w') as f:
    f.write(str(enc))
```

# Phân tích

Với từng ký tự trong plaintext, chương trình sẽ hash sử dụng md5.Để giải mã, ta cần biết rằng với mỗi một input, hàm băm md5 sẽ trả ra một output duy nhất, tức là với mỗi ký tự ASCII chỉ tạo ra 1 và chỉ 1 giá trị bằm. 
Do đó, ta sẽ băm lần lượt từng ký tự AS II để biếta giá trị bằm tương ứng, rồi giải mã thep phương pháp mã hóa thay thế (substitution cipher)

# Lời giải

```
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
```

# Output

```
Decrypted calendar:
Wednesday, 11/8, clear skies. This morning, I had breakfast at my favorite cafe. Drinking the freshly brewed coffee and savoring the warm buttery toast is the best. Changing the subject, I received an email today with something rather peculiar in it. It contained a mysterious message that said "This is a secret code, so please don't tell anyone. FLAG{13epl4cem3nt}". How strange!

Gureisya
```

# Flag

`FLAG{13epl4cem3nt}`
