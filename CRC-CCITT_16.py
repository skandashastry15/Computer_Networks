def crc_ccitt_encoder(dataword):
    polynomial = 0x1021
    crc = 0xFFFF 
    dataword_int = int(dataword, 2)
    for i in range(len(dataword)):
        msb = (crc >> 15) & 1      
        crc <<= 1
        crc ^= ((dataword_int >> (len(dataword) - i - 1)) & 1)

        if msb:
            crc ^= polynomial
    crc_codeword = format(crc, '016b')
    return crc_codeword

def main():
    
    dataword = input("Enter the binary dataword (0s and 1s): ")
    crc_codeword = crc_ccitt_encoder(dataword)
    print(f"CRC-CCITT (16-bits) Codeword: {crc_codeword}")
    received_codeword = input("Enter the received codeword: ")

    if received_codeword == crc_codeword:
        print("No errors detected. Data is correct.")
    else:
        print("Error detected. Data is corrupt.")


if __name__ == "__main__":
    main()
