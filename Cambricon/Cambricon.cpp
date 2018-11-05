// Cambricon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <limits>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;


bool isHuiwen(string s)
{
	string str = s;
	
	int length = s.size();
	for (size_t i = 0; i < s.length()/2; i++)
	{
		char temp = s.at(i);
		s.at(i) = s.at(s.length() - 1);
		s.at(s.length() - 1) = temp;
	}

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str.at(i) == s.at(i))
		{
			continue;
		}
		else
		{
			return false;
		}

	}
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int k;
	cin >> k;
	
	vector<string> vec(k);
	vec.clear();

	for (size_t i = 0; i < k; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}

	vector<int> vecIndex(k);    //����ֵ������
	vecIndex.clear();

	for (size_t m = 0; m < k; m++)
	{
		
		if (isHuiwen(vec[m]))
		{
			vecIndex.push_back(-1);
		}
		else
		{ 
			for (int i = 0; i < vec[m].length(); i++) {
				string tmp = vec[m];
				for (int j = i; j < vec[m].length(); j++)
				{
					if (j == vec[m].length()-1)
					{
						tmp[j] = '\0';
					}
					else
					{
						tmp[j] = tmp[j + 1]; // ɾ��tmp[j]���Ѻ������ǰ�ƶ�
					}
					
				}
				tmp.resize(tmp.length() - 1);

				if (isHuiwen(tmp))
				{
					vecIndex.push_back(i);
					break;
				}

			}
		}
		
	}

	//��ӡ
	for (size_t i = 0; i < k; i++)
	{
		cout << vecIndex[i] << " ";
	}
	cout << endl;
	return 0;
}
