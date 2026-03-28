class Solution {
public:
// 	•	1 → divisors = {1} → 1 divisor
// 	•	2 → {1,2} → 2 divisors
// 	•	3 → {1,3} → 2 divisors
// 	•	4 → {1,2,4} → 3 divisors
// 	•	5 → {1,5} → 2 divisors
// 	•	6 → {1,2,3,6} → 4 divisors
// 	•	7 → {1,7} → 2 divisors
// 	•	8 → {1,2,4,8} → 4 divisors
// 	•	9 → {1,3,9} → 3 divisors
// 	•	10 → {1,2,5,10} → 4 divisors
// 	•	16 → {1,2,4,8,16} → 5 divisors
// 	•	25 → {1,5,25} → 3 divisors 

// So special numbers are:
// 	•	4
// 	•	9
// 	•	25
// 	•	49
// 	•	…

// Now ask:

// What is common in these?

// They are:
// 	•	4 = 2²
// 	•	9 = 3²
// 	•	25 = 5²
// 	•	49 = 7²

// So they are perfect squares.

// But not all squares work:
// 	•	16 = 4² 
// 	•	36 = 6² 

// So what’s special about:
// 	•	2, 3, 5, 7

// They are prime.

// So the pattern becomes:

// A special number = square of a prime
    int nonSpecialCount(int l, int r) {
    int limit =sqrt(r);
    vector<bool> isPrime(limit+1,true);
    if (limit>=0) isPrime[0]=false;
    if (limit>=1) isPrime[1]=false;
    
    // Sieve of Eratosthenes
//     If i = 7, then:

// Multiples are:
// 	•	14 = 7 × 2 → already marked by 2
// 	•	21 = 7 × 3 → already marked by 3
// 	•	28 = 7 × 4 → already marked by 2
// 	•	35 = 7 × 5 → already marked by 5
// 	•	42 = 7 × 6 → already marked by 2 or 3

    for (int i=2;i*2<=limit;i++){
        if (isPrime[i]){
            for (int j=i*i;j<=limit;j+=i){
                isPrime[j]=false;
            }
        }
        
    }
    int cnt=0;
    for (int p=2;p<=limit;p++){
        if (isPrime[p]){
            long long sq = 1LL*p*p;
            if (sq>=l && sq<=r){
                cnt++;
            }
        }
    }
    return r-l+1 -cnt;
    }
};