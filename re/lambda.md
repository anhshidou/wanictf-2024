![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/eb4ca031-dc33-436f-af90-15ee8a21865d)

``` import sys

sys.setrecursionlimit(10000000)

(lambda _0: _0(input))(lambda _1: (lambda _2: _2('Enter the flag: '))(lambda _3: (lambda _4: _4(_1(_3)))(lambda _5: (lambda _6: _6(''.join))(lambda _7: (lambda _8: _8(lambda _9: _7((chr(ord(c) + 12) for c in _9))))(lambda _10: (lambda _11: _11(''.join))(lambda _12: (lambda _13: _13((chr(ord(c) - 3) for c in _10(_5))))(lambda _14: (lambda _15: _15(_12(_14)))(lambda _16: (lambda _17: _17(''.join))(lambda _18: (lambda _19: _19(lambda _20: _18((chr(123 ^ ord(c)) for c in _20))))(lambda _21: (lambda _22: _22(''.join))(lambda _23: (lambda _24: _24((_21(c) for c in _16)))(lambda _25: (lambda _26: _26(_23(_25)))(lambda _27: (lambda _28: _28('16_10_13_x_6t_4_1o_9_1j_7_9_1j_1o_3_6_c_1o_6r'))(lambda _29: (lambda _30: _30(''.join))(lambda _31: (lambda _32: _32((chr(int(c,36) + 10) for c in _29.split('_'))))(lambda _33: (lambda _34: _34(_31(_33)))(lambda _35: (lambda _36: _36(lambda _37: lambda _38: _37 == _38))(lambda _39: (lambda _40: _40(print))(lambda _41: (lambda _42: _42(_39))(lambda _43: (lambda _44: _44(_27))(lambda _45: (lambda _46: _46(_43(_45)))(lambda _47: (lambda _48: _48(_35))(lambda _49: (lambda _50: _50(_47(_49)))(lambda _51: (lambda _52: _52('Correct FLAG!'))(lambda _53: (lambda _54: _54('Incorrect'))(lambda _55: (lambda _56: _56(_41(_53 if _51 else _55)))(lambda _57: lambda _58: _58)))))))))))))))))))))))))))
```

Ở bài này thì mình có một đoạn code python nói về lambda. Theo mình nghĩ thì đoạn code này đã bị obfus, vậy thì mình chỉ cần tìm ra những điểm cần lưu ý trong đoạn code này:

Strings 1: Chuyển strings (16_10_13_x_6t_4_1o_9_1j_7_9_1j_1o_3_6_c_1o_6r) thành 1 base36 strings và + 10 vào từng kí tự

Tiếp theo: XOR nó với 123

Và -3 đi ở mỗi kí tự

Rồi cuối cùng thì +12 vào mỗi kí tự theo bảng mã ascii, với những gì đã có, mình viết code để reverse lại và đã có được flag

Flag: FLAG{l4_1a_14mbd4}



