#include "calculate.hpp"
#include <string>
using namespace bullpgia;
using std::string, std::to_string;

namespace bullpgia{
	const string calculateBullAndPgia(const string chosen, const string guess){
		
		int size=chosen.size();
int bull=0;
int pgia=0;
int arr[size]; //TODO need to fix this to [size]
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
}