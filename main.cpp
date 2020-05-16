#include<bits/stdc++.h>
using namespace std;

int card[4][15];
int N;
vector<string> ans_list;

void print(){
    N++;
    cout<<"I found available case!!"<<'\n';
    for(auto ans : ans_list){
        cout<<ans<<'\n';
    }
    cout<<"End case."<<'\n';
}

bool isclear(){
    bool flag = true;
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
            if(card[i][j]) flag = false;
        }
    }
    return flag;
}

void dfs(){
    int color = -1, num = 0;
    for(int c=0;c<4;c++){
        if(num) break;
        for(int n=1;n<=13;n++){
            if(card[c][n]){
                color=c; num=n; break;
            }
        }
    }
    
    if(!num){
        if(isclear()) print();
        return;
    }
    
    //numbers
    if(num<=11 && card[color][num+1]){
        string t="";
        card[color][num]--;
        card[color][num+1]--;
        t += to_string(color) + "/" + to_string(num) + " " + to_string(color) + "/" + to_string(num+1) +" ";
        int len = 2;
        while(card[color][num+len] && num+len <= 13){
            card[color][num+len]--;
            t += to_string(color) + "/" + to_string(num+len) + " ";
            ans_list.push_back(t);
            dfs();
            ans_list.pop_back();
            len++;
        }
        len--;
        
        while(len>-1){
            card[color][num+len]++;
            len--;
        }
    }
    //colors
    int c_avail=0;
    int c_avail_list[6] = {-1,-1,-1,-1,-1,-1};
    for(int i=0;i<4;i++){
        if(card[i][num]){
            c_avail_list[c_avail++]=i;
        }
    }
    if(c_avail==3){
        string t = "";
        for(int i=0;i<3;i++){
            card[c_avail_list[i]][num]--;
            t += to_string(c_avail_list[i]) + "/" + to_string(num) + " ";
        }
        ans_list.push_back(t);
        dfs();
        ans_list.pop_back();
        for(int i=0;i<3;i++){
            card[c_avail_list[i]][num]++;
        }
    }
    if(c_avail==4){
        for(int i=0;i<4;i++){
            if(color==i) continue;
            
            string t = "";
            for(int j=0;j<4;j++){
                if(i==j) continue;
                card[j][num]--;
                t+=to_string(j)+"/"+to_string(num)+" ";
            }
            ans_list.push_back(t);
            dfs();
            ans_list.pop_back();
            for(int j=0;j<4;j++){
                if(j==i) continue;
                card[j][num]++;
            }
        }
    }
}

int main(){
	while(1){
		cout<<"Input cards :\n";
		for(int i=0;i<4;i++){
			for(int j=1;j<=13;j++){
				cin>>card[i][j];
			}
		}
		dfs();
		cout<<"Found "<<N<<" cases!\n";
	}
}
