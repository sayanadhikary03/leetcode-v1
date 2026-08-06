class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;

        for(int i=0; i<n; i++){
            int bill = bills[i];

            if(bill == 5) five++;
            else if (bill == 10){
                if(five == 0) return false;
                five--;
                ten++;
            }
            else if(bill == 20){
                if(ten >= 1){
                    ten--;
                    if(five == 0) return false;
                    five--;
                }
                else if (five < 3) return false;
                else{
                    five -= 3;
                }
            }
        }
        return true;
    }
};