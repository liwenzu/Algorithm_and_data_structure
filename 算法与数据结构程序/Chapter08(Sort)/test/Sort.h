#include <iostream>
#include <vector>


using namespace std;

template <typename T>
void insertionSort(vector<T> &arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        T temp = arr[i];
        int j = i-1;
        for(; arr[j]>temp && j>=0;j--)
            arr[j+1]=arr[j];
        arr[j+1] = temp;
    }
}

//���ڱ�
template <typename T>
void insertionSortSB(vector<T> &arr)
{
    int n=arr.size();
    for(int i=2;i<n;i++)
    {
        arr[0] = arr[i];
        int j = i-1;
        for(; arr[j]>arr[0];j--)
            arr[j+1]=arr[j];
        arr[j+1] = arr[0];
    }
}

//�۰�
template <typename T>
void insertionSortBS(vector<T> &arr)
{
    int n=arr.size();
    for(int i=2;i<n;i++)
    {
        arr[0] = arr[i];
        int left = 1;
        int right = i-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(arr[mid]>arr[0])
                right = mid-1;
            else
                left = mid+1;
        }
        int j = i-1;
        for(; j>=right+1;j--)
            arr[j+1]=arr[j];
        arr[right+1] = arr[0];
    }
}

//shell
template<typename T>
void insertionSortSH(vector<T> &arr)
{
    int n=arr.size();
    for(int d=n>>1;d>0;d=d>>1)
    {
        for(int i=d+1;i<n;i++)
        {
           if(arr[i]<arr[i-d])
           {
                arr[0]=arr[i];
                int j=i-d;
                for(;j>0 && arr[j]>arr[0];j-=d)
                    arr[j+d] = arr[j];
                arr[j+d] = arr[0];
           }
        }
    }
}

//Bubble Sort
template<typename T>
void bubbleSort(vector<T> &arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                T temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Optimized bubble sort algorithm
template<typename T>
void bubbleSortOP(vector<T> &arr)
{
    int n=arr.size();
    int flag=1;
    for(int i=1;i<n && flag;i++)
    {
        flag = 0;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                T temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
    }
}

//����(��Ҫ���ñ�־λ)
template <typename T>
int Partition(vector<T> &arr, int left, int right)
{
    arr[0] = arr[left];
    int pivotkey = arr[left];
    while(left<right)
    {
        while(left<right && arr[right]>=pivotkey)
            right--;
        arr[left] = arr[right];
        while(left<right && arr[left]<=pivotkey)
            left++;
        arr[right]=arr[left];
    }
    arr[left] = arr[0];
    return left;
}

template <typename T>
void quickSort(vector<T> &arr, int left, int right)
{
    if(left < right)
    {
        int pivotloc = Partition(arr, left, right);
        quickSort(arr, left, pivotloc-1);
        quickSort(arr, pivotloc+1, right);
    }
}

template <typename T>
void quickSort(vector<T> &arr)
{
    int left = 1, right = arr.size()-1;
    quickSort(arr, left, right);
}

//ѡ������(�����ñ�־λ)
template <typename T>
void selectSort(vector<T> &arr)
{
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        T temp = arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<temp)
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }

        }
    }
}

template <typename T>
void selectSortOP(vector<T> &arr)
{
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        int m=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[m])
                m=j;
        }
        if(m!=i)
        {
            T temp = arr[m];
            arr[m] = arr[i];
            arr[i] = temp;
        }
    }
}


//������
template <typename T>
void HeapAdjust(vector<T> &nu, int s, int m)
{
    nu[0] = nu[s];
    for(int j=2*s;j<=m;j*=2)
    {
        if(j<m && nu[j]<nu[j+1])
            j++;
        if(nu[0]>=nu[j])
            break;
        nu[s] = nu[j];
        s=j;
    }
    nu[s] = nu[0];
}

template <typename T>
void CreatHeap(vector<T> &nu)
{
    int n=nu.size();
    for(int i=(n-1)/2;i>0;i--)
    {
        HeapAdjust(nu, i, n-1);
    }
}

