#include "BinaryTree.h"  
#include "ConvertCode.h"  
#include "EncoderDecoder.h"  
#include "HashTable.h"  
#include "MorseTree.h"  
#include <iostream>  
  
  
 using namespace std;  
 int main()  
 {  
 	 Convert_Code MorseCode;  
 	 MorseCode.parse();  
  
 	 string resultA = MorseCode.decode("._.");  
 	 string resultB = MorseCode.encode("cat");  
 	 cout << resultA << " " << resultB << endl;  
  
  
  
 	 system("pause");  
         return   0;  
 }  
  
 
