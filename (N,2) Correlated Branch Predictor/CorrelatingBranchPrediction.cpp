#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
unsigned int binaryToDecimal(unsigned int n);
void performBranchPrediction(vector<int> correctOutcome, unsigned int targetAddress, int n, int numOutcomes);


int main(){
	bool valid = true;
	unsigned int branchTarget;
	int k;
	unsigned int significantDigits;
	int outcomes;
	vector<int> outcomeSequence;
	int eachOutcome;
	cout<<"Enter an arbitrary binary branch target address up to 9 bits."<<endl;
	cin>>branchTarget;
	if(branchTarget>=1000000000){
		valid = false;
		cout<<"Invalid branch target. Try again!"<<endl;
	}

	if(valid){
		cout<<"Enter the number of least significant bits used to index the Local History Table. Range from 1-9 inclusive."<<endl;
		cin>>k;
		if(k>9 || k<1){
			valid = false;
			cout<<"Invalid number of least significant digits. Try again!"<<endl;
		}
	}

	significantDigits = pow(10,k);
	significantDigits = branchTarget % significantDigits;


	if(valid){
		cout<<"Enter the total number of correct outcomes. Must be greater than 0."<<endl;
		cin>>outcomes;
		if(outcomes<1){
			cout<<"Invalid number of outcomes. Try again!"<<endl;
			valid = false;
		}
	}

	if(valid){
		cout<<"Enter a 0 when the branch is not taken and a 1 when the branch is taken. Separate with spaces."<<endl;
		for(int i = 0; i<outcomes; i++){
			cin>>eachOutcome;
			outcomeSequence.push_back(eachOutcome);
		}

		performBranchPrediction(outcomeSequence,significantDigits, k, outcomes);
	}


}

void performBranchPrediction(vector<int> correctOutcome, unsigned int targetAddress, int n, int numOutcomes){
	int accuracy = 0;
	int LPTindex;
	int prediction;
	int LHTvalue;
	int entries = pow(2,n);
	vector<int> LHT(entries,0);
	vector<int> LPT(entries,0);
	vector<int> guessedPredictions;
	targetAddress = binaryToDecimal(targetAddress);

	for(int counter = 0; counter<numOutcomes; counter++){
		LPTindex = LHT[targetAddress];
		prediction = LPT[LPTindex];

		if(prediction == 1 || prediction ==0){
			int x = 0;
			guessedPredictions.push_back(x);
		}else if(prediction == 3 || prediction == 2){
			int y = 1;
			guessedPredictions.push_back(y);
		}


		if(prediction==0 && correctOutcome[counter]==1){
			LPT[LPTindex]++;
		}else if(prediction == 1 && correctOutcome[counter]==0){
			LPT[LPTindex]--;
			accuracy++;
		}else if(prediction == 1 && correctOutcome[counter]==1){
			LPT[LPTindex]+=2;
		}else if(prediction == 3 && correctOutcome[counter]==0){
			LPT[LPTindex]-=2;
		}else if(prediction==3 && correctOutcome[counter] == 1){
			LPT[LPTindex]--;
			accuracy++;
		}else if(prediction==2 && correctOutcome[counter]==0){
			LPT[LPTindex]++;
		}else if(prediction == 0 && correctOutcome[counter]==0){
			accuracy++;
		}else if(prediction == 2 && correctOutcome[counter]==1){
			accuracy++;
		}

		if(counter==0){
			LHT[targetAddress] = targetAddress;
		}else{
			LHTvalue = targetAddress >> 1;
		}

		if(correctOutcome[counter] == 1){
			unsigned int mask = pow(10,n-1);
			LHTvalue = targetAddress | mask;
		}

		LHT[targetAddress] =LHTvalue;
	}

	double accuracypercent = (double)accuracy/(double)numOutcomes;
	accuracypercent *= 100;
	cout<<endl;

	cout<<"The sequence of expected outcomes is shown below"<<endl;
	for(int i = 0; i<numOutcomes; i++){
		cout<<correctOutcome[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	cout<<"The sequence of predicted outcomes by the branch predictor is show below"<<endl;
	for(int i = 0; i<numOutcomes; i++){
		cout<<guessedPredictions[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	cout<<"Thus the accuracy of the correlated ("<<n<<",2) branch predictor is "<<accuracypercent<<"%"<<endl;


}


unsigned int binaryToDecimal(unsigned int n)
{
    unsigned int num = n;
    unsigned int dec_value = 0;
    int base = 1;
 
    unsigned int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}