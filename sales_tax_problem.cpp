#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;


float roundIt(float var) 
{ 
    // 37.66666 * 100 =3766.66 
    // 3766.66 + .5 =3767.16    for rounding off value 
    // then type cast to int so value is 3766 
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
} 

int main()
{    
    string line;
    float taxValue = 0;
    float totalPrice = 0;
    while( getline(cin,line))
    {
        if(line.empty())
            break;
            
        int i = 0;
        vector<string> parts;
        int start = -1;
        int imported = line.find("imported");
        int food = line.find("chocolate");
        int medical = line.find("pill");
        int books = line.find("book");
        
        for(i = 0; i < line.size(); i++){
            if(line[i] == ' ' ){
                parts.push_back(line.substr(start+1,i-start-1));
                start = i;
            }
            else if(i == line.size()-1){
                parts.push_back(line.substr(start+1,i-start));
            }
        }
        string itemName = parts[0];
        float itemPrice = 0;
        bool atCame = false;
        for(i = 1; i < parts.size(); i++){
            
            if(parts[i] != "at" && !atCame){
                itemName += " " + parts[i];
            }
            else if(parts[i] == "at"){
                atCame = true;
            }
            else{
                itemPrice = atof(parts[i].c_str());
            }
        }
        
        float taxedPrice = itemPrice;
        
        if(books == -1 && food == -1 && medical == -1){
            taxedPrice = 1.1*itemPrice;
            taxValue += 0.1*itemPrice;
            
        }
        
        if(imported != -1){
            taxedPrice += 0.05*itemPrice;
            taxValue += 0.05*itemPrice;
        }
        totalPrice += taxedPrice;
        cout << itemName << ": " <<roundIt(taxedPrice) << "\n" ;
    }
    taxValue = ceil(taxValue*20)/20;
    cout << "Sales Taxes: "<< taxValue << "\n";
    cout << "Total: " << roundIt(totalPrice);
    
    
}


