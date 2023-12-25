#include <string>
#include <vector>

class TranspositionCipher
{
public:
    TranspositionCipher(int numColumns);
    std::wstring encrypt(const std::wstring& plaintext);
    std::wstring decrypt(const std::wstring& ciphertext);

private:
    int numColumns;
};
