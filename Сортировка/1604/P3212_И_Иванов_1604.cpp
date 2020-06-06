#include<bits/stdc++.h>
#include<string>

using namespace std;

const double PI = 3.14159265358979323846;

//queue<int> a[10002];
pair<int, int> a[10002];

void heap(int n, int i){
    int mx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 1 + 1;

    if(l < n && a[l].first > a[mx].first)
        mx = l;

    if(r < n && a[r].first > a[mx].first)
        mx = r;
        
    if (mx != i)
    {
        swap(a[mx], a[i]); 
        heap(n, mx);
    }
}

int main()
{
	int n, mn;
	//bool key = false;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first;	
		a[i].second = i + 1;
		
//		if(a[i].first > mx)
//			mx = a[i].first;
	}
			
			
	for (int i = n / 2 - 1; i >= 0; --i)
	 	heap(n, i); 
	
//	sort(b, b + n);
//	reverse(b, b + n);

	while(a[0].first != 0){

        cout << a[0].second << " ";
        a[0].first--;
        
        mn = 1;
        
        if(n > 2)
        {
            if(a[1].first < a[2].first)
				mn = 2; 
        }

        if (a[mn].first != 0)
        {
            cout << a[mn].second << " ";
            a[mn].first--;
        }
        
        if (n > 2)
			heap(n, 2);
			 
        heap(n, 1);
        heap(n, 0);
    }
	
//	while(l < n)
//	{
//		for(int i = 0; i < mx; i++)
//		{
//			if(b[l].first > 0)
//			{
//				a[i].push(b[l].second);
//				b[l].first--;
//			}
//			else
//			{
//				l++;
//				
//				if(l < n)
//				{
//					a[i].push(b[l].second);
//					b[l].first--;
//				}
//				else
//					break;
//			}
//				
//			//cout << i <<" ";		
//		}
		
		//cout << endl;
		
//	}
//	
//	
//	for(int i = 0; i < mx; i++)
//	{
//		while(!a[i].empty())
//		{
//			cout << a[i].front() << " ";
//			a[i].pop();
//		}
//		
//	}
	

   	return 0;		
}

