# Đề bài

```
import os
import random
from hashlib import md5

from Crypto.Cipher import AES
from Crypto.Util.number import long_to_bytes, getPrime

FLAG = os.getenvb(b"FLAG", b"FAKE{THIS_IS_NOT_THE_FLAG!!!!!!}")


def encrypt(m: bytes, key: int) -> bytes:
    iv = os.urandom(16)
    key = long_to_bytes(key)
    key = md5(key).digest()
    cipher = AES.new(key, AES.MODE_CBC, iv=iv)
    return iv + cipher.encrypt(m)


def f(s, p):
    u = 0
    for i in range(p):
        u += p - i
        u *= s
        u %= p

    return u 


p = getPrime(1024)
s = random.randint(1, p - 1)

A = f(s, p)
ciphertext = encrypt(FLAG, s).hex()
```

# Phân tích

 Mấu chốt của bài toán nằm ở hàm `f(s, p)`, đề bài sử dụng `s` để mã hóa, nhưng lại sử dụng hàm này để biến đổi `s` thành `A` thông qua p rồi in ra. Nhiệm vụ của ta tìm lại được `s` từ `p` và `A`

 Phân tích hàm `f(s, p)`:

   - `i` sẽ chạy lần lượt từ 0 đến p - 1:
       + i = 0: $u = 0$ (do ps chia hết cho p)
       + i = 1: $u = -s   \mod p$
       + i = 2: $u = -s^{2} - 2s   \mod p$
       + ...
       + i = p - 1: $u = -s^{p-1} - 2s^{p-2} - 3s^{p-3} - ... - (p-2)s^{2} - (p-1)s$
   - Sau khi chạy xong có:
   - 
$$A =  -s^{p-1} - 2s^{p-2} - 3s^{p-3} - ... - (p-2)s^{2} - (p-1)s \mod p$$

Hay:

$$A = - [(p-1)s + (p-2)s^{2} + (p-3)s^{3} + ... + 2s^{p-2} + s^{p-1}] \mod p$$

Nhờ có gợi ý của anh trung là công thức tổng cấp số nhân nâng cao [này](https://brilliant.org/wiki/arithmetic-geometric-progression/), mình biến đổi A:

$$A
