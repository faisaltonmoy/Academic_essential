/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package memoryManagement;

/**
 *
 * @author faisa
 */
public class first_fit__worst_fit {
    public static int ex_frag_ff = 0;
    public static int ex_frag_wf = 0;
    static void firstFit(int blockSize[], int m, int processSize[], int n) { 
        
        int[] alloc = new int[n];
        for (int i = 0; i < alloc.length; i++) {
            alloc[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    alloc[i] = j;
                    blockSize[j] -= processSize[i];
                    break;
                }
            }
        
            if (alloc[i] != -1) 
            {
                for (int k = 0; k < m; k++) 
                {
                    System.out.print(blockSize[k]+"  \t");
                }
                System.out.println();
            } else {
                for(int k=0; k<m; k++)
                {
                ex_frag_ff+=blockSize[k];
                }
                System.out.println("Not Allocated");
            }
        }
    }
    static void bestFit(int blockSize[], int m, int processSize[], int n) { 
        
        int[] alloc = new int[n];
        for (int i = 0; i < alloc.length; i++) {
            alloc[i] = -1;
        }
        for(int i =0;i<n;i++)
    {
        int besttInd=-1;
        for(int j =0;j<m;j++)
        {
            if(blockSize[j]>=processSize[i])
            {
                if(besttInd==-1)
                {
                    besttInd=j;
                }
                else if (blockSize[besttInd]>blockSize[j])
                {
                    besttInd=j;
                }
            }
        }
        if(besttInd!=-1)
        {
            alloc[i]=besttInd;
            blockSize[besttInd]-=processSize[i];
        }
        if(alloc[i]!=-1)
        {
            for(int k=0; k<m; k++)
            {
                System.out.print(blockSize[k]+"  \t");
            }
            System.out.println();

        }
        else {
            for(int k=0; k<m; k++)
            {
                ex_frag_wf+=blockSize[k];
            }
            System.out.println("Not Allocated");
            break;
        }
    }
    }
    static void worstFit(int blockSize[], int m, int processSize[], int n) { 
        
        int[] alloc = new int[n];
        for (int i = 0; i < alloc.length; i++) {
            alloc[i] = -1;
        }
        for(int i =0;i<n;i++)
    {
        int wrstInd=-1;
        for(int j =0;j<m;j++)
        {
            if(blockSize[j]>=processSize[i])
            {
                if(wrstInd==-1)
                {
                    wrstInd=j;
                }
                else if (blockSize[wrstInd]<blockSize[j])
                {
                    wrstInd=j;
                }
            }
        }
        if(wrstInd!=-1)
        {
            alloc[i]=wrstInd;
            blockSize[wrstInd]-=processSize[i];
        }
        if(alloc[i]!=-1)
        {
            for(int k=0; k<m; k++)
            {
                System.out.print(blockSize[k]+"  \t");
            }
            System.out.println();

        }
        else {
            for(int k=0; k<m; k++)
            {
                ex_frag_wf+=blockSize[k];
            }
            System.out.println("Not Allocated");
            break;
        }
    }
    }
    public static void main(String[] args) {
        
        int blockSize1[] = {50, 200, 70, 115, 15};
        int processSize1[] = {100, 10, 35, 15, 23, 6, 25, 55, 88, 40};
        int m1 = blockSize1.length;
        int n1 = processSize1.length;
        System.out.println("\t    First Fit     \t");
        firstFit(blockSize1, m1, processSize1, n1);
        System.out.println("External Fragmentation: " + ex_frag_ff);
        
        System.out.println();
        
        int blockSize2[] = {50, 200, 70, 115, 15};
        int processSize2[] = {100, 10, 35, 15, 23, 6, 25, 55, 88, 40};
        int m2 = blockSize2.length;
        int n2 = processSize2.length;
        System.out.println("\t    Best  Fit     \t");
        bestFit(blockSize2, m2, processSize2, n2);
        System.out.println("External Fragmentation: " + ex_frag_wf);
        
        System.out.println();
        
        int blockSize3[] = {50, 200, 70, 115, 15};
        int processSize3[] = {100, 10, 35, 15, 23, 6, 25, 55, 88, 40};
        int m3 = blockSize3.length;
        int n3 = processSize3.length;
        System.out.println("\t    Worst Fit     \t");
        worstFit(blockSize3, m3, processSize3, n3);
        System.out.println("External Fragmentation: " + ex_frag_wf);
    }
    
}
