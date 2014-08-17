int partition(int a[], int beg, int end) {
	int x = a[beg];
	int i = beg;
	int j = end;
	while(i < j) {
		while(i < j && a[j] > x) {
			j --;
		}
		a[i] = a[j];
		while(i < j && a[i] < x) {
			i ++;
		}
		a[j] = a[i];
	}
	a[i] = x;
	return i;
}

void quicksort(int a[], int beg, int end) {
	if(beg > end) {
		return;
	}
	int pivot = partition(a,beg,end);
	quicksort(a,beg,pivot-1);
	quicksort(a,pivot+1,end);
}
