// Inflation Calculator
#include<iostream>
using namespace std;

class inflationCalculator{
    protected:
        float initialValue;
        float rate;
        int year;

    public:

    inflationCalculator(float initialVal,float r,int y):initialValue(initialVal),rate(r),year(y){}

    // Calculate Compound Interest
    float expo(float b,float p){
        float ans;
        if(p==0) return 1;
        else if(p==1) return b;
        else if(int(p)%2==0) {
            ans = expo(b,p / 2);
            return ans * ans;
        }
        else{
            ans = expo(b, (p - 1) / 2);
            return b * ans * ans;
        }
    }

    // Formula -> CI = p(1+r/100)^t;
    float calculateInflation(){
        float futureValue;
        float y = expo(1 + rate / 100,year);
        futureValue = y * initialValue;
        return futureValue;
    }

// Display
    void displayCalculator(){
        cout << "Initial Value : " << initialValue << endl;
        cout << "Rate :" << rate<<endl;
        cout << "Year :" << year << endl;
        
    }
};

int main(){
    inflationCalculator c(100, 5, 2);
    c.displayCalculator();
    cout << "FutureValue :" <<c.calculateInflation();

}