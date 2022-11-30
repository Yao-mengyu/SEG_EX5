#include "policy.h"
#include <assert.h>
//--------------------------------initial---------------------------------//
Policy::Policy(string eq_file){
    this ->file_map.clear();
    this ->neq_vec.clear();
   // this ->doubt.clear();
    this ->equal_file = eq_file;
    this ->file.open(equal_file,ios::in);
    this ->w = NULL;
    this -> doubt_scope = false;
}

//-------------------------并查集操作-----------------------------//

static my_file* init_file(){
    struct my_file* new_file = new my_file();
    new_file ->father = new_file;// 初始是自己
   // new_file ->size = 1;
   return new_file;
}

static my_file* find(my_file* file){
    if (file == NULL) assert(0);
    if(file ->father == file) return file;
    else {
        file ->father = find(file ->father);
        return file ->father;
    }
}

static bool judge_union(my_file* file1, my_file* file2){
    my_file* p1 = find(file1);
    my_file* p2 = find(file2);
    if(p1 == p2) return true;
    return false;
}

static void union_file(my_file* file1, my_file* file2){
    my_file* p1 = find(file1);
    my_file* p2 = find(file2);
    if(p1 == p2) return;
   // if(p1->size )
    p1->father = p2;
}

// 对于所有的等价条目，先进行该判断，保证一定会创建对应实例my_file
bool Policy::need_judge(string file1_name, string file2_name){
    assert(!file1_name.empty()&&!file2_name.empty());
    my_file *file1, *file2;//一定会创建对应选项
    //注意代码复用
    if (!this->file_map.count(file1_name)){
       // cout<<"add 1"<<endl;
        file1 = init_file();
        this->file_map.emplace(make_pair(file1_name, file1));
    }else{
        file1 = this->file_map[file1_name];
    }

    if (!this->file_map.count(file2_name)){
        file2 = init_file();
        this->file_map.emplace(make_pair(file2_name, file2));
    }else{
        file2 = this->file_map[file2_name];
    }

    if(judge_union(file1, file2))return false;
    if(judge_in_neq(file1, file2)){
        return false;
    }
   // cout<<file_map.size()<<endl;
    return true;
}

bool Policy::judge_in_neq(my_file* file1, my_file* file2){
    for(auto i = this->neq_vec.begin(); i != this->neq_vec.end(); i++){
        if(judge_union(i->first, file1) && judge_union(i->second, file2)){
            return true;
        }
    }
    return false;
}

void Policy::update_result(string file1_name, string file2_name, bool manual_judge){
    assert(!file1_name.empty()&&!file2_name.empty());
    // cout<<this->file_map.size()<<endl;
    my_file* file1 = file_map[file1_name];
    my_file* file2 = file_map[file2_name];
    if(file1 == NULL || file2 == NULL){
        cout<<"Error! Uninitialized file in function updata_result!"<<endl;
        return;
    }
    if(manual_judge == false){
        this ->neq_vec.emplace_back(make_pair(find(file1), find(file2)));
        this ->neq_vec.emplace_back(make_pair(find(file2), find(file1)));
    }else{
        union_file(file1, file2);
    }
}

bool Policy::final_eq(string file1_name, string file2_name){
    assert(!file1_name.empty()&&!file2_name.empty());
    my_file* file1 = this->file_map[file1_name];
    my_file* file2 = this->file_map[file2_name];
   // cout<<file1_name<<endl<<file2_name<<endl;
    if(file1 == NULL || file2 == NULL){
        cout<<"Error! Uninitialized file in function final_eq!"<<endl;
        assert(0);
    }
    if(judge_union(file1, file2)) return true;
    return false;
}

//对存疑文件对进行留存
void Policy::reserve_doubt(string file1_name, string file2_name){
    assert(!file1_name.empty()&&!file2_name.empty());
    if(!doubt_scope)this->doubt.push(make_pair(file1_name, file2_name));
    else{this->double_doubt.push(make_pair(file1_name, file2_name));}
}

// 获取下一对需要比较的文件名pair
pair<string, string> Policy::get_nxt_pair(){
    string strLine;
    if(getline(file,strLine)){
        auto semi = strLine.find(",");
        return make_pair(strLine.substr(0, semi), strLine.substr(semi+1, strLine.size()));
    }else{
        if(!doubt.empty()){
            pair<string, string> to_judge = doubt.front();
            doubt.pop();
            while(!need_judge(to_judge.first, to_judge.second)&&!doubt.empty()){
                to_judge = doubt.front();
                doubt.pop();
            }
            if(doubt.empty()&&!need_judge(to_judge.first, to_judge.second)){
                return make_pair("", "");
            }else{
                if(!doubt_scope){
               // QMessageBox::StandardButton ret;
                QMessageBox::warning(nullptr, "提示", "以下出现的是曾经存疑过的程序对，请谨慎比对",QMessageBox::Ok);}
                doubt_scope = true;  
                return to_judge;
            }
        }
        else{
            return make_pair("", "");
        }
    }
}

