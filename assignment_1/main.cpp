#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>
#define Vector_Matrix vector<vector<int>>
#define float_Vector vector<float>
#define forLoop for(int i=0;i<v.size();i++)
using namespace std;

//To print a matrix
void print(Vector_Matrix v){
    for(int i=0;i<v.size();i++){
      for(int j=0;j<v[0].size();j++){
          cout<<v[i][j]<<" ";
          
      }
      cout<<endl;
  }
}
// max pooling and average pooling are on the same program
//      max pooling = 'max'   average pooling = 'avg'
// assuming square matrix according to the problem statement
Vector_Matrix Pooling(Vector_Matrix v1, string pool,int stride)
{
    int size = v1.size();
    int n = size/stride;
    string max = "max";
    string avg = "avg";
    // This contains the answer
    Vector_Matrix ans(n,vector<int>((n),0));
    // This contains Part to check
    Vector_Matrix part(n,vector<int>(n,0));

    
    for(int i = 0; i < size; i+=stride){
        for(int j = 0; j < size; j+=stride){
            if (pool == max) {
                int max = 0;
                for(int l = 0; l < stride; l++){
                    for(int m = 0; m < stride; m++){
                        if(max < v1[i+l][j+m]){
                            max = v1[i+l][j+m];
                        }
                    }  
                }
                ans[i/stride][j/stride] = max;
            }  
            else if (pool == avg) {
                int avg = 0;
                for(int l = 0; l < stride; l++){
                    for(int m = 0; m < stride; m++){
                        avg+=v1[i+l][j+m];
                    }  
                }
                ans[i/stride][j/stride] = avg/(stride*stride);
            }  
            else 
            {
                cout << "choose 'max' or 'avg' pool" << endl; 
                return ans;
            }   
        }
        
    }
    return ans;
}


/* ---------- Convolution -----------*/
int sub_convo(Vector_Matrix v1, Vector_Matrix v2){
    int sum = 0;
    int n = v1[0].size();
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            sum += v1[i][j]*v2[n-i-1][n-j-1];
        }
    }
    return sum;
}
// void sub_vector(vector<vector<int>> as, int n, int a, int b){
//     vector<vector<int>> sol;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             sol[i][j] = as[i+a][j+b];
//         }
//     }
//     print(sol);
// }

Vector_Matrix convolution(Vector_Matrix v1, Vector_Matrix v2){
    // v1: kernel
    
    int rows_v1 = v1.size();
    int rows_v2 = v2.size();
    int coloumns_v1 = v1[0].size();
    int coloumns_v2 = v2[0].size();
    int n = rows_v1;
    
    Vector_Matrix v((rows_v2-rows_v1+1),vector<int>((coloumns_v2-coloumns_v1+1),0)); //answer here
    Vector_Matrix v_temp(n,vector<int>(n,0)); //Extraction of smaller matrix from image matrix
    
    for(int x=0;x<(coloumns_v2-coloumns_v1+1);x++){
        for(int y=0;y<(rows_v2-rows_v1+1);y++){
            for(int a=0;a<coloumns_v1;a++){
                for(int b=0;b<rows_v1;b++){
                    v_temp[a][b] = v2[a+x][b+y];
                }
            }
            v[x][y] = sub_convo(v1,v_temp);
        }
    }
    //print(v);
    return v;    
}
Vector_Matrix convolution_pad(Vector_Matrix v2, int padding){
    Vector_Matrix pad(v2.size()+2*padding,vector<int>(v2[0].size()+2*padding,0));
    for(int q=0;q<v2.size();q++){
        for(int w=0;w<v2[0].size();w++){
            pad[q+padding][w+padding] = v2[q][w];
        }
    }
    return pad;
}

/* ---------- SOftmax ----------- */
void print(float_Vector v){
    for(int i=0;i<v.size();i++){
      cout<<v[i]<<" ";
  }
}
void print_sum(float_Vector v){
    float ans = 0.0;
    for(int i=0;i<v.size();i++){
        ans += v[i];
    }
    cout<<"***"<<ans<<"***";
}
float_Vector sigmoid(float_Vector a){
    float_Vector ans(a.size(),0.0);
    for(int i=0;i<a.size();i++){
        ans[i] = 1/(1+exp(-1*a[i]));
    }
    return ans;
}
float_Vector softmax(float_Vector a){
    float_Vector blu(a.size(),0.0);
    float sum = 0.0;
    for(int i=0;i<a.size();i++){
        sum += exp(a[i]);
    }
    //cout<<"AAA "<<sum<<" ";
    for(int j=0;j<a.size();j++){
        blu[j] = (exp(a[j]))/sum;
    }
    return blu;
}

int main(int argc, char const *argv[])
{
    //this is of the form
    // ./main.out convolution_withpadding_matrixmult padsize matrix1.txt matrix1_numrows matrix2.txt matrix2_numrows
    if(argv[1] == "convolution_withpadding_matrixmult"){
        
    }
    else if(argv[1] == "convolution_withoutpadding_matrixmult"){

    }
    else if(argv[1] == "max_pooling"){

    }
    else if(argv[1] == "average_pooling"){

    }
    else if(argv[1] == "softmax"){

    }
    else{
        cout << "None of the above functions written:" << endl;
        cout << "'convolution_withpadding_matrixmult'" << endl;
        cout << "'convolution_withoutpadding_matrixmult'" << endl;
        cout << "'max_pooling'" << endl;
        cout << "'average_pooling'" << endl;
        cout << "'softmax'" << endl;
    }
    return 0;
}