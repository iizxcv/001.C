#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

class Parking_car
{
public:
    string id = "";
    int accum_time = 0;

    void process_car(int h_time, int m_time, string state, string id_)
    {
        parking(state);
        if (parked == true)
            in_time = to_minutes(h_time, m_time);
        else
        {
            out_time = to_minutes(h_time, m_time);
            calc_minutes();
        }
        if (id == "")
        {
            id = id_;
        }
    }

    bool check_parking() const
    {
        return parked;
    }

private:
    int in_time = 0;
    int out_time = 0;
    bool parked = false;

    void parking(string in_out)
    {
        if (in_out == "IN")
            parked = true;
        else if (in_out == "OUT")
            parked = false;
    }

    int to_minutes(int h, int m)
    {
        return h * 60 + m;
    }

    void calc_minutes()
    {
        accum_time += (out_time - in_time);
        in_time = out_time = 0;
    }
};

class Parking_system
{
public:
    void set(const vector<int> &fees_, const vector<string> &records_)
    {
        base_time_ = fees_[0];
        base_fee_ = fees_[1];
        over_time_ = fees_[2];
        over_fee_ = fees_[3];
        p_cars.clear();
        init_p_cars(records_);
        process_still_in_car();
    }

    void process_record(const string &line)
    {
        istringstream iss(line);
        string time, id, state;
        // parking_system에서 ID기반으로 접근해야함
        int h_time, m_time;

        iss >> time >> id >> state;
        h_time = stoi(time.substr(0, 2));
        m_time = stoi(time.substr(3, 2));

        auto &car = p_cars[id];
        car.process_car(h_time, m_time, state, id);
    }

    void init_p_cars(const vector<string> &records)
    {
        for (auto &reco : records)
        {
            process_record(reco);
        }
    }

    void process_still_in_car()
    {
        const int end_of_day_h = 23;
        const int end_of_day_m = 59;
        for (auto &kv : p_cars)
        {
            Parking_car &car = kv.second;
            if (car.check_parking())
            {
                car.process_car(end_of_day_h, end_of_day_m, "OUT", car.id);
            }
        }
    }

    vector<int> compute_fees_by_id()
    {
        vector<int> compute_ans;
        vector<pair<string, Parking_car>> items;
        for (const auto &kv : p_cars)
            items.push_back(kv);
        sort(items.begin(), items.end(), [](const pair<string, Parking_car> &a, const pair<string, Parking_car> &b)
             { return a.first < b.first; });
        for (auto &kv : items)
        {
            compute_ans.push_back(calc_fee(kv.second.accum_time));
        }
        return compute_ans;
    }

private:
    unordered_map<string, Parking_car> p_cars;
    int base_time_{}, base_fee_{}, over_time_{}, over_fee_{};

    int calc_fee(int minutes) const
    {
        if (minutes <= base_time_)
            return base_fee_;
        int extra = minutes - base_time_;
        int units = (extra + over_time_ - 1) / over_time_;
        return base_fee_ + (units * over_fee_);
    }
};

vector<int> solution(vector<int> fees, vector<string> records)
{

    Parking_system a;
    a.set(fees, records);

    vector<int> answer;
    // a.compute_fees_by_id(answer);
    answer = a.compute_fees_by_id();
    return answer;
}

int main()
{
    std::vector<int> fees = {120, 0, 60, 591};
    std::vector<std::string> records = {
        "16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT", "23:58 3961 IN"};
    vector<int> ans;
    ans = solution(fees, records);

    for (auto &a : ans)
    {
        cout << a << ",";
    }
    return 0;
}