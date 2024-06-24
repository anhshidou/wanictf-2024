![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/5de8ef6a-502e-46fd-8b89-debfef9df492)

Ở bài này, đây là 1 kiểu bài memory analysis mà mình đánh giá là tương đối dễ. Vì nó khá dài nên mình sẽ chỉ walkthrough

![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/0017c974-95fc-4c79-ae3b-1dfea04cb32a)

Ở đây mình đã thấy được 2 file khả nghi, lúc này mình sẽ dump 2 file này ra để xem nó có gì không

![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/dc281302-b0aa-4944-b759-10bb834e3d67)

Sau khi đã dump file về, mình thử bật lên và thấy rằng có đoạn code powershell có vẻ đã bị obfus

![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/bf05c647-cfeb-4aec-a9d2-99709558d6b7)

Sau khi xóa các dấu cách và null bytes, mình thu về 1 đoạn nhìn có vẻ là base64

![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/a7e55209-7a78-41d7-8b7f-be5dc7556e53)

Sau khi decode xong, mình nhận ra đáp án đã tới rồi

![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/2ab23f5c-7ffa-455c-9338-24eb29a433cf)

``` 'ht'+'tp://192.168.0.16:8282/B64_dec'+'ode_RkxBR3tEYXl1bV90aGlzX'+'2lzX3NlY3JldF9maWxlfQ%3'+'D%3D/chall_mem_se'+'arch.e'+'xe' ```

Lúc này, mình chỉ cần decode đoạn base64 còn lại bằng cách ghép chúng vào với nhau

![image](https://github.com/anhshidou/wanictf-2024/assets/120787381/359b970d-6f99-447f-92b8-c4af1020c0f3)

