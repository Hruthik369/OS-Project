// Banker's Algorithm
#include <stdio.h>
int main()
{
	// P0, P1, P2, P3, P4 are the Process names here

	int n, i, j, k;
	printf("Enter the no.of Process Required:");
	scanf("%d",&n);// Number of processes
	int alloc[n],max[n];
	printf("Enter the Max_need resources for each process:");
	for(i=0;i<n;i++)
        scanf("%d",&max[i]);
        //int max[5]= {2,1,1,7,1};
	printf("Enter the Allocated resources for each process:");
	for (i=0;i<n;i++)
        scanf("%d",&alloc[i]);
	//int alloc[5]= {1,0,0,4,0};

	int avail=1;

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n];
	for (i = 0; i < n; i++) {
			need[i]= max[i] - alloc[i];
	}
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {
				int flag = 0;
				if (need[i] > avail)
                {
					flag = 1;

                }
      			if (flag == 0)
				  {
				    ans[ind++] = i;
					avail += alloc[i];
					f[i] = 1;
				  }
			}
		}
	}

	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n-1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d\n", ans[n - 1]);

	return (0);
}

