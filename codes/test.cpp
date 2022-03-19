#include<iostream>
#define MAX 30
#define INF 9999

using namespace std;

class MST{
    int n,a[MAX][MAX],f[MAX];
public:
    MST();
    void kruskal();
    int Set(int);
    bool joint(int,int);
};

MST::MST(){
    cout<<"Enter the no. of vertices : ";
    cin>>n;
    cout<<"\nEnter the weighted adjacency matrix of the graph"<<endl;
    for(int i=0;i<n;i++){
        f[i]=-1;
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(!a[i][j])
                a[i][j]=INF;
        }
    }
    cout<<"\nThe sequence of edges in the MST are as follows"<<endl;
    kruskal();
}

void MST::kruskal(){
    int m,c=0,e=0,x,y;
    cout<<"\nEdge       Weight"<<endl;
    while(e<n-1){
        m=INF;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]<m){
                    m=a[i][j];
                    x=i;
                    y=j;
                }
            }
        }
        if(joint(x,y)){
            cout<<"("<<char(65+x)<<","<<char(65+y)<<")  -->   "<<m<<endl;
            e++;
            c+=m;
        }
        a[x][y]=a[y][x]=INF;
    }
    cout<<"\nTotal MST weight : "<<c<<endl;
}

int MST::Set(int x){
    while(f[x]!=-1)
        x=f[x];
    return x;
}

bool MST::joint(int x,int y){
    int i=Set(x),j=Set(y);
    if(i!=j){
        f[j]=i;
        return true;
    }
    return false;
}

int main(){
    int c;
    do{
        MST m;
        cout<<"\nDo you want to find another MST 1/0 : ";
        cin>>c;cout<<endl;
    }while(c);
    return 0;
}
