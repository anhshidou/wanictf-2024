![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/d431972d-0559-42ff-be7e-7a17a17d78e3)

Ở bài này, họ cho mình 1 hàm construct_flag bị obfus, nhưng thuật toán và code thì khá rõ ràng. Một người anh trong CLB mình có bảo sau khi hết giải là debug là ra, nhưng tại mình không biết debug nên viết lại thuật toán là cách duy nhất của mình

Ở đây, mình để ý unk_2010

![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/b02d5d0f-a338-44ac-8913-1836eb6a8824)

Bởi vì memory sẽ được copy từ trong unk_2010 để so sánh

``` .rodata:0000000000002010 unk_2010        db 0B2h                 ; DATA XREF: constructFlag+14↑o
.rodata:0000000000002011                 db    3
.rodata:0000000000002012                 db    0
.rodata:0000000000002013                 db    0
.rodata:0000000000002014                 db 0A4h
.rodata:0000000000002015                 db    3
.rodata:0000000000002016                 db    0
.rodata:0000000000002017                 db    0
.rodata:0000000000002018                 db 0B8h
.rodata:0000000000002019                 db    3
.rodata:000000000000201A                 db    0
.rodata:000000000000201B                 db    0
.rodata:000000000000201C                 db 0AAh
.rodata:000000000000201D                 db    3
.rodata:000000000000201E                 db    0
.rodata:000000000000201F                 db    0
.rodata:0000000000002020                 db 0C0h
.rodata:0000000000002021                 db    3
.rodata:0000000000002022                 db    0
.rodata:0000000000002023                 db    0
.rodata:0000000000002024                 db 0A4h
.rodata:0000000000002025                 db    3
.rodata:0000000000002026                 db    0
.rodata:0000000000002027                 db    0
.rodata:0000000000002028                 db 0D4h
.rodata:0000000000002029                 db    3
.rodata:000000000000202A                 db    0
.rodata:000000000000202B                 db    0
.rodata:000000000000202C                 db 0C2h
.rodata:000000000000202D                 db    3
.rodata:000000000000202E                 db    0
.rodata:000000000000202F                 db    0
.rodata:0000000000002030                 db 0F0h
.rodata:0000000000002031                 db    3
.rodata:0000000000002032                 db    0
.rodata:0000000000002033                 db    0
.rodata:0000000000002034                 db 0E4h
.rodata:0000000000002035                 db    3
.rodata:0000000000002036                 db    0
.rodata:0000000000002037                 db    0
.rodata:0000000000002038                 db 0D8h
.rodata:0000000000002039                 db    3
.rodata:000000000000203A                 db    0
.rodata:000000000000203B                 db    0
.rodata:000000000000203C                 db 0E0h
.rodata:000000000000203D                 db    3
.rodata:000000000000203E                 db    0
.rodata:000000000000203F                 db    0
.rodata:0000000000002040                 db 0E8h
.rodata:0000000000002041                 db    3
.rodata:0000000000002042                 db    0
.rodata:0000000000002043                 db    0
.rodata:0000000000002044                 db  32h ; 2
.rodata:0000000000002045                 db    2
.rodata:0000000000002046                 db    0
.rodata:0000000000002047                 db    0
.rodata:0000000000002048                 db 0C4h
.rodata:0000000000002049                 db    3
.rodata:000000000000204A                 db    0
.rodata:000000000000204B                 db    0
.rodata:000000000000204C                 db  36h ; 6
.rodata:000000000000204D                 db    2
.rodata:000000000000204E                 db    0
.rodata:000000000000204F                 db    0
.rodata:0000000000002050                 db 0E0h
.rodata:0000000000002051                 db    3
.rodata:0000000000002052                 db    0
.rodata:0000000000002053                 db    0
.rodata:0000000000002054                 db 0CEh
.rodata:0000000000002055                 db    3
.rodata:0000000000002056                 db    0
.rodata:0000000000002057                 db    0
.rodata:0000000000002058                 db 0D0h
.rodata:0000000000002059                 db    3
.rodata:000000000000205A                 db    0
.rodata:000000000000205B                 db    0
.rodata:000000000000205C                 db  30h ; 0
.rodata:000000000000205D                 db    2
.rodata:000000000000205E                 db    0
.rodata:000000000000205F                 db    0
.rodata:0000000000002060                 db 0D8h
.rodata:0000000000002061                 db    3
.rodata:0000000000002062                 db    0
.rodata:0000000000002063                 db    0
.rodata:0000000000002064                 db 0C4h
.rodata:0000000000002065                 db    3
.rodata:0000000000002066                 db    0
.rodata:0000000000002067                 db    0
.rodata:0000000000002068                 db 0C8h
.rodata:0000000000002069                 db    3
.rodata:000000000000206A                 db    0
.rodata:000000000000206B                 db    0
.rodata:000000000000206C                 db  2Ch ; ,
.rodata:000000000000206D                 db    2
.rodata:000000000000206E                 db    0
.rodata:000000000000206F                 db    0
.rodata:0000000000002070                 db 0C4h
.rodata:0000000000002071                 db    3
.rodata:0000000000002072                 db    0
.rodata:0000000000002073                 db    0
.rodata:0000000000002074                 db 0CEh
.rodata:0000000000002075                 db    3
.rodata:0000000000002076                 db    0
.rodata:0000000000002077                 db    0
.rodata:0000000000002078                 db 0A2h
.rodata:0000000000002079                 db    3
.rodata:000000000000207A                 db    0
.rodata:000000000000207B                 db    0
.rodata:000000000000207C                 db 0DCh
.rodata:000000000000207D                 db    3
.rodata:000000000000207E                 db    0
.rodata:000000000000207F                 db    0
.rodata:0000000000002080                 db 0F0h
.rodata:0000000000002081                 db    3
.rodata:0000000000002082                 db    0
.rodata:0000000000002083                 db    0
.rodata:0000000000002084                 db  10h
.rodata:0000000000002085                 db    2
.rodata:0000000000002086                 db    0
.rodata:0000000000002087                 db    0
.rodata:0000000000002088                 db 0DAh
.rodata:0000000000002089                 db    3
.rodata:000000000000208A                 db    0
.rodata:000000000000208B                 db    0
.rodata:000000000000208C                 db 0E8h
.rodata:000000000000208D                 db    3
.rodata:000000000000208E                 db    0
.rodata:000000000000208F                 db    0
.rodata:0000000000002090                 db  2Ch ; ,
.rodata:0000000000002091                 db    2
.rodata:0000000000002092                 db    0
.rodata:0000000000002093                 db    0
.rodata:0000000000002094                 db  38h ; 8
.rodata:0000000000002095                 db    2
.rodata:0000000000002096                 db    0
.rodata:0000000000002097                 db    0
.rodata:0000000000002098                 db 0D8h
.rodata:0000000000002099                 db    3
.rodata:000000000000209A                 db    0
.rodata:000000000000209B                 db    0
.rodata:000000000000209C                 db  1Eh
.rodata:000000000000209D                 db    2
.rodata:000000000000209E                 db    0
.rodata:000000000000209F                 db    0
.rodata:00000000000020A0                 db 0D6h
.rodata:00000000000020A1                 db    3
.rodata:00000000000020A2                 db    0
.rodata:00000000000020A3                 db    0
.rodata:00000000000020A4                 db  32h ; 2
.rodata:00000000000020A5                 db    2
.rodata:00000000000020A6                 db    0
.rodata:00000000000020A7                 db    0
.rodata:00000000000020A8                 db 0EEh
.rodata:00000000000020A9                 db    3
.rodata:00000000000020AA                 db    0
.rodata:00000000000020AB                 db    0
.rodata:00000000000020AC                 db  3Ch ; <
.rodata:00000000000020AD                 db    2
.rodata:00000000000020AE                 db    0
.rodata:00000000000020AF                 db    0
.rodata:00000000000020B0                 db  3Ch ; <
.rodata:00000000000020B1                 db    2
.rodata:00000000000020B2                 db    0
.rodata:00000000000020B3                 db    0
.rodata:00000000000020B4                 db  84h
.rodata:00000000000020B5                 db    3
.rodata:00000000000020B6                 db    0
.rodata:00000000000020B7                 db    0
.rodata:00000000000020B8                 db  70h ; p
.rodata:00000000000020B9                 db    2
.rodata:00000000000020BA                 db    0
.rodata:00000000000020BB                 db    0
.rodata:00000000000020BC                 db  68h ; h
.rodata:00000000000020BD                 db    3
.rodata:00000000000020BE                 db    0
.rodata:00000000000020BF                 db    0
```

