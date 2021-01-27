int *BubbleSort(int *val,int len);
int *ChooseSort(int *val,int len);
int *insertSort(int *val,int len);
int *shellSort(int *val,int len,int dis);
int *mergeSort(int *val,int left,int right,int *tmp);
int *quickSort(int *val,int left,int right);
int *heapSort(int *val,int len);
int *countSort(int *val,int len);

int *BubbleSort(int *val,int len){
    int i,j;
    for(i = 0;i<len;i++){
        for(j = len -2;j >= i;j--){
            if(val[j] > val[j + 1])
                swap(&val[j],&val[j+1]);
        }
    }
    return val;
}
int *ChooseSort(int *val,int len){
    int i,j,max;
    for(i = len-1;i >= 0;i--){
        max = i;
        for(j = 0;j <= i;j++){
            if(val[max] < val[j])
                max = j;
        }
        swap(&val[i],&val[max]);
    }
    return val;
}
int *insertSort(int *val,int len){
    int i,j,tmp;
    for(i = 1;i < len;i++){
        for(j = i-1,tmp = i;val[tmp] < val[j] && j > -1;j--,tmp--){
            swap(&val[tmp],&val[j]);
        }
    }
    return val;
}
int *shellSort(int *val,int len,int dis){
    int i,j,tmp;
    for(;dis >= 1;dis--){
        for(i = 0;i < len / dis;i++){
            for(j = i-dis,tmp = i;val[tmp] < val[j] && j> -1;j -= dis,tmp-=dis){
                swap(&val[tmp],&val[j]);
            }
        }
    }
    return val;
}
int *mergeSort(int *val,int left,int right,int *tmp){
    if(left < right){
        mergeSort(val,left,(right + left) /2,tmp);
        mergeSort(val,(right + left)/2 + 1,right,tmp);
    }
    if(left == right)
        return NULL;
    int p1 = left,p2 = (right + left)/2 + 1,pTmp = left;
    while(p1 <= (right + left) /2 && p2 <= right){
        if(val[p1] > val[p2])
            tmp[pTmp++] = val[p2++];
        else
            tmp[pTmp++] = val[p1++];
    }
    while(p1 <= (right + left) /2)
        tmp[pTmp++] = val[p1++];
    while(p2 <= right)
        tmp[pTmp++] = val[p2++];
    for(int k = left;k <= right;k++)
        val[k] = tmp[k];
    return tmp;
}
int *quickSort(int *val,int left,int right){
    if(left >= right)
        return NULL;
    int p1 = left,p2 = right;
    int chosen = val[p1];
    while (p1 < p2){
        while(chosen < val[p2] && p1 < p2)
            p2--;
        swap(&val[p1],&val[p2]);
        while(chosen > val[p1] && p1 < p2)
            p1++;
        swap(&val[p1],&val[p2]);
    }
    swap(&val[p1],&chosen);
    quickSort(val,left,(left + right)/2);
    quickSort(val,(left + right)/2 + 1,right);
    return val;
}
int *heapSort(int *val,int len){
    int i,j,parent,div;
    for(i = 0,div = 0;i < len;i++,div++){
        for(j = len-div-1;j > -1;j--){
            parent = j/2;
            if(val[parent] < val[j])
                swap(&val[parent],&val[j]);
        }
        swap(&val[0],&val[len-1-div]);
    }
    return val;
}
int *countSort(int *val,int len){
    int max = maxInAll(val,len);
    int div = 1,count = 1;
    int i,j;
    while(max /= 10){
        div *= 10;
        count++;
    }
    int tmp[len][10];
    for(int row = 0;row < len;row++)
        for(int col = 0;col < 10;col++)
            tmp[row][col] = 0;
    int idex[10] = {0},pos;
    for(i = 0;i < count;i++,div /= 10){
        for(j = 0;j < len;j++){
            pos = val[j] / div;
            tmp[idex[pos]++][pos] = val[j];
        }
        int pVal = 0;
        for(int row = 0;row < len;row++)
            for(int col = 9;col >= 0;col--){
                if(tmp[row][col] != 0 && pVal < len)
                    val[pVal++] = tmp[row][col];
                tmp[row][col] = 0;
            }

    }
    return val;
}