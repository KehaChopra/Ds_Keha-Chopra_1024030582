//QUES5
//Diagonal Matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int A[100];  

   
    cout << "Enter " << n ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    
    cout << "Diagonal Matrix:";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
//Tri-Diagonal Matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int lower[100], diag[100], upper[100];

    cout << "Enter " << n-1 << " lower diagonal elements:\n";
    for (int i = 0; i < n-1; i++) cin >> lower[i];

    cout << "Enter " << n << " diagonal elements:\n";
    for (int i = 0; i < n; i++) cin >> diag[i];

    cout << "Enter " << n-1 << " upper diagonal elements:\n";
    for (int i = 0; i < n-1; i++) cin >> upper[i];

    cout << "\nTri-diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else if (i == j+1) cout << lower[j] << " ";
            else if (i+1 == j) cout << upper[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
//Lower Triangular Matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int A[100]; 
    int k = 0;

    cout << "Enter " << n*(n+1)/2 << " elements (row-wise):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> A[k++];
        }
    }

    cout << "\nLower Triangular Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << A[i*(i+1)/2 + j] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
//  Upper Traingular
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int A[100];  // store only upper triangle
    int k = 0;

    cout << "Enter " << n*(n+1)/2 << " elements row-wise upper triangle\n";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> A[k++];
        }
    }

    cout << "Upper Triangular Matrix:";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
               
                int index = (i * n - (i*(i-1))/2) + (j-i);
                cout << A[index] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
//Symmetric
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int A[100]; 
    int k = 0;

    cout << "Enter " << n*(n+1)/2 << " elements lower triangle row-wise:";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> A[k++];
        }
    }

    cout << "\nSymmetric Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << A[i*(i+1)/2 + j] << " ";
            else cout << A[j*(j+1)/2 + i] << " ";
        }
        cout << endl;
    }

    return 0;
}
//Ques6

//Transpose
#include <iostream>
using namespace std;


void transpose(int mat[MAX][3], int trans[MAX][3]) {
    int k = mat[0][2]; 
    trans[0][0] = mat[0][1];
    trans[0][1] = mat[0][0];
    trans[0][2] = k;

    int q = 1;
    for (int col = 0; col < mat[0][1]; col++) {
        for (int p = 1; p <= k; p++) {
            if (mat[p][1] == col) {
                trans[q][0] = mat[p][1];
                trans[q][1] = mat[p][0];
                trans[q][2] = mat[p][2];
                q++;
            }
        }
    }
}

int main() {
    int mat[MAX][3], trans[MAX][3];
    int rows, cols, num;

    cout << "Enter rows, cols and non-zero elements: ";
    cin >> rows >> cols >> num;

    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = num;

    cout << "Enter sparse matrix in triplet form :\n";
    for (int i = 1; i <= num; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

    transpose(mat, trans);

    cout << "\nTranspose matrix in triplet form:\n";
    for (int i = 0; i <= num; i++) {
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2];
    }

    return 0;
}
//Addtion
#include <iostream>
using namespace std;



void addSparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible ";
        return;
    }

    int i = 1, j = 1, k = 1;
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] || (a[i][0] == b[j][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2];
            j++; k++;
        }
        else { 
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= a[0][2]) {
        c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2];
        j++; k++;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    c[0][2] = k - 1;
}

int main() {
    int a[MAX][3], b[MAX][3], c[MAX][3];
    int num1, num2;

    cout << "Enter rows cols and non-zero for matrix A: ";
    cin >> a[0][0] >> a[0][1] >> num1;
    a[0][2] = num1;
    cout << "Enter triplets for A:\n";
    for (int i = 1; i <= num1; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];

    cout << "Enter rows cols and non-zero for matrix B: ";
    cin >> b[0][0] >> b[0][1] >> num2;
    b[0][2] = num2;
    cout << "Enter triplets for B:\n";
    for (int i = 1; i <= num2; i++) cin >> b[i][0] >> b[i][1] >> b[i][2];

    addSparse(a, b, c);

    cout << "\nResult of addition in triplet form:\n";
    for (int i = 0; i <= c[0][2]; i++)
        cout << c[i][0] << " " << c[i][1] << " " << c[i][2] << endl;

    return 0;
}

//multiplication
#include <iostream>
using namespace std;



void multiply(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible ";
        return;
    }

    int r = a[0][0], ccols = b[0][1];
    int temp[MAX][MAX] = {0};

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= b[0][2]; j++) {
            if (a[i][1] == b[j][0]) {
                temp[a[i][0]][b[j][1]] += a[i][2] * b[j][2];
            }
        }
    }

    c[0][0] = r;
    c[0][1] = ccols;
    int k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < ccols; j++) {
            if (temp[i][j] != 0) {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = temp[i][j];
                k++;
            }
        }
    }
    c[0][2] = k - 1;
}

int main() {
    int a[MAX][3], b[MAX][3], c[MAX][3];
    int num1, num2;

    cout << "Enter rows cols and non-zero for matrix A: ";
    cin >> a[0][0] >> a[0][1] >> num1;
    a[0][2] = num1;
    cout << "Enter triplets for A:\n";
    for (int i = 1; i <= num1; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];

    cout << "Enter rows cols and non-zero for matrix B: ";
    cin >> b[0][0] >> b[0][1] >> num2;
    b[0][2] = num2;
    cout << "Enter triplets for B:\n";
    for (int i = 1; i <= num2; i++) cin >> b[i][0] >> b[i][1] >> b[i][2];

    multiply(a, b, c);

    cout << "\nResult of multiplication in triplet form:";
    for (int i = 0; i <= c[0][2]; i++)
        cout << c[i][0] << " " << c[i][1] << " " << c[i][2] << endl;

    return 0;
}


//Ques8
//distinct
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinct = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

       
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            distinct++;
        }
    }

    cout << "Total distinct elements = " << distinct ;

    return 0;
}






