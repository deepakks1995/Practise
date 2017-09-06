

void merge_sort(long a[], int lo, int hi)
{
    if(lo < hi )
    {
        long mid = lo + (hi-lo)/2;

        merge_sort(a,lo,mid);
        merge_sort(a,mid+1,hi);
        _merge(a,lo,mid,hi);
    }
}

void _merge(long a[], int lo, int mid, int hi)
{
    long LHS[mid-lo+1];
    long RHS[hi-mid];
    int i,j;

    for(i=0,j=lo; j<=mid; i++,j++)
        LHS[i] = a[j];
    for(i=0,j=mid+1; j<=hi; i++,j++)
        RHS[i] = a[j];
    int k=lo;
    i=0;
    j=0;
    while(i<mid-lo+1 && j<hi-mid)
    {
        if( LHS[i] <= RHS[j] )
            a[k] = LHS[i++];
        else
            a[k] = RHS[j++];
        k++;
    }
    while(i<mid-lo+1)
    {
        a[k] = LHS[i];
        ++k;
        ++i;
    }
    while(j<hi-mid)
    {
        a[k] = RHS[j];
        ++k;
        ++j;
    }
}
