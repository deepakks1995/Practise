vector<int> Solution::flip(string s) {
    vector<int> A,o,z;
    bool check = 0;
    int count1 =0,count2 = 0,one = 0, zero = 0;
    for(int i=0;i<s.size(); ++i)
    {
        if(s[i]=='1')
            o.push_back(i);
        else
            z.push_back(i);
    }
    int L=-1,R=-1,max=0;
    if(z.size()>1)
    {
        for(int i=0;i<z.size();++i)
        {
            one = zero = 0;
            for(int j=i;j<z.size()-1;++j)
            {
                ++zero;
                one += z[j] - z[i] - 1 - zero;
                if(zero - one >max )
                {
                    max = zero - one;
                    R = j;
                    L = i;
                } 
            }
        }
        if(L!=-1)
        {
            A.push_back(L+1);
            A.push_back(R+1);
        }
    }
    else if(z.size()==1)
    {
        R = L = z[0];
        A.push_back(L+1);
        A.push_back(R+1);
    }
    return A;  
}
