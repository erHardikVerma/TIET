#include<iostream>
#include<cmath>
#include<algorithm>
#define MAX 8
using namespace std;

bool used[MAX] = {0,0,0,0,0,0,0,0};

#if 0
//sstf
int ret(int* arr, int ptr){
    int min = 1e6;
    int result = -1;
    int idx = -1;
    for(int i = 0 ; i < MAX ; i++){
        int diff = abs(arr[i]-ptr);
        if(diff < min && !used[i]){
            min = diff;
            result = arr[i];
            idx = i;
        }
    }
    used[idx] = 1;
    return result;
}
#endif

bool check(bool* arr){
    for(int i = 0 ; i < MAX ; i++){
        if(arr[i] == 0) return 1;   
    }
    return 0;
}

int main(){
    
    int q[MAX] = {98,183,37,122,14,124,65,67};
    int ptr = 53;
    
    int mov = 0;
    
    #if 0
    for(int i = 0 ; i < MAX ; i++){
        mov += abs(q[i]-ptr);
        ptr = q[i];
        cout << ptr << endl;
    }
    #endif
    
    #if 0
    while(check(used)){
        int data = ret(q, ptr);
        mov += abs(ptr-data);
        cout << data << endl;
        ptr = data;
    }
    #endif
    
    sort(q, q+MAX);
    
    #if 1
    int start = -1;
    for(int i = 0 ; i < MAX ; i++){
        if(q[i] > ptr){
            start = i;
            break;
        }
    }
    ptr = 53;
    #endif
    
    #if 0
    //cscan
    while(check(used)){
        mov += abs(q[start] - ptr);
        used[start] = 1;
        cout << q[start] << endl;
        ptr = q[start];
        start = (start+1)%MAX;
    }
    #endif
    
    int iter = start-1;
    int forward = 0;
    while(check(used)){
        mov += abs(q[iter] - ptr);
        used[iter] = 1;
        cout << q[iter] << endl;
        ptr = q[iter];
        
        if(iter == 0){
            iter = start;
            forward = 1;
            continue;
        }
        if(forward) iter++;
        else iter--;
    }
    
    cout << mov;
    
    return 0;
}
