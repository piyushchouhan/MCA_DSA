#include<iostream>
using namespace std;
int print_LCS(int i,int j,int B[][j] ,char a[]) {
    if(i==0||j==0){
        return 0;
    }
    if(B[i][j]=='<'){
        print_LCS(i-1,j-1,B,a);
        cout<<a[i]<<endl;
    }else if(B[i][j]=='^'){
        print_LCS(i-1,j,B,a);
    }else{
        print_LCS(i,j-1,B,a);
    }
}
void LCS_Length(int n,int m,char a[], char b[]){
    int c[n][m];
    char B[n][m];
    for(int i=1;i<=n;i++){
        c[i][0]=0;
    }
    for(int j=1;j<=m;j++){
        c[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[i]){
                c[i][j]=c[i-1][j-1]+1;
                B[i][j]='<';
            }else if(c[i-1][j]>=c[i][j-1]){
                B[i][j]='^';
            }else{
                c[i][j]=c[i][j-1];
                B[i][j]='>';
            }
        }
    }
    print_LCS(n,m,B,a);
}
int main(){
    int n,m;
    cout<<"enter total number of elements in first array";
    cin>>n;
    char a[n];
    cout<<"enter the elements of first array";
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<"enter total number of elements in second array";
    cin>>m;
    char b[m];
    cout<<"enter the elements of second array";
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    cout<<" elements of first array";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"elements of second array";
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    LCS_Length(n,m,a,b);
}