class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        
        for (int p=0; p<32; p++) {
            if (n & (1L<<p)) res = res | 1L<<(32-(p+1));
        }        
        return res;
    }
};
