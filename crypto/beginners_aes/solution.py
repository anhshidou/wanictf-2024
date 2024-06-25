from Crypto.Util.Padding import unpad
from Crypto.Cipher import AES
import hashlib
from os import urandom

def brute_force_decrypt(enc, flag_hash):
    base_key = b'the_enc_key_is_'
    base_iv = b'my_great_iv_is_'
    
    # Thử tất cả các khả năng của một byte
    for i in range(256):
        for j in range(256):
            key = base_key + bytes([i])
            iv = base_iv + bytes([j])
            cipher = AES.new(key, AES.MODE_CBC, iv)
            try:
                msg = unpad(cipher.decrypt(enc), 16)
                if hashlib.sha256(msg).hexdigest() == flag_hash:
                    return msg
            except ValueError:
                continue
    return None

# Ciphertext và flag_hash từ đoạn mã trên
enc = b'\x16\x97,\xa7\xfb_\xf3\x15.\x87jKRaF&"\xb6\xc4x\xf4.K\xd77j\xe5MLI_y\xd96\xf1$\xc5\xa3\x03\x990Q^\xc0\x17M2\x18' # Example encrypted bytes
flag_hash = '6a96111d69e015a07e96dcd141d31e7fc81c4420dbbef75aef5201809093210e' # Example SHA-256 hash

# Gọi hàm giải mã và in ra flag
decrypted_flag = brute_force_decrypt(enc, flag_hash)
if decrypted_flag:
    print(f'Decrypted flag: {decrypted_flag}')
else:
    print('Failed to decrypt flag')
