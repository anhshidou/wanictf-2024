![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/aac9da25-a91c-4931-b625-0092b26c11eb)

Ở đây họ cho ta 1 file binary không rõ để làm gì, theo thói quen thì mình sử dụng hxd để kiểm tra hex bên trong file

![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/b2e0f4c8-70f6-40af-b842-0191d5cd40e3)

Ở đây mình để ý các byte đầu là RDP8bmp, thì mình cũng đã đoán ra được đây là cache của bmp, và có 1 script trên github để có thể giúp mình biến đoạn cache này thành từng ảnh

```https://github.com/ANSSI-FR/bmc-tools```

![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/966a5b5b-1fdc-44c7-bac3-7df3418b27f0)

Sau khi làm xong thì mình có bức ảnh

![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/4b2cf4e8-5c3e-4630-a005-13c01599e2b4)
