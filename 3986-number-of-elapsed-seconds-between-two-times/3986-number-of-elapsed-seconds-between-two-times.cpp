class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int sec=stoi(startTime.substr(6))-stoi(endTime.substr(6));
        int min=(stoi(startTime.substr(3,2))-stoi(endTime.substr(3,2)))*60;
        int hour=(stoi(startTime.substr(0,2))-stoi(endTime.substr(0,2)))*60*60;
        int ans=sec+min+hour;
        return abs(ans);
    }
};