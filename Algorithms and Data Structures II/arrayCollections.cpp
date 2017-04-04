#include <cstdio>
#include <algorithm>
#include <iostream>



using namespace std;

int main()

{
    int n;
    cout << "Podaj rozmiar pierwszego zbioru: \n";
    scanf("%d", &n);
    cout << "Podaj wartoœci elementów zbioru - liczby calkowite: \n";
    int A[n];
    for (int i=0; i<n; i++) scanf("%d", &A[i]);

    int m;
    cout << "Podaj rozmiar drugiego zbioru: \n";
    scanf("%d", &m);
    cout << "Podaj wartosci elementow zbioru - liczby calkowite: \n";
    int B[m];
    for (int i=0; i<m; i++) scanf("%d", &B[i]);

    int C[n+m];
    
    for (int i=0; i<n; i++) C[i] = A[i];
    for (int i=0; i<m; i++) C[i+n] = B[i];

    sort(C, C+n+m);

	cout << "Suma zbiorow: \n";

	//wypisanie sumy zbiorów
    for (int i=0; i<n+m; i++)
       if ( C[i] != C[i+1] )
          cout << ("%d ", C[i]);

    cout << ("\n");

    int k = 0;
    int D[k];
    
    cout << "Przekroj zbiorow: \n";
    
    for (int i=0; i<n; i++)
       for (int j=0; j<m; j++)
          if ( A[i] == B[j] )
          {
              D[k] = A[i];
              k = k+1;
          }

	//wypisanie elementów przekroju
    for (int i=0; i<k; i++) cout << ("%d ", D[i]);

    cout << ("\n");

	int l = 0;
    int E[l];

	sort(A, A+n);
	sort(B, B+m);

	cout << "Roznica zbiorow: \n";
    
    bool flag = true;
    
    for (int i=0; i<n; i++){
    	//A = 1
    	for (int j=0; j<m; j++){
    		//1 =? 2
    		if(A[i] == B[j]){
    			flag = false;
    			break;
			}
		}
		//A = 1
		if(flag == true){
			E[l] = A[i];
			l++;
		} else{
			flag = true;
		}
	}

	//wypisanie elementów przekroju
    for (int i=0; i<l; i++){
    	
    		if(E[i]!=E[i+1]){
    		cout << ("%d ", E[i]);
		}
	}


	cout << "\n";
	cout << "Roznica symetryczna: \n";

	//wypisanie elementów ró¿nicy symetrycznej
	for (int i=0; i<n+m; i++)
	  {
	  if (C[i] == C[i+1])
	     i++;
	  else
	  printf("%d ", C[i]);
	  }

    return 0;
}
