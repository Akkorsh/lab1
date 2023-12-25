#include "transpositioncipher.h"
#include <vector>
#include <codecvt>
#include <locale>

TranspositionCipher::TranspositionCipher(int numColumns) : numColumns(numColumns) {}

std::wstring TranspositionCipher::encrypt(const std::wstring& plaintext)
{
    std::wstring ciphertext;
    int numRows = (plaintext.length() + numColumns - 1) / numColumns;
    std::vector<std::wstring> table(numRows, std::wstring(numColumns, L' '));
    int index = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = numColumns - 1; j >= 0; j--) {
            if (index < plaintext.length()) {
                table[i][j] = plaintext[index++];
            }
        }
    }

    for (int j = 0; j < numColumns; j++) {
        for (int i = 0; i < numRows; i++) {
            ciphertext += table[i][j];
        }
    }

    return ciphertext;
}

std::wstring TranspositionCipher::decrypt(const std::wstring& ciphertext)
{
    std::wstring decryptedText;
    int numRows = (ciphertext.length() + numColumns - 1) / numColumns;
    std::vector<std::wstring> table(numRows, std::wstring(numColumns, ' '));
    uint index = 0;
    for (int j = numColumns - 1; j >= 0; j--) {
        for (int i = 0; i < numRows; i++) {
            if (index < ciphertext.length()) {
                table[i][j] = ciphertext[index++];
            }
        }
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            decryptedText += table[i][j];
        }
    }
    return decryptedText;
}
