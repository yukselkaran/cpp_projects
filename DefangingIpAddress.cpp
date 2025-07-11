#include <iostream>
#include <string>
using namespace std;
//defang tehlikeli olabilecek bir şey zararsız hale getirmek anlamında kullanılıyor, burada gerçek anlamı da dişlerini kesmek.
string DefangingIpAddress(string address){
	string result = "";
	for (char c : address) {
		if (c == '.') {
			result += "[.]";
		}
		else {
			result += c;
		}
	}
	return result;
}
int main()
{
	string addres1 = "192.168.1.1";
	cout << DefangingIpAddress(addres1);
}
