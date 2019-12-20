//
// Created by 이석규 on 2019/12/08.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
vector<string> split(string str, char delimeter);
vector<string> solution(vector<string> record);

int main(){
    vector<string> record;
    vector<string> answer;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");
    answer = solution(record);
    for (int i = 0; i < answer.size(); ++i) {
        cout<<answer.at(i);
    }
    cout<<"changes for github";
}
vector<string> solution(vector<string> record) {

    vector<string> answer;

    class account{
    public:
        string order;
        string id;
        string nickname;
        account(string order, string id, string nickname){
            this->order = order;
            this->id = id;
            this->nickname = nickname;
        }
    };
    vector<string> temp;
    vector<account> accVec;
    vector<account> beforeAns;
    int nameNum;
    for (int i = 0; i < record.size(); ++i) {
        string toParse = record.at(i);
        temp = split(record.at(i),' ');

        cout<<temp.at(0)<<endl;
        if(temp.size()==3)
        accVec.push_back(account(temp.at(0),temp.at(1),temp.at(2)));
        else{
            accVec.push_back(account(temp.at(0),temp.at(1),"."));
        }
    }
    for (int i = 0; i < record.size(); ++i) {
        if (accVec.at(i).order == "Enter") {
            for (int j = 0; j< answer.size(); ++j) {
                if(beforeAns.at(j).id == accVec.at(i).id) {
                    beforeAns.at(j).nickname = accVec.at(i).nickname;
                    if(beforeAns.at(j).order == "Enter")
                        answer.at(j) = beforeAns.at(j).nickname + "님이 들어왔습니다.";
                    else if(beforeAns.at(j).order == "Leave")
                        answer.at(j) = beforeAns.at(j).nickname + "님이 나갔습니다.";
                }
            }
            beforeAns.push_back(accVec.at(i));
            answer.push_back(accVec.at(i).nickname + "님이 들어왔습니다.");
        } else if (accVec.at(i).order == "Leave") {
            for (int j = 0; j< answer.size(); ++j) {
                if(beforeAns.at(j).id == accVec.at(i).id) {
                    accVec.at(i).nickname = beforeAns.at(j).nickname;
                }
            }
            beforeAns.push_back(accVec.at(i));
            answer.push_back(accVec.at(i).nickname + "님이 나갔습니다.");
        } else if (accVec.at(i).order == "Change") {
            for (int j = 0; j< answer.size(); ++j) {
                if(beforeAns.at(j).id == accVec.at(i).id){
                    beforeAns.at(j).nickname = accVec.at(i).nickname;
                    if(beforeAns.at(j).order=="Enter"){
                        answer.at(j) = beforeAns.at(j).nickname +"님이 들어왔습니다.";
                    }
                    if(beforeAns.at(j).order=="Leave"){
                        answer.at(j) = beforeAns.at(j).nickname +"님이 나갔습니다.";
                    }

                }
            }
        }
    }
    return answer;
}

vector<string> split(string str, char delimeter){
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while(getline(ss, temp, delimeter)){
        internal.push_back(temp);
    }
    return internal;
}