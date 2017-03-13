#include <iostream>
#include <iomanip>
using namespace std;
class tome{

    friend class printer;
    double waqt;
public:
    tome(double x)
    {
        waqt = x;
    }


};
class printer{

public:
    void display(tome t)
    {
        int hour = int(t.waqt);
        int min = (t.waqt - hour)*60;
        int sec = (t.waqt-hour)*3600 - min*60;
        cout<<setw(2)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<min<<":"<<setw(2)<<setfill('0')<<sec<<endl;
    }
};

int main(){
    tome  B(2.02);
    printer p;
    p.display(B);
}
