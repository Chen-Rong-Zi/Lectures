#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <string>
// 你可以根据你的需要增加任何标准库头文件

// 你可以根据你的需要定义各种辅助类和函数

/**
 * 字符串加密器抽象类
 * 你不应该修改其中的实现
 */
class Encryptor {
public:
    /**
     * 将给定的字符串加密为密文
     * @param text 原始字符串的内容
     * @return 加密后的密文内容
     */
    virtual std::string encrypt(const std::string& text) const = 0;

    /**
     * 将给定的密文还原为原始字符串
     * @param text 密文的内容
     * @return 解密后的原文内容
     */
    virtual std::string decrypt(const std::string& text) const = 0;
};

/**
 * 使用凯撒加密算法实现的字符串加密器
 * 你可以添加任何你认为需要的成员变量和成员函数
 */
class CaesarCipherEncryptor: public Encryptor {
public:
    /**
     * 构造函数,通过给定的密钥k实例化加密器
     * @param k 加密密钥(测试样例保证-25 <= k <= 25)
     */
    int shift;
    explicit CaesarCipherEncryptor(int k);

    std::string encrypt(const std::string& text) const override;

    std::string decrypt(const std::string& text) const override;
};

/**
 * 使用单表替换算法实现的字符串加密器
 * 你可以添加任何你认为需要的成员变量和成员函数
 */
class SubstitutionCipherEncryptor: public Encryptor {
public:
    /**
     * 构造函数,通过给定的密钥key实例化加密器
     * @param key 加密密钥(测试样例保证key是"ABCDEFGHIJKLMNOPQRSTUVWXYZ"的一个排列)
     */
    std::string key;
    explicit SubstitutionCipherEncryptor(std::string key);

    std::string encrypt(const std::string& text) const override;

    std::string decrypt(const std::string& text) const override;
};

#endif //ENCRYPTOR_H

