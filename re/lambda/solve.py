def decode_flag(encoded_str):
    return ''.join(chr(int(c, 36) + 10) for c in encoded_str.split('_'))

def reverse_transform(transformed_str):
    step1 = ''.join(chr(123 ^ ord(c)) for c in transformed_str)
    step2 = ''.join(chr(ord(c) + 3) for c in step1)
    step3 = ''.join(chr(ord(c) - 12) for c in step2)
    return step3

correct_encoded_str = '16_10_13_x_6t_4_1o_9_1j_7_9_1j_1o_3_6_c_1o_6r'
correct_flag = decode_flag(correct_encoded_str)

original_flag = reverse_transform(correct_flag)
print(f'The correct flag is: {original_flag}')
