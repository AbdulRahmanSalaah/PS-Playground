#include <bits/stdc++.h>
using namespace std;
class TimeMap
{
private:
    map<string, vector<pair<int, string>>> mp; //  mp [key] = vector<pair<timestamp, value>>

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {

        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        int l = 0, r = mp[key].size() - 1;

        if (mp.find(key) == mp.end() || mp[key].empty())
            return "";


        string res = "";

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (mp[key][mid].first == timestamp)
            {
                return mp[key][mid].second;
            }

            else if (mp[key][mid].first < timestamp)
            {
                res = mp[key][mid].second;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */