#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <bits/stdc++.h>
#include <deque>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <bits/stdc++.h>
#include <numeric>
# define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mach_id_global = 0;
int user_id_global = 0;

class Machine {
public:
    int mach_id = 0;
    string mach_name = "";
    float cpu_count;
    float mem_count;
    float cpu_use = 0;
    float mem_use = 0;
    float com_pow_cpu;
    float com_pow_mem;
    float static_power;
    float max_power;
    Machine(string mach_name_c,float cpu_count_c,float mem_count_c,float com_pow_cpu_c,float com_pow_mem_c,float static_power,float max_power){
        mach_id = mach_id_global++;
        mach_name = mach_name_c;
        cpu_count = cpu_count_c;
        mem_count = mem_count_c;
        com_pow_cpu = com_pow_cpu_c;
        com_pow_mem = com_pow_mem_c;
        static_power = static_power;
        max_power = max_power;
    }
};

class User {
public:
    int user_id = 0;
    string user_name = "";
    int task_count;
    int task_run = 0;
    float cpu_require;
    float mem_require;
    float cpu_com_pow_allocate;
    float mem_com_pow_allocate;
    float DR_share = 0;
    string DR = "";
    User(string user_name_c,int task_count_c,float cpu_require_c,float mem_require_c){
        user_id = user_id_global++;
        user_name = user_name_c;
        task_count = task_count_c;
        cpu_require = cpu_require_c;
        mem_require = mem_require_c;
    }
};

float cal_score_k8s_LeastRequestedPriority(Machine* mach,User* user){
    // cout<<"机器id为："<<mach->mach_id<<"    ";
    // cout<<"机器名称为："<<mach->mach_name<<"    ";
    float sc_mach = 0;
    if(mach->cpu_count - mach->cpu_use - user->cpu_require < 0 || mach->mem_count - mach->mem_use - user->mem_require < 0){
        sc_mach = 0;
    }else{
        sc_mach = ((mach->cpu_count - mach->cpu_use - user->cpu_require)/mach->cpu_count + (mach->mem_count - mach->mem_use - user->mem_require)/mach->mem_count)*5;
    }
    // printf("机器的得分为：((%.0f-%.0f-%.0f)/%.0f + (%.0f-%.0f-%.0f)/%.0f)*5 = %.3f",mach->cpu_count,mach->cpu_use,user->cpu_require,mach->cpu_count, mach->mem_count,mach->mem_use,user->mem_require,mach->mem_count, sc_mach);
    // cout<<endl;
    return sc_mach;
    
}

void mach_list_print(vector<Machine*> mach_list){
    for(auto &mach:mach_list){
        cout<<"机器id为："<<mach->mach_id<<"    ";
        cout<<"机器名称为："<<mach->mach_name<<"    ";
        cout<<"总cpu个数为："<<mach->cpu_count<<"    ";
        cout<<"每个cpu的算力为："<<mach->com_pow_cpu<<"    ";
        cout<<"总内存为："<<mach->mem_count<<"    ";
        cout<<"每GB内存的存力为："<<mach->com_pow_mem<<"    ";
        cout<<endl;
    }
}

void mach_list_detail_print(vector<Machine*> mach_list){
    for(auto &mach:mach_list){
        cout<<"机器id为："<<mach->mach_id<<"    ";
        cout<<"机器名称为："<<mach->mach_name<<"    ";
        cout<<"总cpu个数为："<<mach->cpu_count<<"    ";
        cout<<"总内存为："<<mach->mem_count<<"    ";
        cout<<"cpu使用量为："<<mach->cpu_use<<"    ";
        cout<<"内存使用量为："<<mach->mem_use<<"    ";
        cout<<endl;
    }
}

void user_list_print(vector<User*> user_list){
    for(auto &user:user_list){
        cout<<"用户id为："<<user->user_id<<"    ";
        cout<<"用户名称为："<<user->user_name<<"    ";
        cout<<"用户任务个数为："<<user->task_count<<"    ";
        cout<<"用户任务cpu需求为："<<user->cpu_require<<"    ";
        cout<<"用户任务内存需求为："<<user->mem_require<<"    ";
        cout<<"用户DR为："<<user->DR<<"    ";
        cout<<endl;
    }
}

void user_list_detail_print(vector<User*> user_list){
    for(auto &user:user_list){
        cout<<"用户id为："<<user->user_id<<"    ";
        // cout<<"用户名称为："<<user->user_name<<"    ";
        // cout<<"用户目前运行的任务个数为："<<user->task_run<<"    ";
        // cout<<"用户目前分配到的算力存力为：("<<user->cpu_com_pow_allocate<<","<<user->mem_com_pow_allocate<<")    ";
        printf("用户目前的DR share为：%.3f",user->DR_share);
        // cout<<endl;
    }
}


Machine* select_mach_for_user(User* user,vector<Machine*> mach_list){
    float score = 0;
    Machine* target_mach = nullptr;
    for(auto &mach:mach_list){
        //计算每一台机器的分数
        float sc_mach = cal_score_k8s_LeastRequestedPriority(mach,user);
        if(sc_mach > score){
            score = sc_mach;
            target_mach = mach;
        }
    }
    cout<<"选择机器为"<<target_mach->mach_name<<endl<<endl;
    return target_mach;
}

