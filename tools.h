void swap(int *a,int *b);
int maxInAll(int *val,int len);
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int maxInAll(int *val,int len){
    int max = val[0];
    for(int i = 0;i < len;i++)
        if(max < val[i])
            max = val[i];
    return max;
}