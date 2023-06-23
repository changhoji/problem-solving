#include <iostream>
using namespace std;

class PrimeFactor {
  private:
    int two;
    int five;

  public:
    PrimeFactor(){
        this->two = 0;
        this->five = 0;
    }
    PrimeFactor(int two, int five){
        this->two = two;
        this->five = five;
    }
    PrimeFactor(int n){
        this->two = 0;
        this->five = 0;

        while(n % 2 == 0){
            this->two += 1;
            n /= 2;
        }
        while(n % 5 == 0){
            this->five += 1;
            n /= 5;
        }
    }

    void IncreaseTwo(){
        two += 1;
    }
    void IncreaseFive(){
        five += 1;
    }

    int getZeros(){
        return this->two < this->five ? this->two : this->five;
    }

    PrimeFactor& operator+=(PrimeFactor pf){
        this->two += pf.two;
        this->five += pf.five;

        return *this;
    }
};

int main(){
    int N;
    cin >> N;

    PrimeFactor sum;

    for(int i = 1; i <= N; i++){
        sum += PrimeFactor(i);
    }

    cout << sum.getZeros() << '\n';

    return 0;
}
