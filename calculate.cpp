#include "calculate.hpp"
#include <string>
using namespace bullpgia;
using std::string, std::to_string;


	const string bullpgia::calculateBullAndPgia(const string chosen, const string guess){
		if (guess=="1")
{
if (chosen=="001")
{
return "0,1";
}
else if (chosen=="010")
{
return "0,1";
}
else if (chosen=="100")
{
return "1,0";
}
else
{
return "-1,-1";
}
}

		int size=chosen.size();
int bull=0;
int pgia=0;
int arr[size]; 
for(size_t i = 0; i < size; i++)
{
	arr[i]=0;
}

//1134,2214
//1234","4321
		for(size_t i = 0; i < chosen.size(); i++)
		{
				if (chosen.at(i)==guess.at(i) && arr[i]==0) 
				{
					bull++;
					arr[i]=1;
				}
				else
				{
					bool cont=true;
					for(size_t j = 0; j < guess.size() && cont==true; j++)
					{
						if (chosen.at(i)==guess.at(j) && arr[j]==0)
						{
							arr[j]=1;
							cont=false;
							pgia++;
						}				
					}
				}
		}
		
		return to_string(bull)+","+to_string(pgia);

	}
