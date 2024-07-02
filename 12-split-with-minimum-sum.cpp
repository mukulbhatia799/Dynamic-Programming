// class Solution {
// public:
//     void findAns(string &strNum, int ind, string take, string notTake, int &answer) {
//         if(ind < 0) {
//             if(take == "" || notTake == "") return ;
//             sort(take.begin(), take.end());
//             sort(notTake.begin(), notTake.end());
//             int num1 = stoi(take);
//             int num2 = stoi(notTake);
//             answer = min(answer, num1+num2);
//             // cout << "num1: " << num1 << " num2: " << num2 << " answer: " << answer << endl;
//             return ;
//         }

//         // take;
//         findAns(strNum, ind-1, take+strNum[ind], notTake, answer);

//         // notTake;
//         findAns(strNum, ind-1, take, notTake+strNum[ind], answer);
//     }
//     int splitNum(int num) {
//         string strNum = to_string(num);
//         int answer = INT_MAX;
//         findAns(strNum, strNum.size()-1, "", "", answer);
//         return answer;
//     }
// };