template <typename T>
void HeapSort(vector<T> &nu)
{
    CreatHeap(nu);
    int n = nu.size();
    for(int i=n-1;i>1;i--)
    {
        nu[0]=nu[1];
        nu[1]=nu[i];
        nu[i]=nu[0];
        HeapAdjust(nu, 1, i-1);
    }
}

//�鲢����
template <typename T>
void merge(vector<T> &tmp, vector<T> &nu, int l, int mid, int r)
{
    int pos = 0;
    int ll = l;
    int rr = mid+1;
    while(ll<=mid && rr<=r)
    {
        if(nu[ll]<nu[rr])
            tmp[pos++]=nu[ll++];
        else
            tmp[pos++]=nu[rr++];
    }
    while (ll<=mid)
        tmp[pos++] = nu[ll++];
    while (rr<=r)
        tmp[pos++] = nu[rr++];
    pos=0;
    for(int i=l;i<=r;i++)
        nu[i]=tmp[pos++];
}


template <typename T>
void MergeSort(vector<T> &nu, int l, int r)
{
    vector<T> tmp(nu.size()+1);
    if(l<r)
    {
        int mid = (l+r)/2;
        MergeSort(nu, l, mid);
        MergeSort(nu, mid+1, r);
        merge(tmp, nu, l, mid, r);

//        for(int i=l;i<=mid;i++)
//            cout << nu[i] << ";";
//        cout << "***" << ";";
//        for(int i=mid+1;i<=r;i++)
//            cout << nu[i] << ";";
//        cout << endl;
    }
}


template <typename T>
void MergeSort(vector<T> &nu)
{
    int n = nu.size();
    MergeSort(nu, 0, n-1);
}


//��������
/*�����������ֵ�����λ��*/
template <typename T>
int maxBit(const vector<T> arr) {
	int len = 0;
//	for (auto x : arr) {
//		int c = 0;
//		int tmp = x;
//		while (tmp > 0) {
//			tmp /= 10;
//			c++;
//		}
//		if (len < c)
//			len = c;
//	}
	for(int i=0;i<arr.size();i++)
    {
        int c = 0;
        int tmp = arr[i];
        while (tmp > 0) {
			tmp /= 10;
			c++;
		}
		if (len < c)
			len = c;
    }
	return len;
}

/*����int������Ļ��������ʵ��*/
template <typename T>
void radixsort(vector<T> & arr)
{
	const int BUCKETS = 10;									//����Ͱ�ĸ���
	vector<vector<T> > buckets(BUCKETS);		 //���û���Ͱ
	int len = maxBit(arr);											 //�����������ֵ�����λ�������ξ����������
	int r = 1;
	for (int i = 0; i < len; ++i)									//�ӵ�λ����λ���л����������η���Ͱ��
	{
//		for (int & s : arr) {											//��ѭ������Ӧ��������
//			int k = s / r;
//			int q = k%BUCKETS;
//			buckets[q].push_back(std::move(s));
//		}
		for(int j=0; j<arr.size();j++)
        {
            int k = arr[j]/r;
			int q = k%BUCKETS;
			buckets[q].push_back(arr[j]);
        }
//		int idx = 0;
//		for (auto & thisBucket : buckets)					//ѭ��ÿ��Ͱ�е�Ԫ��
//		{
//			for (int &s : thisBucket)								//��ÿ��Ͱ�е�Ԫ�ط���ԭʼ������
//				arr[idx++] = std::move(s);
//			thisBucket.clear();
//		}
		int idx = 0;
		for(int j=0;j<buckets.size();j++)
        {
            for(int f=0;f<buckets[j].size();f++)
                arr[idx++] = buckets[j][f];
            buckets[j].clear();
        }
//		cout << "��"<<i+1<<"����������";
//		for (auto x : arr)
//			cout << x << " ";
//		cout << endl;
		r = r * 10;
	}
}











