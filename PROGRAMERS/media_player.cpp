#include <string>
#include <vector>
#include <iostream>


using namespace std;

int stotime(string &str)
{
  
    int hh,mm;
    size_t colon_pos = str.find(':');
    if(colon_pos != string::npos){
        hh = stoi(str.substr(0, colon_pos));
        mm = stoi(str.substr(colon_pos+1));
    }
    
    return hh*60 + mm;
}

string ttostr(int mmss)
{
    int mm = (mmss/60), ss = mmss%60;
    
    string str;
    str+= (mm/10)+'0';
    str+= (mm%10)+'0';
    str+=':';
    str+= (ss/10)+'0';
    str+= (ss%10)+'0';
    return str;
 
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    
    int t = stotime(pos);


    
    for(auto cmd : commands){
        if(stotime(op_start) <= t && t <= stotime(op_end)){
         t = stotime(op_end);
         }
        
        if(cmd == "next") t = t+10 > stotime(video_len) ? stotime(video_len) : t+10;
        else if(cmd =="prev") t = t-10 < 0 ? 0 : t-10;
    }
            if(stotime(op_start) <= t && t <= stotime(op_end)){
         t = stotime(op_end);
         }

    
    string answer = ttostr(t);
    return answer;
}