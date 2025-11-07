#ifndef SAMPLE_LIB_HPP
#define SAMPLE_LIB_HPP

#include <cstdint>

class SampleLib {
public:
    // コンストラクタ
    SampleLib(uint16_t initial_data = 0) : data_(initial_data) {}

    // データ取得
    uint16_t getData() const {
        return data_;
    }

    // データ設定
    void setData(uint16_t value) {
        data_ = value;
    }

private:
    uint16_t data_ = 0;
};

#endif // SAMPLE_LIB_HPP