int main()
{
    //构造集群，pair为cpu和内存数量
    vector<Machine*> mach_list;
    //集群初始化
    for(int i = 0;i<20;i++){
        mach_list.push_back(new Machine("mach"+to_string(i) , 32,125,3200,2400, 40.2, 170));
    }
    for(int i = 20;i<40;i++){
        mach_list.push_back(new Machine("mach"+to_string(i), 20,187,3200,2933,22.8,100));
    }
    for(int i = 40;i<60;i++){
        mach_list.push_back(new Machine("mach"+to_string(i), 80,125,4000,2933,127.2,250));
    }
    for(int i = 60;i<80;i++){
        mach_list.push_back(new Machine("mach"+to_string(i), 4,15,3500,3200,2.4,80));
    }
    for(int i = 80;i<100;i++){
        mach_list.push_back(new Machine("mach"+to_string(i), 64,251,3900,2933,103.2,250));
    }
    // mach_list.push_back(new Machine("mach0", 32,125,3200,2400, 40.2, 170));
    // mach_list.push_back(new Machine("mach1", 20,187,3200,2933,22.8,100));
    // mach_list.push_back(new Machine("mach2", 80,125,4000,2933,127.2,250));
    // mach_list.push_back(new Machine("mach3", 4,15,3500,3200,2.4,80));
    // mach_list.push_back(new Machine("mach4", 64,251,3900,2933,103.2,250));

    //计算整个集群的总资源
    int total_cpu = 0,total_mem = 0;
    float total_com_pow_cpu = 0,total_com_pow_mem = 0;
    for(auto &mach:mach_list){
        total_cpu += mach->cpu_count;
        total_com_pow_cpu += mach->cpu_count*mach->com_pow_cpu;
        total_mem += mach->mem_count;
        total_com_pow_mem += mach->mem_count*mach->com_pow_mem;
    }

    //用户数量以及每个用户提交的任务型号
    vector<User*> user_list;
    user_list.push_back(new User("userA",3000,2,4));
    user_list.push_back(new User("userB",3000,4,3));

    //计算每个user的DR，主资源，并且初始化
    for(auto &user:user_list){
        if(user->cpu_require/total_cpu >= user->mem_require/total_mem){
            user->DR = "cpu";
        }else{
            user->DR = "mem";
        }
    }

    //打印集群资源和用户信息
    cout<<"++++++++++打印集群总资源和用户信息++++++++++"<<endl;
    //打印集群列表
    mach_list_print(mach_list);
    cout<<endl;
    cout<<"集群的总cpu为："<<total_cpu<<endl;
    cout<<"集群的总mem为："<<total_mem<<endl;
    cout<<"集群的总cpu算力为："<<total_com_pow_cpu<<endl;
    cout<<"集群的总mem存力为："<<total_com_pow_mem<<endl<<endl;
    //打印用户信息
    user_list_print(user_list);

    //为了用比较低的时间复杂度选择出应该选哪个用户，我们用堆来选择
    //排序原则，按照DR来排序，相同的按照id先后
    auto cmp_user = [&](const User* a, const User* b) {
        return a->DR_share > b->DR_share ? true : a->DR_share == b->DR_share && a->user_id > b->user_id;
    };
    priority_queue<User*,vector<User*>,decltype(cmp_user)> pq_user(cmp_user);
    for(auto &a:user_list){
        pq_user.push(a);
    }
    

    //是否要停止分配
    bool isStop = false;
    while(!isStop){
            //判断选择是否要停止
            //a1、用户所有的任务都已运行，停止分配
            bool needStop = true;
            for(auto &a:user_list){
                if(a->task_count > a->task_run){
                    needStop = false;
                    break;
                }
            }
            if(needStop == true){
                cout<<endl<<"所有用户的任务均已运行，结束调度！"<<endl;
                break;
            }
            cout<<endl<<"++++++++++开始资源分配++++++++++"<<endl;
            
            //选择应该给哪个用户分配资源
            //打印目前的用户配额信息
            user_list_detail_print(user_list);
            User* user_now = pq_user.top();
            pq_user.pop();
            //打印选择的用户情况
            cout<<"选择下一步为用户"<<user_now->user_name<<"分配资源！"<<endl;

            //选择目标机器
            //在此按照特定的调度算法选择合适的机器
            Machine* mach_now = select_mach_for_user(user_now,mach_list);
            if(mach_now == nullptr){
                //a2 资源不够，退出任务
                cout<<endl<<"无法为当前用户分配资源，资源不够，结束调度！"<<endl;
                break;
            }

            //资源分配
            //资源相应减少
            mach_list[mach_now->mach_id]->cpu_use += user_now->cpu_require;
            mach_list[mach_now->mach_id]->mem_use += user_now->mem_require;
            //用户运行任务增加，并且更新用户的share值，包括更新堆中的share值，以及更新用户列表中的share值
            user_list[user_now->user_id]->task_run++;
            if(user_list[user_now->user_id]->DR == "cpu"){
                user_list[user_now->user_id]->cpu_com_pow_allocate += mach_list[mach_now->mach_id]->com_pow_cpu*user_now->cpu_require;
                user_list[user_now->user_id]->mem_com_pow_allocate += mach_list[mach_now->mach_id]->com_pow_mem*user_now->mem_require;
                user_list[user_now->user_id]->DR_share = user_list[user_now->user_id]->cpu_com_pow_allocate/total_com_pow_cpu;
            }else{
                user_list[user_now->user_id]->cpu_com_pow_allocate += mach_list[mach_now->mach_id]->com_pow_cpu*user_now->cpu_require;
                user_list[user_now->user_id]->mem_com_pow_allocate += mach_list[mach_now->mach_id]->com_pow_mem*user_now->mem_require;
                user_list[user_now->user_id]->DR_share = user_list[user_now->user_id]->mem_com_pow_allocate/total_com_pow_mem;
            }
            pq_user.push(user_now);

            //分配完之后资源变化情况
            // mach_list_detail_print(mach_list);
            
    }
    return 1; 
}


