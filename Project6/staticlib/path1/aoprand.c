int sum(int* arr,int n)
{
	int s,i;
	for(i = 0;i<n;i++)
		s+= arr[i];
	return s;
}
int min(int* arr,int n)
{
	int m = arr[0],i;
	for(i = 1;i<n;i++)
		m = m > arr[i] ? arr[i] : m;
	return m;

}
