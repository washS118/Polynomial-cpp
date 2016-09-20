/*******************
*   Luke Gauldin   *
*   12/16/14       *
*   version 2.6    *
*******************/

#include <iostream>
#include <list>
#include <iomanip>
#include <cmath>

using namespace std;

//Receives the Equation
list<int> getEquation(){
    int terms = 0;
    int coefficient = 0;
    list<int> equation;

    cout << "How many terms are there (include terms with a coefficient of zero): ";
    cin >> terms;

    for(int x = 1; x <= terms; x++){  // terms; terms>0, terms--
        cout << "\n What is the coefficient of this term: ";
        cin >> coefficient;

        equation.push_back(coefficient);
    }
    return equation;
}

//Factoring function
list<int> factor(int num){
    list<int> factors;
    int intNum=(int) num;
    if(intNum < 0){
        intNum *= -1;
    }

    for(int x = -intNum; x <= intNum; x++){
        if(x != 0){
            if (intNum % x == 0){

                factors.push_back(x);
            }
       }
    }
    return factors;
}

//Calculates rational roots
list<float> getRoots(list<int> factorOne, list<int> factorTwo){
    list<float> roots;

    for(float x :  factorOne){
        for(float y : factorTwo){
            roots.push_back(y / x);
        }
    }

    roots.sort();
    roots.unique();
    return roots;
}

//Tests zeros
list<float> zeroTest(list<float> rationalRoots, list<int> equation){
    float total = 0;
    int term = 0;
	float base = 0;
    list<float> zeros;

    for(float x : rationalRoots){
        total = 0;
        term = equation.size() - 1;

        for(int y : equation){
            if(x < 0 && term % 2 == 0){
                base = x * -1;
            }
            else{
                base = x;
            }

            if(term != 0){
                total += y * powf(base, term);
            }
            else{
                total += y;
            }
            term--;

            /**********************************************************************
            *Debugging line uncomment when testing                                *
            *Displays the root being tested, the coefficient, and the total amount*
            **********************************************************************/
            //cout << base << " " << y << " " << total << "\n";
        }
        if(total > -8e-006 && total < 8e-006){
            zeros.push_back(x);
        }
    }
    zeros.sort();
    return zeros;
}

int main()
{
    list<int> equation;
    list<int> factorTwo;
    list<float> rationalRoots;
    list<int> factorOne;
    list<float> zeros;

    equation = getEquation();

    factorOne = factor(equation.front());
    factorTwo = factor(equation.back());

    rationalRoots = getRoots(factorOne, factorTwo);

    zeros = zeroTest(rationalRoots, equation);

    cout << "\nThe rational roots are: ";
    for(float x : rationalRoots){
        cout << x << " ";
    }

    cout << "\n" << rationalRoots.size();

    cout << "\nThe rational zeros are: ";
    for(float x : zeros){
        cout << x << " ";
    }

    cout << "\n\nPress any key to exit...";
    cin.ignore();
    cin.get();
    return 0;
}

