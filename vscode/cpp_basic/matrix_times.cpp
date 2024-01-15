//矩阵乘法
#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

tuple<vector<float>, int, int> matrixTimes(vector<float> A, vector<float> B, int nA, int mA, int nB, int mB)
{
    int nC=nA,mC=mB;
    vector<float> C(nC * mC, 0);
    //compute C_ij
    //A nA * mA
    //B nB * mB
    //C nA * mB
    //C_ij=\sum_j{A_ik * B_kj}
    //A_ik=A[i*mA+k]
    //B_kj=B[k*mB+j]
    //C_ij=C[i*mC+j]
    for(int i=0 ; i<nC ; i++)
    {
        for(int j=0 ; j<mC ;j++)
        {
            float sum=0.0f;//reset sum
            for(int k=0 ; k<mA ; k++)
            {
                sum+=A[i * mA + k] * B[k * mB + j];
            }
            C[i * mC + j]=sum;
        }
    }
    return {C, nC, mC};
}

int main()
{
    vector <float> A={1,2,1,2};
    vector <float> B={2,1,1,1};
    auto[C,nC,mC]=matrixTimes(A,B,2,2,2,2);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<C[i*2+j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}