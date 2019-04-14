#pragma once
#include"pch.h"
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include"function.h"

#define Number	5
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	void CreatListHead(ListNode* &L, int n)
	{
		for (int i = 0; i < n; i++)
		{
			ListNode* temp = new ListNode(0);
			temp->val = rand() % 10;
			temp->next = L->next;
			L->next = temp;
		}

		L = L->next;
	}

	ListNode* CreatListTail(ListNode* L, int n)
	{
		ListNode* r = L;
		for (int i = 0; i < n; i++)
		{
			ListNode* temp = new ListNode(0);
			temp->val = rand() % 10;;
			r->next = temp;
			r = temp;
		}
		r->next = NULL;
		return L->next;
	}

	void ShowList(ListNode* L)
	{
		while (L != NULL)
		{
			cout << L->val << ",";
			L = L->next;
		}
		cout << endl;
	}
#if(Number==0)
private:
	vector<int> result;
public:
void twoSum(vector<int>& nums, int target) 
{
	
	for (int i = 0; i < nums.size()-1; i++)
	{
		for (int j = i+1; j < nums.size(); j++)
		{
			if (target == (nums[i] + nums[j]))
			{
			result.push_back(i);
			result.push_back(j);
			}
		}
	}
}

void ShowResult(int numSize)
{
	for (int i = 0; i < result.size() / numSize; i++)
	{
		cout << "[";
		for (int j = 0; j < numSize; j++)
		{
			cout << result[numSize*i + j] << ",";
		}
		cout << "]" << endl;
	}
}

#elif(Number==21)
public:
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* newList = new ListNode(-1);
	ListNode*cur = newList;
	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			cur->next = l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	cur->next = l1 ? l1 : l2;
	return newList->next;
}





void ListSort(ListNode* &L)
{
	ListNode* temp = L;
	int listSize = 0;
	//计算链表大小
	do
	{
		listSize++;
		temp = temp->next;
	} while (temp!= NULL);
	cout << "链表大小listSize=" << listSize << endl;
	//分配数组内存
	int* arr_buf = new int[listSize];
	int* p_buf = arr_buf;
	//链表值赋给数组
	temp = L;
	do
	{
		*p_buf++ = temp->val;
		temp = temp->next;
	} while (temp!= NULL);
	//数组排序
	BubbleSort(arr_buf, listSize);
	//排序后的数组值重新赋给链表
	temp = L;
	p_buf = arr_buf;
	while (temp!= NULL)
	{
		temp->val=*p_buf++;
		temp = temp->next;
	}
	delete arr_buf;
}
void ShowResult21()
{
	ListNode* newList = new ListNode(0);
	ListNode* l1= new ListNode(0);
	ListNode* l2= new ListNode(0);
	
	l1=CreatListTail(l1, 7);
	CreatListHead(l2, 8);

	cout << "l1: ";
	newList = l1;
	while (newList != NULL)
	{
		cout << newList->val << ",";
		newList = newList->next;
	}
	cout << endl;

	cout << "l2: ";
	newList = l2;
	while (newList!=NULL)
	{
		cout << newList->val<<",";
		newList = newList->next;
	}
	cout << endl;

	ListSort(l1);
	cout << "Sort-l1: ";
	newList = l1;
	while (newList != NULL)
	{
		cout << newList->val << ",";
		newList = newList->next;
	}
	cout << endl;

	ListSort(l2);
	cout << "Sort-l2: ";
	newList = l2;
	while (newList != NULL)
	{
		cout << newList->val << ",";
		newList = newList->next;
	}
	cout << endl;
	
	newList = mergeTwoLists(l1, l2);
	cout << "newList: ";
	while (newList != NULL)
	{
		cout << newList->val << ",";
		newList = newList->next;
	}
	cout << endl;
}

#elif(Number==2)
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* dummyList = new ListNode(0);
		ListNode* current = dummyList;
		int x, y, sum,carry=0;
		while (l1!=NULL || l2!=NULL)
		{
			
			x = (l1 != NULL) ? l1->val : 0;
			y = (l2 != NULL) ? l2->val : 0;
			sum = x + y + carry;
			ListNode* temp = new ListNode( sum % 10);
			carry = sum / 10;
			current->next = temp;
			current = temp;
			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;
		}
		if (carry>0)
			current->next= new ListNode(carry);

		return dummyList->next;

	}
	
	void ShowResult2()
	{
		ListNode* l1 = new ListNode(0);
		ListNode*l2 = new ListNode(0);
		ListNode*buf=new ListNode(0);

		l1 = CreatListTail(l1,13);
		ShowList(l1);
		l2 = CreatListTail(l2, 7);
		ShowList(l2);
		buf = addTwoNumbers(l1, l2);
		ShowList(buf);
	}
