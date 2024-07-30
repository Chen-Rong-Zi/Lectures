#include "encryptor.h"
#include <string>
#include <iostream>
using namespace std;


CaesarCipherEncryptor::CaesarCipherEncryptor(int k) {
    this->shift = k;
}

std::string CaesarCipherEncryptor::encrypt(const std::string& text) const {
    string ans = "";
    for ( auto &it : text )
    {
        if (it + this->shift >= 65 + 26) {
            ans += (it - 26 + this->shift) % (65 + 26);
        }
        else if ( it + this->shift < 65 ) {
            ans += (it + 26 + this->shift) % (65 + 26);
        } else {
            ans += (it + this->shift) % (65 + 26);
        }
    }
    return ans;
}

std::string CaesarCipherEncryptor::decrypt(const std::string& text) const {
    string ans = "";
    for ( auto &it : text )
    {
        if (it - this->shift >= 65 + 26) {
            ans += (it - 26 - this->shift) % (65 + 26);
            // cout << "charis = " <<(char)((it - 26 - this->shift) % (65 + 26)) << endl;
        }
        else if ( it - this->shift < 65 ) {
            ans += (it + 26 - this->shift) % (65 + 26);
            // cout << "charis = " << (char)((it + 26 - this->shift) % (65 + 26)) << endl;
        } else {
            ans += (it - this->shift) % (65 + 26);
            // cout << "charis = " << (char)((it - this->shift) % (65 + 26)) << endl;
            // if ( ans[ans.length() - 1] < 65 ) {
                // cout << "hello" << endl;
                // cout  << it << endl;
                // cout  << (int)it << endl;
                // cout  << (int)ans[ans.length() - 1] << endl;
            // }
        }
    }
    return ans;
}

SubstitutionCipherEncryptor::SubstitutionCipherEncryptor(std::string key) {
    this->key = key;
    // TODO
}

std::string SubstitutionCipherEncryptor::encrypt(const std::string& text) const {
    string ans = "";
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for ( auto &it : text )
    {
        auto index = ABC.find(it);
        ans += this->key[index];
    }
    return ans;
}

std::string SubstitutionCipherEncryptor::decrypt(const std::string& text) const {
    string ans = "";
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for ( auto &it : text )
    {
        auto index = this->key.find(it);
        ans += ABC[index];
    }
    return ans;
}

#include <iostream>
int main() {
    Encryptor* encryptor = new CaesarCipherEncryptor(25);
    std::string origin = "THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG";

    std::string encrypted = encryptor->encrypt(origin);
    std::cout << encrypted << '\n'; // RFCOSGAIZPMULDMVHSKNQMTCPRFCJYXWBME

    std::cout << encryptor->decrypt(encrypted) << '\n'; // THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG

    // Encryptor* encryptor = new SubstitutionCipherEncryptor("RDMOTQKBAXHWYSULNGVZIFEJPC");
    // std::string origin = "THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG";

    // std::string encrypted = encryptor->encrypt(origin);
    // std::cout << encrypted << '\n'; // ZBTNIAMHDGUESQUJXIYLVUFTGZBTWRCPOUK

    // std::cout << encryptor->decrypt(encrypted) << '\n'; // THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG

    return 0;
}
