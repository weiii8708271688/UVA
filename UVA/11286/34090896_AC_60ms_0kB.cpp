#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	map<string,int> course;
	map<string,int>::iterator it;
	map<string, int>::iterator it2;
	map<string, int>::iterator temp;
	int num = 0;

	int count = 0;
	string temp2="";
	string student="";
	string strincor="";
	string onecourse[5] = {};
	int coursenum = 0;
	while (getline(cin, student))
	{
		if (student.size()<6)
		{
			count = stoi(student);
			if(count ==0)
			{
				break;
			}
		}
		while (count > 0)
		{
			getline(cin, student);
			while (coursenum / 4 < 5)
			{
				onecourse[coursenum / 4].assign(student, coursenum, 3);
				coursenum += 4;
			}
			student = "";
			for (int i = 0; i < 4; i++)
			{
				for (int j = i + 1; j < 5; j++)
				{
					if (onecourse[i] > onecourse[j])
					{
						temp2 = onecourse[i];
						onecourse[i] = onecourse[j];
						onecourse[j] = temp2;
					}
				}
			}
			for (int i = 0; i < 5; i++)
			{
				strincor += onecourse[i];
			}
			if (course.find(strincor) == course.end())
			{
				course.insert(pair<string, int>(strincor, 1));
			}
			else
			{
				it = course.find(strincor);
				it->second++;
			}
			strincor = "";
			coursenum = 0;
			count--;
		}
		it = course.begin();
		it2 = it;
		temp = it;
		it2++;
		while (it != course.end())
		{
			if (it->second > temp->second)
			{
				temp = it;
			}
			it++;
		}
		it = course.begin();
		while (it != course.end())
		{
			if (it->second == temp->second)
			{
				num += it->second;
			}
			it++;
		}
		cout << num<<endl;
		num = 0;
		course.clear();
	}
}
