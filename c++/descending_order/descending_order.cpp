#include <cinttypes>
#include <cstdio>
#include <vector>

using namespace std;

uint64_t descendingOrder(uint64_t a);

int main(int argc, char *argv[])
{
	uint64_t a = 1754444;
	uint64_t digitos_para_ordenar{descendingOrder(a)};
	printf("%u", digitos_para_ordenar );
	return 0;
}

//uint64_t descendingOrder(uint64_t a) {
	//int resto{};
	//vector<int> vec{};
	//int temp{};
	//while ( a > 0 ) {
		//resto = a % 10;
		//a = a / 10;
		////printf("resto: %d, número: %d\n", resto, a);
		//vec.push_back(resto);
	//}
	//for ( size_t i{}; i < vec.size(); i++ ){
		//for ( size_t j{i}; j < vec.size(); j++) {
			//if ( vec[i] < vec[j] ){
				//temp = vec[i];
				//vec[i] = vec[j];
				//vec[j] = temp;
			//};
		//};
	//};
	//uint64_t ans{};
	//for (size_t i = 0; i < vec.size(); ++i) {
		//ans = ans * 10 + vec[i];
	//}
	//return ans;
//}
//############Soluciones para estudiar:

#include <cinttypes>
#include <string>
#include <algorithm>

uint64_t descendingOrder(uint64_t a)
{
	std::string s = std::to_string(a);
	std::sort(s.rbegin(), s.rend());
	return std::stoull(s);
}



//##########Segunda



//#include <cinttypes>
//
//uint64_t descendingOrder(uint64_t a)
//{
  //std::vector<int> c ;

  //for(uint64_t b = a ; b > 0 ; b /=10)
    //c.push_back(b % 10);

  //for(int i=0 ; i < c.size() ; i++)
    //for(int j=i; j < c.size() ; j++)
      //if(c[i] < c[j])
        //std::swap(c[i],c[j]);

  //a=0;

  //for(int i=0; i < c.size() ;i++)
    //a = a*10 + c[i];

  //return a;
//}
