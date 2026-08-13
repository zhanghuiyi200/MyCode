#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string test(string a,string b){
    bool neg=false;
    if(a.size()<b.size()){
        neg=true;
        swap(a,b);
    }else if(a.size()==b.size()&&a<b){
        neg=true;
        swap(a,b);
    }
	string ans="";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int len=max(a.size(),b.size());
	int flag=0;
	for(int i=0;i<len;i++){
		int temp=0;
		if(i<a.size())temp+=a[i]-'0';
		temp -= flag;
		flag=0;
		if(i<b.size())temp-=b[i]-'0';

		if(temp<0){
			flag=1;
			temp+=10;
		}
		ans+=temp+'0';
	}
	reverse(ans.begin(),ans.end());
	while(ans.size()>1&&ans[0]=='0'){
		ans.erase(0,1);
	}
    if(neg) ans="-"+ans;
	return ans;
}

int main(){
	string a,b;
	cin>>a>>b;
	cout<<test(a,b)<<endl;
	return 0;
}