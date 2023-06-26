#include <iostream>
#include <vector>
using namespace std;

class Person{
  private:
    int weight;
    int height;
    int sizeRank;

  public:
    Person(int weight, int height): weight(weight), height(height) {}

    int GetWeight(){ 
        return weight; 
    }

    int GetHeight(){ 
        return height; 
    }

    int GetSizeRank(){
        return sizeRank;
    }

    void SetWeight(int weight){
        this->weight = weight;
    }

    void SetHeight(int height){
        this->height = height;
    }

    void SetSizeRank(int sizeRank){
        this->sizeRank = sizeRank;
    }

    bool HaveBiggerSize(Person *person){
        return (weight > person->weight && height > person->height);
    }
};

class Group{
  private:
    vector<Person*> people;

  public:
    Group(){
        people.clear();
    }

    void AppendPerson(Person *person){
        people.push_back(person);
    }

    void CalculateSizeRanks(){
        for(int i = 0; i < people.size(); i++){
            int rank = 1;
            for(int j = 0; j < people.size(); j++){
                if(i == j) continue;
                if(people[j]->HaveBiggerSize(people[i])) rank++;
            }
            people[i]->SetSizeRank(rank);
        }
    }

    void ShowSizeRanks(){
        for(auto p: people){
            cout << p->GetSizeRank() << ' ';
        }
        cout << '\n';
    }
};

int main(){
    int N;
    cin >> N;

    Group* group = new Group();

    int w, h;
    for(int i = 0; i < N; i++){
        cin >> w >> h;
        group->AppendPerson(new Person(w, h));
    }
    group->CalculateSizeRanks();

    group->ShowSizeRanks();

    return 0;
}
