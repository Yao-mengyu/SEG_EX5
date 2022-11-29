#ifndef POLICY_H
#define POLICY_H


#include <iostream>
#include <map>
#include <vector>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include <fstream>
#include <queue>
using namespace std;
struct my_file{
    //string name;
    struct my_file* father;
    //int size;
};
class Policy{
    private:
        vector<pair<my_file*, my_file*>> neq_vec;
        map<string, my_file*>file_map;
        bool judge_in_neq(my_file* file1, my_file* file2);
        queue<pair<string, string>>doubt;
        ifstream file;

    public:
        bool need_judge(string file1_name, string file2_name);
        void update_result(string file1_name, string file2_name, bool manual_judge);
        bool final_eq(string file1_name, string file2_name);
        void reserve_doubt(string file1_name, string file2_name);
        pair<string, string>get_nxt_pair();//如果返回pair<"", "">则说明没有需要比对的pair了
        Policy(string eq_file);
        string equal_file;
};

#endif // POLICY_H
