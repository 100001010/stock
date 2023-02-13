#include <iostream>
using namespace std;

int main(){
	double bid,quantity,ask,fee_discount;
	cout<<"Please input Quantity, Bid, Ask and Fee discount:"<<endl;
	cin>>quantity>>bid>>ask;
	
	double bid_price = bid*quantity;
	double ask_price = ask*quantity;

	//Below the decimal point is unconditionally discarded, so use int to save
	int tax = ask_price*0.003;
	int minimum1 = bid_price*0.001425*fee_discount;
	int minimum2 = ask_price*0.001425*fee_discount;
	
	if(minimum1<=1){
		minimum1=1;
	}
	if(minimum2<=1)
	{
		minimum2=1;
	}

	int minimum_total=minimum1+minimum2;
	double net_profit=ask_price - bid_price - minimum_total - tax;
	cout<<endl<<"Net Profit"<<endl<<net_profit<<endl;        
	
	
	return 0;
}
