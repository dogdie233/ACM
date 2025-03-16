#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>

struct CompressionChunk {
    int32_t value = 0;
    int32_t length = 0;

    CompressionChunk(int32_t value, int32_t length) : value(value), length(length) {}
};

int main() {
    int32_t n, winCount = 0, arrSum = 0, delSum;
    std::cin >> n;
    auto vec = std::vector<uint8_t>(n);
    auto compression = std::vector<CompressionChunk>();
    std::cin.get(); // skip '\n'
    for (auto& elem : vec) {
        elem = std::cin.get() - '0';
        arrSum += elem;
    }

    #ifndef ONLINE_JUDGE
    std::cout << "arrSum: " << arrSum << std::endl;
    #endif

    compression.push_back(CompressionChunk(vec[0], 1));
    for (auto i = 1; i < vec.size(); i++) {
        if (compression.crbegin()->value == vec[i]) {
            compression.rbegin()->length++;
        } else {
            compression.push_back(CompressionChunk(vec[i], 1));
        }
    }

    delSum = vec[0];
    auto isWinable = [n, compression, arrSum](const int delCount, const int delSum) -> bool const {
        auto remainCount = n - delCount;
        auto remainSum = arrSum - delSum;
        auto decompressIter = compression.crbegin();
        auto chunk = *decompressIter;
        while (remainCount > 0 && (remainSum % 2 == 1 || remainCount % 2 == 1)) {
            if (chunk.length == 0) {
                decompressIter++;
                if (decompressIter == compression.crend()) {
                    break;
                }
                chunk = *decompressIter;
            }
            if (remainCount % 2 == 1 || remainSum % 2 == chunk.value) {
                chunk.length -= 1;
                remainCount -= 1;
                remainSum -= chunk.value;
                continue;
            }
            // consume total chunk
            auto consumeCount = std::min(chunk.length, remainCount);
            chunk.length -= consumeCount;
            remainCount -= consumeCount;
            remainSum -= consumeCount * chunk.value;
        }

        return remainCount > 0 && remainSum % 2 == 0 && remainCount % 2 == 0;
    };
    for (auto i = 1; i < n - 1; delSum += vec[i++]) {
        auto winable = isWinable(i, delSum);
        winCount += winable;
    }

    std::cout << (1.0 * winCount / n) << std::endl;

    return 0;
}