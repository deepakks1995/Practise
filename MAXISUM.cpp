#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define gc() getchar_unlocked()
using namespace std;
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

namespace abc {					// namespace declaration
	template<class Item>
		class vector {
			private:				// member declaration
				int _capacity;
				int _size;
				Item *data;
			public:					// function declaration
				vector();

				vector(const int& isize);

				vector(const int& isize, const Item& ival);

				~vector();

				inline Item& operator[](const int& i);

				void push_back(const Item& item);

				bool empty();

				int size();

				void fill(const Item& item);

				class vector_Iterator
				{
					private:
						Item *buffer;
					public:
						vector_Iterator()
						{
						}

						vector_Iterator(Item * location)
						{
							buffer=location;
						}

						bool operator !=(vector_Iterator  itr)
						{
							if(this->buffer != itr.buffer)
								return true;
							else
								return false;
						}
						void operator =(vector_Iterator a)
						{
							buffer=a.buffer;
						}

						bool operator ==(vector_Iterator& itr)
						{
							if(this->buffer==itr.buffer)
								return true;
							else
								return false;
						}

						void operator ++()
						{
							buffer++;
						}

						void operator ++(int unused_parameter)
						{
							buffer++;
						}

						void operator --()
						{
							buffer--;
						}

						void operator --(int unused_parameter)
						{
							--buffer;
						}

						Item operator*()
						{
							return *buffer;
						}
				};


				vector_Iterator begin()
				{
					return vector_Iterator(data);
				}

				vector_Iterator end()
				{
					return vector_Iterator(data + _size+1);
				}

				vector_Iterator rbegin()
				{
					return vector_Iterator(data + _size);
				}

				vector_Iterator rend()
				{
					return vector_Iterator(data-1);
				}
		};

	template<class Item>
		vector<Item>::vector()
		{
			_capacity=2;
			_size=-1;
			data=new Item[_capacity];
		}

	template<class Item>
		vector<Item>::vector(const int& isize)
		{
			_capacity=isize;
			_size=-1;
			data = new Item[_capacity];
			for(int i=0;i<=_capacity;i++)
				data[i]=0;
		}

	template<class Item>
		vector<Item>::vector(const int& isize,const Item& ival)
		{
			_size=isize-1;
			_capacity=isize;
			data = new Item[_capacity];
			for(int i=0;i<=_size;i++)
				data[i]=ival;
		}

	template<class Item>
		vector<Item>::~vector()
		{
			delete[ ] data;
		}

	template<class Item>
		inline Item& vector<Item>::operator [] (const int& i)
		{
			if(i>_size || i<0)
				std::cout<<"Array Index out of Bounds\n";
			else
				return data[i];
		}

	template<class Item>
		void vector<Item>::push_back(const Item& item)
		{
			if(_size==_capacity-1)
			{
				_capacity*=2;
				Item *new_data = new Item[_capacity];
				for(int i=0;i<=_size;i++)
					new_data[i]=data[i];
				delete [] data;
				data =new_data;
			}
			data[++_size]=item;
		}

	template<class Item>
		bool vector<Item>::empty()
		{
			if(_size==-1)
				return true;
			else
				return false;
		}

	template<class Item>
		int vector<Item>::size()
		{
			return _size+1;
		}

	template<class Item>
		void vector<Item>::fill(const Item& item)
		{
			for(int i=0;i<=_size;i++)
				data[i]=item;
		}

}

#endif


bool mycmp(pair<long,long> p1, pair<long, long> p2)
{
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    return false;
}
void scanint(long long &x)
{
    register long long c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main()
{
    int t;
    scanf("%d",&t);
    long long A[100000],B,i;
    long long sum;
    pair<long long,long long> p;
    while(t--)
    {
        sum=0;
        long long N,K;
        scanint(N);
        scanint(K);
       // scanf("%lld %lld",&N,&K);
        vector< pair<long long,long long> > vec;
        for(i=0; i<N; i++)
            scanint(A[i]);
            //scanf("%lld",&A[i]);
        for(i=0; i<N; i++)
        {
            scanint(B);
            //scanf("%lld",&B);
            if(A[i]<=0)
            {
                A[i]*=-1;
                B*=-1;
            }
            p=make_pair(A[i],B);
            vec.push_back(p);
        }
        sort(vec.begin(),vec.end(),mycmp);
        if(abs(vec[0].second)<abs(vec[N-1].second))
        {
            if(vec[N-1].second>0)
                vec[N-1].first+=K;
            else if(vec[N-1].second<0)
                vec[N-1].first-=K;
        }
        else
        {
            if(vec[0].second>0)
                vec[0].first+=K;
            else if( vec[0].second<0)
                vec[0].first-=K;
        }
        for(i=0;i<N;i++)
            sum+=vec[i].first*vec[i].second;
        cout<<sum<<endl;
    }
    return 0;
}
