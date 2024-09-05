#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

bool controlCNP (char sirCNP[]) {
  int verificator[] = {2,7,9,1,4,6,3,5,8,2,7,9};
  int suma = 0;
  
  for (int i = 0; i<strlen(sirCNP)-1;i++) {
    sirCNP[i] = int (sirCNP[i]);
    
    suma = suma + ((int(sirCNP[i])-int('0'))*verificator[i]);
  }
  
  if (suma%11 == int(sirCNP[12])-int('0'))
    return 1;
  else return 0;
}
int char2num(char ch1, char ch2) {
  int numar=0;
  int num1 = int(ch1)-int('0');
  int num2 = int(ch2)-int('0');
  
  numar = 10*num1+num2;
  return numar;
}
string index2Text (string sirNume[], int elementeSir, int index) {
  string text;
  for (int i=0; i<elementeSir; i++) {
  if (i == index)
  text = sirNume[i];

  }
  return text;
}
//Convertor UNIVERSAL - char array to number
// int CharToNum(char sir[]) {
//   int numar=0;
//   int elemSir = strlen(sir)-1;
//   cout<<elemSir<<endl;
//   for (int i=0; i<elemSir; i++) {     
    
//     numar = numar+pow(10,(elemSir)-i)*(sir[i]-int('0'));
//     }
//   return numar;
// }
bool esteCifra (char sir[]){
    for (int i=0; i<strlen(sir); i++) {
      if (isdigit(sir[i]) == 0) 
        return 0; 
    } return 1;
  }
// CNP = S AA LL ZZ JJ NNN C
string numeLuna [] = {"Luna","Ianuarie", "Februarie", "Martie", "Aprilie", "Mai", "Iunie", "Iulie", "August", "Septembrie", "Octombrie", "Noiembrie", "Decembrie"};
string numeJudet[] = {"Judet","Alba","Arad","Arges","Bacau","Bihor","Bistrita-Nasaud","Botosani","Brasov","Braila","Buzau","Caras-Severin","Cluj","Constanta","Covasna","Dambovita","Dolj","Galati","Gorj","Harghita","Hunedoara","Ialomita","Iasi","Ilfov","Maramures","Mehedinti","Mures","Neamt","Olt","Prahova","Satu Mare","Salaj","Sibiu","Suceava","Teleorman","Timis","Tulcea","Vaslui","Valcea","Vrancea","Bucuresti","Bucuresti-S1","Bucuresti-S2","Bucuresti-S3","Bucuresti-S4","Bucuresti-S5","Bucuresti-S6","Rezerva1","Rezerva2","Rezerva3","Rezerva2","Calarasi","Giurgiu"};
int nrJudete=sizeof(numeJudet)/sizeof(numeJudet[0]);
int nrLuni=sizeof(numeLuna)/sizeof(numeLuna[0]);


bool verificareData (char cnp[]) {
int sex = int(cnp[0])-int('0');
int an = char2num(cnp[1],cnp[2]);
int luna = char2num(cnp[3],cnp[4]);
int zi = char2num(cnp[5],cnp[6]);
int judete = char2num(cnp[7],cnp[8]);
  
if (sex < 4 && an >22) return 0;
  else if  (luna>12 || judete > 53 || zi>31) return 0;
    else if (an%4 == 0 && luna == 2 && zi>29 ) return 0;
      else if (an%4 != 0 && luna == 2 && zi>28 ) return 0;
        else if (luna%2 == 0 && luna !=8 && zi>30) return 0;
          else return 1;
  }


  




int main() {
cout<< nrJudete;
// Judete - index
 // for (int i=1;i<lung;i++) {
 //   cout<<"Judet["<<i<<"]="<<judet[i]<<endl;
 // }
  
  char cnp[13+5]; //nr corect + buffer in caz de typos
  cout<<"CNP: "; cin>>cnp;
  
int sex = int(cnp[0])-int('0');
  
// Bucla introducere corecta CNP tel (13 caractere, doar cifre)
  while (strlen(cnp) != 13 || esteCifra(cnp) == 0 ||  controlCNP(cnp)==0 ){
    cout<<"CNP INVALID!!! \nVerificati CNP-ul si Încercati din nou. \nCNP: ";
    cin>>cnp;
  }



  
if (controlCNP(cnp)==1) cout<<"VALID"<<endl;
  else cout<<"INVALID"<<endl;

  //if (int(cnp[0]) < 6 ):

//data
sex = int(cnp[0])-int('0');
  
  // compilare an:
int an=0;
  if (sex ==1 || sex==2) an = 1900;
  if (sex ==3 || sex==4) an = 1800;
  if (sex ==5 || sex==6) an =2000;
an = an + char2num(cnp[1],cnp[2]);
  
  // compilareLuna
int luna_numar = char2num(cnp[3],cnp[4]);
string luna_text = index2Text(numeLuna, nrLuni, luna_numar);
  
// compilareZi
int zi = char2num(cnp[5],cnp[6]);
  
  // compilareJudete
int judete_numar = char2num(cnp[7],cnp[8]);
string judet_text = index2Text(numeJudet, nrJudete, judete_numar);
  
cout<< "Data nasterii: "<<zi<<"."<<luna_numar<<"."<<an<<endl;

cout<< "Data nasterii: "<<zi<<" "<<luna_text<<" "<<an<<endl;
  

 


  
  cout<<"Luna este " <<luna_text<<endl;
  cout<<"Judetul este " <<judet_text<<endl;
} // endMain





