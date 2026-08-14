#include<iostream>
#include<algorithm>
#include<string>
#include"High_precision.h"
using namespace std;

string add(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string ans="";
	int flag=0;
	int len=max(a.size(),b.size());
	for(int i=0;i<len;i++){
		int temp=0;
		if(i<a.size()){
			temp+=a[i]-'0';
		}
		if(i<b.size()){
			temp+=b[i]-'0';
		}
		temp+=flag;
		ans+=(temp%10)+'0';
		flag=temp/10;
	}
	if(flag){
		ans+=(flag)+'0';
	}
	reverse(ans.begin(),ans.end());
	while(ans.size()>1&&ans[0]=='0'){
		ans.erase(0,1);
	}
	return ans;
}

string minus(string a,string b){
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

string mul(string a,string b){
    if(a=="0" || b=="0")return "0";
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    size_t lena=a.size();
    size_t lenb=b.size();
    string res(lena+lenb+1,'0');
    for(size_t i=0;i<lena;i++){
        uint64_t carry=0;
        for(size_t j=0;j<lenb || carry;j++){
            uint64_t curr=res[i+j]-'0';
            if(j<lenb)curr+=(uint64_t)(a[i]-'0')*(b[j]-'0');
            curr+=carry;
            res[i+j]=(char)(curr%10+'0');
            carry=curr/10;
        }
    }
    while(res.size()>1 && res.back()=='0')res.pop_back();
    reverse(res.begin(),res.end());
    return res;
}

string division(string a,string b){
	
}

string mod(string a,string b){
	
}

string compare(string a,string b,string cmp){
   
}
