#include <iostream>
#include <string>
#include <algorithm>

#include <cassert>

bool is_rotation(const std::string& ref, const std::string& s) {
    auto size = ref.size();
    if (size != s.size()) return false;
    bool res = false;
    size_t ref_pos = ref.find(s[0]);
    size_t pos = 0;
    while (ref_pos != std::string::npos) {
        res = true;
        for (pos = 1; pos < size - ref_pos; ++pos) {
            if (s[pos] != ref[pos + ref_pos]) {
                res = false;
                break;
            }
        }
        for (pos = 0; pos < ref_pos; ++pos) {
            if (ref[pos] != s[size - ref_pos + pos]) {
                res = false;
                break;
            }
        }
        if (res) break;
        ref_pos = ref.find(s[0], ref_pos + 1);
    }
    return res;
}


int main() {
    std::string ref("helloworld");
    std::string   s(ref);
    //std::cout << s << '\n' << '\n';

    s = ref;
    for (int i = 0; i < 10; ++i) {
        std::rotate(s.begin(), s.begin()+1, s.end());
        //std::cout << s << '\n';
        assert(is_rotation(ref, s));
    }

    s[3] = 'x';
    assert(!is_rotation(ref, s));
    return 0;
}