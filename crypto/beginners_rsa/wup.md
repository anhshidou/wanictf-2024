# Đề bài

```
from Crypto.Util.number import *

p = getPrime(64)
q = getPrime(64)
r = getPrime(64)
s = getPrime(64)
a = getPrime(64)
n = p*q*r*s*a
e = 0x10001

FLAG = b'FLAG{This_is_a_fake_flag}'
m = bytes_to_long(FLAG)
enc = pow(m, e, n)
print(f'n = {n}')
print(f'e = {e}')
print(f'enc = {enc}')
```

# Phân tích

Có thể dễ dàng nhận thấy đây là dạng mã hóa RSA với nhiều số nguyên tố, tuy nhiên, kích cỡ của số nguyên tố khá nhỏ nên có thể tìm ra được trong thời gian ngắn.

# Lời giải

Mình sử dụng sagemath để phân tích n thành thừa số nguyên tố:

```
sage: ecm.factor(317903423385943473062528814030345176720578295695512495346444822768171649361480819163749494400347)
[9953162929836910171,
 11771834931016130837,
 12109985960354612149,
 13079524394617385153,
 17129880600534041513]
```

Sử dụng các giá trị tìm được để giải mã:

```
from Crypto.Util.number import *

n = 317903423385943473062528814030345176720578295695512495346444822768171649361480819163749494400347
e = 65537
ct = 127075137729897107295787718796341877071536678034322988535029776806418266591167534816788125330265
p = [9953162929836910171, 11771834931016130837, 12109985960354612149, 13079524394617385153, 17129880600534041513]
phi = 1
for i in p:
    phi *= (i-1)
d = inverse(e, phi)

plain = pow(ct,d,n)

print(long_to_bytes(plain))
```

# Flag

`FLAG{S0_3a5y_1254!!}`



