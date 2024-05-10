#include<bits/stdc++.h>
using namespace std;

string convertTo12HourFormat(int hour, int minute) {
  std::stringstream ss;
  std::string period = (hour >= 12) ? "PM" : "AM";

  hour = (hour > 12)   ? hour - 12
         : (hour == 0) ? 12  : hour;   
  ss << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2)
     << minute << " " << period;
  return ss.str();
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
    string s;
    cin >> s;
     
    cout << convertTo12HourFormat(stoi(s.substr(0,2)), stoi(s.substr(3,2))) << endl;
  }

  return 0;
}