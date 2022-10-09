// leetcode's 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/
class Solution 
{
    public:
    vector<string>o={"","I","II","III","IV","V","VI","VII","VIII","IX"};
    vector<string>t={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vector<string>h={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vector<string>th={"","M","MM","MMM"};
    
    string intToRoman(int nums) 
    {
        return(th[nums/1000]+h[(nums%1000)/100]+t[(nums%100)/10]+o[nums%10]);
    }
};