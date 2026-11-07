class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //Available servers: {weight, index}
        //Smallest weight gets highest priority
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> available;

        //Busy servers: {freeTime, weight, index}
        //Earliest free time gets highest priority
        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> busy;

        int n=servers.size();
        int m=tasks.size();

        //all servers are available
        for(int i=0;i<n;i++){
            available.push({servers[i], i});
        }

        vector<int> ans(m);
        //Current time cannot be earlier than task arrival
            long long time =0;
        //Process tasks in their given order
        for(int i=0;i<m;i++){
            time = max(time, (long long)i);
            //Release all servers that have completed their tasks
            while(!busy.empty() && get<0>(busy.top())<= time){
                auto [freeTime, weight, index] = busy.top();
                busy.pop();
                available.push({weight, index});
            }

            //If no server is available, wait for the earliest one
            if (available.empty()){
                time = get<0>(busy.top());
                //Release all servers available at this new time
                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();
                    available.push({weight, index});
                }
            }

            // Select server with minimum weight, then minimum index
            auto [weight, index] = available.top();
            available.pop();

            // Store the selected server index for this task
            ans[i]=index;

            //Server becomes free after completing the current task
            busy.push({time+tasks[i], weight, index});
        }

        return ans;
    }
};