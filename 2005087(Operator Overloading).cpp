#include <iostream>
using namespace std;

class Time
{
private:
    int hours, minutes,seconds;
public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds=0;
    }

    Time(int hr, int mn,int sc)
    {
        hours = hr;
        minutes = mn;
        seconds=sc;
    }

    friend ostream &operator<<(ostream &output, Time &t);
    friend istream &operator>>(istream &input,  Time &t);

    // your code
    Time operator+(Time t)
    {
        Time Temporary;
        Temporary.hours=hours+t.hours;
        Temporary.minutes=minutes+t.minutes;
        Temporary.seconds=seconds+t.seconds;
        return Temporary;
    }

    Time operator=(Time t)
    {
        hours=t.hours;
        minutes=t.minutes;
        seconds=t.seconds;
        return *this;
    }

    Time operator+(int n)
    {
        Time Temporary;
        Temporary.hours=hours;
        Temporary.minutes=minutes+n;
        Temporary.seconds=seconds;
        return Temporary;
    }

    friend Time operator+(int n,Time t);

    bool operator>(Time t)
    {
        if(hours!=t.hours)return hours>t.hours;
        else return minutes>t.minutes;
    }

    Time operator+=(Time t)
    {
        hours+=t.hours;
        minutes+=t.minutes;
        seconds+=t.seconds;
        return *this;
    }

};

// your code
Time operator+(int n,Time t)
{
    Time Temporary;
    Temporary.hours=4+t.hours;
    Temporary.minutes=t.minutes;
    Temporary.seconds=t.seconds;
    return Temporary;
}

ostream &operator<<(ostream &output, Time &t)
{
    if(t.seconds>=60)
    {
        int I=t.seconds/60;
        t.minutes+=I;
        t.seconds-=(I*60);

    }
    if(t.minutes>=60)
    {
        int I=t.minutes/60;
        t.hours+=I;
        t.minutes-=(I*60);

    }
    output << "Hours: " << t.hours << " Minutes: " << t.minutes <<" Seconds: "<<t.seconds<< endl;
    return output;
}

istream &operator>>(istream  &input, Time &t)
{
    cout << "Enter hours and minutes: ";
    input >> t.hours >> t.minutes >> t.seconds;
    return input;
}

int main()
{
    Time t1, t2, t3, t4, t5, t6;
    cin >> t1;          // take input for hours and minutes of t1
    cin >> t2;          // take input for hours and minutes of t2
    cout << t1;         // output hours and minutes of t1
    cout << t2;         // output hours and minutes of t2
    t3 = t1 + t2;       // t3 is the sum of t1 and t2
    cout << t3;         // output hours and minutes of t3
    t4 = t1 + t2 + t3;  // t4 is the sum of t1, t2, and t3
    cout << t4;         // output hours and minutes of t4
    t5 = t1 + 3;        // t5 is t1 plus 3 minutes
    cout << t5;         // output hours and minutes of t5
    t6 = 4 + t1;        // t6 is t1 plus 4 hours
    cout << t6;         // output hours and minutes of t6
    if(t1 > t2)         // compare t1 and t2
        cout << "t1 is greater than t2" << endl;
    else
        cout << "t1 is less than (or equal to) t2" << endl;
    t1+=t2;             // t1 is t1 plus t2
    cout << t1;         // output hours and minutes of t1
    return 0;
}

/* sample output
Enter hours and minutes: 2 45
Enter hours and minutes: 3 55
Hours: 2 Minutes: 45
Hours: 3 Minutes: 55
Hours: 6 Minutes: 40
Hours: 13 Minutes: 20
Hours: 2 Minutes: 48
Hours: 6 Minutes: 45
t1 is less than (or equal to) t2
Hours: 6 Minutes: 40
*/
