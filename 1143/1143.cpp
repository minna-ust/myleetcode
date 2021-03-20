                    bcde,ace;
                        |
                        |
                        |
                     bcd,ac
                     /      \
                    /       \
                   /         \
                 bc,ac     bcd,a
                   |         /
                  |         /
                  |        /
                 b,a     bc,a
                           /
                          /
                         /
                        b,a


                                 abcdcb, ccbe;
                            /                   \
                           /                     \
                          /                       \
                     abcdcb, ccb;             abcdc, ccbe;
                         |                       /      \
                         |                      /        \
                         |                     /          \
                     abcdc, cc;           abcd, ccbe;   abcdc, ccb;
                                                          /      \
                                                         /       \
                                                        /         \
                                                   abcd, ccb;    abcdc, cc;



|   |   | a | b | c | d | c | b |   |   |   |
|---+---+---+---+---+---+---+---+---+---+---|
|   | 0 | 0 | 0 | 0 | 0 | 0 | 0 |   |   |   |
| c | 0 | 0 | 0 | 1 | 1 | 1 | 1 |   |   |   |
| c | 0 | 0 | 0 | 1 | 1 | 2 | 2 |   |   |   |
| b | 0 |   |   |   |   |   |   |   |   |   |
| e | 0 |   |   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

    }
};
