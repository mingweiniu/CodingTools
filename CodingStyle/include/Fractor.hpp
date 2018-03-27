#include <vector>

void Fractor(int n, std::vector<int> &p, std::vector<int> &k)
{
	for(int i=2; i<n; ++i)
	{
		if( n%i ==0)
		{
			n /= i;
			p.push_back(i);
			k.push_back(1);
			while( n%i ==0)
			{
				n /= i;
				++k.back();
			}
		}
	}
	if(n > 2)
	{
		p.push_back(i);
		k.push_back(1);
	}
}
