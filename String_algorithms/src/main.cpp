//
// Created by horsetif on 19-4-25.
//
#include <base_include.h>
#include <LSD.h>
#include <MSD.h>
#include <Quick3string.h>
#include <hashtable.h>
int main(){
    vector<string> test_data;
    for(int i =0 ;i < 40; i++){
        string temp = "";
        for(int j = 0;j < 10; j++){
            temp.push_back('a'+rand()%26);
        }
        test_data.push_back(temp);
    }


}
