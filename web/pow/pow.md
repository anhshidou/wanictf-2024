# Đề bài:

![Screenshot (622)](https://github.com/anhshidou/wanictf-2024/assets/152991010/9f205a91-0f2e-4362-b48e-9f116e17463b)

# Giao diện:

![Screenshot (623)](https://github.com/anhshidou/wanictf-2024/assets/152991010/53059dab-8e6f-4af8-816a-6a660257d535)

# Khai thác: 

- Ta nhận thấy với giá trị 7844289 thì process tăng lên 1
- Xem response ta có :

![Screenshot (624)](https://github.com/anhshidou/wanictf-2024/assets/152991010/1cc4e97d-3209-4a2e-91fc-5ce64865c883)

- Nếu ta tiếp tục bấm send, process sẽ tăng thêm 1

![Screenshot (625)](https://github.com/anhshidou/wanictf-2024/assets/152991010/0407ec5c-3ba8-407a-9828-740f58b86d36)

- Tuy nhiên server sẽ giới hạn số request chúng ta gửi đi trong 1s, do đó chúng ta cần tìm con đường khác
- Vậy sẽ ra sao nếu ta thêm 1 phần tử nữa vô trong []:

![Screenshot (626)](https://github.com/anhshidou/wanictf-2024/assets/152991010/3b868b37-43c1-4763-bafe-fcbcf5167cee)

- Kết quả là process tăng thêm 2
- Và đó chính là ý tưởng của bài này, bằng việc có 1 triệu phần tử, ta có thể 1 bấm lấy flag
- Ta sẽ sử dụng payload như sau:

![Screenshot (611)](https://github.com/anhshidou/wanictf-2024/assets/152991010/eae4e254-3c1a-44cc-a9f8-51258f11f913)

![Screenshot (610)](https://github.com/anhshidou/wanictf-2024/assets/152991010/7956e0a0-d56a-474b-9c0f-7b6c2b6d6f45)

- Và ta lấy được flag

# Flag:
FLAG{N0nCE_reusE_i$_FUn}
