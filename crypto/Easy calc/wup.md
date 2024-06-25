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

$$A = - ((p-1)s + (p-2)s^{2} + (p-3)s^{3} + ... + 2s^{p-2} + s^{p-1}) \mod p$$

Nhờ có gợi ý của anh trung là công thức tổng cấp số nhân nâng cao [này](https://brilliant.org/wiki/arithmetic-geometric-progression/), mình biến đổi A:

Áp dụng công thức Arithmetic-Geometric Progression (AGP), một tổng với các số hạng có dạng:
$$a,(a+d)r,(a+2d)r^{2},(a+3d)r^{3},…,(a+(n−1)d)r^{n−1}$$
với a là số hạng đầu, d là công sai, r là công bội.

Với A, ta áp dụng công thức AGP với $a = p$, $d = -1$, $r = s$ và số số hạng $n = p + 1$

$$A = - (\frac{p - (p + (p - 1 - 1).(-1)).s^{p+1}}{1-s} + \frac{(-1).s.(1-s^{p})}{(1-s)^{2}}) \mod p$$

$$A = - (\frac{p - (p - p).s^{p+1}}{1 - r} + \frac{-s + s^{p+1}}{(1-s)^{2}}) \mod p$$

$$A = - \frac{-s + s^{p+1}}{(1-s)^{2}} \mod p$$

$$A = \frac{s - s^{p} + s^{p} - s^{p+1}}{(1-s)^{2}} \mod p$$

$$A = \frac{s - s^{p}}{(1 - s)^{2} + \frac{s^{p}(a-s)}{(1 - s)^{2}} \mod p$$

Sử dụng Fermat nhỏ, có $s - s^{p} = 0 \mod p$

$$A = \frac{s^{p}}{1 - s} \mod p$$

Tiếp tục dùng Fermat nhỏ, có $s^{p} = s \mod p$

$$A = \frac{s}{1 - s} \mod p$$

$$A(1 − s) = s \mod p$$

$$A − As = s \mod p$$

$$A = s + As \mod p$$

$$A = s(1 + A) \mod p$$

$$s = \frac{A}{1 + A} \mod p$$

Hay nói cách khác `s = A * inverse(A + 1, p) % `

Từ đầy, ta có thể dễ dàng tìm được s.

# Lời giải

```
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
from hashlib import md5
from Crypto.Util.number import *

def decrypt(ciphertext, key):
    iv = ciphertext[:16]
    key = long_to_bytes(key)
    key = md5(key).digest()
    cipher = AES.new(key, AES.MODE_CBC, iv=iv)
    decrypted = cipher.decrypt(ciphertext[16:])
    return decrypted

# Giả sử tìm được `s`:
ciphertext = '9fb749ef7467a5aff04ec5c751e7dceca4f3386987f252a2fc14a8970ff097a81fcb1a8fbe173465eecb74fb1a843383'
p = 108159532265181242371960862176089900437183046655107822712736597793129430067645352619047923366465213553080964155205008757015024406041606723580700542617009651237415277095236385696694741342539811786180063943404300498027896890240121098409649537982185247548732754713793214557909539077228488668731016501718242238229
A = 60804426023059829529243916100868813693528686280274100232668009387292986893221484159514697867975996653561494260686110180269479231384753818873838897508257692444056934156009244570713404772622837916262561177765724587140931364577707149626116683828625211736898598854127868638686640564102372517526588283709560663960
s = A * inverse(A + 1, p) % p
ciphertext_bytes = bytes.fromhex(ciphertext)
decrypted_flag = decrypt(ciphertext_bytes, s)
print(f"Decrypted FLAG: {decrypted_flag}")
```

# Flag

`FLAG{Do_the_math396691ba7d7270a}`
