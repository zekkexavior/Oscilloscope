#include <iostream>
#include <cmath>

using namespace std;
int main(){
  int sram1[40];
  int sram2[40];
  int prev_sample;
  char poop;
  int data_bus[1000];
  int derivata=0;
  int jump=40;
  bool trigged=0;
  //bool sram_id=0;
  //h = 20
  //v = 10
  for(int i=0;i<1000;++i)
  {
    data_bus[i]=5.5+1*sin(i/25.0)+3*sin(i/3.0);
  }
  int j=0;
  cout << endl;
  for(int k=0;k<100;++k)
  {//frame NR K
    //sram_id=k&1;//maska ut LSB
    for(int h=0;h<40;++h)
    {
      sram1[h]=data_bus[j+h];
    } 
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << "__________________________________________" << endl; //upper boundry, just for fun
    for(int v=0;v<11;++v)
    {  //rader
      for(int h=0;h<40;++h)
      {//kolumner
        if(sram1[h]<6 && prev_sample>=6)
        {//hög flank vid nollan
          if(trigged==0)
          {
            for(int i=0;i<40;++i)
            {//uppdatera sram med triggern på rätt plats
              sram1[i]=data_bus[h+j+i];//orealistiskt, dream. 
            }
            trigged=1;
            jump=40-h;   
          }
          //cout << "?";
        }
        //else
        if(sram1[h]==v)
        {
            cout << "#";
        }
        else if ((h%8)==0)
        {
          cout << "|";
        }
        else if (((v-1)%4)==0)
        {
          cout << "-";
        }
        else
        { 
          cout << " ";
        }
        derivata = prev_sample-sram1[h];
        prev_sample=sram1[h];  
        //en pixel har gått
      }
      prev_sample=0;   
      cout << " " << v <<endl;
      //en rad har gått
    }
    //en frame har gått
    j+=jump;  
    jump=40;
    trigged = 0;
    cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"; //lower boundry, just for fun
    cin >> poop;
  } 
  return 0;
}
