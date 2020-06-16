void merge(int* mas, int N, int l, int r) {
	if (r == l)
		return;
	if (r - l == 1) {
		if (mas[r] < mas[l])
			swap(mas[r], mas[l]);
		return;
	}
	int half = (r + l) / 2;
	merge(mas, N, l, half);
	merge(mas, N, half + 1, r);
	int* newmas = new int[N];
	int xl = l;
	int xr = half + 1;
	int current = 0;
	while (r - l + 1 != current) {
		if (xl > half)
			newmas[current++] = mas[xr++];
		else if (xr > r)
			newmas[current++] = mas[xl++];
		else if (mas[xl] > mas[xr])
			newmas[current++] = mas[xr++];
		else
			newmas[current++] = mas[xl++];
	}
	for (int i = 0; i < current; i++)
		mas[i + l] = newmas[i];
	delete[] newmas;
}

N – size, l – 0 элемент, r – (size-1)
