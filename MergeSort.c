void merge_sort_merge_sub_data( int *pComp1, int *pComp2, int *pWrite, int ulLen1, int ulLen2)
{
    int i, ulCount, ulIndex1 = 0, ulIndex2 = 0;
    ulCount = (ulLen1 + ulLen2);

    for (i = 0; i < ulCount; i++)
    {
	if (pComp1[ulIndex1] > pComp2[ulIndex2])
	{
	    pWrite[i] = pComp2[ulIndex2++];
	}
	else
	{
	    pWrite[i] = pComp1[ulIndex1++];
	}

        if (ulIndex1 == ulLen1)
        {
            while(++i < ulCount)
            {
                pWrite[i] = pComp2[ulIndex2++];
            }
        }

        if (ulIndex2 == ulLen2)
        {
            while(++i < ulCount)
            {
                pWrite[i] = pComp1[ulIndex1++];
            }
        }
     }
}
void merge_sort( int **ppSortBuf, int **ppSortTemp, int ulLen)
{
    int i, j, k;
    int *pSortBuf, *pSortTemp, *pSortTran;
    int *pCompare1, *pCompare2, *pWrite;

    pSortBuf = *ppSortBuf;
    pSortTemp = *ppSortTemp;

    for (i = 1; i < ulLen; i = i * 2)
    {
        for (j = 0; j < ((ulLen / i) - 1); j += 2)
        {
            pCompare1 = pSortBuf + (j * i);
            pCompare2 = pSortBuf + ((j + 1) * i);
            pWrite = pSortTemp + (j * i);

            merge_sort_merge_sub_data(pCompare1, pCompare2, pWrite, i, i );
        }

        if (((j + 1) * i) < ulLen)
        {
            pCompare1 = pSortBuf + (j * i);
            pCompare2 = pSortBuf + (j + 1) * i;
            pWrite = pSortTemp + (j * i);

            merge_sort_merge_sub_data(pCompare1, pCompare2, pWrite, i, (ulLen -((j + 1) * i)) );
        }
        else
        {
            for (k = (j * i); k < ulLen; k++)
            {
                pSortTemp[k] = pSortBuf[k];
            }
        }

        pSortTran = pSortTemp;
        pSortTemp = pSortBuf;
        pSortBuf = pSortTran;
    }

    *ppSortBuf = pSortBuf;
    *ppSortTemp = pSortTemp;
    return;
}

int main()
{
        int * a = malloc(11*sizeof(int));
        int * b = malloc(11*sizeof(int));
        int c[11]={5,8,2,3,6,4,7,9,11,0,1};

        for(i=0;i<11;i++)
        {
                a[i]=c[i];
        }

        merge_sort(&a,&b,11);

        for(i=0;i<11;i++)
        {
                printf("[%d]",a[i]);
        }
}