Nhờ đó thì mình đã list ra được data cần tìm là:

```
unsigned char data[] = {
    0xB2, 0x03, 0x00, 0x00, 0xA4, 0x03, 0x00, 0x00,
    0xB8, 0x03, 0x00, 0x00, 0xAA, 0x03, 0x00, 0x00,
    0xC0, 0x03, 0x00, 0x00, 0xA4, 0x03, 0x00, 0x00,
    0xD4, 0x03, 0x00, 0x00, 0xC2, 0x03, 0x00, 0x00,
    0xF0, 0x03, 0x00, 0x00, 0xE4, 0x03, 0x00, 0x00,
    0xD8, 0x03, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x00,
    0xE8, 0x03, 0x00, 0x00, 0x32, 0x02, 0x00, 0x00,
    0xC4, 0x03, 0x00, 0x00, 0x36, 0x02, 0x00, 0x00,
    0xE0, 0x03, 0x00, 0x00, 0xCE, 0x03, 0x00, 0x00,
    0xD0, 0x03, 0x00, 0x00, 0x30, 0x02, 0x00, 0x00,
    0xD8, 0x03, 0x00, 0x00, 0xC4, 0x03, 0x00, 0x00,
    0xC8, 0x03, 0x00, 0x00, 0x2C, 0x02, 0x00, 0x00,
    0xC4, 0x03, 0x00, 0x00, 0xCE, 0x03, 0x00, 0x00,
    0xA2, 0x03, 0x00, 0x00, 0xDC, 0x03, 0x00, 0x00,
    0xF0, 0x03, 0x00, 0x00, 0x10, 0x02, 0x00, 0x00,
    0xDA, 0x03, 0x00, 0x00, 0xE8, 0x03, 0x00, 0x00,
    0x2C, 0x02, 0x00, 0x00, 0x38, 0x02, 0x00, 0x00,
    0xD8, 0x03, 0x00, 0x00, 0x1E, 0x02, 0x00, 0x00,
    0xD6, 0x03, 0x00, 0x00, 0x32, 0x02, 0x00, 0x00,
    0xEE, 0x03, 0x00, 0x00, 0x3C, 0x02, 0x00, 0x00,
    0x3C, 0x02, 0x00, 0x00, 0x84, 0x03, 0x00, 0x00,
    0x70, 0x02, 0x00, 0x00, 0x68, 0x03, 0x00, 0x00
};

```

Công việc lúc này của mình chỉ là ngồi copy lại thuật toán kia và thêm dòng này vào rồi chạy là sẽ được flag

flag: FLAG{How_did_you_get_here_4VKzTLibQmPaBZY4}











