class Solution {
public:
    int dp[101][101];

    bool solve(string &s, int ind, int cnt) {

        // Too many closing brackets
        if (cnt < 0)
            return false;

        // End of string
        if (ind == s.length())
            return cnt == 0;

        // Already calculated
        if (dp[ind][cnt] != -1)
            return dp[ind][cnt];

        // '('
        if (s[ind] == '(') {
            return dp[ind][cnt] =
                solve(s, ind + 1, cnt + 1);
        }

        // ')'
        if (s[ind] == ')') {
            return dp[ind][cnt] =
                solve(s, ind + 1, cnt - 1);
        }

        // '*'
        return dp[ind][cnt] =
            solve(s, ind + 1, cnt + 1) ||   // '*' = '('
            solve(s, ind + 1, cnt - 1) ||   // '*' = ')'
            solve(s, ind + 1, cnt);         // '*' = ""
    }

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 0);
    }
};

// example ->     s = "(*))"
        //                  f(0,0)
        //                     |
        //                     | '('
        //                     | cnt + 1
        //                     ↓
        //                  f(1,1)
        //                     |
        //                     | '*'
        //      ┌──────────────┼──────────────┐
        //      |              |              |
        //   '*'='('        '*'=')'        '*'=''
        //      |              |              |
        //   cnt+1          cnt-1           cnt
        //      ↓              ↓              ↓
        //   f(2,2)         f(2,0)         f(2,1)
        //      |              |              |
        //      | ')'          | ')'          | ')'
        //      | cnt-1        | cnt-1        | cnt-1
        //      ↓              ↓              ↓
        //   f(3,1)         f(3,-1)        f(3,0)
        //      |              X              |
        //      | ')'                         | ')'
        //      | cnt-1                       | cnt-1
        //      ↓                             ↓
        //   f(4,0)                         f(4,-1)
        //      |                              |
        //   cnt == 0                       cnt < 0
        //      ↓                              ↓
        //   TRUE ✅                         FALSE ❌

//Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// ( )

//Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// ) (

//Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// ( )

//'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
// * -> ), (, ""