#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char *argv[])
{
    int limite = stoi(argv[1]);
    int count = 0;
    ifstream capacity;
    ifstream status;
    string linha;
    string linhaStatus;
    while(true){
        capacity.open("/sys/class/power_supply/BAT1/capacity");
        status.open("/sys/class/power_supply/BAT1/status");
        if(status.is_open())
        {
            while(getline(status, linhaStatus))
            {
                if(linhaStatus == "Discharging")
                {
                    if(capacity.is_open())
                    {
                        while(getline(capacity, linha))
                        {
                            if(stoi(linha)-7 < limite && count < 2)
                            {
                                system("paplay /usr/share/sounds/freedesktop/stereo/alarm-clock-elapsed.oga");
                                count++;
                            }
                        }
                    }
                }else{
                    count = 0;
                }
            }
        }
    
    capacity.close();
    status.close();
    }
    return 0;
}