#elif(Number==3)
public:
int lengthOfLongestSubstring(string s) {
	unordered_map<char, int>m;
	int lastRepeatPos = -1, maxlen = 0, from = 0, i = 0;
	for (i = 0; i < s.size(); i++)
	{
		if (m.find(s[i]) != m.end() && lastRepeatPos < m[s[i]])
		{
			lastRepeatPos = m[s[i]];
		}
		if (i - lastRepeatPos > maxlen)
		{
			maxlen = i - lastRepeatPos;
			from = lastRepeatPos + 1;
		}
		m[s[i]] = i;
	}
	cout << s.substr(from, maxlen).c_str() << endl;
	return maxlen;
}

#elif(Number==4)
public:
	double Middle1(vector<int>& nums1,vector<int>& nums2)
	{
		int size1 = 0, size2 = 0, new_size = 0, i = 0, j = 0;
		double middle = 0.0; 
		vector<int> temp;
		size1 = nums1.size();
		size2 = nums2.size();
		while ((i<size1)&&(j<size2))
		{
			if (nums1[i] < nums2[j])
			{ 
				temp.push_back(nums1[i]);
				i++;
			}
			else
			{ 
				temp.push_back(nums2[j]);
				j++;
			}
		}
		if (i >= size1)
		{
			for (; j < size2; j++)
			{
				temp.push_back(nums2[j]);
			}
		}
		else if (j>=size2)
		{
			for ( ;  i< size1; i++)
			{
				temp.push_back(nums1[i]);
			}
		}
		new_size = temp.size();
		if (new_size % 2 == 0)
		{
			middle = temp[new_size / 2];
			middle = (temp[new_size / 2 - 1] + middle) / 2;
		}
		else
		{
			middle = temp[new_size / 2];
		}
		return middle;
	}

	double Middle2(vector<int>& nums1,vector<int>& nums2)
	{
		int size1 = nums1.size();
		int size2 = nums2.size();
		double leftMax, rightMIn;

		if (size1 > size2)
		{
			vector<int> temp = nums1;
			nums1 = nums2;
			nums2 = temp;
			size1 = nums1.size();
			size2 = nums2.size();
		}
		int imin = 0, imax = size1, halflen = (size1 + size2 + 1) / 2, i = 0, j = 0;
		while (imin <= imax)
		{
			i = (imin + imax) / 2;
			j = halflen - i;
			if (i < imax && nums1[i] < nums2[j - 1])
				imin = i + 1;
			else if (i > imin && nums1[i - 1] > nums2[j])
				imax = i - 1;
			else
			{
				if (i == 0)
				{
					leftMax = nums2[j - 1];
				}
				else if (j == 0)
				{
					leftMax = nums1[i - 1];
				}
				else
				{
					leftMax = max(nums1[i - 1], nums2[j - 1]);
				}
				if ((size1 + size2) % 2 == 1)
					return leftMax;
				if (i == size1)
				{
					rightMIn = nums2[j];
				}
				else if (j == size2)
				{
					rightMIn = nums1[i];
				}
				else
				{
					rightMIn = min(nums2[j], nums1[i]);
				}
				return (leftMax + rightMIn) / 2.0;
			}
		}
		return 0.0;
	}

#elif(Number==5)
private:
	int expandAroundCenter(string s, int left, int right) 
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{
			L--;
			R++;
		}
		return R-L-1;
	}
public:
	string longestPalindrome(string s) 
	{
	
			if (s.empty() || s.length() < 1) return "";
			int start = 0, end = 0, len = 0;
			for (int i = 0; i < s.length(); i++)
			{
				int len1 = expandAroundCenter(s, i, i);
				int len2 = expandAroundCenter(s, i, i + 1);
				int len3 = max(len1, len2);
				if (len3 > end - start)
				{
					start = i - (len3 - 1) / 2;
					end = i + len3 / 2;
					len = end - start + 1;
				}
			}
			string str = s.substr(start, len).c_str();
			cout << s.substr(start, len).c_str() << endl;
			return str;
	}



#endif // 0
};
