class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {


        map<int, int> dayMap;
        int prefixSum = 0, freeDays = 0, previousDay = days;
        bool hasGap = false;

        for (auto& meeting : meetings) {
            // Set first day of meetings
            previousDay = min(previousDay, meeting[0]);

            // Process start and end of meeting
            dayMap[meeting[0]]++;
            dayMap[meeting[1] + 1]--;
        }

        // Add all days before the first day of meetings
        freeDays += (previousDay - 1);
        for (auto& day : dayMap) {
            int currentDay = day.first;
            // Add current range of days without a meeting
            if (prefixSum == 0) {
                freeDays += currentDay - previousDay;
            }
            prefixSum += day.second;
            previousDay = currentDay;
        }

        // Add all days after the last day of meetings
        freeDays += days - previousDay + 1;
        return freeDays;    

        //3rd approach
        // int occupiedDays =0;
        // sort(meetings.begin(),meetings.end());

        // int start = meetings[0][1], end = meetings[0][1];

        // for(int i=1;i<meetings.size();i++)
        // {
        //     if(meetings[i][0]<= end)
        //     {
        //         end = max(end, meetings[i][1]);
        //     }
        //     else{
        //         occupiedDays += (end - start + 1);
        //         start = meetings[i][0];
        //         end = meetings[i][1];
        //     }
        // }
        // occupiedDays += (end - start + 1);

        // return days - occupiedDays;






        //1st approach


        // vector<int> list;
        // unordered_set<int> seen;
        // vector<int> res;

        // sort(meetings.begin(), meetings.end());

        // for(int i=0;i<meetings.size();i++)
        // {
        //     for(int j=meetings[i][0];j<=meetings[i][1];j++)
        //     {
        //         list.push_back(j);
        //     }
        // }


        // for(int num : list)
        // {
        //     if(seen.find(num) == seen.end())
        //     {
        //         res.push_back(num);
        //         seen.insert(num);
        //     }
        // }


        // return (days - res.size());



        // 2nd approach
        // vector<bool> unreserve(days+1,false);

        // for(int i=0;i<meetings.size();i++)
        // {
        //     for(int j=meetings[i][0];j<=meetings[i][1];j++)
        //     {
        //         unreserve[j] =true;
        //     }
        // }

        // int free =0;
        // for(int i=1;i<=days;i++)
        // {
        //     if(!unreserve[i]) free++;
        // }
        // return free;
    }
};