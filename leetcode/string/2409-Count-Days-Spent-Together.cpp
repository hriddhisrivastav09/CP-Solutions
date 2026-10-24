class Solution {
public:

    int cnt_days(string s){
        vector <int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;

        int month = stoi(s.substr(0,2));
        int day = stoi(s.substr(3));

        for(int i = 0 ; i < month-1 ; i++){
            day += months[i];
        } 

        return day ;    
    }


    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int st = max(cnt_days(arriveAlice),cnt_days(arriveBob));
        int ed = min(cnt_days(leaveBob),cnt_days(leaveAlice));

        return max(0,ed-st+1);
    }
};